#include <bits/stdc++.h> 
#include <set> 
#include <map> 
#include <unordered_map> 
#include <vector> 
#include <utility> //pair
#include <string>
#define PB push_back 
#define MP make_pair 
typedef long long ll; 
using namespace std;

// Problem : https://codeforces.com/contest/1000/problem/C

map<ll,ll> cnt;

int main() { 

  int n;
  cin >> n;

  map<ll,int> S; 
  map<ll,int> F; 

  ll a,b;
  set<ll> st;
  for(int i = 0; i<n; i++){
    cin >> a >> b;
    S[a]++;
    F[b]++;
    st.insert(a);
    st.insert(b);
  }

  ll active = 0;
  ll last = -1;
  ll x;
  for(auto it = st.begin(); it != st.end(); it++){
    x = *it;
    if(last == -1){
        last = x;
        cnt[S[x]]++;
        active = S[x] - F[x];
    }else{
        cnt[active] += x-last-1;
        active += S[x];
        cnt[active]++;
        active -= F[x];
        last = x;
    }
  }

  for(int i = 1; i<=n; i++){
    cout << cnt[i] << " ";
  }


return 0;
}