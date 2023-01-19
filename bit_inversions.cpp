//Problem : https://cses.fi/problemset/task/1188

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
 
set<pair<int, int>> zero_ranges;
set<pair<int, int>> one_ranges;
multiset<int> longest;

void remove_range(int x, set<pair<int,int>> &range){
  auto it = range.lower_bound(MP(x, -1));

  auto p = *it;
 
  int b = p.first;
  int a = p.second;
  range.erase(it);
  longest.erase(longest.find(b-a+1));

  if(a <= x-1){
    range.insert(MP(x-1, a));
    longest.insert(x-1 - a + 1);
  }
  if(x+1 <= b){
    range.insert(MP(b, x+1));
    longest.insert(b - (x+1) + 1);
  }
}

void add_range(int x, set<pair<int,int>> &range){
 
  if(range.size() == 0){
    range.insert(MP(x,x));
    longest.insert(1);
    return;
  }
 
  auto it = range.lower_bound(MP(x, -1));
 
  if(it == range.end()){
    it--;
    auto p = *it;
    if(p.first + 1 == x){
      int b = p.first;
      int a = p.second;
      longest.erase(longest.find(b-a+1));
      range.erase(it);
      range.insert(MP(b+1, a));
      longest.insert(b+1 - a + 1);
    }else{
      range.insert(MP(x, x));
      longest.insert(1);
    }
    return;
  }
 
  if(it == range.begin()){
    auto p = *it;
    if(p.second - 1 == x){
      int b = p.first;
      int a = p.second;
      longest.erase(longest.find(b-a+1));
      range.erase(it);
      range.insert(MP(b, a-1));
      longest.insert(b - (a-1) + 1);
    }else{
      range.insert(MP(x, x));
      longest.insert(1);
    }
    return;
  }
 
 
  auto p = *it;
  int b = p.first;
  int a = p.second;
  it--;
  p = *it;
  int c = p.first;
  int d = p.second; 
  
 if(c + 2 == a && c+1 == x){
    range.erase(MP(b,a));
    range.erase(MP(c,d));
    longest.erase(longest.find(b-a+1));
    longest.erase(longest.find(c-d+1));
    range.insert(MP(b,d));
    longest.insert(b-d+1);
    return;
  }
 
  if(x + 1 == a){
    range.erase(MP(b,a));
    longest.erase(longest.find(b-a+1));
    range.insert(MP(b,x));
    longest.insert(b-x+1);
    return;
  }
 
  if(c+1 == x){
    range.erase(MP(c,d));
    longest.erase(longest.find(c-d+1));
    range.insert(MP(x, d));
    longest.insert(x-d+1);
    return;
  }
 
  range.insert(MP(x, x));
  longest.insert(1);
   
}
 
int main() { 
 
  string s;
  cin >> s;
  int n = s.length();

  int m;
  cin >> m;
  int q[m];
  for(int i = 0; i<n; i++) cin >> q[i], q[i]--;
 
  int j = 0;
  for(int i = 0; i<n; i++){
    while(j < n && s[j] == s[i]){
      j++;
    }
    if(s[i] == '0') zero_ranges.insert(MP(j-1,i)), longest.insert(j-1-i+1);
    else one_ranges.insert(MP(j-1,i)), longest.insert(j-1-i+1);
    i = j-1;
  }

  for(int i = 0; i<m; i++){
    if(s[q[i]] == '0'){   
      add_range(q[i], one_ranges); 
      remove_range(q[i], zero_ranges);
      s[q[i]] = '1';
    }else{
      add_range(q[i], zero_ranges); 
      remove_range(q[i], one_ranges); 
      s[q[i]] = '0';
    }
 
    cout << *longest.rbegin() << " ";
  }
 
 
return 0;
}