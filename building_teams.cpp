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
#define N 100001
typedef long long ll; 
using namespace std;

// problem url : https://cses.fi/problemset/task/1668/

vector<int> adj[N];
bool visited[N];
int a[N];

void dfs(int n, int color){
  visited[n] = true;
  color = color == 1 ? 2 : 1;
  a[n] = color;
  for(auto node : adj[n]){
    if(!visited[node])
      dfs(node, color);
  }
}

int main() { 
 
 #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt", "w", stdout); 
 #endif

  //code here 
  int n, m;
  cin >> n >> m;

  int x, y;

  bool possible = true;

  vector<pair<int,int>> vp;
  for(int i = 0; i<m; i++){
    cin >> x >> y;
    x--, y--;
    vp.push_back({x,y});
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for(int i = 0; i<n; i++){
    if(!visited[i])
      dfs(i, -1);  
  }

  bool ok = true;
  for(auto p : vp){
    if(a[p.first] == a[p.second]){
      cout << "IMPOSSIBLE" << endl;
      ok = false;
      break;
    }
  }

  if(ok)
    for(int i = 0; i<n; i++) cout << a[i] << " ";

return 0;
}