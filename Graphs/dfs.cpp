#include "graph-list-implementation.cpp"

bool discovered[MAXNUM];
int start[MAXNUM];
int t_end[MAXNUM];
int t_time = 0;
void prepare_dfs(graph* g){	
	int i;	
	/*initialize the graph fro DFS*/
	for( i = 1 ; i <=  g->numVertices ; i++){
		discovered[i] = false;
		start[i] = 0;
		t_end[i] = 0;
	}
}

void process_early(int n){
	cout << "Entering : " << n <<"\n";

}

void process_late(int n){
	cout << "Exiting : " << n <<"\n";
	
}

void process_edge(int a , int b){
	cout << "processing  : "  << a << " --> " << b << "\n";
}
void dfs(graph* g , int node){

	t_time  = t_time + 1;
	start[node] = t_time;
	discovered[node] = true;
	process_early(node);

	edgenode* p = g->x[node];
	while(p != NULL){
		if(discovered[p->y] == false){
			discovered[p->y] = true;
			dfs(g , p->y);
			process_edge(node , p->y);
		}
		p = p->link;
	}
	process_late(node);
	t_end[node] = t_time;
	t_time  = t_time + 1;
}


/*int main(){
	graph* g ;
	initializeGraph(&g);
	make_test_graph(g);
	prepare_dfs(g);

	dfs(g , 1);

	printGraph(g);
	return 0;
}
*/