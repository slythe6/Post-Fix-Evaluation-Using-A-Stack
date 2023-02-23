//CS311 Yoshii FALL21
//INSTRUCTION:
//Look for ** to complete this program (Use control-S)
//The output should match my hw1stackDemo.out 
// NEVER delete my comments !!!
//=========================================================
//HW#: HW1P1 stack application (post-fix evaluation)
//Your name: Simon Hausmaninger
//Complier:  g++
//File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"

//Purpose of the program: Communicate with user to solve postfix problems
//Algorithm: ** Receive post fix expresssion
// while char is of type int, push to stack
//when operand is recieved, pop
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  int result;
  while (expression[i] != '\0') // til the end of the expression
    {
     try
       {
	 item = expression[i];  // current char
	 // ** do all the steps in the algorithm given in Notes-2A
	 if(item > 47 && item < 58){
     int num;
     num = expression[i] - '0';
     postfixstack.push(num);
     postfixstack.displayAll();
   } else if((item == '+') || (item == '-') || (item == '*')) {
     postfixstack.pop(box1);
     postfixstack.pop(box2);
    
     if(item == '+'){
     result = box2 + box1; 
     postfixstack.push(result);
     }
     else if(item == '-'){
     result = box2 - box1;
     postfixstack.push(result);
     }
     else if(item == '*'){
     result = box2 * box1;
     postfixstack.push(result);
     }

    
    }
     else{
      cout<< "Invalid element" << endl;
      exit(1);
   }
   
       } // this closes try
      // Catch exceptions and report problems and quit the program now (exit(1)). 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{cerr << "ERROR: StackOverflow - Expression has too many operands" << endl; }
      catch (stack::Underflow)
	{cerr << "ERROR: StackUnderflow - Expression has too few operands" << endl; }
      catch (char const* errormsg ) // for invalid item case
	{cerr << "Error: invalid expression" << endl; }
      // go back to the loop after incrementing i
      i+=1;
    }// end of while
  
 // After the loop successfully completes: 
 // Pop the result and show it.
   postfixstack.pop(result);
   cout << "Result = " << result << endl;
 // If anything is left on the stack, an incomplete expression 
 // was found so also inform the user.
   if(!(postfixstack.isEmpty()))
   cout << "Incomplete Expression" << endl;

   postfixstack.clearIt();

}// end of the program
