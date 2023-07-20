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

// problem : https://cses.fi/problemset/task/1085

int n,k;
ll a[200000];

bool check(ll x){
    ll cur = 0;
    ll segs = 1;
    int i = 0;

    while(i<n){
        if(a[i] > x) return false;

        if(cur + a[i] <= x) 
            cur += a[i];
        else{
            segs++;
            cur = a[i];
        }

        i++;
    }

    if(segs <= k) return true;

    return false;
}

int main() { 
 
 /* #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt", "w", stdout); 
 #endif */

  //code here

  cin >> n >> k;
  for(int i = 0; i<n; i++) cin >> a[i];

  ll l = 0, r = 1e15, mid, ans;
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