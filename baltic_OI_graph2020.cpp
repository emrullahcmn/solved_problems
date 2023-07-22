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
#define N 200000 
typedef long long ll; 
using namespace std;

// problem url : https://codeforces.com/contest/1387/status

vector<pair<int, int>> adj[N];
bool visited[N];
double node_values[N];
vector<int> currently_visited;
vector<set<pair<int,int>>> v(N);
set<int> nodes_having_2;
bool compatible = true;
 
void dfs(int n, bool loop, int c, double currentVal, double factor, double cnst){
 
    visited[n] = true;
    currently_visited.push_back(n);
 
    if(loop){
        currentVal = c - currentVal;
        node_values[n] = currentVal;
    }else{
        if(factor == 0){
            factor = 1;
            cnst = 0;
        }else{
            factor *= -1;
            cnst = c - cnst;
        }
        v[n].insert({factor, cnst});
        if(v[n].size() > 2){
            compatible = false;
            return;
        }
 
        if(v[n].size() == 2){
            nodes_having_2.insert(n);
        }
    }
 
    for(auto& p : adj[n]){
        if(!visited[p.first])
            dfs(p.first, loop, p.second, currentVal, factor, cnst);
        else{
            if(!loop){
                v[p.first].insert({-1*factor, p.second-cnst});
                if(v[p.first].size() > 2){
                    compatible = false;
                    return;
                }
                if(v[p.first].size() == 2){
                    nodes_having_2.insert(p.first);
                }
            }
        }
    }
 
}
 
 
int main() { 
 
  int n, m;
  cin >> n >> m;
 
  vector<pair<int, pair<int,int>>> input;
 
  map<pair<int,int>, int> mp;
  bool ok = true;
  vector<pair<int,int>> loops;
  for(int i = 0; i<m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
 
    input.push_back({a, {b, c}});
 
    if(a == b){
        loops.push_back({a, c});
    }
 
    adj[a].push_back({b, c});
    adj[b].push_back({a, c});
 
    int val = mp[MP(min(a,b), max(a,b))];
    if(val != 0 && c != val){
        ok = false;
    }else{
        mp[MP(min(a,b), max(a,b))] = c;
    }
  }
 
  if(!ok){
    cout << "NO" << endl;
    return 0;
  }
 
  for(auto& p : loops){
      if(!visited[p.first]){
          dfs(p.first, true, p.second, p.second / (double)2, 0, 0);
      }
  }
 
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            compatible = true;
            nodes_having_2.clear();
            currently_visited.clear();
            dfs(i, false, 0, 0, 0, 0); 
 
            if(!compatible){
                cout << "NO" << endl;
                return 0;
            }
 
            double x = 0;
            if(nodes_having_2.size() > 0){
                
                int nodeNum = *(nodes_having_2.begin());
                auto& pair1 = *(v[nodeNum].begin());
                auto& pair2 = *(++v[nodeNum].begin());
                x = (pair2.second - (double)pair1.second) / (pair1.first - (double)pair2.first);
                for(auto& node : currently_visited){
                    node_values[node] = (*v[node].begin()).first * x + (*v[node].begin()).second;
                }
            }else{
 
                vector<int> numbers;
                for(auto& node : currently_visited){
                    auto& pr = *(v[node].begin());
                    if(pr.first < 0){
                        numbers.push_back(pr.second);
                    }else{
                        numbers.push_back(-pr.second);
                    }
                }
 
               sort(numbers.begin(), numbers.end());
 
               double x;
               if(numbers.size() == 1){
                x = numbers[0];
               }else{
                if(numbers.size() % 2 == 0){
                    x = (numbers[numbers.size() / 2] + numbers[numbers.size() / 2 - 1]) / 2.0;
                }else{
                    x = numbers[numbers.size() / 2];
                }
               }
 
                for(auto& node : currently_visited){
                    auto& pr = *(v[node].begin());
                    node_values[node] = pr.first*x + pr.second;
                }
            }
 
        }
    }
 
    for(auto& p : input){
        auto& p2 = p.second;
        if(node_values[p.first] + node_values[p2.first] != p2.second){
            cout << "NO" << endl;
            return 0;
        }
    }
 
    cout << "YES" << endl;
    for(int i = 0; i<n; i++){
        cout << node_values[i] << " ";
    }
    cout << "\n";
 
 
return 0;
}