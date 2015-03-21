#include "graph-list-implementation.cpp"
#include <stack>

bool processed[MAXNUM];
bool discovered[MAXNUM];
int entry_t[MAXNUM];
int exit_t[MAXNUM];
int t = 0;
stack<int> top_sort_stack;

enum edge_type {BACK , FORWARD , CROSS, TREE} ;

edge_type  edge_classification(int x,int y){
	if(discovered[y] == false){
		//no problemoooo ;
		//its a normal edge brother

		return TREE;
	}
	else if(discovered[y] == true && processed[y] == false){
		cout <<" This is not allowed in a DAG. So no more Topological Sorting to be done on this DAG-less graph !";
		cout <<"\n This is a back edge .";

		return BACK;
	}
	else if(processed[y] == true){
		//now you have to check of the exit times of these people . 
		//if exit(x) > exit(y) , then x was rpocessed before y, that means its a forward edge.
		//if exit(y) > exit(x) , it means that x is processed after y , and hence this is a cross edge.
		return CROSS  ;
		//this can be either CROSS / FORWARD, but thats OK in top_sort, so I wont be checking for them, at the moment.
	}

	return FORWARD; //this is a wrong statement
}


void init_dfs(graph* g){
	int l = g->numVertices;
	int i ;
	for(i = 1 ; i <= l ;i ++){
		processed[i] = false;
		discovered[i] = false;
		entry_t[i] = 0;
		exit_t[i] = 0;
	}

}

void process_node_late(int n){
	processed[n] = true;
	top_sort_stack.push(n);
}
void process_node_early(int n){

}

void process_edge(int a , int b){

}
void dfs(graph* g , int n){
	t = t + 1;
	entry_t[n] = t;
	discovered[n] = true;
	process_node_early(n);

	edgenode* temp = g->x[n];
	while(temp){
		if(discovered[temp->y] == false){
			process_edge(n , temp->y);
			dfs(g , temp->y);
		}

		if( !processed[temp->y] || g->directed ){
			process_edge(n , temp->y);
		}

		temp = temp->link;
	}
	process_node_late(n);
	t = t + 1;
	
	exit_t[n] = t;
}

void topological_sort(graph* g){
		init_dfs(g);
		int num_v = g->numVertices;

		int i ;
		for(i = 1 ; i <= num_v ; i++){
			if(discovered[i] ==  false){
				dfs(g , i);
			}
		}
}

int main(){
	graph* g;
	initializeGraph(&g);
	make_test_directed_graph(g);
//	printGraph(g);
	topological_sort(g);

	while(!top_sort_stack.empty()){
		cout << top_sort_stack.top() << "\t";
		top_sort_stack.pop(); 
	}
	cout <<"\n";

//	init_dfs(g);
//	dfs(g , 1);


/*
stack<int> x;
x.push(10);
x.push(20);
while(!x.empty()){
	cout << x.top()<< "\n";
	x.pop () ;
}
*/


/*
	int i;
	for( i = 1 ; i <= g->numVertices ; i++){
		cout << "Node : " << i << "\nEntry : "<< entry_t[i];
		cout <<"\nExit : " << exit_t[i];
		cout <<endl;
	}
*/
	return 0;
}