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

//Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=1038

int n, m;

bool check(vector<pair<ll,ll>> &vp, ll D){
    ll placed = 0;
    ll lst = -2e18;
    ll st;
    for(auto &p: vp){

        if(p.first - D >= lst){
            st = p.first;
        }else{
            st = lst + D;
        }
        
        while(st <= p.second){
            placed++;
            lst = st;
            if(placed == n) return true;
            st += D;
        }

    }

    return false;
}

void setIO(string name = ""){
    if(name == "") return;
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() { 
 
 
  setIO("socdist"); 

  cin >> n >> m;

  vector<pair<ll,ll>> vp(m);
  for(int i = 0; i<m; i++){
    cin >> vp[i].first >> vp[i].second;
  }

  sort(vp.begin(), vp.end());


  ll l = 1, r = 1e18, mid, ans;

  while(l<=r){
    mid = l + (r - l)/2;
    if(check(vp, mid)){
        ans = mid;
        l = mid + 1;
    }else{
        r = mid - 1;
    }
  }

  cout << ans << endl;

return 0;
}