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
#define N 200
typedef long long ll; 
using namespace std;

// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=668

vector<int> adj[N];
bool visited[N];

int ans = 0;
int cnt = 0;

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
	cnt++;
    
    for (auto u: adj[s]) {
        dfs(u);
    }
}

int main() { 

   freopen("moocast.in","r",stdin);
   freopen("moocast.out", "w", stdout); 

  int n;
  cin >> n;

  int x,y,r;
  vector<vector<int>> v(n);
  for(int i = 0; i<n; i++){
	cin >> x >> y >> r;
	v[i].push_back(x);
	v[i].push_back(y);
	v[i].push_back(r);
  }

  for(int i = 0; i<n; i++){
	for(int j = 0; j<n; j++){
		int x1 = v[i][0], y1 = v[i][1], r = v[i][2];
		int x2 = v[j][0], y2 = v[j][1];
		int difx = x1-x2;
		difx *= difx;
		int dify = y1-y2;
		dify *= dify;
		r *= r;

		if(difx + dify <= r){
			adj[i].push_back(j);
		}
	}
  }

  for(int i = 0; i<n; i++){
	cnt = 0;
	dfs(i);
	ans = max(ans, cnt);
	for(int j = 0; j<n; j++) visited[j] = 0;
  }


  cout << ans << endl;

return 0;
}