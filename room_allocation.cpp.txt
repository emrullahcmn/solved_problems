// Problem : https://cses.fi/problemset/result/5180303/
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
 
struct Customer{
    int arr;
    int dep;
    int i;
};
 
bool operator<(const Customer &a, const Customer &b){
    if(a.arr == b.arr) return a.dep < b.dep;
    return a.arr < b.arr;
}
 
int main() { 
 
 
  int n;
  cin >> n;
  int a,d;
 vector<Customer> v;
  int ans[n]{0};
  for(int i = 0; i<n; i++){
    cin >> a >> d;
    v.push_back({a, d, i});
  }
  sort(v.begin(), v.end());
  
  set<pair<int,int>> st;
  
  st.insert({v[0].dep, 1});
  ans[v[0].i] = 1;
  int room = 1;
  int cur;
  for(int i = 1; i<n; i++){
    auto customer = v[i];
    auto it = st.lower_bound(MP(customer.arr, -1));
    
    if(it != st.begin()){
        it--;
        auto p = *it;
        cur = p.second;
        st.erase(it);
        st.insert(MP(customer.dep, cur));
        ans[customer.i] = cur;
    }else{
        room++;
        st.insert(MP(customer.dep, room));
        ans[customer.i] = room;
    }
  }
 
  cout << room << endl;
  for(int i = 0; i<n; i++){
    cout << ans[i] << " ";
  }
 
return 0;
}