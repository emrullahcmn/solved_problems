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

// problem : https://codeforces.com/contest/1486/problem/D
 
int n, k;
 
vector<int> a;
 
bool check(int x){
 
    vector<int> prefix(n+1);
    prefix[0] = 0;
    for(int i = 1; i<=n; i++){
        prefix[i] = a[i] < x ? 1 : 0;
        prefix[i] += prefix[i-1];
    }
 
    vector<pair<int,int>> ind_to_val(n+1);
    set<pair<int,int>> st;
    for(int i = k; i<=n; i++){
        ind_to_val[i] = MP(2 * prefix[i] - i, i);
 
        st.insert(ind_to_val[i]);
    }
 
    pair<int,int> srch = {-1,-1};
    int cnt = k;
 
    for(int i = 1; n-k>=i-1; i++){
        srch.first = 2*prefix[i-1] - i + 2 - 1;
 
        auto it = st.lower_bound(srch);
 
        if(it == st.end() || it != st.begin()) return true;
        
        st.erase(ind_to_val[cnt]);
        cnt++;
        
    }
 
    return false;
}
 
int main() { 
 
  cin >> n >> k;
  int tmp;
  a.push_back(0);
  for(int i = 0; i<n; i++)
    cin >> tmp, a.push_back(tmp);
 
  int l = 0, r = 200000, mid, ans = -1;
  while(l<=r){
    mid = l + (r-l)/2;
    if(check(mid)){
        ans = mid;
        l = mid + 1;
    }else{
        r = mid - 1;
    }
  }
 
  cout << ans << endl;
 
 
return 0;
}