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
#define N 3000
typedef long long ll; 
using namespace std;

// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=644

vector<int> adj[N];
bool visited[N];
bool flag[N];

int n,m;
int cnt = 0;

void dfs(int s) {
    if (visited[s] || flag[s]) return;
    visited[s] = true;
    cnt++;

    for (auto u: adj[s]) {
        dfs(u);
    }
    return;
}

int main() { 
 
  freopen("closing.in","r",stdin);
  freopen("closing.out", "w", stdout);

  cin >> n >> m;

  int a,b;
  for(int i = 0; i<m; i++){
    cin >> a >> b;
    adj[a-1].push_back(b-1);
    adj[b-1].push_back(a-1);
  }

  dfs(0);
  if(cnt == n) cout << "YES" << endl;
  else cout << "NO" << endl;

  for(int i = 0; i<n; i++) visited[i] = 0;
  cnt = 0;

  int q;

  int k = n;
  for(int i = 0; i<n-1; i++){
    cin >> q;
    q--;
    flag[q] = 1;
    k--;
    cnt = 0;
    for(int i = 0; i<n; i++){
        if(flag[i] != 1){
            dfs(i);
            break;
        }
    }

    for(int i = 0; i<n; i++) visited[i] = 0;

    if(cnt == k){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
  }

  cin >> q;

return 0;
}