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
  std::string NewStrPr;
  std::string Temp;
  TStack <char> StackN;
  for (int i = 0; i < inf.length(); i++) {
    if ((inf[i] >= '0') && (inf[i] <= '9')) {
      Temp = inf[i];
      NewStr += Temp + " ";
    } else if (inf[i] == '(') {
      StackN.push(inf[i]);
    } else if (inf[i] == ')') {
      while (!StackN.isEmpty() && StackN.get() != '(') {
        Temp = StackN.get();
        NewStr += Temp + " ";
        StackN.pop();
      }
      if (StackN.get() == '(') {
        StackN.pop();
      }
    } else {
      while (!StackN.isEmpty() && pr(StackN.get()) >= pr(inf[i])) {
          Temp = StackN.get();
          NewStr += Temp + " ";
          StackN.pop();
      }
      StackN.push(inf[i]);
    }
  }
  while (!StackN.isEmpty()) {
    Temp = StackN.get();
    NewStr += Temp + " ";
    StackN.pop();
  }
  NewStrPr = NewStr.substr(0, NewStr.length()-1);
  return NewStrPr;
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
