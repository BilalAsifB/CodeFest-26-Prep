// Problem: https://codeforces.com/problemset/problem/466/C

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first 
#define S second    
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vl a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    ll sum = accumulate(all(a), 0LL);
    if(sum%3!=0){
        cout << "0";
    } else {
        ll t = 0, ct = 0, res = 0, one = sum/3, two = 2*sum/3;
        for(int i=0; i<n-1; i++){
            t += a[i];
            if(t==two) res += ct;
            if(t==one) ct++; 
        }
        cout << res;
    }
    return 0;
}

/*
We add ct to res only when t=2sum/3 beacuse this forms the second boundry, i.e.
this tells us that the array can be divided inot three parts. t==sum/3 forms the 
first boundry.
*/