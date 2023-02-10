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

//Problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=690

int n, T;
int a[10000];

void setIO(string name = ""){
    if(name == "") return;
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

bool possible(int gr){
    multiset<int> ms;
    for(int i = 0; i<gr; i++){
        ms.insert(a[i]);
    }
    if(ms.size() < gr){
        return *ms.rbegin() > T ? false : true;
    }

    for(int i = gr; i<n; i++){
        int x = *ms.begin();
        ms.erase(ms.find(x));
        ms.insert(x + a[i]);
    }

    return *ms.rbegin() > T ? false : true;
}


int main() { 

  setIO("cowdance");

  cin >> n >> T;

  for(int i = 0; i<n; i++){
    cin >> a[i];
  }

  int l = 0;
  int r = n;
  int mid;
  int ans = 0;
  while(l<=r){
    mid = l + (r-l)/2;
    if(possible(mid)){
        ans = mid;
        r = mid - 1;
    }else{
        l = mid + 1;
    }
  }

  cout << ans << endl;


return 0;
}