// Problem: https://codeforces.com/problemset/problem/1363/B

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector(ll)
#define vi vector(int)
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
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        int suf0 = 0, suf1= 0;
        for(int j=0;j<s.size(); j++){
            if(s[j]=='0') suf0++;
                else suf1++;
            }
        int ans = min(suf0, suf1);
        int pref0 = 0, pref1 = 0;
        for(int j=0; j<s.size(); j++){
            if(s[j] == '0') { pref0++; suf0--; }
            else { pref1++; suf1--; }
            ans = min(ans, pref1+suf0);
            ans = min(ans, pref0+suf1);
        }
        cout << ans << '\n';
    }
    return 0;
}

/*  
We want continuos 0s or 1s, we are not allowed peaks, 101 or 010. So we can
either have all 0000111.. or 111000.., we keep track of total number of 1s and 0s
at each index and our answer is the the minimum of how many 1s or 0s we need to 
flip at each index, i.e. for prefix and suffix.
*/