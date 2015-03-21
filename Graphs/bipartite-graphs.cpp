#include "graph-list-implementation.cpp"
#include<queue>


enum color { NOCOLOR , WHITE , BLACK };


bool processed[MAXNUM+1];
bool parents[MAXNUM + 1 ];
bool discovered[ MAXNUM +  1];

color edge_color[MAXNUM + 1];



color complement_color(color c ){
	return c == WHITE ? BLACK : WHITE;
}

void process_edge(int x, int y){
	if(edge_color[x] == edge_color[y]){

		cout <<" WARNING :  this is not a bipartite graph\n";
	}

	edge_color[y] = complement_color(edge_color[x]);
}

void process_node(int i){
//	cout << "Processed : " << i << "\n";
}

void bfs(graph* m , int start){

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





bool is_bipartite(graph* g) {
	bool ans = true;


	int n_ver = g->numVertices;
	int i ;


for( i = 1 ; i <= n_ver ; i++){
	edge_color[i] = NOCOLOR;
}
	for( i = 1 ; i <= n_ver ; i++){
		if(discovered[i] == false){
			edge_color[i] = WHITE;
			bfs(g , i);
		}
	}

	return ans ; 
}

void make_bipartite_graph(graph* m){
	insertEdge(m , 1 , 2 , false);
	insertEdge(m , 1 , 7 , false);
	insertEdge(m , 7 , 8 , false);
	insertEdge(m , 8 , 2 , false);
	insertEdge(m , 1 , 3 , false);
	insertEdge(m , 4 , 2 , false);
	insertEdge(m , 6 , 8 , false);
	insertEdge(m , 7 , 5 , false);
	insertEdge(m , 3, 5 , false);
	insertEdge(m , 5 , 6 , false);
	insertEdge(m , 4 , 6 , false);
	insertEdge(m , 3 , 4 , false);
	

}

int main(){
	graph* g ; 
	initializeGraph(&g);
	make_bipartite_graph(g);

	cout << "Graph is Bipartite : " <<  is_bipartite(g) << "\n";

	return 0;
}