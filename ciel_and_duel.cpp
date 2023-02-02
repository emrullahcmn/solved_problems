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
 
// Problem: https://codeforces.com/contest/321/problem/B
ll ans = 0;
 
void match(vector<int> &attack, vector<int> &fox, bool ok){
    ll cur = 0;
    int k = attack.size();
    int m = fox.size();
 
    multiset<int> fox_keep;
    multiset<int> attack_keep;
    vector<int> removed;
 
    if(k == 0 && ok && fox.size() > 0){
        for(int i = 0; i<fox.size(); i++){
            cur += fox[i];
        }
        ans = max(cur, ans);
        cur = 0;
    }
 
    int i = m-1;
    int j = 0;
    while(i > -1 && j < k){
        cur = 0;
        fox_keep.insert(fox[i]);
        attack_keep.insert(attack[j]);
 
        for(auto q = attack_keep.begin(); q != attack_keep.end(); q++){
            auto it = fox_keep.lower_bound(*q);
            if(it != fox_keep.end()){
                removed.push_back(*it);
                int r = *it;
                int w = *q;
                cur += 1LL * r - w;
                fox_keep.erase(fox_keep.find(*it));
            }else{
                break;
            }
        }
        i--;
        j++;
 
        if(j == k && fox_keep.size() == 0 && ok){
            for(int a = 0; a < m-k; a++){
                cur += fox[a];
            }
        } 
        ans = max(ans, cur);
        for(int &a : removed) fox_keep.insert(a);
        removed.clear();
    }
 
}
 
int main() { 
 
  int n,m;
  cin >> n >> m;
 
  vector<int> attack;
  vector<int> defense;
  string s;
  int x;
  for(int i = 0; i<n; i++){
    cin >> s >> x;
    if(s == "ATK") attack.push_back(x);
    else defense.push_back(x);
  }
 
  vector<int> fox;
  for(int i = 0; i<m; i++){
    cin >> x;
    fox.push_back(x);
  }
 
  sort(attack.begin(), attack.end());
  sort(defense.begin(), defense.end());
  sort(fox.begin(), fox.end());
 
  int cnt = 0;
  
  match(attack, fox, (cnt == defense.size() ? true : false));
 
  for(int i = 0; i<defense.size(); i++){
    auto it = lower_bound(fox.begin(), fox.end(), defense[i] + 1);
    if(it == fox.end()){
        break;
    }else{
        cnt++;
        fox.erase(it);
    }
  }
 
  match(attack, fox, (cnt == defense.size() ? true : false));
  
  cout << ans << endl;
 
  return 0;
}