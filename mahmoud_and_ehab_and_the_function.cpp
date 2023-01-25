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

// Problem: https://codeforces.com/contest/862/problem/E

int main() { 
 
  int n, m, q;
  cin >> n >> m >> q;

  ll a[n];
  for(int i = 0; i<n; i++) cin >> a[i];
  ll b[m];
  for(int i = 0; i<m; i++) cin >> b[i];

  vector<pair<int,int>> queries(q);
  ll qval[q];

  for(int i = 0; i<q; i++){
    cin >> queries[i].first >> queries[i].second >> qval[i];
    queries[i].first--;
    queries[i].second--;
  }

  ll suma = 0;
  for(int i = 0; i<n; i++){
    if(i % 2 == 0) suma += a[i];
    else suma -= a[i];
  }

  ll pref_zero[m];
  ll pref_one[m];
  pref_zero[0] = b[0];
  pref_one[0] = 0;

  for(int i = 1; i<m; i++){
    if(i % 2 == 0){
        pref_zero[i] = pref_zero[i-1] + b[i];
        pref_one[i] = pref_one[i-1]; 
    }else{
        pref_one[i] = pref_one[i-1] + b[i];
        pref_zero[i] = pref_zero[i-1];
    }
  }

  int k = m-n; 

  set<ll> negatives;
  set<ll> pozitives;

  ll cur;

  for(int i = 0; i<=k; i++){
    if(i == 0){
        cur = suma - 1 * (pref_zero[i+n-1]) + (pref_one[i+n-1]);
    }else if(i % 2 == 0){
        cur = suma - 1 * (pref_zero[i+n-1] - pref_zero[i-1]) + (pref_one[i+n-1] - pref_one[i-1]);
    }else{
        cur = suma - 1 * (pref_one[i+n-1] - pref_one[i-1]) + (pref_zero[i+n-1] - pref_zero[i-1]);
    }

    if(cur < 0) 
        negatives.insert(cur);
    else if(cur > 0)
        pozitives.insert(cur);
    else
        pozitives.insert(cur), negatives.insert(cur);
    }

  ll cumul = 0;
  ll mn = 1e18;

  if(pozitives.size() > 0){
      ll pozG = *pozitives.rbegin();
      ll pozS = *pozitives.begin();
      mn = min(mn, min(abs(pozG + cumul), abs(pozS + cumul)));
  }
  
  if(negatives.size() > 0){
      ll negG = *negatives.rbegin();
      ll negS = *negatives.begin();
      mn = min(mn, min(abs(negG + cumul), abs(negS + cumul)));
  }

  cout << mn << endl;

  for(int i = 0; i<q; i++){
    mn = 1e18;
    auto &range = queries[i];
    auto val = qval[i];

    if(range.first == range.second){
        if(range.first % 2 == 0){
            cumul += val;
        }else{
            cumul -= val;
        }
    }else if(range.first % 2 == range.second % 2){
        if(range.first % 2 == 0){
            cumul += val;
        }else{
            cumul -= val;
        }
    }

    if(negatives.size() > 2){
        auto it = negatives.lower_bound(-cumul);
        if(it == negatives.end()){
            it--;
            mn = min(mn, abs(*it + cumul));
            it--;
            mn = min(mn, abs(*it + cumul));
        }else{
            if(it != negatives.begin()){
                mn = min(mn, abs(*it + cumul));
                it--;
                mn = min(mn, abs(*it + cumul));
            }
        }
    }

    if(pozitives.size() > 2){
        auto it = pozitives.lower_bound(-cumul);
        if(it == pozitives.end()){
            it--;
            mn = min(mn, abs(*it + cumul));
            it--;
            mn = min(mn, abs(*it + cumul));
        }else{
            if(it != pozitives.begin()){
                mn = min(mn, abs(*it + cumul));
                it--;
                mn = min(mn, abs(*it + cumul));
            }
        }
    }

    if(pozitives.size() > 0){
        ll pozG = *pozitives.rbegin();
        ll pozS = *pozitives.begin();
        mn = min(mn, min(abs(pozG + cumul), abs(pozS + cumul)));
    }
    
    if(negatives.size() > 0){
        ll negG = *negatives.rbegin();
        ll negS = *negatives.begin();
        mn = min(mn, min(abs(negG + cumul), abs(negS + cumul)));
    }

    cout << mn << endl;
  }

return 0;
}