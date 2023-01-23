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

//Problem : https://codeforces.com/contest/1474/problem/C
 
int main() { 
 
  int t;
  cin >> t;
 
  while(t--){
    int n;
    cin >> n;
    n *= 2;
    vector<pair<int,int>> v;
    vector<pair<int,int>> ans;
    set<pair<int,int>> st;
    
    int a[n];
    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
 
    sort(a, a+n);
    for(int i = 0; i<n; i++){
        v.push_back(MP(a[i],i));
        st.insert(MP(a[i],i));
    }
 
 
    int last;
    bool ok = false;
    for(int i = 0; i<n-1; i++){
        last = (*st.rbegin()).first;
        ans.push_back(MP(v[n-1].first, v[i].first));
        
        st.erase(v[i]);
        st.erase(v[n-1]);
 
        while(!st.empty()){
            int x = (*st.rbegin()).first;
            int y = last - x;
            st.erase(--st.end());
            auto it = st.lower_bound(MP(y, -1));
            if(it == st.end() || (*it).first > y){
                break;
            }
            
            ans.push_back(MP(x,y));
            st.erase(it);
            last = x;
        }
 
        if(ans.size() == n/2){
            ok = true;
            break;
        }
 
 
        ans.clear();
 
        for(int k = 0; k<n; k++){
            st.insert(v[k]);
        }
 
    }
    if(ok){
        cout << "YES" << endl;
        cout << ans[0].first + ans[0].second << endl;
        for(auto &i : ans){
            cout << i.first << " " << i.second << endl;
        }
        continue;
    }
    cout << "NO" << endl;
 
  }
 
return 0;
}