#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 1;

long long exgcd(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }
    else{
        long long d = exgcd(b, a % b, x, y);
        long long t = x;
        x = y;
        y = t - a / b * y;
        return d;
    }
}

long long CRT(long long a[], long long m[], int n){
    long long N = 1, ans = 0, M[MAX];
    for(int i = 0 ; i < n ; ++i){
        N *= m[i];
    }
    for(int i = 0 ; i < n ; ++i){
        M[i] = N / m[i];
    }
    for(int i = 0 ; i < n ; ++i){
        long long x, y;
        exgcd(M[i], m[i], x, y);
        ans = (ans + a[i] * M[i] * x) % N;
    }
    return (ans + N) % N;
}

int main(){
    
    return 0;
}
