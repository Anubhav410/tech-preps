#include "graph-list-implementation.cpp"

int main(){
	cout <<"works\n";
	graph* m;
	initializeGraph(&m);
	make_test_graph(m);


	printGraph(m);
	return 0;


}