#pragma once

#include "token.h"

constexpr char eps = 'E'; // обозначения эпсилона в регулярном выражении

namespace inv {
std::vector<Token> false_states = {
  {"strange_variable", "(((0-9).((0-9)*)).(a-z))"}
};
std::vector<Token> tokens = {
  {"number", "(1-9).((0-9)*)"},
  {"var", "(((a-z)+(A-Z)).(((a-z)+_+(0-9))*))"},
  {"semicolon", ";"},
  {"keyword", "int+for+if+else+while+fun+char+print"},
  {"equal", "="},
  {"string", "\".(((a-z)+(0-9))*).\""},
  {"left_cur_brace", "{"},
  {"right_cur_brace", "}"},
  {"left_sq_brace", "["},
  {"right_sq_brace", "]"},
  {"less", "<"},
  {"more", ">"},
  {"comma", ","},
};
std::map<char, std::string> symv_for_reg = {
  {'(', "left_scope"},
  {')', "right_scope"},
  {'+', "plus"},
  {'-', "minus"},
  {'.',"dot"},
  {'*', "star"},
  {' ', "space"}
};
} // namespace inv