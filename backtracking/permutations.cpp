#include<iostream>
using namespace std;
#define MAXN 200

void print_permutation(int * a, int n) {
	int i ;
	for( i = 0 ; i < n ; i++) {
		cout << a[i] << "\t";
	}
	cout <<endl;
}

void get_candidates(int *a , int* c, int k  , int *num_cand , int n) {
	*num_cand = 0;

	bool in_perm[k];
	int i;
	for(i = 0 ; i < k ; i++) in_perm[i] = false;

	for(i = 0 ; i < k ; i++){
	 in_perm[a[i]] = true;
	 cout << "Excluded : "  << a[i] <<"\t";	
	}

	cout <<endl;
	for(i = 0 ; i < n ; i++) {
		if(in_perm[i] ==  false) {
			c[*num_cand] = i;
			*num_cand += 1;
		}
	}
	
}

void permutations(int a[] ,int k , int n) {
	if( k == n) {
		print_permutation(a , k);
	} else {
		int cand[n] ;
		int num_cand;
		get_candidates(a , cand , k , &num_cand,   n);
		int i;
		for(i = 0 ; i < num_cand ; i++ ) {
	//			cout << "Candidate for k = " << k << " : " << cand[i] <<"\n";
			a[k] = cand[i];
			permutations(a , k+1 , n);
		}

	}

}

int main() {

	int a[MAXN];
	int n = 3;
	permutations(a , 0 , n);

	return 0 ;
}