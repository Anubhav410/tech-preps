#include<iostream>
#define MAXN 200
using namespace std;

void print_solution(int *a , int n) { 

	int i ;
	for( i = 0 ; i <= n ; i++ ) {
		if(a[i] == 1) {
			cout << i <<"\t" ;			
		}

	}
	cout << endl;
}

void list_subset(int a[] , int k , int n) {

	if( k == n) {
		//this means we have found a solution;
		print_solution( a , n);
	}
	else {
		k = k + 1 ;
		a[k] = 1;
		list_subset(a , k , n);
		a[k] = 0;
		list_subset(a, k , n);
	}
}


int main() {
	int a[MAXN];
	int n  = 3 ; //the number of total elements 
	list_subset(a , 0 , n);

	return 0;
}