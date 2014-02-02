/*
 *  mainProg.cpp
 *  sh2_pb2
 *
 *  Created by athony on 1/29/14.
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


void ReverseQueue(Queue<int> &q){
	
	Stack<int> sta;
	while(! q.isEmpty()){
		sta.push(q.dequeue());
	}
	
	while(! sta.isEmpty()){
	
	
		q.enqueue(sta.pop());
	
	}
	
}
		

int main(){
	
	Queue<int> q;
	
	q.enqueue(10);
	q.enqueue(15);
	q.enqueue(20);
	q.enqueue(25);
	
	Queue<int> copy = q;
	
	while(! copy.isEmpty()){
		cout << copy.dequeue() << endl;
	}
	
	cout << "---" << endl;
	ReverseQueue(q);
	while(! q.isEmpty()){
		cout << q.dequeue() << endl;
	}
		
								
	
	
	
	return 0;
}


