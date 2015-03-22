#include "graph-list-implementation.cpp"
//this is to use the max value of int as a distance upper bound . The constant is called INT_MAX
#include <limits.h>
#include <queue>

void prims_MST(graph* g , int start){
	int num_v = g->numVertices;
	queue<int> order_found ; //a stack to tell us the order in which we added the various nodes/vertex of the grapgh in the MST
	bool in_tree[num_v + 1];
	int distance[num_v + 1];
	int parent[ num_v +  1];
	edgenode* p;	//this is a temp variable for going through the various neighbours of a vertex
	int weight ; //the one that holds the weight of the current node under consideration . Basically a temp var.
	int i ; 	// a looping variable

	for(i = 1;  i <= num_v ;i++){
		in_tree[i] = false;
		distance[i] = INT_MAX;
	}

	int v ;
	v = start;
	while(in_tree[v] == false){
		order_found.push(v);

		in_tree[v] = true;
		p = g->x[v];
		while(p != NULL){
			int y = p->y;
			weight = p->weight;

			if(distance[y] > weight && in_tree[y] == false){
				distance[y] = weight;
				parent[y] = v;
			}
			p = p->link;
		}

		int dist = INT_MAX;
		v = 1;
		for( i = 1; i <= num_v ;i++){
			if(in_tree[i] == false && distance[i] < dist){
				v = i;
				dist = distance[i];
			}
		}
	//	order_found.push(v);
	}
	
	cout << "Order in which the nodes were added : \n";

	while(order_found.empty() != true){
		cout << order_found.front() << "\t";
		order_found.pop();
	}
	cout <<"\n";
}


int main(){
	graph* g;
	initializeGraph(&g);
	make_test_weighted_graph(g);
	//printGraph(g);
	prims_MST(g , 2);

}