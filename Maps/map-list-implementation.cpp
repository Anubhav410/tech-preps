#include<iostream>
using namespace std;

#define MAXNUM 1000


typedef struct edgenode{
	int y ; /*the adjacency info*/
	int weight; /*the weight of the node*/
	struct edgenode* link;
}edgenode;


typedef struct map{
	int numVertices;
	int numEdges;
	edgenode *x[MAXNUM];/*adjacency info per node*/
	int degree[MAXNUM];

}map;


void initializeMap(map* m){
	m = (map*)malloc(sizeof(map));
	m->numEdges = 0;
	m->numVertices = 0;
	int i;
	for(i = 0 ; i < MAXNUM ; i++){
		m->x[i]  = NULL;
		m->degree[i] = 0;
	}
}

void insertEdge(map* m , int a , int b , bool directed){
	edgenode* temp = (edgenode*)malloc(sizeof(edgenode));

	temp->y = b;
	temp->weight = 0;
	temp->link = m->x[a];

	m->degree[a]++;
	m->x[a] = temp;
	if(directed){
		insertEdge(m , b , a , false);
	}else{
		m->numEdges++;		
	}

}

void printGraph(){
	
}

int main(){
	cout <<"works\n";
	return 0;
}