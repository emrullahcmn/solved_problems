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

// Problem : https://codeforces.com/contest/1158/problem/A

int main() { 

  int n,m;
  cin >> n >> m;

  int tmp;
  vector<pair<int,int>> v;
  map<int,int> here;
  ll ans = 0;
  int mxa = -1;
  int mnb = 1e9;
  for(int i = 0; i<n; i++) cin >> tmp, here[tmp]++, v.push_back(MP(tmp, m-1)), ans += 1LL * m * tmp, mxa = max(mxa, tmp);
  
  int b[m];
  for(int i = 0; i<m; i++) cin >> b[i], mnb = min(mnb, b[i]);

  if(mxa > mnb){
    cout << -1 << endl;
    return 0;
  }

  sort(v.rbegin(), v.rend());
  sort(b, b+m);
  int j = 0;
  for(int i = m-1; i >= 0; i--){
    while(j < n && v[j].second < 1){
        j++;
    }

    if(here[b[i]]){
        break;
    }

    if(j == n){
            ans += b[i];
    }else{
        if(b[i] == v[j].first){
            break;
        }
        ans += b[i] - v[j].first;
        v[j].second--;
    }

  }

  cout << ans << endl;

return 0;
}