// Section Handout #1
// Problem 3: Vectors


#include "genlib.h"
#include "strutils.h"
#include <iostream>
#include "Vector.h"
#include <fstream> 
#include "simpio.h"




void printVector(Vector<int> v) { 
	string letters = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; i++) { 
		string result = "";
		result = letters.substr(i,1) + ": " + IntegerToString(v[i]);
		
		cout << result << endl;
	}
	

	
}



void countLetters(Vector<int> &makeChart, ifstream &in )
{
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	while(true){
		string line;
		getline(in, line);
		line = ConvertToLowerCase(line);
		if(in.fail()) break;
		for(int i = 0; i < line.length(); i++){
			if(alphabet.find(line[i]) != string::npos){
				makeChart[alphabet.find(line[i])]++;
			}	
		}
			
		
	}
	
}


int main()
{
	ifstream in;
	cout << "Enter name of file: ";
	string letters = GetLine();
	in.open(letters.c_str());
	
	if(in.fail())
		Error("file didn't open");
	
	
	Vector<int> letterCounts;
	
	for(int i = 0; i < 26; i++){
		letterCounts.add(0);
		
	}
	
	countLetters(letterCounts, in);
	

	printVector(letterCounts);
	return 0;
}
