\\ 1
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

\\ 2
constexpr char eps = 'E';

struct Node {
  int finish = -1;
  size_t num;
  size_t size;
  std::vector<Node*> trans;
  std::vector<Node*> epsilon;
  Node(size_t size) :  num(-1), size(size), trans(size, nullptr), epsilon(0) {}
  Node* Trans(size_t let) { return trans[let]; }
  void Add(size_t let, Node* nd) { trans[let] = nd; }
  void Add(Node* nd) { epsilon.push_back(nd); }
  bool IsFinish() { return finish >= 0; }
  void MakeFinish(size_t fin) { finish = fin; }
  std::vector<Node*>& Eplison() { return epsilon; }
};

size_t Index(const std::string& str) {
  int ind = 0;
  for (size_t i = 0; i < str.size(); ++i) {
    if (str[i] == '(') {
      ++ind;
    }
    if (str[i] == ')') {
      --ind;
    }
    if (ind == 0 && (str[i] == '+' || str[i] == '*' || str[i] == '.') && i > 0) {
      return i;
    }
  }
}

class ParseTree {
  struct Vertex {
    virtual std::pair<Node*, Node*> NKA() = 0;
    virtual ~Vertex() = default;
    Vertex(size_t size) : size(size) {}
    size_t size;
  };
  struct Letter : public Vertex {
    size_t letter;
    Letter(size_t letter, size_t size) : Vertex(size), letter(letter) {}
    ~Letter() override = default;
    std::pair<Node*, Node*> NKA() override {
      Node* start = new Node(size);
      Node* finish = new Node(size);
      start->Add(letter, finish);
      return {start, finish};
    }
  };
  struct Epsilon : public Vertex {
    Epsilon(size_t size) : Vertex(size) {}
    ~Epsilon() override = default;
    std::pair<Node*, Node*> NKA() override {
      Node* start = new Node(size);
      Node* finish = new Node(size);
      start->Add(finish);
      return {start, finish};
    }
  };
  struct Plus : public Vertex {
    Vertex* left;
    Vertex* right;
    ~Plus() override {
      delete left;
      delete right;
    }
    Plus(Vertex* left, Vertex* right, size_t size) : Vertex(size), left(left), right(right) {}
    std::pair<Node*, Node*> NKA() override {
      std::pair<Node*, Node*> r = right->NKA();
      std::pair<Node*, Node*> l = left->NKA();
      Node* start = new Node(size);
      Node* finish = new Node(size);
      start->Add(l.first);
      start->Add(r.first);
      l.second->Add(finish);
      r.second->Add(finish);
      return {start, finish};
    }
  };
  struct Star : public Vertex {
    ~Star() override { delete son; }
    Vertex* son;
    Star(Vertex* son, size_t size) : Vertex(size), son(son) {}
    std::pair<Node*, Node*> NKA() override {
      Node* start = new Node(size);
      Node* finish = new Node(size);
      std::pair<Node*, Node*> s = son->NKA();
      start->Add(s.first);
      s.second->Add(s.first);
      s.second->Add(finish);
      start->Add(finish);
      return {start, finish};
    }
  };
  struct Dot : public Vertex {
    Vertex* left;
    Vertex* right;
    ~Dot() override {
      delete left;
      delete right;
    }
    Dot(Vertex* left, Vertex* right, size_t size) : Vertex(size), left(left), right(right) {}
    std::pair<Node*, Node*> NKA() override {
      std::pair<Node*, Node*> r = right->NKA();
      std::pair<Node*, Node*> l = left->NKA();

      l.second->Add(r.first);
      return {l.first, r.second};
    }
  };
  size_t size_;
  const std::map<char, int>& dict_;
  Vertex* root_;
  Vertex* Built(std::string str) {
    if (str.size() == 1) {
      if (str[0] == eps) {
        return new Epsilon(size_);
      }
      return new Letter(dict_.at(str[0]), size_);
    }
    if (str[0] == '(' && str[str.size() - 1] == ')') {
      str = str.substr(1, str.size() - 2);
    }
    if (str[str.size() - 1] == '*') {
      return new Star(Built(str.substr(0, str.size() - 1)), size_);
    }
    size_t ind = Index(str);
    Vertex* right = Built(str.substr(ind + 1, str.size() - 1 - ind));
    Vertex* left = Built(str.substr(0, ind));
    if (str[ind] == '+') {
      return new Plus(left, right, size_);
    }
    if (str[ind] == '.') {
      return new Dot(left, right, size_);
    }
  }

