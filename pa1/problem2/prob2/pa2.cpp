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


double singleSimulation(int voters, double spread, double error){
	
	int votersA = (0.5 + spread) * voters;
	int votersB = (voters - votersA);
	
	

	int accA = 0;
	int accB = 0;
	for(int i = 0; i < votersA; i++){
		if(RandomChance(error)){
			accB++;
		}
		else {
			accA++;
	    }
	}
	

	
	for(int i = 0; i < votersB; i++){
		if(RandomChance(error)){
			accA++;
		}
		else {
			accB++;
		}
	}
	
	return accA > accB;
    
}
		
		
int main() 
{
	int voters;
	double spread;
	double error;
	cout << "Enter number of voters: ";
	cin >> voters;
	while(voters < 0){
		cout << "Number of voters must be greater than 0.\n";
		cout << "Enter number of voters: ";
		cin >> voters;
	}
	
	cout << "Enter percentage spread between candidates: ";
	cin >> spread;
	while(spread < 0 || spread > 1.0){
		cout << "Percentage must be between 0 - 1.0.\n";
		cout << "Enter percentage spread between candidates: ";
		cin >> spread;
	}
	
	cout << "Enter voting error percentage: ";
	cin >> error;
	while(error < 0 || error > 1.0) {
		cout << "Voting error percentage must be between 0 - 1.0.\n";
		cout << "Enter voting error percentage: ";
		cin >> error;
	}
	
	int invalidAcc = 0;
	for(int i = 0; i < 500; i++){
		if(!singleSimulation(voters, spread, error)){
			invalidAcc++;
			
		}
	}
	
	
	
	
	cout << "Chance of an invalid election result after 500 trials = " << (((double) invalidAcc / 500) * 100) << "%";
	return 0;
}
