// Problem :  https://cses.fi/problemset/result/5179875/
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
 
int main() { 
 
 
  ll x,n;
  cin >> x >> n;
  set<ll> lights;
  lights.insert(0); 
  lights.insert(x);
  multiset<ll> distances; 
  distances.insert(x);
  ll tmp;
  ll a,b;
  for(int i = 0; i<n; i++){
    cin >> tmp;
    lights.insert(tmp);
    auto it = lights.find(tmp);
    it++;
    a = *it;
    it--, it--;
    b = *it;
    distances.erase(distances.find(a-b));
    distances.insert(a-tmp);
    distances.insert(tmp-b);
    
    cout << *distances.rbegin() << " ";
  }
 
 
 
return 0;
}