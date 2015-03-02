//
//  mergeSort.cpp
//  
//
//  Created by Anubhav Shrivastava on 02/03/15.
//
//

#include<iostream>
using namespace std;

void merge(int* a , int low , int mid,  int high){
    
    int n1 = mid - low + 1;
    int n2 = high - (mid+1) +1  ;
    int n = high - low + 1;
    int k  = 0, l = 0;
    
    int x[n];
    int i = 0;
    while( k < n1 && l < n2){
        if(a[k+low] < a[l+mid+1]){
            x[i] = a[k+low];
            k++;
        }
        else{
            x[i] = a[l+mid+1];
            l++;
        }
        i++;
        
    }
    
    while(k < n1){
        x[i++] = a[k+low];
        k++;
    }

    while(l < n2){
        x[i++] = a[l+mid];
        l++;
    }
    
    
    
    i = 0;
 //   cout <<"final .. \n";
    while( i < n ){
        a[i + low] = x[i];
//        cout << x[i] <<"\t";
        i++;
    }
    cout <<"\n";

}


void mergeSort(int* a , int low, int high){
    int i ;
    int mid;
    
    if(low < high){
    /*    int x = low;
        while(x <= high){
            cout << a[x++] << "\t";
        }
        cout <<"\n";
      */
        mid = (low + high)/2;
        mergeSort(a ,low , mid );
        mergeSort(a , mid+1 , high);
        merge(a , low, mid, high);
    }
}

int main(){
    int a[] = {6,5,4,3,2,1};
    mergeSort(a, 0 , 5);
    
    int  i = 0 ;
    while(i  < 6){
        cout << a[i++] <<"\t";
    }
    cout <<"\n";
    
    return 0;
}