#include "nodes.h"
class stack{ //only a stack of nodes objects
private:
	nodes* arrptr;
	int cstack;
	int arrsize;
public:
	stack();
	stack(const stack& arg);
	stack& operator=(const stack& arg);
	~stack();
	push(linkedlist arg);
	pop();
	peek();
}