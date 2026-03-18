// Problem: https://codeforces.com/problemset/problem/71/A

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
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    for (const auto& s : words) {
        if (s.length() > 10) {
            cout << s.front() << (s.length() - 2) << s.back() << '\n';
        } else {
            cout.write(s.data(), s.size()); // writes raw bytes directly to the output stream
            cout << '\n';
        }
    }
    return 0;
}