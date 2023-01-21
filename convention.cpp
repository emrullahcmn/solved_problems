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

int eating_time[100000];
int arriving_time[100000];
int n;
int lastIndex;


bool cmp(const pair<int,int> &x, const pair<int,int> &y) {
    if(x.first == y.first) y.second > x.second;
    return x.first < y.first;
}
void detectWaiting(vector<pair<int,int>> &v, set<int> &waiting, int finish, pair<int,int> &pr){
    if(lastIndex > n-1){
        return;
    }

    for(int i = lastIndex; i<v.size(); i++){
        if(v[i].first > pr.first){
            break;
        }
        if(v[i].first < pr.first || (v[i].first == pr.first && v[i].second >= pr.second)){
            lastIndex++;
            continue;
        }
        if(v[i].first == pr.first && v[i].second < pr.second){
            break;
        }
    }

    if(lastIndex > n-1){
        return;
    }

    for(auto i = lastIndex; i < v.size(); i++){
        auto p = v[i];
        if(p.first > finish) { break; }
        if(p.first <= finish){
            waiting.insert(p.second);
            lastIndex++;
        }
    }
}

int main() { 
 
  freopen("convention2.in","r",stdin);
  freopen("convention2.out", "w", stdout); 

  cin >> n;

  int a, t;

  vector<pair<int,int>> v;
  lastIndex = 0;

  for(int i = 0; i<n; i++){
    cin >> a >> t;
    v.push_back({a, n-i-1});
    eating_time[n-i-1] = t;
    arriving_time[n-i-1] = a;
  }

  sort(v.begin(), v.end(), cmp);


  set<int> waiting;
  int time = 0;

  int ans = 0;
  pair<int,int> myp = {-1,-1};
  while(lastIndex < n || waiting.size() > 0){
    if(waiting.size() == 0){
        auto it = lower_bound(v.begin(), v.end(), MP(time, -1));

        int start = (*it).first;
        int ind = (*it).second;
        int finish = start + eating_time[ind];
        pair<int,int> prnow = {start,ind};
        detectWaiting(v, waiting, finish, prnow);
        time = finish;
        continue;
    }
    
    int ind = *waiting.rbegin();
    ans = max(ans, time - arriving_time[ind]);

    waiting.erase(ind);

    time += eating_time[ind];
    detectWaiting(v, waiting, time, myp);
  }

  cout << ans << endl;

return 0;
}