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

//Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=858

int n,m,c;
int a[100000];

bool check(int maxt){

    int i = 0;
    int b = 0;
    int cows;
    int fst = -1;
    while(i<n){
        if(fst == -1){
            fst = a[i];
            cows = 1;
            b++;
        }else if(a[i] - fst > maxt || cows + 1 > c){
            b++;
            fst = a[i];
            cows = 1;
        }else{
            cows++;
        }
        i++;
    }

    if(b > m) return false;
    return true;
}

void setIO(string name = ""){
    if(name == "") return;
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

int main() { 

  setIO("convention");

  cin >> n >> m >> c;

  for(int i = 0; i<n; i++){
    cin >> a[i];
  }

  sort(a, a+n);

  int l = 0;
  int r = a[n-1] - a[0];
  int mid, ans = 0;

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


return 0;
}