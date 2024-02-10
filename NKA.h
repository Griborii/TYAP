class NKA {
  size_t size_;
  Node* start_;
  std::vector<Node*> finish_;
  std::vector<Node*> all_; // список всех вершин
  void DFS(Node* now) { // обход DFS, нумерующий ноды и создающий список all
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
  Node* Start() { return start_; }
  Node* GetNode(size_t num) { return all_[num]; }
  void Print() { // вывод NKA
    std::cout << "start_: " << start_->num << " " << "finish: ";
    for (auto fin : finish_) {
      std::cout << fin->num << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < all_.size(); ++i) {
      Node* now = all_[i];
      std::cout << "\n Node: " << i << "\n";
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
  NKA(const std::map<char, int>& dict, const std::vector<std::string>& v_str, 
                                       const std::vector<std::string>& false_st)
      : size_(dict.size()), start_(new Node(dict.size())), finish_(0), all_(0) { //  строим одно NKA по n регуляркам и словарю, нумерующим символы
    for (size_t i = 0; i < v_str.size(); ++i) {
      ParseTree gr(dict, v_str[i]);
      std::pair<Node*, Node*> pr = gr.BuildNKA(i);
      start_->Add(pr.first); // эпсилон переход из общего старта в локальный (для одной регулярки)
      finish_.push_back(pr.second);
    }
    for (size_t i = 0; i < false_st.size(); ++i) {
      ParseTree gr(dict, false_st[i]);
      std::pair<Node*, Node*> pr = gr.BuildNKA(2000000);
      start_->Add(pr.first); // эпсилон переход из общего старта в локальный (для одной регулярки)
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
