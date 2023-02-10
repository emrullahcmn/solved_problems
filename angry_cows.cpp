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

//Problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=594

int n, k;

bool check(vector<int> &v, int R){
    int i = 0, hand = 0;
    while(i<n){
        int x = v[i] + 2*R;
        hand++;
        auto it = upper_bound(v.begin(), v.end(), x);
        if(it == v.end()){
            break;
        }
        i = it - v.begin();
    }

    if(hand > k) return false;
    return true;
}

void setIO(string name = ""){
    if(name == "") return;
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() { 

  setIO("angry");

  cin >> n >> k;
  vector<int> v(n);

  for(int i = 0; i<n; i++){
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int l = 0, r = 1e9, mid, ans;
  while(l<=r){
    mid = l + (r-l)/2;
    if(check(v, mid)){
        ans = mid;
        r = mid - 1;
    }else{
        l = mid + 1;
    }
  }

  cout << ans << endl;


return 0;
}