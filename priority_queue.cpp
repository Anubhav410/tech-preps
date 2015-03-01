#include<iostream>

using namespace std;

typedef struct priority_queue{
    
    int n; //current number of elements in the queue
    int q[100+1]; //for now out queue cannot have more than 100 elements. I am implementing this just so that I know I can :P
    
}priority_queue;

void init_queue(priority_queue* q){
    q->n  = 0;
}

int pq_parent(int  n){
    if(n == 1){
        return -1;
    }
    else
        return (int)n/2;
}


int pq_young_child(int n){
    return (2*n);
}

void swap(priority_queue* q1 , int x , int y){
    int t = q1->q[x];
    q1->q[x] = q1->q[y];
    q1->q[y] = t;
}

void bubble_up(priority_queue* q1 , int n){
    int parent = pq_parent(n);
    if(parent != -1 && q1->q[parent] > q1->q[n]){
        swap(q1,parent,n);
        bubble_up(q1,parent);
    }
}



/*
 This insert function will insert inside the queue to finally generate a min-heap DS
 */
void insert(priority_queue* q1 , int x ){
    q1->n = q1->n + 1;
    q1->q[q1->n] = x;

    bubble_up( q1 , q1->n);
    
}

void print(priority_queue* q1){
    int n = q1->n;
    int i = 1;
    while(i <=n){
        cout << q1->q[i++] <<" " ;
    }
    cout << endl;
}

void bubble_down(priority_queue* q1 , int n){
//    cout <<"Bubble down\n";
    int i;
    int young_child = pq_young_child(n);
    if(young_child <= n){
    int min_child = -1;

    for(i = 0; i < 2 ; i++){
        if(q1->q[young_child + i] < q1->q[n]){
            min_child = young_child + i;
            
        }
    }
    
    swap(q1 , min_child , n);
    bubble_down(q1 , min_child);
    }
}

int get_minimum(priority_queue* q1){
    int n = q1->n;
    int min_item = q1->q[1];
    q1->q[1] = q1->q[n];
    q1->n = q1->n - 1;

    bubble_down(q1 , 1);

    return min_item;
}

int main(){
    priority_queue* q1;
    init_queue(q1) ;
    insert(q1 , 3);
    insert(q1 , 2);
    insert(q1 , 1);
    

    cout <<"Min : " << get_minimum(q1) <<"\n";
    cout <<"Min : " << get_minimum(q1) <<"\n";
    cout <<"Min : " << get_minimum(q1)<<"\n";

//    print(q1);
    return 0;
}