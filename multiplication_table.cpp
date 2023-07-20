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

// problem : https://cses.fi/problemset/task/2422

ll n;

pair<ll,ll> check(ll x){

    ll itself = 0;
    ll cnt = 0;
    ll div;
    for(int i = 1; i<=n; i++){
        div = x / i;
        cnt += min(div, n);

        if(x%i == 0 && div <= n){
            itself++;
        }
    }

    return MP(cnt, itself);
}

int main() { 

  cin >> n;

  ll l = 1, r = n*n, mid, ans = -1;
  ll need = n*n / 2 + 1;

  while(l<=r){
    mid = l + (r-l)/2;
    auto res = check(mid);

    ll range_L = res.first;
    if(res.second > 0){
        range_L = res.first - res.second + 1;
    }

    if(range_L <= need && need <= res.first){

        if(res.second > 0){
            ans = mid;
            break;
        }else{
            l = mid + 1;
        }
    }else if(range_L > need){
        r = mid - 1;
    }else{
        l = mid + 1;
    }
  }

  cout << ans << endl;

return 0;
}