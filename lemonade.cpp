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

// Problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=835

int main() { 
 
  freopen("lemonade.in","r",stdin);
  freopen("lemonade.out","w",stdout);


  int n;
  cin >> n;

  multiset<int> ms;
  int x;
  for(int i = 0; i<n; i++){
    cin >> x;
    ms.insert(x);
  }
  int ans = 0;
  while(ms.size() > 0){
    x = *ms.rbegin();
    if(ans <= x){
        ms.erase(ms.find(x));
        ans++;
    }else{
        break;
    }
  }

  cout << ans << endl;

return 0;
}