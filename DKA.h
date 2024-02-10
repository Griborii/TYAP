template <typename DkaNode>
class DKA {
  friend class Table;
  size_t dict_size_; // размер алфавита
  DkaNode* start_;
  DkaNode* trash_;
  std::vector<DkaNode*> finish_;
  std::vector<DkaNode*> states_;  // dka states_
  std::map<std::set<size_t>, size_t> nka_map_;// мапа из множеств подмножеств нка в новое состояние дка
  std::map<char, int>& dict_;
 public:
  DKA(DKA&& dka)
      : dict_size_(dka.dict_size_),
        start_(dka.start_),
        trash_(dka.trash_),
        finish_(dka.finish_),
        states_(dka.states_),
        nka_map_(dka.nka_map_),
        dict_(dka.dict_) {
    dka.start_ = nullptr;
    for (auto& elem: dka.states_) {
      elem = nullptr;
    }
  }
  DKA(NKA& nka, size_t size, std::map<char, int>& dict)
      : dict_size_(size),
        start_(nullptr),
        states_(std::vector<DkaNode*>()),
        nka_map_(std::map<std::set<size_t>, size_t>()),
        dict_(dict) {
    BuildDFA(nka);
  }
  void Print() const { // Вывод ДКА
    std::cout << "\n\nstart_: " << start_->num << " " << "finish: ";
    for (auto fin : finish_) {
      std::cout << "(numder: "<< fin->num << " type: " << fin->finish << ") ";
    }
    std::cout << std::endl;
    std::cout << "Trash: " << trash_->num << std::endl;
    for (size_t i = 0; i < states_.size(); ++i) {
      auto now = states_[i];
      std::cout << "\n node: " << i << "\n";
      for (size_t j = 0; j < dict_size_; ++j) {
        if (now->trans[j] != nullptr) {
          std::cout << "(" << FindInMap(j) << "->" << now->trans[j]->num << ") ";
        }
      }
    }
    std::cout << std::endl << "dict:\n";
    for (auto [elem, key] : dict_) {
      std::cout << elem << " " << key << std::endl;
    }

  }
  int Finish(size_t ind) const { return states_[ind]->finish; }
  bool IsFinish(size_t ind) const { return states_[ind]->finish != -1; }
  bool IsErr(size_t ind) const { return states_[ind]->err; }
  bool IsFalse(size_t ind) const { return states_[ind]->finish == 2000000; }
  // bool IsVar(size_t ind) const { return states_[ind]->finish == 1; }
  size_t Trans(size_t ind, char letter) const {
    return states_[ind]->Trans(dict_.at(letter))->num;
  }
  ~DKA() {
    for (auto node : states_) {
      delete node;
    }
  }
  void AddSpecSymvs() {
    for (auto [key, value] : inv::symv_for_reg) {
      dict_[key] = dict_.size();
      for (auto& state : states_) {
        state->Add(dict_.size() - 1, trash_);
      }
    }
  }
 private:
  char FindInMap(size_t n) const {
    for (auto [key, value] : dict_) {
      if (value == n) {
        return key;
      }
    }
  }
  void EpsClosure(std::set<size_t>& closure, Node* node) {
    closure.insert(node->num);
    for (auto next : node->Eplison()) {
      if (closure.find(next->num) == closure.end()) {
        closure.insert(next->num);
        EpsClosure(closure, next);
      }
    }
  }
  std::set<size_t> EpsClosure(NKA& nfa, std::set<size_t> indexes) {
    std::set<size_t> closure;
    for (auto index : indexes) {
      EpsClosure(closure, nfa.GetNode(index));
    }
    return closure;
  }
  int PutFinal(NKA& nfa, std::set<size_t>& set) {
    int finish = -1;
    std::set<size_t> closure = EpsClosure(nfa, set);
    for (auto num:closure) {
      auto curr_node = nfa.GetNode(num);
      if (curr_node->IsFinish()) {
        finish = curr_node->finish;
        finish_.push_back(states_[states_.size() - 1]);
      }
    }
    return finish;
  }
  void CreateNode(NKA& nfa, std::set<size_t>& set) {
    auto new_node = new DkaNode(dict_size_);
    nka_map_[set] = states_.size();
    new_node->num = states_.size();
    states_.push_back(new_node);
    new_node->MakeFinish(PutFinal(nfa, set));
    std::set<size_t> closure = EpsClosure(nfa, set);
    if (set.empty()) {
      new_node->err = true;
      trash_ = new_node;
    }
  }
  DkaNode* GetNode(std::set<size_t>& set) {
    auto node_ind = nka_map_[set];
    return states_[node_ind];
  }
  void CreateTrans(std::set<size_t>& from, std::set<size_t>& to, size_t let) {
    auto from_node = GetNode(from);
    auto to_node = GetNode(to);
    from_node->Add(let, to_node);
  }
  bool SetNotProcessed(std::set<size_t>& set) {
    return nka_map_.find(set) == nka_map_.end();
  }
  void BuildDFA(NKA& nfa) {
    std::queue<std::set<size_t>> queue; // очередь из новых состояний
    std::set<size_t> first_set;  // новое состояние (это подмножество множеств старых состояний)
    first_set.insert(nfa.Start()->num);  // создали состояние начальной вершины


    CreateNode(nfa, first_set);  // добавил в дка старт вершину
    start_ = states_[0];

    queue.push(first_set);
    while (!queue.empty()) {
      auto curr_set = queue.front();  // вытащили подмножество
      queue.pop();
      std::set<size_t> closure = EpsClosure(nfa, curr_set);

      for (size_t letter = 0; letter < dict_size_; ++letter) {
        std::set<size_t> next_set;
        for (auto ind : closure) {  // находим следующее подмножество по букве
          auto curr_node = nfa.GetNode(ind);
          auto to_node = curr_node->trans[letter];
          if (to_node != nullptr) {
            next_set.insert(to_node->num);
          }
        }
        if (SetNotProcessed(next_set)) {  // создаем новую вершину в дка
          CreateNode(nfa, next_set);
          queue.push(next_set);
        }
        CreateTrans(curr_set, next_set, letter);
      }
    }
  }
};
