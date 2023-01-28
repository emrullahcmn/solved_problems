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

// Problem: https://cses.fi/problemset/result/5370139/

int main() { 

  int x,n;
  cin >> x >> n;

  multiset<ll> ms;
  ll tmp;
  for(int i = 0; i<n; i++){
    cin >> tmp;
    ms.insert(tmp); 
  }

  ll ans = 0;
  while(ms.size() > 1){
    auto a = *ms.begin();
    auto b = *(++ms.begin());
    ans += a+b;
    ms.erase(ms.find(a));
    ms.erase(ms.find(b));
    ms.insert(a+b);
  }

  cout << ans << endl;

return 0;
}