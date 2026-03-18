// Problem: https://codeforces.com/problemset/problem/4/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define F first 
#define S second
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll w;
    cin >> w;
    cout << ((w % 2 == 0 && w > 2) ? "YES" : "NO");
    return 0;
}

// Any even number greater than 2 can be expressed as the sum of two even numbers (2 + (w-2)).