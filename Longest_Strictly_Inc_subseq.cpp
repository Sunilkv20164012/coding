#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define fr first
#define sc second
const ll inf = (ll)1e18+7;
const ll Mod = (ll)987654319;
using namespace std;
#define PI 3.14159265

ll Lis(vector<ll>& v)  
{  
    if (v.size() == 0)  
        return 0;  
  
    std::vector<ll> tail(v.size(), 0);  
    ll length = 1;
  
    tail[0] = v[0];  
      
    for (ll i = 1; i < v.size(); i++)
    {  
        auto b = tail.begin(), e = tail.begin() + length; 
        auto it = lower_bound(b, e, v[i]);  
              
        if (it == tail.begin() + length) 
        tail[length++] = v[i];  
        else   
        *it = v[i];  
    }
  
    return length;  
}
