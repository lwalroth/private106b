/*
 *  File: p5.cpp
 *  ------------------
 *
 *  
 *
 */

#include "genlib.h"
#include "strutils.h"
#include <iostream>
#include "Vector.h"
#include <fstream> 
#include "simpio.h"


/* makePrefix generates the prefix for the histogram
 * e.g. 
 * 0-9:
 * 10-19:
 * ... 
 */ 

string makePrefix(int n) { 
	string output; 
	output = IntegerToString(n * 10) + "-" + IntegerToString(n*10+9) + ": "; 
	return output;
}

/* printVector takes a vector as input and prints
 * in specified format
 */ 
string makeX(int num){
	string result = "";
	for(int i = 0; i < num; i++){
		result += "X";
	}
	return result;
}

void printVector(Vector<int> examScores) { 
	for (int i = 0; i < 10; i++) { 
		string result = makePrefix(i) + makeX(examScores[i]);
		
		
		cout << result << endl;	
	}
}


	

/* makeHistogram reads in a file line by line and 
 * populates a Vector<int> 
 *
 * The algorithm uses integer division to truncate scores
 * (e.g. 87/10 becomes 8) which we can then use to index
 * into the vector
 */ 


void makeHistogram(Vector<int> &examScores, ifstream &in )
{
	
	while(true){
		string line;
		getline(in, line);
		if(in.fail()) break;
		examScores[StringToInteger(line)/10] += 1;
	}
	
}
	


int main(){
	
	ifstream in; 
	while (true) { 
		cout << "Enter Filename: "; 
		string s = GetLine(); 
		in.open(s.c_str()); 
		if (!in.fail()) break; 
		cout << "File open failed, try again" << endl;
		in.clear(); 
	} 

    
	Vector<int> examScores;
	for(int i = 0; i < 10; i++){
		examScores.add(0);
	}
	
	makeHistogram(examScores, in);
	printVector(examScores);
	return 0;
}  
