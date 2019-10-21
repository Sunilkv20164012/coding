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

ll Lis(ll a[],ll n)
{
	vector<ll> d;
	for (ll i=0;i<n;i++)
	{
        ll x=a[i];
        vector<ll>::iterator it = upper_bound(d.begin(), d.end(), x);
        if (it == d.end()) d.push_back(x);
        else *it = x;
    }
    return d.size();
}
