// Section Handout #1
// Problem 1: Removing all occurrences of characters

#include "genlib.h"
#include "strutils.h"
#include <iostream>
#include "Vector.h"
#include <fstream> 
#include "simpio.h"


string censorString1(string text, string remove){
	
	string newStr = "";
	for(int i = 0; i < text.length(); i++){
		if(remove.find(text[i]) == string::npos){
			newStr += text[i];
		}
	}
	return newStr;
}
			

string censorString2(string text, string remove){
	
	
	for(int i = 0; i < text.length(); i++){
		if(remove.find(text[i]) != string::npos){
			text.erase(i,1);
		}
	}
	return text;
}


int main(){
	
	cout << censorString1("Stanford University", "nt") << endl;
	cout << censorString2("Stanford University", "nt");
	return 0;
}


