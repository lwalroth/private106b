/*
 *  MainProg.cpp
 *  warm_up_a
 *
 *  Created by athony on 1/31/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include "genlib.h"



void PrintInBinary(int num){
	if(num > 1)
		PrintInBinary(num / 2);
	cout << (num % 2);
}

int main(){
	PrintInBinary(10);
	return 0;
}


