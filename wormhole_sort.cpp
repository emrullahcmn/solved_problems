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

//problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=992

vector<pair<int,int>> adj[N];
int pos_of[N];
int n, m;
bool visited[N];

vector<int> visited_nodes;
vector<int> numbers_here;

void dfs(int s, int width, int limit) {
    if (visited[s] || width < limit) return;

    visited[s] = true;
    visited_nodes.push_back(s);
    numbers_here.push_back(pos_of[s]);
    
    for (auto p: adj[s]) {
        dfs(p.first, p.second, limit);
    }
    
}

bool check(int x){
    for(int i = 0; i<n; i++) visited[i] = false;
    for(int i = 0; i<n; i++){
        if(visited[i]) continue;
        visited_nodes.clear();
        numbers_here.clear();
        dfs(i, 1e9, x);
        sort(visited_nodes.begin(), visited_nodes.end());
        sort(numbers_here.begin(), numbers_here.end());
        for(int i = 0; i<visited_nodes.size(); i++){
            if(visited_nodes[i] != numbers_here[i]){
                return false;
            }
        }
    }

    return true;
}

int main() { 

 freopen("wormsort.in","r",stdin);
 freopen("wormsort.out", "w", stdout); 

  cin >> n >> m;

  int tmp;
  for(int i = 0; i<n; i++){
    cin >> tmp;
    pos_of[i] = tmp - 1; 
  }

  int forbs[m];

  int from, to, width;
  for(int i = 0; i<m; i++){
    cin >> from >> to >> width;
    forbs[i] = width;
    from--, to--;
    adj[from].push_back({to, width});
    adj[to].push_back({from, width});
  }

  bool ok = true;
  for(int i = 0; i<n; i++){
    if(pos_of[i] != i){
        ok = false;
        break;
    }
  }

  if(ok){
    cout << -1 << endl;
    return 0;
  }

  sort(forbs, forbs+m);

  int l = 0, r = m-1, mid, ans = -1;

  while(l<=r){
    mid = l + (r-l)/2;
    if(check(forbs[mid])){
        ans = forbs[mid];
        l = mid + 1;
    }else{
        r = mid - 1;
    }
  }

  cout << ans << endl;
return 0;
}