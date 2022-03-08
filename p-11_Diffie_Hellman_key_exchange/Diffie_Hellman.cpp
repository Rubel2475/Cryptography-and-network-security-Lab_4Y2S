#include<bits/stdc++.h>
#include<cstdlib>      //for srand()
using namespace std;

long long BigMod(long long a, long long power, long long q){

    long long res = 1;
    for(long long i=1; i<=power; i++){
        res *= a;
        res %= q;
    }
    return res%q;
}

int main(){

    srand(time(NULL));

    long long q = 13; //prime number
    long long a = 2; //primitive root of q

    long long xA = 1 + rand() % 100;  //user A's selected random integer(private) as if xA<q 
    long long xB = 1 + rand() % 100;  //user B's selected random integer(private) as if xB<q 

    long long yA = BigMod(a, xA, q);    //compute A's public key yA= a^xA mod q
    long long yB = BigMod(a, xB, q);    //compute B's public key yB= a^xB mod q

    long long kA = BigMod(yB, xA, q);    //compute key k = yB^xA mod q
    long long kB = BigMod(yA, xB, q);    //compute key k = yA^xB mod q

    cout << "A's generated key(common key): " << kA << endl;
    cout << "B's generated key(common key): " << kB << endl;

    return 0;
}