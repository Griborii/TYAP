struct Node {
  bool err = false;
  int finish = -1; // номер токена, которму принадлежит
  size_t num; // номер
  size_t size;
  std::vector<Node*> trans; // обычные переходы (считаем что их не более одного, этого в нашей задаче построения ДКА достаточно)
  std::vector<Node*> epsilon; // эпсилон переходы, может быть много
  Node(size_t size) :  num(-1), size(size), trans(size, nullptr), epsilon(0) {}
  Node* Trans(size_t let) { return trans[let]; }
  void Add(size_t let, Node* nd) {
    if (let >= trans.size()) {
      trans.resize(let + 1);
    }
    trans[let] = nd; 
  } //новый переход по букве
  void Add(Node* nd) { epsilon.push_back(nd); } // новый эпсилон переход
  bool IsFinish() { return finish >= 0; }
  void MakeFinish(size_t fin) { finish = fin; }
  std::vector<Node*>& Eplison() { return epsilon; }
};