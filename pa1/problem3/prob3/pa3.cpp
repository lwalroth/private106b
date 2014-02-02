/*
* File: add2.cpp
* --------------
* This program reads in two numbers, adds them together,
* and prints their sum.
*/

#include <iostream>
#include "genlib.h"
#include "simpio.h"
#include "random.h"

#include "strutils.h"



string fullCode(string surname){
	
	
	string group0 = "AEIOUHWY";
	string group1 = "BFPV";
	string group2 = "CGJKQSXZ";
	string group3 = "DT";
	string group4 = "MN";
	string group5 = "L";
	string group6 = "R";
	
    string surnameCap = ConvertToUpperCase(surname);
	string code = surnameCap.substr(0,1);
	
	
	for(int i = 1; i < surname.length(); i++){
		
		if(group0.find(surnameCap[i])!= string::npos){
			code += IntegerToString(0);
			
		}
		
		else if(group1.find(surnameCap[i]) != string::npos){
			code += IntegerToString(1);
		}
		else if(group2.find(surnameCap[i]) != string::npos){
			code += IntegerToString(2);
		}
		else if(group3.find(surnameCap[i]) != string::npos){
			code += IntegerToString(3);
		}
		else if(group4.find(surnameCap[i]) != string::npos){
			code += IntegerToString(4);
		}
		else if(group5.find(surnameCap[i]) != string::npos){
			code += IntegerToString(5);
		}
		else if(group6.find(surnameCap[i]) != string::npos){
			code += IntegerToString(6);
		}
	}
	
	return code;
	
}

string removeDuplicates(string code){
	string dupRemoved = code.substr(0,1);
	
	for(int i = 1; i < code.length(); i++){
		if(code[i] != code[i + 1]){
		    dupRemoved += code[i];
		}
	
	}
	return dupRemoved;
	
}

string removeZeros(string dupRemoved){
	string zerosRemoved = dupRemoved.substr(0,1);
	
	for(int i = 1; i < dupRemoved.length(); i++){
		if(dupRemoved[i] != '0'){
			zerosRemoved += dupRemoved[i];
		}
	}
	return zerosRemoved;
}

string finalCode(string zerosRemoved){
	string finalC = zerosRemoved.substr(0);
	
	if (zerosRemoved.length() == 4){
		return zerosRemoved;
	}
	else {
		while(finalC.length() != 4){
			finalC += IntegerToString(0);
		}
		return finalC;
		
	}
	
	
}

int main() 
{
	string surname;
	
	    cout << "Enter surname (RETURN to quit): ";
	    getline(cin,surname);
	    while (surname != ""){
			string temp1 = fullCode(surname);
	        string temp2 = removeDuplicates(temp1);
	        string temp3 = removeZeros(temp2);
	
	
	        cout << "Soundex code for " << surname << " is " << finalCode(temp3) << endl;
			cout << "Enter surname (RETURN to quit): ";
			getline(cin,surname);
	    }
	return 0;
}
