# 🏆 Internation CodeFest'26 — 40-Day Preparation Roadmap

> **Goal:** Go from C++ experience (no CP background) to solving 3–4 problems in an ICPC-style contest in 40 days, with 2 hours of daily practice.

---

## Table of Contents

- [Philosophy & Approach](#philosophy--approach)
- [The Constraint → Algorithm Table](#the-constraint--algorithm-table)
- [Daily Schedule Template](#daily-schedule-template)
- [Phase 1 — Foundation (Days 1–12)](#phase-1--foundation-days-112)
- [Phase 2 — Pattern Library (Days 13–28)](#phase-2--pattern-library-days-1328)
- [Phase 3 — Speed & Contest Simulation (Days 29–40)](#phase-3--speed--contest-simulation-days-2940)
- [Pattern Recognition Triggers](#pattern-recognition-triggers)
- [Contest Meta-Strategy](#contest-meta-strategy)
- [Template Reference](#template-reference)
- [Resources](#resources)
- [Mistakes Log Template](#mistakes-log-template)

---

## Philosophy & Approach

This roadmap follows a **pattern-first** methodology rather than the traditional topic-by-topic approach. The core insight:

> **Classify before you code.** Spend the first 2 minutes of any problem identifying *what kind* of problem it is. Once classified, the code almost writes itself.

### The 3 Core Habits

1. **Write your time complexity before writing any code.** If your approach doesn't pass the constraint check, don't implement it — think of a better one first.
2. **Read ALL problems before solving any.** In contests, spend the first 8 minutes reading everything and classifying. Attack in order of confidence, not problem number.
3. **Upsolve every problem you don't solve in contests.** Read editorial for 5 minutes, close it, then code from scratch. "Read then implement blind" is 5× more effective than copying editorial solutions.

---

## The Constraint → Algorithm Table

Memorize this. It is the single most important reference in competitive programming.

| Input Size (N) | Target Complexity | Typical Algorithm |
|---|---|---|
| N ≤ 10 | O(N!) | Brute force, all permutations |
| N ≤ 20 | O(2ᴺ) | Bitmask DP, backtracking |
| N ≤ 500 | O(N²) | DP, brute force pairs, Floyd-Warshall |
| N ≤ 5,000 | O(N² log N) | Careful DP with sorting |
| N ≤ 10⁵ | O(N log N) | Greedy + sort, BFS/DFS, binary search, segment tree |
| N ≤ 10⁶ | O(N) | Linear DP, sieve, two pointers, sliding window |
| N ≤ 10⁹ | O(log N) | Binary search on answer, fast power |
| N ≤ 10¹⁸ | O(1) or O(√N) | Math formula, prime factorization |

> **Rule of thumb:** Most judges handle ~10⁸ simple operations per second. If `complexity × N > 10⁸`, expect TLE.

---

## Daily Schedule Template

**Total: 2 hours/day**

| Block | Duration | Activity |
|---|---|---|
| Learn | 35–50 min | Study concept, read template, understand *why* |
| Practice | 60–80 min | Solve 3–5 targeted problems (no hints for first 20 min) |
| Review | 10–15 min | Update cheat sheet, write pattern trigger words |

---

## Phase 1 — Foundation (Days 1–12)

### Day 1 — CP Template & STL Setup

**Goal:** Build and memorize your contest template. Understand every line.

**Your base template:**
```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define F first
#define S second
const ll MOD = 1e9+7;
const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // your code here
    return 0;
}
```

**Why `ios::sync_with_stdio(false)` + `cin.tie(0)` matters:** Without these, reading 10⁵ integers can TLE. These 2 lines give ~5× speedup. Never forget them.

**STL to know cold:** `vector`, `map`, `unordered_map`, `set`, `priority_queue` (max-heap default; `greater<int>` for min-heap), `stack`, `queue`, `deque`.

**Practice Problems:**
| Problem | Link | Focus |
|---|---|---|
| CF 4A — Watermelon | https://codeforces.com/problemset/problem/4/A | Submit with new template |
| CF 71A — Way Too Long Words | https://codeforces.com/problemset/problem/71/A | String + cin/cout |
| CF 158A — Next Round | https://codeforces.com/problemset/problem/158/A | vector + condition |
| CF 231A — Team | https://codeforces.com/problemset/problem/231/A | Counting |

**5 bugs that kill easy problems:**
1. `int` overflow — use `ll` when answer can exceed 2×10⁹
2. Off-by-one in loop bounds
3. Array out of bounds
4. Forgot fast I/O
5. Wrong output format (newline vs space)

---

### Day 2 — Arrays & Prefix Sums

**Pattern trigger:** "range sum", "subarray sum", "prefix", "sliding queries"

**Template:**
```cpp
int n; cin >> n;
vector<ll> a(n+1), pre(n+1, 0);
for(int i=1;i<=n;i++){ cin>>a[i]; pre[i]=pre[i-1]+a[i]; }

// Range sum query [l, r] (1-indexed) — O(1)
auto rangeSum = [&](int l, int r){ return pre[r] - pre[l-1]; };
```

**2D Prefix Sum:**
```cpp
// Build
pre[i][j] = a[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
// Query rectangle (r1,c1) to (r2,c2)
pre[r2][c2] - pre[r1-1][c2] - pre[r2][c1-1] + pre[r1-1][c1-1];
```

**Practice Problems:**
| Problem | Link | Rating |
|---|---|---|
| CF 1363B — Subsequence Hate | https://codeforces.com/problemset/problem/1363/B | Easy |
| CF 816B — Karen and Coffee | https://codeforces.com/problemset/problem/816/B | Easy |
| CF 682B — Alyona and Flowers | https://codeforces.com/problemset/problem/682/B | Easy |
| CF 466C — Number of Ways | https://codeforces.com/problemset/problem/466/C | Medium |
| CF 1207B — Square Filling | https://codeforces.com/problemset/problem/1207/B | Medium |

> **Mentor tip:** Always use 1-indexed arrays for prefix sums — it makes the formula `pre[r] - pre[l-1]` clean without worrying about negative indices.

---

### Day 3 — Two Pointers

**Pattern trigger:** "sorted array + pair/triple", "subarray with property", "longest/shortest window"

**3 Variants:**

| Variant | Setup | Use case |
|---|---|---|
| Opposite ends | `l=0, r=n-1` | Pair with target sum, palindrome check |
| Same direction (sliding window) | Both move right | Longest subarray, minimum window |
| Two arrays | One pointer per array | Merge step, intersection |

**Sliding window template:**
```cpp
int l=0; ll sum=0, ans=0;
for(int r=0;r<n;r++){
    sum += a[r];                    // expand window
    while(sum > target){            // shrink condition
        sum -= a[l++];
    }
    ans = max(ans, r-l+1);          // update answer
}
```

**Practice Problems:**
| Problem | Link | Rating |
|---|---|---|
| CF 6C — Alice, Bob and Chocolate | https://codeforces.com/problemset/problem/6/C | Easy |
| CF 1462B — Last Year's Substring | https://codeforces.com/problemset/problem/1462/B | Easy |
| CF 610D — Vitaly and Strings | https://codeforces.com/problemset/problem/610/D | Medium |
| Leetcode 3 — Longest Substring Without Repeating | https://leetcode.com/problems/longest-substring-without-repeating-characters | Medium |

> **Most common mistake:** Forgetting to reset/update state when the window shrinks. Always trace a `[1,2,3,4,5]` example by hand before coding.

---

### Day 4 — Binary Search — Value & Answer

**Two types:**

**Type 1 — Classic (search in sorted array):**
```cpp
// Use STL — lower_bound(all(v), x) = first element >= x
auto it = lower_bound(all(v), x);
```

**Type 2 — Binary search on answer (the powerful one):**

Trigger: *"minimize the maximum"*, *"maximize the minimum"*, *"can you do X in Y time?"*, *"is it possible to"*

```cpp
auto check = [&](ll mid) -> bool {
    // Is it feasible to achieve answer <= mid?
    return true; // or false
};

ll lo=1, hi=1e9, ans=hi;
while(lo<=hi){
    ll mid=(lo+hi)/2;
    if(check(mid)){ ans=mid; hi=mid-1; }
    else lo=mid+1;
}
```

**Practice Problems:**
| Problem | Link | Rating |
|---|---|---|
| CF 1373C — Choosing Teams | https://codeforces.com/problemset/problem/1373/C | Easy |
| CF 460C — Present | https://codeforces.com/problemset/problem/460/C | Medium |
| CF 1538C — Odd Number of Divisors | https://codeforces.com/problemset/problem/1538/C | Medium |

**3 classic binary search bugs:**
1. Wrong `lo`/`hi` bounds — think: what is the minimum/maximum possible answer?
2. Integer overflow: always use `(lo+hi)/2`
3. Infinite loop: ensure `lo=mid+1` and `hi=mid-1` (not `mid`)

> **Mentor tip:** "Binary search on answer" separates Div.2 B solvers from C solvers. Every time you see "minimize/maximize" in a problem, ask: *can I binary search the answer?*

---

### Day 5 — Number Theory Essentials

**Templates:**
```cpp
// GCD & LCM
ll gcd(ll a, ll b){ return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b){ return a/gcd(a,b)*b; }   // divide first to avoid overflow

// Sieve of Eratosthenes — O(N log log N)
const int MAXN=1e6+5;
bool isp[MAXN]; vector<int> primes;
void sieve(){
    fill(isp,isp+MAXN,true); isp[0]=isp[1]=false;
    for(int i=2;i<MAXN;i++){
        if(isp[i]){ primes.pb(i);
            for(ll j=(ll)i*i;j<MAXN;j+=i) isp[j]=false;
        }
    }
}

// Modular arithmetic — ALWAYS mod intermediate results
// (a - b) % m: use ((a-b)%m+m)%m — never plain (a-b)%m

// Fast power — O(log exp)
ll power(ll base, ll exp, ll mod){
    ll res=1; base%=mod;
    while(exp>0){
        if(exp&1) res=res*base%mod;
        base=base*base%mod; exp>>=1;
    }
    return res;
}
```

**Recognition map:**
| Trigger | Algorithm |
|---|---|
| "count primes ≤ N" | Sieve |
| "simplify fraction / common factor" | GCD |
| "output mod 10⁹+7" | Modular arithmetic throughout |
| "power of large number mod m" | Fast power |
| "count divisors of N" | Loop i=1 to √N |

**Practice Problems:**
| Problem | Link |
|---|---|
| CF 1282B — Vova and Trophies | https://codeforces.com/problemset/problem/1282/B |
| CF 577B — Modulo Sum | https://codeforces.com/problemset/problem/577/B |
| CF 1295C — Obtain The String | https://codeforces.com/problemset/problem/1295/C |

---

### Day 6 — Sorting & Custom Comparators

```cpp
// Sort by second element descending
sort(all(v), [](auto& a, auto& b){ return a.second > b.second; });

// Sort structs by ratio
sort(all(items), [](auto& a, auto& b){
    return (double)a.val/a.wt > (double)b.val/b.wt;
});
```

**Key insight:** Sorting reveals order. Before any greedy solution, ask: *"What order makes the greedy choice obvious?"*
- Intervals → sort by finish time
- Budget problems → sort by cost
- Comparative problems → sort by difference

**Practice Problems:**
| Problem | Link |
|---|---|
| CF 1369C — RationalNumbers | https://codeforces.com/problemset/problem/1369/C |
| CF 1430C — Numbers on Whiteboard | https://codeforces.com/problemset/problem/1430/C |
| CF 558C — Amr and the Large Array | https://codeforces.com/problemset/problem/558/C |

---

### Day 7 — Rest & Consolidation

- Re-solve 3 problems from Days 1–6 from scratch (no notes)
- Write your **pattern cheat sheet** (physical notebook): trigger words + template signature + one example problem per pattern
- 5 easy A-level problems for fluency: CF 1A, CF 50A, CF 263A, CF 116A, CF 977A

---

### Day 8 — Greedy Algorithms

**Pattern trigger:** "minimum cost/time", "maximum tasks/events", "assign/schedule", "can you fit?"

**Interval scheduling (activity selection):**
```cpp
// Maximum non-overlapping intervals — sort by END time
sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
    return a.second < b.second;
});
int count=0; ll last_end=-INF;
for(auto& [s,e] : intervals){
    if(s >= last_end){ count++; last_end=e; }
}
```

**Greedy vs DP decision rule:**
- Local optimal choice leads to global optimal → **Greedy**
- Value of a choice depends on future choices → **DP**
- When in doubt: try greedy first (faster to code), verify with small examples

**Practice Problems:**
| Problem | Link |
|---|---|
| CF 1077C — Good Array | https://codeforces.com/problemset/problem/1077/C |
| CF 1253C — Sweets Eating | https://codeforces.com/problemset/problem/1253/C |
| CF 1430D — String Deletion | https://codeforces.com/problemset/problem/1430/D |

---

### Day 9 — Recursion & Backtracking

**Pattern trigger:** "generate all", "try all possibilities", N ≤ 20, "enumerate subsets/permutations"

**Universal template:**
```cpp
void solve(int pos, vector<int>& current){
    if(pos == n){           // base case — complete solution
        // process solution
        return;
    }
    for(int choice : choices){
        if(isValid(choice)){
            current.pb(choice);         // choose
            solve(pos+1, current);
            current.pop_back();         // unchoose
        }
    }
}
```

**Complexity limits:**
| N | Complexity | Verdict |
|---|---|---|
| ≤ 20 | O(2ᴺ) = 10⁶ | Fine |
| ≤ 15 | O(N!) permutations | Fine |
| > 25 | O(2ᴺ) | TLE — need DP |

**Practice Problems:**
| Problem | Link |
|---|---|
| Leetcode 78 — Subsets | https://leetcode.com/problems/subsets/ |
| Leetcode 46 — Permutations | https://leetcode.com/problems/permutations/ |
| CF 1033B — Creating the Contest | https://codeforces.com/problemset/problem/1033/B |

---

### Day 10 — Monotonic Stack & Deque

**Pattern trigger:** "next/previous greater/smaller element", "max/min in sliding window", "largest rectangle"

**Next Greater Element:**
```cpp
vector<int> nge(n, -1);
stack<int> st;                  // stores indices
for(int i=0;i<n;i++){
    while(!st.empty() && a[st.top()] < a[i]){
        nge[st.top()] = i;      // i is next greater for st.top()
        st.pop();
    }
    st.push(i);
}
```

**Sliding window minimum (monotonic deque):**
```cpp
deque<int> dq;                  // indices, maintain increasing order
for(int i=0;i<n;i++){
    while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
    while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
    dq.push_back(i);
    if(i>=k-1) cout << a[dq.front()] << " ";
}
```

**Must-solve benchmark:** Leetcode 84 — Largest Rectangle in Histogram. After solving this once, all other monotonic stack problems become easy.

**Practice Problems:**
| Problem | Link |
|---|---|
| Leetcode 84 — Largest Rectangle in Histogram | https://leetcode.com/problems/largest-rectangle-in-histogram/ |
| Leetcode 739 — Daily Temperatures | https://leetcode.com/problems/daily-temperatures/ |
| CF 1529B — Sifid and Strange Subsequences | https://codeforces.com/problemset/problem/1529/B |

---

### Day 11 — Hashing & Frequency Maps

**Two-sum pattern (complement lookup):**
```cpp
unordered_map<int,int> seen;
for(int i=0;i<n;i++){
    int need = target - a[i];
    if(seen.count(need)){ /* found pair at (seen[need], i) */ }
    seen[a[i]] = i;
}
```

**4 use cases:** Frequency count, O(1) existence check, memoization, two-sum complement lookup.

**3 hash traps:**
1. `map[key]` creates the key even when checking — use `.count()` or `.find()` instead
2. `unordered_map` can be slow for adversarial inputs — add `.reserve(N)` for large maps
3. String hash collisions on large N — use polynomial hashing

**Practice Problems:**
| Problem | Link |
|---|---|
| CF 1520B — Ordinary Numbers | https://codeforces.com/problemset/problem/1520/B |
| CF 1005C — Summarize to the Power of Two | https://codeforces.com/problemset/problem/1005/C |

---

### Day 12 — Complexity Analysis

Full constraint → algorithm table (see top of document). Practice estimating complexity *before* coding any solution.

**Self-assessment before Phase 2:**
- [ ] Write CP template from memory in 2 min
- [ ] Recognize prefix sum, two pointer, binary search, greedy triggers instantly
- [ ] Estimate if a solution will TLE before submitting
- [ ] Solve CF Div.2 A in < 10 min, B in < 25 min

**Practice Problems:**
| Problem | Link |
|---|---|
| CF 1399C — Boats Competition | https://codeforces.com/problemset/problem/1399/C |
| CF 1285C — Fadi and LCM | https://codeforces.com/problemset/problem/1285/C |
| CF 1451C — String Equality | https://codeforces.com/problemset/problem/1451/C |

---

## Phase 2 — Pattern Library (Days 13–28)

### Day 13 — Graph Representation & BFS

**Adjacency list (use 95% of the time):**
```cpp
vector<vector<int>> adj(n);
adj[u].push_back(v);            // directed
adj[v].push_back(u);            // undirected — add both
```

**BFS template (shortest path, unweighted):**
```cpp
vector<int> dist(n, -1);
queue<int> q;
dist[src] = 0; q.push(src);
while(!q.empty()){
    int u = q.front(); q.pop();
    for(int v : adj[u]){
        if(dist[v] == -1){ dist[v] = dist[u]+1; q.push(v); }
    }
}
```

**Graph recognition:** Entities + relationships = graph. Cities/roads, people/friendships, states/transitions, grid cells/movement — all graphs.

**Grid graphs:** Cell `(r,c)` has neighbors `(r±1,c)` and `(r,c±1)`. Build this adjacency mentally.

**Practice Problems:**
| Problem | Link |
|---|---|
| CF 1365D — Solve The Maze | https://codeforces.com/problemset/problem/1365/D |
| CF 580B — Kefa and Company | https://codeforces.com/problemset/problem/580/B |
| CF 1033D — Divisors | https://codeforces.com/problemset/problem/1033/D |

---

### Day 14 — DFS, Connectivity & Topological Sort

**DFS + connected components:**
```cpp
vector<bool> vis(n, false);
void dfs(int u){ vis[u]=true; for(int v:adj[u]) if(!vis[v]) dfs(v); }

int components=0;
for(int i=0;i<n;i++) if(!vis[i]){ dfs(i); components++; }
```

**Topological sort (Kahn's BFS algorithm):**
```cpp
vector<int> indeg(n, 0);
for(auto& [u,v] : edges) indeg[v]++;
queue<int> q;
for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i);
vector<int> topo;
while(!q.empty()){
    int u=q.front(); q.pop(); topo.pb(u);
    for(int v:adj[u]) if(--indeg[v]==0) q.push(v);
}
// If topo.size() < n, there is a cycle
```

> **Warning:** Recursive DFS on N=10⁵ nodes can cause stack overflow. Use iterative DFS (replace queue with stack) for large graphs.

**Practice Problems:**
| Problem | Link |
|---|---|
| CF 1385D — a-Good String | https://codeforces.com/problemset/problem/1385/D |
| CF 1385E — Directing Edges | https://codeforces.com/problemset/problem/1385/E |

---

### Day 15 — Dijkstra & Weighted Shortest Paths

```cpp
typedef pair<ll,int> pli;           // {dist, node}
vector<ll> dist(n, INF);
priority_queue<pli, vector<pli>, greater<pli>> pq;  // min-heap
dist[src]=0; pq.push({0, src});
while(!pq.empty()){
    auto [d,u] = pq.top(); pq.pop();
    if(d > dist[u]) continue;       // NEVER skip this line
    for(auto [v,w] : adj[u])        // adj[u] = {neighbor, weight}
        if(dist[u]+w < dist[v]){
            dist[v]=dist[u]+w;
            pq.push({dist[v], v});
        }
}
```

**When NOT to use Dijkstra:**
- Negative edge weights → Bellman-Ford
- Unweighted graph → BFS (simpler and faster)

> **Critical:** The stale entry check `if(d > dist[u]) continue` is the single most commonly forgotten line. Without it, you process nodes multiple times and get WA or TLE.

---

### Day 16 — Union-Find (DSU)

```cpp
struct DSU {
    vector<int> par, rank_;
    DSU(int n): par(n), rank_(n,0){ iota(all(par),0); }
    int find(int x){ return par[x]==x ? x : par[x]=find(par[x]); }
    bool unite(int x, int y){
        x=find(x); y=find(y); if(x==y) return false;
        if(rank_[x]<rank_[y]) swap(x,y);
        par[y]=x; if(rank_[x]==rank_[y]) rank_[x]++;
        return true;
    }
    bool connected(int x, int y){ return find(x)==find(y); }
};
```

**Kruskal's MST:**
```cpp
sort(edges.begin(), edges.end());  // sort by weight: {w, u, v}
DSU dsu(n);
ll mst_cost=0; int edges_used=0;
for(auto [w,u,v] : edges)
    if(dsu.unite(u,v)){ mst_cost+=w; if(++edges_used==n-1) break; }
```

**Trigger phrases:** "are A and B connected?", "merge two groups", "how many components?", "minimum spanning tree"

---

### Day 17 — 1D Dynamic Programming

**The 4-step DP process:**
1. **DEFINE STATE:** Write the sentence `dp[i] means ___`
2. **RECURRENCE:** `dp[i] = f(dp[i-1], dp[i-2], ...)`
3. **BASE CASE:** `dp[0] = ?, dp[1] = ?`
4. **ORDER:** Left-to-right, right-to-left, or by subproblem size

**5 essential 1D DP patterns:**

```cpp
// 1. Kadane's — maximum subarray sum
ll dp=a[0], ans=a[0];
for(int i=1;i<n;i++){ dp=max(a[i], dp+a[i]); ans=max(ans,dp); }

// 2. LIS — Longest Increasing Subsequence — O(N log N)
vector<int> lis;
for(int x:a){
    auto it=lower_bound(all(lis),x);
    if(it==lis.end()) lis.pb(x); else *it=x;
}
// lis.size() = LIS length

// 3. Coin change (min coins)
// dp[j] = min coins to make sum j
vector<int> dp(target+1, INF); dp[0]=0;
for(int coin:coins)
    for(int j=coin;j<=target;j++) dp[j]=min(dp[j], dp[j-coin]+1);

// 4. House robber (max non-adjacent sum)
ll a=0, b=0;
for(int x:nums){ ll c=max(b, a+x); a=b; b=c; }
// answer = b
```

> **The #1 DP lesson:** Before writing any code, write the English sentence "dp[i] means the ___". Get this right and the recurrence follows. If you can't write the sentence, you don't understand the state yet.

**Practice Problems:**
| Problem | Link |
|---|---|
| CF 1549B — Gregor and the Two Painters | https://codeforces.com/problemset/problem/1549/B |
| CF 1077D — Cutting Out | https://codeforces.com/problemset/problem/1077/D |
| Atcoder DP Contest | https://atcoder.jp/contests/dp |

---

### Day 18 — Knapsack & 2D DP

```cpp
// 0/1 Knapsack — each item used AT MOST ONCE → REVERSE order
vector<ll> dp(W+1, 0);
for(auto [val,wt] : items)
    for(int j=W; j>=wt; j--)         // REVERSE
        dp[j] = max(dp[j], dp[j-wt]+val);

// Unbounded Knapsack — items REUSABLE → FORWARD order
for(auto [val,wt] : items)
    for(int j=wt; j<=W; j++)          // FORWARD
        dp[j] = max(dp[j], dp[j-wt]+val);

// Subset sum (does subset with sum S exist?)
vector<bool> dp(S+1, false); dp[0]=true;
for(int x:nums)
    for(int j=S; j>=x; j--)
        dp[j] = dp[j] || dp[j-x];

// LCS — Longest Common Subsequence
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        dp[i][j] = (s[i-1]==t[j-1]) ? dp[i-1][j-1]+1
                                      : max(dp[i-1][j], dp[i][j-1]);
```

> **The iteration order rule:** Backwards = each item used once. Forwards = items reusable. Memorize this.

---

### Day 19 — DP on Grids & Strings

```cpp
// Grid DP — min cost path
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + cost[i][j];

// Edit distance
for(int i=0;i<=n;i++) dp[i][0]=i;
for(int j=0;j<=m;j++) dp[0][j]=j;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        dp[i][j] = (s[i-1]==t[j-1]) ? dp[i-1][j-1]
            : 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
```

---

### Day 20 — Rest & Classification Drill

**Pattern classification speed drill:**
- Open CF problemset, filter rating 1200–1500
- For each of 10 problems: spend 3 minutes reading, then write (without coding): algorithm family, key observation, time complexity
- **Target:** 7/10 correct classifications

---

### Day 21 — Sliding Window DP (Deque Optimization)

```cpp
// dp[i] = max(dp[j]) for j in [i-k, i-1], then + cost[i]
deque<int> dq;
for(int i=0;i<n;i++){
    while(!dq.empty() && dq.front() < i-k) dq.pop_front();
    dp[i] = dp[dq.front()] + cost[i];
    while(!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
    dq.push_back(i);
}
```

Reduces O(NK) DP to O(N). Use when dp[i] depends on a window of k previous states.

---

### Day 22 — Trees — DFS & Tree DP

```cpp
// Tree DFS (the parent parameter is critical)
void dfs(int u, int par){
    for(int v : adj[u]){
        if(v==par) continue;      // never forget this
        dfs(v, u);
    }
    // post-order processing here
}

// Subtree sizes + Tree DP
vector<int> sz(n,1), dp(n,0);
void dfs(int u, int par){
    for(int v : adj[u]){
        if(v==par) continue;
        dfs(v, u);
        sz[u] += sz[v];
        dp[u] = max(dp[u], dp[v] + sz[v]);
    }
}
```

**Tree diameter:** Two DFS — from any node find farthest A, from A find farthest B. Length A→B is the diameter.

---

### Day 23 — Bit Manipulation & Bitmask DP

```cpp
bool isSet(int mask, int k)  { return (mask>>k)&1; }
int  setBit(int mask, int k) { return mask|(1<<k); }
int  clrBit(int mask, int k) { return mask&~(1<<k); }
int  popcount(int mask)      { return __builtin_popcount(mask); }

// Enumerate all subsets of mask
for(int sub=mask; sub>0; sub=(sub-1)&mask){ /* ... */ }

// Bitmask DP (TSP-style) — O(2ᴺ × N²)
vector<vector<ll>> dp(1<<n, vector<ll>(n, INF));
dp[1][0]=0;
for(int mask=1;mask<(1<<n);mask++)
    for(int u=0;u<n;u++) if(isSet(mask,u) && dp[mask][u]!=INF)
        for(int v=0;v<n;v++) if(!isSet(mask,v))
            dp[mask|(1<<v)][v] = min(dp[mask|(1<<v)][v], dp[mask][u]+dist[u][v]);
```

**Useful GCC builtins:** `__builtin_popcount(x)` (set bits), `__builtin_clz(x)` (leading zeros), `__builtin_ctz(x)` (trailing zeros) — all O(1).

---

### Day 24 — String Algorithms — Z-function & KMP

**Z-function:**
```cpp
vector<int> zfunc(string s){
    int n=s.size(); vector<int> z(n,0); z[0]=n;
    int l=0, r=0;
    for(int i=1;i<n;i++){
        if(i<r) z[i]=min(r-i, z[i-l]);
        while(i+z[i]<n && s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]>r){ l=i; r=i+z[i]; }
    }
    return z;
}

// Find all occurrences of P in T
string s = P + "#" + T;          // '#' must not appear in P or T
auto z = zfunc(s);
for(int i=P.size()+1; i<s.size(); i++)
    if(z[i]==(int)P.size())      // P occurs at index i-P.size()-1 in T
        cout << i-P.size()-1 << "\n";
```

**KMP prefix function:**
```cpp
vector<int> kmpPrefix(string s){
    int n=s.size(); vector<int> pi(n,0);
    for(int i=1;i<n;i++){
        int j=pi[i-1];
        while(j && s[i]!=s[j]) j=pi[j-1];
        if(s[i]==s[j]) j++;
        pi[i]=j;
    }
    return pi;
}
```

---

### Day 25 — Combinatorics & Modular Inverse

```cpp
const int MAXN=1e6+5;
ll fact[MAXN], inv_fact[MAXN];

void precompute(){
    fact[0]=1;
    for(int i=1;i<MAXN;i++) fact[i]=fact[i-1]*i%MOD;
    inv_fact[MAXN-1]=power(fact[MAXN-1], MOD-2, MOD);  // Fermat's little theorem
    for(int i=MAXN-2;i>=0;i--) inv_fact[i]=inv_fact[i+1]*(i+1)%MOD;
}

ll C(int n, int r){
    if(r<0 || r>n) return 0;
    return fact[n]%MOD * inv_fact[r]%MOD * inv_fact[n-r]%MOD;
}
```

**Key formulas:**
| Formula | Use |
|---|---|
| `C(n,r)` | Choose r from n |
| `C(n+k-1, k-1)` | Stars and bars — distribute n items into k groups |
| `D(n) = (n-1)(D(n-1)+D(n-2))` | Derangements |
| `C(2n,n)/(n+1)` | Catalan numbers |

> **Note:** `a⁻¹ mod p = a^(p-2) mod p` only works when p is prime. 10⁹+7 is prime.

---

### Day 26 — Segment Trees

**Iterative segment tree (point update, range query):**
```cpp
struct SegTree {
    int n; vector<ll> tree;
    SegTree(int n): n(n), tree(2*n, 0){}
    void update(int i, ll val){
        tree[i+n]=val;
        for(i=(i+n)>>1; i>=1; i>>=1)
            tree[i] = tree[2*i] + tree[2*i+1];  // change merge here
    }
    ll query(int l, int r){  // [l, r] inclusive
        ll res=0;
        for(l+=n,r+=n+1; l<r; l>>=1,r>>=1){
            if(l&1) res += tree[l++];
            if(r&1) res += tree[--r];
        }
        return res;
    }
};
```

**Merge options:** Sum (`+`), Max (`max`), Min (`min`), GCD (`__gcd`), XOR (`^`). Rest of code is identical.

---

### Day 27 — Divide & Conquer

**Count inversions (merge sort):**
```cpp
ll mergeCount(vector<int>& a, int l, int r){
    if(r-l<=1) return 0;
    int mid=(l+r)/2;
    ll cnt = mergeCount(a,l,mid) + mergeCount(a,mid,r);
    vector<int> tmp; int i=l, j=mid;
    while(i<mid && j<r){
        if(a[i]<=a[j]) tmp.pb(a[i++]);
        else{ cnt+=mid-i; tmp.pb(a[j++]); }
    }
    while(i<mid) tmp.pb(a[i++]); while(j<r) tmp.pb(a[j++]);
    copy(tmp.begin(),tmp.end(),a.begin()+l);
    return cnt;
}
```

Inversions = "how many swaps to sort?" = "pairs (i,j) where i<j but a[i]>a[j]".

---

### Day 28 — Phase 2 Mock Contest

Run a full 90-minute virtual contest on Codeforces. No hints during the timer. Upsolve everything afterward using the "read editorial 5 min → close → code blind" method.

---

## Phase 3 — Speed & Contest Simulation (Days 29–40)

### Days 29–30 — Contest Speed & Virtual Contest #1

**Speed drill targets:**
- CF Div.2 A problem: < 8 minutes
- CF Div.2 B problem: < 20 minutes
- Attempt C with remaining time

**Stuck protocol:** 20 minutes on one problem → switch. Write a `// TODO: try X` comment and move on. Return only if time allows.

**Pre-code 3-step (do this before every problem):**
1. Write variable names on paper
2. Trace through the example manually
3. Note edge cases: n=0, n=1, all-same values, overflow

---

### Days 31–32 — Weak Pattern Drilling & Virtual Contest #2

Identify your 2 weakest patterns from submission history. For each:
1. Re-read the template (5 min)
2. Solve 3 problems tagged with that pattern at 1200–1500 rating without hints
3. Focus: can you classify within 2 minutes of reading?

---

### Day 33 — ICPC-Specific Strategy

**Key differences from Codeforces:**
- 5 hours, 10–12 problems, team of 3, **1 computer**
- Score = problems solved; ties broken by time + penalties
- **No partial credit** — only full AC counts
- Penalty: **+20 min** per WA on a later-accepted problem

**Penalty management:** Test thoroughly before submitting, but don't over-test. 3 manual traces is usually enough. The cost of NOT submitting (no AC = no score) is also high.

**Print your template reference sheet** before the contest: CP template, BFS/DFS/Dijkstra/DSU/SegTree/Knapsack, constraint→algorithm table, nCr precomputation.

---

### Day 34 — Debugging & Stress Testing

**5-step debug protocol:**
1. Run provided examples manually
2. Trace with a small hand-crafted example
3. Check edge cases: n=0, n=1, all-same, max values, overflow
4. Add print statements at key points
5. Verify time complexity on worst case

**Stress test template:**
```cpp
srand(42);
for(int test=0;test<1000;test++){
    int n=rand()%10+2;
    vector<int> a(n);
    for(int& x:a) x=rand()%20-10;
    if(brute(a) != fast(a)){
        cout << "MISMATCH: ";
        for(int x:a) cout<<x<<" ";
        return 0;
    }
}
cout << "All tests passed" << endl;
```

**Common bugs by category:**
| Bug type | Cause |
|---|---|
| Wrong Answer | Off-by-one, wrong indexing, missing edge case |
| Time Limit Exceeded | Wrong complexity, forgotten memoization, quadratic inner loop |
| Runtime Error | Array out of bounds (most common), stack overflow, empty container access |

---

### Days 35–36 — Virtual Contest #3 & Upsolve

Third simulation, 100 minutes. Target: A+B under 40 min, serious C attempt.

After: upsolve all unsolved problems over Days 36–37. Space the upsolving — don't cram it all into one session.

---

### Day 37 — Template Memorization Test

Write all 10 templates from memory, timed:

| Template | Target time |
|---|---|
| CP base template | 2 min |
| BFS shortest path | 3 min |
| DFS + component count | 3 min |
| Dijkstra with priority_queue | 5 min |
| DSU with path compression | 4 min |
| 0/1 Knapsack DP | 3 min |
| Prefix sum build + query | 2 min |
| Binary search on answer | 3 min |
| Z-function | 4 min |
| Iterative segment tree | 5 min |

If you can write all 10 without errors, you are ready.

---

### Days 38–39 — Light Practice & Rest

- Day 38: 2–3 easy problems (CF 1000–1200) only. Contest logistics check.
- Day 39: Read cheat sheet once. No new problems. Sleep at normal time.

---

### Day 40 — Contest Day

**The 8-minute protocol:**
1. **Min 0–8:** Read ALL problems. Write pattern name + easy/med/hard for each. Do NOT start coding.
2. **Min 8–15:** Write template, start problem A.
3. **Min 35:** If not AC on A, re-read the problem statement. Something is wrong with your understanding.
4. **Min 35–70:** Problem B.
5. **Min 70+:** Problem C attempt.

**Before every submit:**
1. Run example 1
2. Run example 2
3. Check: n=1? overflow? off-by-one?
4. Submit

The 2-minute pre-submit check prevents the 20-minute WA penalty.

---

## Pattern Recognition Triggers

| Trigger phrase in problem | Pattern |
|---|---|
| "range sum", "sum of subarray", "prefix" | Prefix sum |
| "sorted + pair/triple with sum" | Two pointers |
| "minimize the maximum" / "maximize the minimum" | Binary search on answer |
| "find if prime" / "count primes ≤ N" | Sieve |
| "minimum cost/time to schedule/assign" | Greedy + sort |
| "maximum non-overlapping intervals" | Greedy by finish time |
| "generate all / try all possibilities", N ≤ 20 | Backtracking |
| "next/previous greater/smaller element" | Monotonic stack |
| "max/min in sliding window of size k" | Monotonic deque |
| "shortest path (unweighted)" | BFS |
| "shortest path (weighted, non-negative)" | Dijkstra |
| "are A and B connected?" / "merge groups" | DSU / Union-Find |
| "optimal substructure + overlapping subproblems" | Dynamic programming |
| "choose items with weight/value constraint" | Knapsack DP |
| "pattern P in text T" / "all occurrences" | Z-function |
| "count pairs/triples" / "C(n,r) mod p" | Combinatorics + modular inverse |
| "range query + point update" | Segment tree |
| "count inversions" / "how many swaps to sort?" | Merge sort D&C |

---

## Contest Meta-Strategy

### Problem Reading Order
Read **all** problems before solving any. Spend 2 min per problem: constraints → classify → difficulty estimate. First impressions mislead — the "hard" problem is sometimes the easy one.

### Time Allocation
| Problem | Max time before switching |
|---|---|
| A (easy) | 15 min |
| B (medium) | 35 min |
| C (hard) | Remaining time |

### The 3 Questions Before Coding
1. What are the constraints? (→ look up complexity table)
2. What pattern is this? (→ check trigger list)
3. Can I verify on example 1? (→ trace before coding)

### ICPC Scoring Insight
Solving ALL easy problems quickly + one medium = better score than attempting hard problems and missing easy ones. **Accuracy beats ambition.**

---

## Template Reference

All templates are included throughout the day-by-day sections above. Quick index:

| Template | Day |
|---|---|
| CP Base Template | Day 1 |
| Prefix Sum | Day 2 |
| Sliding Window (Two Pointers) | Day 3 |
| Binary Search on Answer | Day 4 |
| Sieve + Fast Power + GCD | Day 5 |
| Interval Scheduling (Greedy) | Day 8 |
| Backtracking | Day 9 |
| Monotonic Stack + Deque | Day 10 |
| BFS Shortest Path | Day 13 |
| DFS + Topological Sort | Day 14 |
| Dijkstra | Day 15 |
| DSU + Kruskal | Day 16 |
| Kadane's + LIS | Day 17 |
| Knapsack (0/1, Unbounded, Subset Sum) | Day 18 |
| Grid DP + Edit Distance | Day 19 |
| Sliding Window DP | Day 21 |
| Tree DFS + Tree DP | Day 22 |
| Bitmask DP | Day 23 |
| Z-function + KMP | Day 24 |
| nCr mod p | Day 25 |
| Iterative Segment Tree | Day 26 |
| Count Inversions (Merge Sort) | Day 27 |
| Stress Test | Day 34 |

---

## Resources

### Primary Practice Platform
- **Codeforces** — https://codeforces.com/problemset
  - Filter by rating (800 → 1600) and tag for targeted practice
  - Virtual contests from Div.2 archives for simulation

### Reference & Learning
- **CP-Algorithms** — https://cp-algorithms.com — Best free reference; read the page then solve 3 problems on it
- **USACO Guide** — https://usaco.guide — Silver level = your ICPC target range
- **Atcoder DP Contest** — https://atcoder.jp/contests/dp — 26 educational DP problems, essential for Day 17–19

### Problem Lists
- **Striver's A2Z Sheet** — Topic-wise problem list, strong on DP and graphs
- **ICPC Regional Archives** — https://icpc.global — Official problem sets
- **CF Gym (ICPC)** — https://codeforces.com/gyms — Filter "ICPC" for regional problem sets

### Tools
- **cppreference.com** — C++ STL documentation
- **codeforces.com/edu** — Structured educational courses with problems

---

## Mistakes Log Template

Keep a running log in a physical notebook or a file in this repo. Review before every contest.

```
Date: ____
Contest: ____
Problems solved: ____

Problem A:
  - Pattern: ____
  - Time to AC: ____ min
  - WA bugs: ____

Problem B:
  - Pattern: ____
  - Time to AC: ____ min
  - WA bugs: ____

Problem C (attempted):
  - My classification: ____
  - Actual pattern: ____
  - What I missed: ____

Recurring errors this session:
  1.
  2.

Things to drill next session:
  1.
  2.
```

---

## Realistic Target

After 40 days (2 hours/day):
- **Codeforces rating:** ~1200–1400
- **Contest performance:** Solve A+B reliably under 40 min, occasional C
- **ICPC debut:** 3–4 problems in a 5-hour contest

This is a strong debut. Most first-time ICPC contestants plateau here. You're building real foundations — the patterns internalized in this 40-day sprint compound with every future contest.

---

*Good luck. The patterns are in your fingers now.*