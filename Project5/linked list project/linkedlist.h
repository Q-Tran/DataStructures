class nodes{

private:
	nodes*[] ptrs;
	int nodeschecked;
	int nnodes;
public:
	bool isexhausted();
	node gotonext();
	node();
	node(int numnodes, node*[] pt);
	node(const node& arg);
	node& operator=(const node& arg);
	~node();
}