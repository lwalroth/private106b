// Section Handout #1
// Problem 2: Files and Structs
 

#include "genlib.h"
#include "strutils.h"
#include <iostream>
#include "Vector.h"
#include <fstream> 
#include "simpio.h"

struct statsT {
	int min;
	int max;
	double average;
};


statsT calculateStats(ifstream &in) {
	statsT stats;
	stats.min = 101;
	stats.max = -1;
	
	int total = 0;
	int count = 0;
	
// Open a new filestream and make sure it worked
	
	while(true){
		int num;
		in >> num;
		
		
		// Check that we read successfully 
		if (in.fail()) break;
		// Update or data if we need to 
		if (num < stats.min) 
		stats.min = num; 
		if (num > stats.max) 
		stats.max = num; 
		total += num; count++;
	}
	// Don't forget to watch for integer division! 
	stats.average = double(total)/count; 
	// And make sure to close your files in.close();
	return stats;
	in.close();

	
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
	statsT results = calculateStats(in);
	cout << " min: " << results.min << " max: " << results.max << " avg: " << results.average << endl; 
	return 0;
}



