#include<iostream>

using namespace std;

double squareRoot(int n){

	double h = n;
	double l = 0;
    bool flag = true;
    double mid;
	while(flag){
//		cout << x << " h: " << h << " l: "<<l<<"\n";
		 mid = (h+l)/2;
        double res = mid * mid;
         double diff  = res - n;
        diff *= (diff < 0)?-1:1;
        if(diff <= numeric_limits<float>::epsilon()){
            flag = false;
        }
        else if( res > n ){
            h = mid;
        }
        else{
            l = mid;
        }
        
        
	}

	return mid;

}

int main(){
	cout << squareRoot(621) << "\n";
	return 0;
}