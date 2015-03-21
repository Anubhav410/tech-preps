#include<iostream>
using namespace std;

#define MAXNUM 1000


typedef struct edgenode{
	int y ; /*the adjacency info*/
	int weight; /*the weight of the node*/
	struct edgenode* link;
}edgenode;


typedef struct graph{
	bool directed;
	int numVertices;
	int numEdges;
	edgenode *x[MAXNUM];/*adjacency info per node*/
	int degree[MAXNUM];

}graph;


void initializeGraph(graph** m){
	*m = (graph*)malloc(sizeof(graph));
	(*m)->numEdges = 0;
	(*m)->numVertices = 0;
	int i;
	for(i = 0 ; i < MAXNUM ; i++){
		(*m)->x[i]  = NULL;
		(*m)->degree[i] = 0;
	}
}

void insertEdge(graph* m , int a , int b , bool directed){
	edgenode* temp = (edgenode*)malloc(sizeof(edgenode));

	temp->y = b;
	temp->weight = 0;
	temp->link = m->x[a];

	m->degree[a] += 1;
	m->x[a] = temp;
	if(directed == false){
		insertEdge(m , b , a , true);
	}else{
		m->numEdges++;		

	}

}

void make_test_directed_graph(graph* m ){
	m->numVertices = 7;
	m->directed = true;
	insertEdge(m , 1 , 2 , true);
	insertEdge(m , 1 , 3 , true);
	insertEdge(m , 2 , 4 , true);
	insertEdge(m , 2 , 3 , true);
	insertEdge(m , 3 , 5 , true);
	insertEdge(m , 3 , 6 , true);
	insertEdge(m , 5 , 4 , true);
	insertEdge(m , 6 , 5 , true);
	insertEdge(m , 7 , 6 , true);
	insertEdge(m , 7 , 1 , true);

}
void make_test_graph(graph* m ){
		m->numVertices = 6;

	m->directed = false;
		
	insertEdge(m , 1 , 2 , false);
	insertEdge(m , 1 , 5 , false);
//	insertEdge(m , 2 , 5 , false);
	insertEdge(m , 5 , 4 , false);
	insertEdge(m , 3 , 2 , false);
	insertEdge(m , 4 , 3 , false);
//	insertEdge(m , 4 , 2 , false);
	insertEdge(m , 1 , 6 , false);

}

void printGraph(graph* m){
	/*First we access each of the node and then print the nodes that are connected to */
	int n = m->numVertices;
	int i ;
	for(i = 1 ; i <= n ; i++){
		edgenode* temp = m->x[i];
		cout << i << "->";
		while(temp){
			cout << temp->y <<"->";
			temp = temp->link;
		}
		cout <<endl;
	}
}

/*
int main(){
	cout <<"works\n";
	graph* m;
	initializeGraph(&m);
	insertEdge(m , 1 , 2 , false);
	insertEdge(m , 1 , 5 , false);
	insertEdge(m , 2 , 5 , false);
	insertEdge(m , 5 , 4 , false);
	insertEdge(m , 3 , 2 , false);
	insertEdge(m , 4 , 3 , false);
	insertEdge(m , 4 , 2 , false);

	printGraph(m);
	return 0;
}
*/