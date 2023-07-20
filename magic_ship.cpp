#include <bits/stdc++.h> 
#include <set> 
#include <map> 
#include <unordered_map> 
#include <vector> 
#include <utility> //pair
#include <string>
#define F first 
#define S second 
#define PB push_back 
#define MP make_pair 
#define MAXN 100001
typedef long long ll; 
using namespace std;

// problem : https://codeforces.com/problemset/problem/1117/C

ll n, x, y, x2, y2;
ll U[MAXN];
ll L[MAXN];
ll D[MAXN];
ll R[MAXN];

bool check(ll m){
    ll curx = x, cury = y;
    cury += m/n * U[n] + U[m%n];
    cury -= m/n * D[n] + D[m%n];
    curx += m/n * R[n] + R[m%n];
    curx -= m/n * L[n] + L[m%n];

    if(abs(curx - x2) + abs(cury - y2) <= m) return true;
    return false;
}

int main() { 
 
 #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt", "w", stdout); 
 #endif

  //code here 

  cin >> x >> y;
  cin >> x2 >> y2;
  cin >> n;
  string s;
  cin >> s;

  for(int i = 0; i<n; i++){
    if(s[i] == 'U') U[i+1]++;
    else if(s[i] == 'L') L[i+1]++;
    else if(s[i] == 'D') D[i+1]++;
    else R[i+1]++;
  }

  for(int i = 1; i<= n; i++){
    U[i] += U[i-1];
    L[i] += L[i-1];
    D[i] += D[i-1];
    R[i] += R[i-1];
  }

  ll l = 0, r = 1e18, mid, ans = -1;
  while(l<=r){
    mid = l + (r-l)/2;
    
    if(check(mid)){
        ans = mid;
        r = mid - 1;
    }else{
        l = mid + 1;
    }
  }

  cout << ans << endl;


return 0;
}