// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int pr(char symbol) {
  switch (symbol) {
    case '(':
      return 0;
      break;
    case ')':
      return 1;
      break;
    case '+':
      return 2;
      break;
    case '-':
      return 2;
      break;
    case '*':
      return 3;
      break;
    case '/':
      return 3;
      break;
    default:
      return -1;
      break;
  }
}


std::string infx2pstfx(std::string inf) {
  std::string NewStr;
  std::string NewStrPr;
  std::string Temp;
  TStack <char> StackN;
  for (int i = 0; i < inf.length(); i++) {
    if (pr(inf[i]) == -1) {
      Temp = inf[i];
      NewStr += Temp + " ";       
    } else if (pr(inf[i]) == 0) {
      StackN.push(inf[i]);
    } else if (pr(inf[i]) == 1) {
      while (StackN.get() != '(') {
        Temp = StackN.get();
        NewStr += Temp + " ";
        StackN.pop();
      }
      StackN.pop();
    } else {
      while (!StackN.isEmpty() && pr(StackN.get()) >= pr(inf[i])) {
          NewStr += StackN.get() + " ";
          StackN.pop();
      }
      StackN.push(inf[i]);
    }
  }
  while (!StackN.isEmpty()) {
    NewStr += StackN.get() + " ";
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
  TStack<char>StackN;
  for (int i = 0; i<pst.length(); i++) {
    if (pst[i] <= '9' && pst[i] >= '0') {
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
