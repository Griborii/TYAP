struct Lexem {
  std::string token;
  std::string text;
  int64_t value = -1;
  bool sign_ = true;
  Lexem() = default;
  Lexem(const std::string& token, const std::string& text) : token(token), text(text) {}
  Lexem(const std::string& token, int64_t value) : token(token), text(""), value(value) {}
  void Print() {
    std::cout << "token: " <<  token << " ";
    if (value >= 0) {
      std::cout << "value: ";
      if (!sign_) {
        std::cout << "-";
      }
      std::cout << value << "\n";
    } else {
      std::cout << " lexem: " << text << "\n";
    }
  }
};

class Table { // ходит по состояниям в ДКА
  const DKA<Node>& dka_;
  size_t state_;
  size_t pos_;
  size_t last_finish_;
  size_t last_finish_state_;
  int64_t value_;
  bool sign_;
  bool is_value;
 public:
  Table(const DKA<Node>& dka) : dka_(dka), state_(dka_.start_->num), pos_(0),
      last_finish_(0), last_finish_state_(0), value_(0), sign_(true), is_value(false) {}
  void Reset() {
    state_ = 0;
    pos_ = 0;
    last_finish_ = 0;
    value_ = 0;
    sign_ = 0;
    is_value = false;
  }
  bool IsErr() { return dka_.IsErr(state_); }
  bool IsFalse() { return dka_.IsFalse(state_); }
  void Trans(char let) {
    ++pos_;
    state_ = dka_.Trans(state_, let);
    // std::cout << "\nnow finish is:" << dka_.Finish(state_) << "\n";
    if (static_cast<int>(let) <= static_cast<int>('9') &&
        static_cast<int>(let) >= static_cast<int>('0')) {
      value_ = value_ * 10 + static_cast<int>(let) - static_cast<int>('0');
    }
    if (dka_.IsFinish(state_)) {
      last_finish_ = pos_;
      last_finish_state_ = state_;
    }
  }
  void MakeValue() { is_value = true; }
  bool IsNumber() { return is_value; }
  int64_t Value() { return value_; }
  bool IsVar() {
    return last_finish_ == 0;
  }
  std::pair<size_t, size_t> Finish() { return {last_finish_,
                                               dka_.Finish(last_finish_state_)}; }
};

class Scaner {
  Table table_;
  std::vector<Lexem> ans_;
 public:
  Scaner(const DKA<Node>& dka) : table_(dka), ans_(0) {}
  void Print() {
    for (auto lex : ans_) {
      lex.Print();
    }
  }
  void Read(const std::string& str) {
    table_.Reset();
    size_t pos = 0;
    while (pos < str.size()) {
      while (str[pos] == ' ' && pos < str.size()) {
        ++pos;
      }
      ans_.push_back(ReadWord(str, pos));
    }
  }
 private:
  Lexem ReadWord(const std::string& str, size_t& pos) {
    if (inv::symv_for_reg.find(str[pos]) != inv::symv_for_reg.end()) {
      ++pos;
      return Lexem((*(inv::symv_for_reg.find(str[pos - 1]))).second,
                    std::string(1, (*(inv::symv_for_reg.find(str[pos - 1]))).first));
    }
    table_.Reset();
    size_t now = pos, start = pos;
    do {
      ++now;
      if (now == pos + 1 && static_cast<int>(str[now - 1]) <= static_cast<int>('9') &&
        static_cast<int>(str[now - 1]) >= static_cast<int>('0')) {
        table_.MakeValue();
      }
      table_.Trans(str[now - 1]);
      if (table_.IsFalse()) {
        std::cout << str.substr(start, table_.Finish().first) << " - ";
        std::cout << "Scaner error!!!" << std::endl;
        throw;
      }
    } while(!table_.IsErr() && now < str.size());
    if (table_.IsNumber()) {
      pos = now;
      return Lexem("number", table_.Value());
    }
    auto ans = table_.Finish();
    pos += ans.first;
    return Lexem(inv::tokens[ans.second].name, str.substr(start, ans.first));
  }
};