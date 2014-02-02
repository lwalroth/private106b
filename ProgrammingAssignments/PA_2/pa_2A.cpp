
// Assignment #2: ADT Client Extravaganza

#include "genlib.h"
#include <fstream> 
#include <iostream> 
#include "simpio.h" 
#include "map.h"
#include "vector.h" 
#include "random.h"

string initialSeed(Map<Vector<string> > &m);

string randomString(Map<Vector<string> > &m){
	
	string currentSeed = initialSeed(m);
	string outputString = currentSeed;
	for(int i = 0; i < 2000; i++){
		
		Vector<string> posNextChar = m[currentSeed];
		if(posNextChar.isEmpty()) break;
		string nextChar = posNextChar.getAt(RandomInteger(0, posNextChar.size()-1));
		outputString += nextChar;
		currentSeed = currentSeed.erase(0,1) + nextChar;
		
	}
	return outputString;
}
											


string initialSeed(Map<Vector<string> > &m){
	Map<Vector<string> >::Iterator itr = m.iterator();
	string seed = "";
	int maxSize = 0;
	while(itr.hasNext()){
		string key = itr.next();
		if(m[key].size() > maxSize){
			maxSize = m[key].size();
			seed = key;
		}
	}
	return seed;
	
	
}

void PopulateMap(ifstream &in, Map<Vector<string> > &m, int ord){
	
	string workingString = "";
	while(true){
		string letter;
		letter = in.get();
		letter = ConvertToLowerCase(letter);
		if(in.fail()) break;
		workingString += letter;
		if(workingString.length() == ord + 1){
			string keyComp = workingString.substr(0, ord);
			string nextChar = workingString.substr(ord);
			
			m[keyComp].add(nextChar);
			workingString.erase(0,1);
		}
	}


}

void printVec(Vector<string> &vec)
{
	for(int i = 0; i < vec.size(); i++){
		cout << "    vec index: " << i << " vec elem: " << vec[i] << endl;
		
	}
}

void printMap(Map<Vector<string> > &myMap)
{
	Map<Vector<string> >::Iterator itr = myMap.iterator(); 
	
	while(itr.hasNext()) { 
		string key = itr.next(); 
		cout << key << endl;
		Vector<string> temp = myMap[key]; 
		printVec(temp);
		
	}
}


int main(){
	Map<Vector<string> > m;
	ifstream in;
	cout << "Enter name of file: ";
	string s = GetLine();
	in.open(s.c_str());
	
	if(in.fail())
		Error("file didn't open");
	
	
	
	cout << "What order of Markov model do you want to use? (number must be between 1-10): " << endl;
	int ord = GetInteger();
	
			  
	PopulateMap(in, m, ord); 
    //printMap(m);
	
	string printRandom = randomString(m);
	cout << printRandom << endl;
	
	return 0;
}








