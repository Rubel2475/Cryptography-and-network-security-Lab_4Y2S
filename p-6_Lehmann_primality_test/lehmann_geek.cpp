#include<bits/stdc++.h>
using namespace std;


int lehman(int n, int iter){
    int a = 2 + rand()%(n-1);
    int e = (n-1)/2;

    while (iter>0)
    {
        int x = ((int)pow(a,e)) % n;

        if((x%n)==1 | (x%n)==-1 | (x%n)==(n-1)){
            int a = 2 + rand()%(n-1);
            iter -= 1;
        }
        else{
            return -1;
        }

        return 1;
    }
}

int main(){

    int n = 9767;

    if(n==2){
        cout << "prime";
    }

    else if(n%2 == 0){
        cout << "Not prime";
    }

    else{
        int flag = lehman(n, 100);

        if(flag == 1){
            cout << n << " may be prime";
        }
        else{
            cout << "comoposite";
        }
    }

    return 0;
}