// Problem: https://codeforces.com/problemset/problem/682/B

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
    sort(all(a));
    int curr = 1;
    for(int i=0; i<n; i++){
        if(a[i] >= curr) curr++;
    }
    cout << curr << "\n";
    return 0;
}
