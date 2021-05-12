// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int prio(char symbol) {
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
      break                 
  }
}


std::string infx2pstfx(std::string inf) {
  std::string NewStr;
  std::string NewStrPr;
  std::string Temp;
  TStack <char> StackOfNumbers;
  for (int i = 0; i < inf.length(); i++) {
    if (pr(inf[i]) == -1) {
      temp = inf[i];
      NewStr += temp + " ";          
    } else if (pr(inf[i]) == 0) {
      StackOfNumbers.push(inf[i]);
    } else if (pr(inf[i]) == 1) {
      while (StackOfNumbers.get() != '(') {
        Temp = StackOfNumbers.get();
        NewStr += Temp + " "; 
        StackOfNumbers.pop();      
      }
      StackOfNumbers.pop();        
    } else {
      while (!StackOfNumbers.isEmpty() && pr(StackOfNumbers.get()) >= pr(inf[i])) {
          NewStr += StackOfNumbers.get() + " ";
          StackOfNumbers.pop();
      }
      StackOfNumbers.push(inf[i]);         
    }
  }
  while (!StackOfNumbers.isEmpty()) {
    NewStr += StackOfNumbers.get() + " ";
    StackOfNumbers.pop();
  }
  NewStrPr = NewStr.substr(0, NewStr.length()-1);
  return NewStrPr;
}
int calculation (int first,int second,char symbol) {
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
int eval (std::string pst) {
  TStack <char> StackOfNumbers;  
  for (int i = 0; i<pst.length(); i++) {
    int charpr = priority(pst[i]);
    if (pst[i] <= '9' && pst[i] >= '0') {
      StackOfNumbers.push(pst[i] - '0');
    } else if (pst[i] != ' ') {
      int first = StackOfNumbers.get();
      StackOfNumbers.pop();
      int second = StackOfNumbers.get();
      StackOfNumbers.pop();
      int result = calculation(first, second,pst[i]);
      StackOfNumbers.push(result);        
    }
  }
  int result = StackOfNumbers.get();
  return result;
}
