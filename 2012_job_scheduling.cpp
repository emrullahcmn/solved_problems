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

// problem : https://oj.uz/problem/view/CEOI12_jobs

int n, d, m;

vector<pair<int,int>> vp;
vector<vector<int>> for_ans (100001);

void make_ans(int ans){
    int placed = 0;
    int i = 0;
    int day = 1;
    while(i < m){
        if(day >= vp[i].first && day <= vp[i].first + d){
            placed++;
            for_ans[day].push_back(++vp[i].second);
            if(placed == ans){
                if(i != m-1)
                    day++;
                placed = 0;
            }
        }else{
            day = vp[i].first;
            continue;
        }
        i++;
    }

    int j;
    for(int i = 1; i<=n; i++){
        j = 0;
        while(j < for_ans[i].size()){
            cout << for_ans[i][j] << " ";
            j++;
        }
        cout << 0 << endl;
    }
}

bool check(int x){
    int placed = 0;
    int i = 0;
    int day = 1;
    while(i < m){
        if(day >= vp[i].first && day <= vp[i].first + d){
            placed++;
            if(placed == x){
                if(i != m-1)
                    day++;
                placed = 0;
            }
        }else{
            if(day > vp[i].first + d){
                return false;
            }
            day = vp[i].first;
            placed = 0;
            continue;
        }
        i++;

    }

    if(day <= n){
        return true;
    }
    return false;
}

int main() { 
 
 #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt", "w", stdout); 
 #endif

  //code here

  cin >> n >> d >> m;
  int day;
  for(int i = 0; i<m; i++){
    cin >> day;
    vp.push_back(MP(day,i));
  }

  sort(vp.begin(), vp.end());

  int l = 1, r = 1e7, mid, ans;

  while(l<=r){
    mid = l + (r-l)/2;
    if(check(mid)){
        ans = mid;
        r = mid - 1;
    }else{
        l = mid + 1;
    }
  }

  cout << ans << endl;

  make_ans(ans);

return 0;
}