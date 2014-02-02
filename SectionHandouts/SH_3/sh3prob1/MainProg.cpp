/*
 *  MainProg.cpp
 *  sh3prob1
 *
 *  Created by athony on 1/31/14.
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


struct entryT{
	string firstName;
	string lastName;
	string phoneNumber;
} student1, student2, student3, student4;

int cmpEntry(entryT a, entryT b){
	if(a.lastName < b.lastName) return -1;
	else if (a.lastName > b.lastName) return 1;
	else if (a.firstName < b.firstName) return -1;
	else if (a.firstName > b.firstName) return 1;
	return 0;
	
}



void printMyStruct(entryT student)
{
	cout << student.firstName << " " << student.lastName << " " << student.phoneNumber << endl;
}

int main(){
	
	student1.firstName = "Laurie";
	student1.lastName = "Walroth";
	student1.phoneNumber = "5559879878";
	
	student2.firstName = "Anthony";
	student2.lastName = "Zavadil";
	student2.phoneNumber = "9875675654";
	
	student3.firstName = "Jenn";
	student3.lastName = "Smith";
	student3.phoneNumber = "8763451234";
	
	student4.firstName = "Scott";
	student4.lastName = "Jones";
	student4.phoneNumber = "9876786475";
	
	
			
	Set<entryT> set(cmpEntry);
	set.add(student1);
	set.add(student2);
	set.add(student3);
	set.add(student4);
	set.add(student4);
	
	Set<entryT>::Iterator itr = set.iterator();
	while (itr.hasNext())
		printMyStruct(itr.next());
	
		
	
	return 0;
}


