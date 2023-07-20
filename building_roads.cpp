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
#define N 100000
typedef long long ll; 
using namespace std;

// problem : https://cses.fi/problemset/task/1666

int n, m;
vector<int> adj[N];
bool visited[N];

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;

    for (auto u: adj[s]) {
        dfs(u);
    }
}


int main() { 

  cin >> n >> m;
  int x,y;
  
  for(int i = 0; i<m; i++){
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int components = 0;
  vector<int> comps;
  for(int i = 0; i<n; i++){
    if(visited[i]) continue;
    components++;
    comps.push_back(i);
    dfs(i);
  }

  cout << components - 1 << endl;
  for(int j = 1; j<comps.size(); j++){
      cout << comps[0] + 1 << " " << comps[j] + 1 << endl;
  }
  

return 0;
}