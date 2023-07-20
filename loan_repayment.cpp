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

//problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=991

ll n, k, m;

bool check(ll x){

    ll spend = 0;
    ll days = 0;
    ll give;
    ll givefordays;
    while(days < k && spend < n){
        give = (n - spend) / x;
        if(give <= m){
            days += ceil((n - spend) / (double)m);
            spend += ceil((n - spend) / (double)m) * m;
            break;
        }

        givefordays = min(((n-spend) - (x*give))/give + 1, k-days);
        spend += givefordays * give;
        days += givefordays;
    }


    if(days <= k && spend >= n){
        return true;
    }
    return false;

}

int main() { 
 
/*  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt", "w", stdout); 
 #endif */
 freopen("loan.in", "r", stdin);
  freopen("loan.out", "w", stdout);

  //code here

  cin >> n >> k >> m;

/*   check(2);
  return 0; */

  ll l = 2, r = 1e12;
  ll mid, ans = 1;

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