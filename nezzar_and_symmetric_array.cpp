// Problem : https://codeforces.com/contest/1478/problem/C

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
 
int main() { 
 
  int t;
  cin >> t;
 
  while(t--){
 
    int n;
    cin >> n;
 
    ll tmp;
    set<ll> st;
    bool ok = true;
    map<ll,int> mp;
    for(int i = 0; i<2*n; i++){
        cin >> tmp;
        st.insert(tmp);
        mp[tmp]++;
        if(mp[tmp] > 2){
            ok = false;
        }
    }
 
    if(st.size() != n || ok == false){
        cout << "no" << endl;
        continue;
    }
    auto it = st.end();
    it--;
 
    ll factor = n*2;
    ll rest = 0;
    ll x;
    set<ll> unq;
    while(true){
        x = *it;
        if(factor <= 0){
            ok = false;
            break;
        }
        if((x - rest) % factor == 0){
            unq.insert((x-rest) / factor);
            rest += (x-rest) / factor*2;
            factor -= 2;
        }else{
            ok = false;
            break;
        }
        if(it == st.begin()){
            break;
        }
        it--;
    }
 
    if(!ok || *unq.begin() <= 0){
        cout << "no" << endl;
    }else if(ok && unq.size() == n){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
  }
 
return 0;
}