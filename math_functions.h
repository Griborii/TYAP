#pragma once

size_t Index(const std::string& str) { // ищет нулевой индекс
  int ind = 0;
  for (size_t i = 0; i < str.size(); ++i) {
    if (str[i] == '(') {
      ++ind;
    }
    if (str[i] == ')') {
      --ind;
    }
    if (ind == 0 && (str[i] == '+' || str[i] == '*' || str[i] == '.' || str[i] == '-') && i > 0) {
      return i;
    }
  }
  return 0; // если приходит последовательность букв без прочих символов, такое бывает
}

void Count(std::map<char, int>& dict, const std::vector<std::string>& v_str) { // нумерует буквы алфавита
  for (auto str : v_str) {
    for (size_t i = 0; i < str.size(); ++i) {
      if (str[i] != '+' && str[i] != '.' && str[i] != '*' && str[i] != '(' &&
          str[i] != ')' && str[i] != eps && dict.find(str[i]) == dict.end()) {
        if (str[i] == '-') {
          char l = str[i - 1];
          while (l != str[i + 1]) {
            ++l;
            if (dict.find(l) == dict.end()) {
              dict[l] = dict.size();
            }
          }
        } else {
          if (dict.find(str[i]) == dict.end()) {
            dict[str[i]] = dict.size();
          }
        }
      }
    }
  }  
}

