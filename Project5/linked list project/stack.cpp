#include "stack.h"
#include "nodes.h"
stack::stack(){//default constructor
	arrptr = new nodes[10];
	arrsize = 10;
}
stack::~stack(){//destructor
	delete [] arrptr;
}
void stack::push(linkedlist arg){
	cstack++;
	if(cstack > arrsize-1){ //resize array if number of elements is larger than the arraysize
		linkedlist* temp = new linkedlist[arrsize*2];
		for(int i = 0; i<arrsize-1; i++){
			temp[i] = arrptr[i];
		}
		delete[] arrptr;
		arrptr = temp;
	}
	arrptr[cstack] = arg;
	arrsize = arrsize*2;
}
nodes stack::pop(){
	linkedlist temp = arrptr[cstack];
	cstack--;
	return temp;
	//no need to spend time deleting value from array
}
nodes stack::peek(){
	return arrptr[cstack];
}