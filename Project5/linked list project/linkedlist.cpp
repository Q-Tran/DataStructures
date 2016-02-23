node::node(int numnode, node*[] anodes){//initialized constructor
	int nnodes = numnode;
	node*[] nodes = anodes;
}
node::~node(){//destructor

}
bool node::isexhausted(){
	if(nodescheked == nnodes){
		return true;
	}
}
node node::gotonext(){
	nodeschecked++;
	return *(ptrs[nodeschecked-1]);
}