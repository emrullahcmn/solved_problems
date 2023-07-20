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

// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=944

vector<int> adj[N];
bool visited[N];
vector<vector<int>> pos(N);

int maxX;
int maxY;
int minX;
int minY;

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    maxX = max(pos[s][0], maxX);
    minX = min(pos[s][0], minX);
    maxY = max(pos[s][1], maxY);
    minY = min(pos[s][1], minY);

    for (auto u: adj[s]) {
        dfs(u);
    }
}

int main() { 

  freopen("fenceplan.in", "r", stdin);
  freopen("fenceplan.out", "w", stdout);

  int n,m;
  cin >> n >> m;;
  int x,y;
  for(int i = 0; i<n; i++){
    cin >> x >> y;
    pos[i].push_back(x);
    pos[i].push_back(y);
  }

  for(int i = 0; i<m; i++){
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int ans = 1e9;
  for(int i = 0; i<n; i++){
    if(visited[i]) continue;
    maxX = maxY = -1;
    minX = minY = 1e9;
    dfs(i);

    ans = min(ans, 2*(maxX - minX) + 2*(maxY - minY)); 
  }

  cout << ans << endl;

return 0;
}