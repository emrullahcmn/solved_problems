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

// Problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=571

int belongto[100001];

int main() { 
 
  freopen("highcard.in", "r", stdin);
  freopen("highcard.out", "w", stdout);

  int n;
  cin >> n;

  int x;
  for(int i = 0; i<n; i++){
    cin >> x;
    belongto[x]++;
  }

  int elsie = 0;
  int ans = 0;
  for(int i = 1; i<= 2*n; i++){
    if(belongto[i]) elsie++;
    else{
        if(elsie > 0) ans++, elsie--;
    }
  }

  cout << ans << endl;

return 0;
}