/*
 *  MainProg.cpp
 *  warm_up_b
 *
 *  Created by athony on 1/31/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include "genlib.h"
#include "vector.h"


bool RecSum(Vector<int> &nums, int index, int sumSoFar, int target){
	if(sumSoFar == target) return true; // success basecase
	if(index == nums.size()) return false; // failure basecase
	
	return RecSum(nums, index + 1, sumSoFar, target) ||
	       RecSum(nums, index + 1, sumSoFar + nums[index], target);
}


/*bool AltRecSum(Vector<int> & nums, int index, int sumSoFar, int target)
{
    if (sumSoFar == target) return true; 	// success base case
	// can include same explicit failure case as above, or let fall
	// through (loop will not execute)
	
    for (int i = index; i < nums.size(); i++) {
        if (RecSum(nums, i+1, sumSoFar+nums[i], target))
			return true;
    }
    return false;
}
*/
	
bool CanMakeSum(Vector<int> &nums, int targetSum){
	return RecSum(nums, 0, 0, targetSum);
}

void myRec(Vector<int> soFar, Vector<int> rest, Vector<Vector<int> > &accum)
{ 
	if( rest.isEmpty() ) {
		accum.add(soFar); 
	} else {
		Vector<int> copy = soFar;
		soFar.add(rest[0]);
		rest.removeAt(0);
		myRec(soFar, rest, accum); 
		myRec(copy, rest, accum); 
	}
}

Vector<Vector<int> > recSubsets(Vector<int> nums){
	Vector<Vector<int> > acc;
	Vector<int> start; 
	myRec(start, nums, acc);
	return acc; 
}

	
void printVecs(Vector<Vector<int> > vs){ 
	for(int i = 0; i < vs.size(); i++){ 
		Vector<int> is = vs[i]; 
		for(int j = 0; j < is.size(); j++){ 
			cout << is[j] << " , "; 
		}
		cout << "\n---" << endl; 
	}
}

int main(){
	
	Vector<int> nums;
	
	nums.add(2);
	nums.add(4);
	nums.add(7);
	nums.add(1);
	
	Vector<Vector<int> > subsets = recSubsets(nums);
	printVecs(subsets);
	return 0;
}


