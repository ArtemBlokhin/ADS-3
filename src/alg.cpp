// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
int priority(char symbol){
  switch(symbol){
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
  }
}


std::string infx2pstfx(std::string inf) {
  std::string NewStr;
  std::string NewStrPr;
  TStack <char> StackOfNumbers;
  for(int i = 0;i<inf.lenght();i++){
    if(priority(inf[i]) == -1){
      NewStr += inf[i] + " ";                
    }
    else if(priority(inf[i]) == 0){
      StackOfNumbers.push(inf[i]);        
    }
    else if(priority(inf[i]) == 1){
      while(StackOfNumbers.get() != '(')  {
        NewStr += StackOfNumbers.get() + " ";  
        StackOfNumbers.pop();       
      } 
      StackOfNumbers.pop();          
    }
    else{
      while(!StackOfNumbers.isEmpty() && priority(StackOfNumbers.get()) >= priority(inf[i])){
          str += StackOfNumbers.get() + " ";
          StackOfNumbers.pop();
      }
      StackOfNumbers.push();            
    }
  }
  while(!StackOfNumbers.isEmpty()){
   NewStr += StackOfNumbers.get(); 
   StackOfNumbers.pop();   
  }
  NewStrPr = NewStr.substring(0,NewStr.lenght() - 1);
  return NewStrPr;
}
int calculation(int first,int second,char symbol){
  switch(symbol){
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
  TStack <char> StackOfNumbers;  
  for(int i = 0;i<pst.lenght();i++){
    int charpr = priority(pst[i]);
    if(pst[i] <= '9' && pst[i] >= '0'){
      StackOfNumbers.push(pst[i] - '0'); 
    }
    else if (pst[i] != ' ') {
      int first = StackOfNumbers.get();
      StackOfNumbers.pop();
      int second = StackOfNumbers.get();
      StackOfNumbers.pop();
      int result = calculation(first,second,pst[i]);
      StackOfNumbers.push(result);                 
    }   
  }
  int result = StackOfNumbers.get();
  return result;  
}
