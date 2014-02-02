/*
 *  MainProg.cpp
 *  sh3prob2
 *
 *  Created by athony on 2/1/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream> 
#include "genlib.h"
#include "simpio.h"
#include "strutils.h" 
#include "vector.h"
#include "queue.h"
#include "stack.h"
#include <fstream> 
#include "map.h"
#include "grid.h"
#include "set.h"
#include "random.h"

struct pointT {
	int x, y;
};

struct cityT {
	string name;
	pointT coordinates;
};

string makeKey(cityT city){
	
	string key = IntegerToString(city.coordinates.x) + "-" + IntegerToString(city.coordinates.y);
	return key;


}
void printMyStruct(cityT cities)
{
	cout << cities.name << " " << cities.coordinates.x << " " << cities.coordinates.y << endl;
}
	
int main(){
	
	cityT neastCoast;
	neastCoast.name = "New York";
	neastCoast.coordinates.x = 2;
	neastCoast.coordinates.y = 4;

	cityT swestCoast;
	swestCoast.name = "Los Angeles";
	swestCoast.coordinates.x = 5;
	swestCoast.coordinates.y = 9;
	
	cityT nwestCoast;
	nwestCoast.name = "Seattle";
	nwestCoast.coordinates.x = 4;
	nwestCoast.coordinates.y = 6;
	
	cityT seastCoast;
	seastCoast.name = "North Carolina";
	seastCoast.coordinates.x = 3;
	seastCoast.coordinates.y = 1;
	
	Map<cityT> cities;
	cities.add(makeKey(neastCoast), neastCoast);
	cities.add(makeKey(seastCoast), seastCoast);
	cities.add(makeKey(nwestCoast), nwestCoast);
	cities.add(makeKey(swestCoast), swestCoast);
	
	Map<cityT>::Iterator itr = cities.iterator();
	while (itr.hasNext()){
		string key = itr.next();
		printMyStruct(cities[key]);
    }
	
	return 0;
}




