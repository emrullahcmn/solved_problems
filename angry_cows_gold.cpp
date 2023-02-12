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

// Problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=597

int n;
vector<ll> v;

string checkInner(ll x, ll R){

    ll forl = x;
    ll rad = R;
    bool left = false, right = false;
    auto it = lower_bound(v.begin(), v.end(), forl-rad);

    while(it != v.begin() && it != v.end()){
        if(*it == forl) break;
        forl = *it;
        rad -= 2;
        it = lower_bound(v.begin(), v.end(), forl-rad);
    }

    if(it == v.begin()){
        left = true;
    }

    ll forr = x;  
    rad = R;   
    it = lower_bound(v.begin(), v.end(), forr + rad);

    while(it != v.end()){
        if(*it > forr + rad){
            it--;
            if(*it == forr){
                break;
            }
        }

        forr = *it;
        rad -= 2;
        if(rad == 0){
            if(it == --v.end()) right = true;
            break;
        }
        it = lower_bound(v.begin(), v.end(), forr + rad);
    }

    if(it == v.end()){
        right = true;
    }

    if(left && right) return "ok";

    if(left == false) return "go_left";

    return "go_right";
}

bool check(ll R){
    ll l = v[0], r = v[n-1], mid;
    while(l<=r){
        mid = l + (r-l)/2;
        string res = checkInner(mid, R);

        if(res == "ok"){
            return true;
        }else if(res == "go_left"){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }

    return false;
}

int main() { 
 
  freopen("angry.in","r",stdin);
  freopen("angry.out", "w", stdout); 

  cin >> n;
  ll a;
  for(int i = 0; i<n; i++)
    cin >> a, v.push_back(2*a);
  
  sort(v.begin(), v.end());

  ll l = 0, r = 2e9;
  ll mid, ans;

  while(l<=r){
    mid = l + (r-l)/2;
    if(check(mid)){
        ans = mid;
        r = mid - 1;
    }else{
        l = mid + 1;
    }
  }

  printf("%.1f\n", ans / 2.0);  


return 0;
}