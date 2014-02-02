

#include "genlib.h"
#include "strutils.h"
#include <iostream>
#include "Vector.h"
#include <fstream> 
#include "simpio.h"


string CensorString1(string text, string remove){
	string newString = "";
	
	for(int i = 0; i < text.length(); i++){
		if((remove.find(text[i]))== string::npos){
			
				newString += text[i];
				
		    
			
		}
    }
	return newString;
}

string CensorString2(string text, string remove){
	
	for(int i = 0; i < text.length(); i++){
		if((remove.find(text[i])) != string::npos){
			text.erase(i, 1);
		}
	}
	return text;
}

int main(){
	
	cout << CensorString1("Stanford University", "nt");
	cout << CensorString2("Stanford University", "nt");
	return 0;
}