 public:
  ParseTree(const std::map<char, int>& dict, const std::string str)
      : size_(dict.size()), dict_(dict), root_(nullptr) {
    root_ = Built(str);
  }
  ~ParseTree() { delete root_; }
  std::pair<Node*, Node*> BuiltNKA(size_t fin) {
    auto pr = root_->NKA();
    pr.second->MakeFinish(fin);
    return pr;
  }
};

class NKA {
  size_t size_;
  Node* start_;
  std::vector<Node*> finish_;
  std::vector<Node*> all_;
  void DFS(Node* now) {
    now->num = all_.size();
    all_.push_back(now);
    for (size_t i = 0; i < size_; ++i) {
      if (now->trans[i] != nullptr && now->trans[i]->num == -1) {
        DFS(now->trans[i]);
      }
    }
    for (size_t i = 0; i < now->epsilon.size(); ++i) {
      if (now->epsilon[i] != nullptr && now->epsilon[i]->num == -1) {
        DFS(now->epsilon[i]);
      }
    }
  }

 public:
  Node* Start() {
    return start_;
  }
  Node* GetNode(size_t num) {
    return all_[num];
  }
  void Print() {
    std::cout << "start_: " << start_->num << " " << "finish: ";
    for (auto fin : finish_) {
      std::cout << fin->num << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < all_.size(); ++i) {
      Node* now = all_[i];
      std::cout << "\n-----------------------------" << i << "\n";
      for (size_t i = 0; i < size_; ++i) {
        if (now->trans[i] != nullptr) {
          std::cout << "(" << i << "->" << now->trans[i]->num << ") ";
        }
      }
      for (size_t i = 0; i < now->epsilon.size(); ++i) {
        if (now->epsilon[i] != nullptr) {
          std::cout << "(E" << "->" << now->epsilon[i]->num << ") ";
        }
      }
    }
  }
  NKA(const std::map<char, int>& dict, const std::vector<std::string>& v_str)
      : size_(dict.size()), start_(new Node(dict.size())), finish_(0), all_(0) {
    for (size_t i = 0; i < v_str.size(); ++i) {
      ParseTree gr(dict, v_str[i]);
      std::pair<Node*, Node*> pr = gr.BuiltNKA(i);
      start_->Add(pr.first);
      finish_.push_back(pr.second);
    }
    DFS(start_);
  }
  ~NKA() {
    for (size_t i = 0; i < all_.size(); ++i) {
      // std::cout <<all_[i] << "\n";
      delete all_[i];
    }
  }
};

void Count(std::map<char, int>& dict, const std::vector<std::string>& v_str) {
  for (auto str : v_str) {
    for (size_t i = 0; i < str.size(); ++i) {
      if (str[i] != '+' && str[i] != '.' && str[i] != '*' && str[i] != '(' &&
          str[i] != ')' && str[i] != eps && dict.find(str[i]) == dict.end()) {
        dict[str[i]] = dict.size();
      }
    }
  }
}

template <typename DkaNode>
class DKA {
 public:
  DKA(NKA& nka, size_t size)
      : dict_size_(size),
        start_(nullptr),
        states_(std::vector<DkaNode*>()),
        nka_map_(std::map<std::set<size_t>, size_t>()) {
    BuildDFA(nka);
  }

  void Print() {
    std::cout << "start_: " << start_->num << " " << "finish: ";
    for (auto fin : finish_) {
      std::cout << fin->num << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < states_.size(); ++i) {
      auto now = states_[i];
      std::cout << "\n-----------------------------" << i << "\n";
      for (size_t j = 0; j < dict_size_; ++j) {
        if (now->trans[j] != nullptr) {
          std::cout << "(" << j << "->" << now->trans[j]->num << ") ";
        }
      }
    }
  }

 private:
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
    std::cout << "----------" << new_node->num << "-------------\n";
    std::set<size_t> closure = EpsClosure(nfa, set);
    for (auto item:closure) {
      std::cout << item << " ";
    }
    if (set.empty()) {
      std::cout << "TRASH";
    }
    std::cout << "\n";
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

  size_t dict_size_; // размер алфавита
  DkaNode* start_;
  std::vector<DkaNode*> finish_;
  std::vector<DkaNode*> states_;  // dka states_
  std::map<std::set<size_t>, size_t> nka_map_;  // мапа из множеств подмножеств нка в новое состояние дка
};

int main() {
  size_t n;
  std::cin >> n;
  std::vector<std::string> v_str(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> v_str[i];
  }
  std::map<char, int> dict;
  Count(dict, v_str);
  NKA nka(dict, v_str);
  std::cout << "\n--------------NKA---------------\n";
  nka.Print();

  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n--------------DKA---------------\n";
  DKA<Node> dka(nka, dict.size());
  dka.Print();
}
