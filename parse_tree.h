#include "consts.h"
#include "math_functions.h"

class ParseTree { // структура дерева разбора.
  struct Vertex { // Node для дерева разбора. Из него наследуются все типы.
    virtual std::pair<Node*, Node*> NKA() = 0; // будет рекурсивно строить NKA, углябляясь по дереву разбора
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
  Vertex* Build(std::string str) { // на основе функции Index каждый раз бьет строку на две и рекурсивно идет от них
    if (str.size() > 1 && str[0] == '(' && str[str.size() - 1] == ')') {
      str = str.substr(1, str.size() - 2);
    }
    size_t ind = Index(str);
    if (ind == 0) {
      if (str[0] == eps) {
        return new Epsilon(size_);
      }
      char l = str[0];
      Vertex* left = new Letter(dict_.at(l), size_);
      for (size_t i = 1; i < str.size(); ++i) {
        l = str[i];
        Vertex* right = new Letter(dict_.at(l), size_);
        left = new Dot(left, right, size_);
      }
      return left;
    }
    if (str[str.size() - 1] == '*') {
      return new Star(Build(str.substr(0, str.size() - 1)), size_);
    }
    if (str[ind] == '-') { // Понимаем это как перечисление элементов от s[i-1] до s[i+1] - например 0-9
      char l = str[ind - 1], r = str[ind + 1];
      Vertex* left = new Letter(dict_.at(l), size_);
      while (static_cast<int> (l) != static_cast<int> (r)) {
        ++l;
        Vertex* right = new Letter(dict_.at(l), size_);
        left = new Plus(left, right, size_);
      }
      return left;
    }
    Vertex* right = Build(str.substr(ind + 1, str.size() - 1 - ind));
    Vertex* left = Build(str.substr(0, ind));
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
    root_ = Build(str);
  }
  ~ParseTree() { delete root_; }
  std::pair<Node*, Node*> BuildNKA(int fin) { // строит NKA, возвращает пару вершин - начало, конец. fin - номер токена (то, как помечаем финищ)
    auto pr = root_->NKA(); // для каждого наследника своя NKA, которая идет рекурсивно по дереву
    pr.second->MakeFinish(fin);
    return pr;
  }
};
