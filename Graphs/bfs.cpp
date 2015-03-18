#include "graph-list-implementation.cpp"
#include<queue>

void process_edge(int x, int y){
	cout << "Edge : " << x << " --> " << y <<"\n";  
}

void process_node(int i){
	cout << "Processed : " << i << "\n";
}

void bfs(graph* m , int start){
	bool processed[MAXNUM+1];
	bool parents[MAXNUM + 1 ];
	bool discovered[ MAXNUM +  1];

	queue<int> Q;
	/*
	initialize the bfs arrays for bfs processing
	*/
	int  i = 0 ;
	for(i = 1 ; i <= m->numVertices ; i++){
		processed[i] = false;
		discovered[i] = false;
		parents[i] = -1;
	}

	/* lets start the main work */

	Q.push(start);
	parents[start] = -1;
	discovered[start] = true;
	while(!Q.empty()){
		int curr = Q.front();
		Q.pop();
		process_node(curr);
		processed[curr] = true;

		edgenode* p = m->x[curr];
		while(p != NULL){
			if(processed[p->y] == false ){
				process_edge(curr , p->y);
			}

			if(discovered[p->y] ==  false){
				Q.push(p->y);
				discovered[p->y] = true;

			}
			p = p->link;
		}
	}
}

int main(){
	cout <<"works\n";
	graph* m;
	initializeGraph(&m);
	make_test_graph(m);
	bfs(m , 1);

	return 0;


}