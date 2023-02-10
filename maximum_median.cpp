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
typedef long long ll; 
using namespace std;

// Problem : https://codeforces.com/contest/1201/problem/C

ll a[200001];
ll n,k;

bool check(ll mid){
    int median = n/2;
    ll eat = k;
    for(int i = n-1; i >= n/2; i--){
        if(a[i] <= mid){
            eat -= mid - a[i];
        }
    }
    if(eat < 0) return false;
    return true;
}

int main() { 
 
  cin >> n >> k;

  for(int i = 0; i<n; i++){
    cin >> a[i];
  }

  sort(a, a+n);

  ll l = 0, r = 2e9, mid, ans = 0;
  while(l <= r){
    mid = l + (r-l)/2;
    if(check(mid)){
        ans = mid;
        l = mid + 1;
    }else{
        r = mid - 1;
    }
  }

  cout << ans << endl;

return 0;
}