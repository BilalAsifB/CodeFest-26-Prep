// Problme: https://codeforces.com/problemset/problem/1207/B

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
    int n, m; cin >> n >> m;
    vector<vi> a(n, vi(m));
    vector<vi> ans;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin >> a[i][j]; 
    }
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            if(a[i][j] * a[i][j+1] *a[i+1][j] *a[i+1][j+1] > 0){
                a[i][j] = 2;
                a[i][j+1] = 2;
                a[i+1][j] = 2;
                a[i+1][j+1] = 2;
                ans.pb(vi({i, j}));
            }
        }
    }
    int k = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 1) k++;
        }
    }
    if(k > 0){
        cout << -1 << "\n";
    }
    else{
        cout << ans.size() << "\n";
        for(vi v: ans){
            cout << v[0]+1 << " " << v[1]+1 << "\n"; 
        }
    }
    return 0;
}

/*
We mark evey submatrix that contains all 1s with 2s, and store its starting submatrix in ans.
Our final answe increments the indexs by 1 beacuse the CodeForces final answer expect the bottom 
right corner index of the submatrix.
*/