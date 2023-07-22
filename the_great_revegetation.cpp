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

// problem url : http://www.usaco.org/index.php?page=viewproblem2&cpid=920

vector<pair<int,char>> adj[N];
bool visited[N];
int cntTotal = 0;
int node_color[N];

void dfs(int n, char c, int color){
    visited[n] = true;
    if(c == 'n'){
        color = 1;
    }
    if(c == 'D')
        color = color == 1 ? 2 : 1;

    node_color[n] = color;
    cntTotal++;
    for(auto& pr : adj[n]){
        if(!visited[pr.first])
            dfs(pr.first, pr.second, color);
    }
}

void setIO(string name){
    if(name != ""){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() { 
 

  setIO("revegetate");

  //code here

  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> dif;
  vector<pair<int,int>> same;
  for(int i = 0; i<m; i++){
    int a, b;
    char c;
    cin >> c >> a >> b;
    a--, b--;
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});

    if(c == 'S') same.push_back({a,b});
    if(c == 'D') dif.push_back({a,b});
  }

  int connected = 0;
  for(int i = 0; i<n; i++){
    if(!visited[i]) dfs(i, 'n', 1), connected++;
  }

  bool ok = true;
  for(auto& p :dif){
    if(node_color[p.first] == node_color[p.second]){
        ok = false;
        break;
    }
  }
  for(auto& p :same){
    if(node_color[p.first] != node_color[p.second]){
        ok = false;
        break;
    }
  }

  if(!ok){
    cout << "0" << endl;
    return 0;
  }

  int willBePut = connected + n - cntTotal + 1;

  vector<int> ans(willBePut, 0);
  ans[0] = 1;
  for(auto& x:ans){
    cout << x;
  }

return 0;
}