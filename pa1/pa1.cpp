/*
* File: add2.cpp
* --------------
* This program reads in two numbers, adds them together,
* and prints their sum.
*/

#include <iostream>
#include "genlib.h"
#include "simpio.h"


bool isPerfect(int num){
  int acc = 0;
  for(int i = 1; i < num; i++) {
    if(num % i == 0){
	  acc += i;
	}
  }
  if(acc == num){
	return true;
  }	
  else {
	return false;
  }		
	
}
			
		
		
int main() 
{
	for(int i = 1; i < 1000; i++){
		if(isPerfect(i)){
			cout << i << endl;
		}
	}
	return 0;
}
