# USACO training
- [USACO training](#usaco-training)
  - [Section 3.1](#section-31)
    - [PROB humble numbers](#prob-humble-numbers)

## Section 3.1

### PROB humble numbers

Great dp question, found time complexity N\*K, seen NlogK is possible  
[Humble Numbers](https://train.usaco.org/usacoprob2?a=LHry42334zj&S=humble)

\*\* Unique intuition for dp

Code:

```
/*
ID: vineeth13
TASK: humble
LANG: C++
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define PII pair<int, int>
#define pub push_back
#define puf push_front
#define F first
#define S second
#define ld long double
#define fastIO ios::sync_with_stdio(0); cin.tie(0);
vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
int n, m;
// Fill these!
bool isValid(int i, int j) {return i>=0 && i<n && j>=0 && j<m;}
const int inf = 0x3f3f3f3f;
int modpow(int a, int b, int mod) {
    if(a == 0) return 0;
    else if(a == 1 || b == 0) return 1;
    int x = modpow(a, b/2, mod);
    if(b % 2 == 0) {
        x = (x*x)%mod;
    }else {
        x = (x*x)%mod;
        x = (x*a)%mod;
    }
    return x;
}
vector<int> dp(1e5);
int32_t main(){
    // fastIO
    freopen("humble.in", "r", stdin);
    freopen("humble.out", "w", stdout);
    int k, n; cin>>k>>n;
    vector<int> prime(k);
    for(int i = 0; i<k; i++) cin>>prime[i];
    vector<int> pindex(k, 0);
    vector<int> dp(n+1, LLONG_MAX);
    dp[0] = 1;
    int ptr = 1;
    while(ptr <= n) {
        int num = LLONG_MAX;
        int num_idx = -1;
        for(int i = 0; i<k; i++) {
            while((double)prime[i] * dp[pindex[i]] <= dp[ptr-1]) pindex[i]++;

            if((double)dp[pindex[i]] * prime[i] < num) {
                num = dp[pindex[i]] * prime[i];
                num_idx = i;
            }
        }
        dp[ptr] = num; ptr++;
        pindex[num_idx]++;
    }

    cout<<dp[n]<<"\n";


    return 0;
}
```
