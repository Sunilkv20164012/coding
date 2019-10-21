#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define pb push_back
#define fr first
#define sc second
const ll inf = (ll)1e18+7;
const ll Mod = (ll)987654319;
using namespace std;
#define PI 3.14159265


ll getSum(ll BITree[], ll index) 
{ 
    ll sum = 0;
    index = index + 1; 
    while (index>0) 
    {
        sum += BITree[index];
        if(sum>=Mod)sum-=Mod; 
        index -= index & (-index); 
    } 
    return sum; 
} 

void updateBIT(ll BITree[], ll n, ll index, ll val) 
{ 
    index = index + 1; 
    while (index <= n) 
    { 
	    BITree[index] += val;
	    if(BITree[index]>=Mod)BITree[index]-=Mod; 
	    index += index & (-index); 
    } 
} 
