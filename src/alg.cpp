// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int pr(char symbol) {
  switch (symbol) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '+':
      return 2;
    case '-':
      return 2;
    case '*':
      return 3;
    case '/':
      return 3;
    default:
      return -1;
  }
}


std::string infx2pstfx(std::string inf) {
  std::string NewStr;
  std::string Temp;
  TStack <char> StackN;
  for (int i = 0; i < inf.length(); i++) {
    if ((inf[i] >= '0') && (inf[i] <= '9')) {
      NewStr += inf[i];
      NewStr += ' ';
    } else if (inf[i] == '(') {
      StackN.push(inf[i]);
    } else if (pr(inf[i]) > pr(StackN.get()) || StackN.isEmpty()) {
      StackN.push(inf[i]);
    } else if (inf[i] == ')') {
      while (!StackN.isEmpty() && StackN.get() != '(') {
        NewStr += StackN.get();
        NewStr += ' ';
        StackN.pop();
      }
      if (StackN.get() == '(') {
        StackN.pop();
      }
    } else {
      while (!StackN.isEmpty() && pr(StackN.get()) >= pr(inf[i])) {
        NewStr += StackN.get();
        NewStr += ' ';
        StackN.pop();
      }
      StackN.push(inf[i]);
      }
    }
  while (!StackN.isEmpty()) {
        NewStr += StackN.get();
        NewStr += ' ';
        StackN.pop();
  }

  while (NewStr[NewStr.length() - 1] == ' ') {
    NewStr = NewStr.substr(0, NewStr.length()-1);
  }
  return NewStr;
}
int calculation(int first, int second, char symbol) {
  switch (symbol) {
    case '+':
      return first + second;
      break;
    case '-':
      return first - second;
      break;
    case '*':
      return first * second;
      break;
    case '/':
      return first / second;
      break;
  }
}
int eval(std::string pst) {
  TStack <int> StackN;
  for (int i = 0; i < pst.length(); i++) {
    if ((pst[i] <= '9') && (pst[i] >= '0')) {
      StackN.push(pst[i] - '0');
    } else if (pst[i] != ' ') {
      int first = StackN.get();
      StackN.pop();
      int second = StackN.get();
      StackN.pop();
      int result = calculation(first, second, pst[i]);
      StackN.push(result);
    }
  }
  int result = StackN.get();
  return result;
}
