// Problem: https://codeforces.com/problemset/problem/158/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int count = 0;
    vi nums(n);
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    for(int i=0; i<n; ++i){
        if(nums[i] >= nums[k-1] && nums[i] > 0){
            count++;
        }
    }
    cout << count;	
    return 0;
}