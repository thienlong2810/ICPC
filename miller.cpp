using namespace std;
using ll = long long;
using i128 = __int128_t;
/*
    Miller-Rabin: checking prime <= 2^64
    test link: https://judge.yosupo.jp/problem/primality_test
*/ 
ll binpow(ll base , ll e , ll m){
    ll res = 1;
    base %= m;
    while(e){
        if(e & 1) res = (i128)1 * res * base % m;
        base = (i128)1 * base * base % m;
        e /= 2;
    }
    return res;
}
bool checkComp(ll n , ll a , ll d , int s){
    ll x = binpow(a , d , n);
    if(x == 1 || x == n - 1) return 0;
    for(int r = 1 ; r < s ; r++){
        x = (i128)1 * x * x % n;
        if(x  == n - 1) return 0;
    }
    return 1;
}
bool isprime(ll n){
    if(n < 2) return 0;
    if(n == 2 || n == 3) return 1;
    if(n % 2 == 0) return 0;
    int s = 0;
    ll d = n - 1;
    while(d % 2 == 0){
        d /= 2;
        s++;
    }
    ll bases[] = {2 , 3 , 5 , 7 , 11 , 13 , 17 , 19 , 23 , 29 , 31 , 37};
    for(ll a : bases){
        if(n == a) return 1;
        if(checkComp(n , a , d , s)) return 0;
    }
    return 1;
}
