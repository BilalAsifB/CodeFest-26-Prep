// Problem: https://codeforces.com/problemset/problem/816/B

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
const ll MAXN = 200001;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    vi diff(MAXN + 1, 0);
    while(n--){
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r+1]--;
    }
    int count = 0;
    vi pref(MAXN, 0);
    for(int i=1; i<MAXN; i++){
        count += diff[i];
        pref[i] = pref[i-1] + (count >= k ? 1 : 0);
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l-1] << "\n";
    }
    return 0;
}

/*
The diff vector marks the starting of each recipe with +1
and ending+1 with -1 (ending+1 because the ranges are inclusive).
Then a running count is performed and if the value at an index is > k,
then +1 is added to running count for that index. Now all we have to
do is return the end - start-1 for each query(start-1 because the range
is inclusive).
*/