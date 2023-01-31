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

// Problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=990


void setIO(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() { 

  setIO("berries");

  int n, k;
  cin >> n >> k;

  vector<int> v(n);
  for(int i = 0; i<n; i++){
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  map<int,int> mp;
  set<pair<int,int>> st;
  int cur_k;
  ll ans = 0;
  ll cur_ans;
  for(int x = 1; x <= 1000; x++){
    
    for(int j = n-1; j >= 0; j--){
        mp[x] += v[j] / x;
        mp[v[j] % x] += 1;
    }

    cur_k = 0;
    for(int i = 1000; i > 0; i--){
        if(mp[i] == 0) continue;
        
        if(cur_k + mp[i] <= k){
            cur_k += mp[i];
            st.insert(MP(i, mp[i]));
        }else{
            if(cur_k != k){
                st.insert(MP(i, k-cur_k));
                cur_k = k;
                break;
            }
        }
    }

    if(cur_k != k){
        st.clear();
        mp.clear();
        continue;
    }

    cur_k = 0;
    cur_ans = 0;
    for(auto it = st.begin(); it != st.end(); it++){
        auto p = *it;
        if(p.second + cur_k <= k/2){
            cur_k += p.second;
            cur_ans += 1LL * p.second * p.first;
        }else{
            if(cur_k == k/2){
                ans = max(ans, cur_ans);
            }else{
                cur_ans += 1LL * (k/2 - cur_k) * p.first; 
                ans = max(ans, cur_ans);
            }
            break;
        }
    }

    st.clear();
    mp.clear();
  }

  cout << ans << endl;

return 0;
}