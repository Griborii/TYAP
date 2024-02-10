#pragma once

struct Token {
  std::string name;
  std::string reg;
  Token() = default;
  Token(std::initializer_list<std::string> lst) : name(*(lst.begin())), reg(*(lst.end() - 1)) {}
};
