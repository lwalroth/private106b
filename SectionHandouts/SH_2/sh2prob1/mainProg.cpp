// Section Handout #2
// Problem 1 - Vectors
 
#include <iostream> 


#include "genlib.h"
#include "simpio.h"
#include "strutils.h" 
#include "vector.h"


struct eMailMsg 
{
	Vector<string> to;
	string from;
	string message;
	string subject;
	int date;
	int time;
}; 





void RemoveSpam(Vector<eMailMsg> &mail){
	

	for(int i = mail.size()-1; i >= 0; i--){
		
		if(mail[i].subject.substr(0,4) == "spam"){
			mail.removeAt(i);
		}
	}
	
	
}


void printMsgTo(eMailMsg msg){ 
	for(int i = 0; i < msg.to.size(); i++){
		cout << msg.to[i] << endl; 
	}
}


void printMsg(eMailMsg msg){
	
	cout << msg.from << endl;
	cout << msg.message << endl; 
	cout << msg.subject << endl; 
	cout << "---" << endl;
}

int main()

{

	eMailMsg msg1;
	msg1.to.add("a@gmail.com");
	msg1.to.add("l@gmail.com");
	msg1.to.add("lw@gmail.com");
	msg1.from = "laurieisthebest@gmail.com";
	msg1.message = "I will understand this crap one day";
	msg1.subject = "sometimes i hate c++";
	msg1.date = 020314;
	msg1.time = 800;
	
	eMailMsg msg2;
	
	msg2.from = "a@gmail.com";
	msg2.message = "blah blah";
	msg2.subject = "spam";
	msg2.date = 30491;
	msg2.time = 600;
	
	
	
	Vector<eMailMsg> messages;
		
	
	
	messages.add(msg1);
	messages.add(msg2);
	
	RemoveSpam(messages);
	
	for(int i = 0; i < messages.size(); i++){
		printMsg(messages[i]);
	}
	printMsgTo(msg1); 
	
	
		
	return 0; 
}