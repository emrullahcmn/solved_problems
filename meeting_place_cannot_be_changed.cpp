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

// problem : https://codeforces.com/contest/782/problem/B
 
int n;
 
ll coords[60000];
ll vs[60000];
vector<pair<ll,ll>> vp;
 
bool check(double t){
 
    vector<pair<double,int>> vec;
    for(int i = 0; i<n; i++){
        vec.push_back(MP(vp[i].first - vp[i].second * t, 1));
        vec.push_back(MP(vp[i].first + vp[i].second * t, 2));
    }
    sort(vec.begin(), vec.end());
    int cur = 0;
    for(int i = 0; i<vec.size(); i++){
        auto p = vec[i];
        if(p.second == 1){
            cur++;
            if(cur == n){
                return true;
            }
        }else{
            cur--;
        }
    }
    return false;
}
 
int main() { 
 
  cin >> n;
 
  for(int i = 0; i<n; i++) cin >> coords[i];
  for(int i = 0; i<n; i++) cin >> vs[i];
  for(int i = 0; i<n; i++) vp.push_back(MP(coords[i], vs[i]));
  sort(vp.begin(), vp.end());
 
  double l = 0, r = 1e9, ans, mid;
  double e = 1e-6;
  while(r-l > e){
    mid = l + (r-l)/2;
    if(check(mid)){
        ans = mid;
        r = mid;
    }else{
        l = mid;
    }
  }
 
  printf("%.12f", ans);
 
 
return 0;
}