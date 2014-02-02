/*
 *  mainProg.cpp
 *  sh2_pb3
 *
 *  Created by athony on 1/29/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

// Problem 4: Map Warm-up

#include <iostream> 
#include "genlib.h"
#include "simpio.h"
#include "strutils.h" 
#include "vector.h"
#include "queue.h"
#include "stack.h"
#include <fstream> 
#include "map.h"

string MostFrequentCharacter(ifstream &in, int &numOccurences){
	
	Map<int> characters;
	
	while(true){
		string letter;
		letter = in.get();
		
		if(in.fail()) break;
		
		if(!characters.containsKey(letter)) {
			characters.add(letter,0); 
		}
		characters[letter] += 1; 
				
	}
	int numOcc = 0;
	string mostFrequent = "";
	Map<int>::Iterator itr = characters.iterator();
	while(itr.hasNext()){
		string key = itr.next();
		if(characters[key] > numOcc){
			numOcc = characters[key];
			mostFrequent = key;
		}
	}
	return mostFrequent;
	
	
}

int main()
{
	
	ifstream in;
	cout << "Enter name of file: " << endl;
	string s = GetLine();
	if(in.fail())
		Error("file didn't open");
	
	
	
	
	return 0;
}





