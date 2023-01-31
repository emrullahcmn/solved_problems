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

 // problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=573

int b[100001];

void setIO(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() { 

 setIO("cardgame");

  int n;
  cin >> n;
  int x;
  vector<int> v1;
  vector<int> v2;
  for(int i = 0; i<n; i++){
    cin >> x;
    if(v1.size() < n/2){
        v1.push_back(x);
    }else
        v2.push_back(x);
    b[x]++;
  }

  for(int i = 2*n; i > 0; i--){
    if(!b[i]){
        if(v1.size() < n)
            v1.push_back(i);
        else
            v2.push_back(i);
    }
  }

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  int ans = 0;
  int keep = 0;
  for(int y : v1){
    if(b[y]){
        keep++;
    }else{
        if(keep > 0){
            keep--;
            ans++;
        }
    }
  }

  keep = 0;
  for(int y : v2){
    if(!b[y]){
        keep++;
    }else{
        if(keep > 0){
            keep--;
            ans++;
        }
    }
  }

  cout << ans << endl;


return 0;
}