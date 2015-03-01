#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int getHash(char* , int , int);
void rabin_carp(char* str , char* pattern){

	int m = strlen(str);
	int n = strlen(pattern);

	int hash_pattern = getHash(pattern , 0 , n-1);
	int hash_str = getHash(str , 0 , n-1);
//	printf("%d..%d\n",hash_pattern,hash_str );
	int ar_size = m - n + 1 ;
	int table[ar_size];
	table[0] = hash_str;
	for(int i = 1 ; i < ar_size ; i++){
		table[i] = getHash(str , i , n+i-1); 
	}
    
    for(int i = 0 ; i < ar_size ; i++){
        printf("Hash Codes : %d\n" , table[i]);
    }
    printf("Target Hash Code : %d\n" , hash_pattern);
	for(int i = 0 ; i < ar_size ; i++){
		if(hash_pattern == table[i]){
			printf("index : %d\n" , i);
		}
	}



}

int getHash(char* str , int x , int y){
	int i;
	int hash = 0;
	int alpha = 26;
	int m = y-x+1;
	for(i =  0 ; i < m ; i++){		
		hash += pow(alpha , m-i+1) * str[i+x];

	}

	return hash;
}

int main(){
	char* str = "THIS IS A TEST TEXT";
	char* pattern = "TEST";
	rabin_carp(str , pattern);
	return 0;
}