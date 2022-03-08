#include <bits/stdc++.h>
using namespace std;

long long BigMod(long long a, long long e, long long n){

    long long res =1;
    for(long long i=1; i<=e; i++){
        res *= a;
        res %= n; 
    }    
    return res;
}

bool isPrime(long long n, int iter){

    if(n==1) return false;
    if(n==2 | n==3) return true;
    if(n%2==0) return false;

    for(int i=0; i<iter; i++){
        long long a = 2 + rand()%(n-3);
        long long exponent = (n-1)/2;
        
        int x = BigMod(a, exponent, n);        // lehman rule, x = (a^((n-1)/2)) mod n
        if(x!=-1 && x!=1 && x!=(n-1)){
            return false;
        }
    }
    
    return true;
}

int main(){

    long long n=9767165778;

    if(isPrime(n, 100)){
        cout << n<< " is prime";
    }
    else{
        cout << n << " is composite";
    }

    return 0;
}