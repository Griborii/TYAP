#include <initializer_list>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <stack>
#include "node.h"
#include "parse_tree.h"
#include "consts.h"
#include "math_functions.h"
#include "NKA.h"
#include "DKA.h"
#include "scaner.h"

DKA<Node> BuildDka(std::map<char, int>& dict) {
  std::vector<std::string> v_str;
  for (auto lex : inv::tokens) {
    v_str.push_back(lex.reg);
  }
  std::vector<std::string> false_st;
  for (auto lex : inv::false_states) {
    false_st.push_back(lex.reg);
  }
  Count(dict, v_str);
  Count(dict, false_st);
  NKA nka(dict, v_str, false_st);
  return DKA<Node>(nka, dict.size(), dict);
}
int main2() {
  std::map<char, int> dict;
  DKA<Node> dka(std::move(BuildDka(dict))); // Построение ДКА по заданным в consts.h регуляркам
  Scaner scaner(dka);
  std::string str = "", s;
  dka.AddSpecSymvs(); // в ДКА нужно добавить переходы по спецсимволам (см consts::inv::symv_for_reg), которые также есть в языке
  std::ifstream ifstr ("file.txt");
  while (std::getline(ifstr, s)) {
    str += s;
  }
  // dka.Print();
  scaner.Read(str);
  scaner.Print();
}

int main() {
  size_t n;
  std::cin >> n;
  std::map<char, int> dict;
  std::vector<std::string> v_str(n);
  for (size_t i = 0; i < n; ++i) {
    std::cin >> v_str[i];
  }
  Count(dict, v_str);
  NKA nka(dict, v_str, std::vector<std::string>());
  DKA<Node> dka(nka, dict.size(), dict);
  dka.Print();
}
