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

// Problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=714

void setIO(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() { 

  setIO("helpcross");
  
  int c,n;
  cin >> c >> n;

  multiset<int> ms;
  int x,y;
  for(int i = 0; i<c; i++) cin >> x, ms.insert(x);
  
  vector<pair<int,int>> v;
  for(int i = 0; i<n; i++) cin >> x, cin >> y, v.push_back(MP(x,y));

  sort(v.begin(), v.end());

  int ans = 0;
  for(int i = n-1; i >= 0 && ms.size() > 0; i--){
    x = v[i].first;
    y = v[i].second;

    auto it = ms.lower_bound(y);

    if(it == ms.end()) it--;
    else{
        if(it == ms.begin() && *it > y){
            continue;
        }else{
            if(*it > y)
                it--;
        }
    }

    if(*it >= x){
        ms.erase(ms.find(*it));
        ans++;
    }
  }

  cout << ans << endl;

return 0;
}