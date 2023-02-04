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

// Problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1158

int main() { 

  int k, m, n;
  cin >> k >> m >> n;

  vector<pair<ll,ll>> tastes(k);
  for(int i = 0; i<k; i++){
    cin >> tastes[i].first >> tastes[i].second;
  }
  tastes.push_back(MP(-1,0));

  vector<ll> cows(m);
  for(int i = 0; i<m; i++){
    cin >> cows[i];
    tastes.push_back(MP(cows[i], 0));     // cowları da taste 0 olarak ekledik.
  }

  sort(cows.begin(), cows.end());
  sort(tastes.begin(), tastes.end());

  for(int i = 1; i<tastes.size(); i++){
    tastes[i].second += tastes[i-1].second;
  }

  /* for(auto p : tastes){
    cout << "point : " <<p.first << " " << p.second << endl;
  } */

  vector<ll> possible;

  pair<ll,ll> srch = {0,0};
  // t t      cow    c c c c      cow          t t      yi ekle burada

  srch.first = cows[0];
  auto fst = lower_bound(tastes.begin(), tastes.end(), srch);

  possible.push_back((*fst).second);
  srch.first = cows[m-1];

  auto sec = lower_bound(tastes.begin(), tastes.end(), srch);
  possible.push_back((*tastes.rbegin()).second -  (*sec).second);

 //cout << "ilk taraf: " << possible[0] << " son taraf : " << possible[1] << endl;

  for(int i = 0; i+1<m; i++){
    srch.first = cows[i];
    auto sp = lower_bound(tastes.begin(), tastes.end(), srch);

    srch.first = cows[i+1];
    auto fnsh = lower_bound(tastes.begin(), tastes.end(), srch);

    // total value of the range
    ll tot = (*fnsh).second - (*sp).second;
    //cout << "TOT : " << tot << endl;
    sp++;

    // | sp                |    sp = a+1    fnsh = b
    //                    fnsh
    // sp = start point ve fnsh = finish 'in iteratorlerini bulduk suanda

    ll d = (cows[i+1] - cows[i])/2;
    ll mx = 0;
    for(auto it = sp; it < fnsh; it++){

        //cout << "0# it : " << (*it).first << " val : " << (*it).second << " d : " << d << endl;
        srch.first = min(cows[i+1], (*it).first + d);
        //cout << "1# Search : " << srch.first << endl;

        auto last_it = lower_bound(tastes.begin(), tastes.end(), srch);

        //cout << "2# Last_Found : " << (*last_it).first<< " val : " << (*last_it).second << endl;

        if( (*last_it).first > (*it).first + d ){
          last_it--;
          //cout << "3# AfterControl Last : " << (*last_it).first<< " val : " << (*last_it).second << endl;
        }



        if( (*last_it).first == (*it).first + d  
        && (cows[i] + cows[i+1])/2 == (cows[i] + cows[i+1])/(double)2 ){
          
          last_it--;
        }

        it--;
        if( (*last_it).second < (*it).second){
          it++;
          continue;
        }

        //cout << "4# mx_candidate : " << (*last_it).second - (*it).second << endl;
        mx = max(mx, (*last_it).second - (*it).second);
        it++;
    }

    possible.push_back(mx);
    possible.push_back(tot-mx);
    
  }

  sort(possible.rbegin(), possible.rend());

  ll ans = 0;
  for(int i = 0; i<possible.size(); i++){
    if(n != 0){
        ans += possible[i];
        n--;
    }
  }

  cout << ans << endl;

return 0;
}