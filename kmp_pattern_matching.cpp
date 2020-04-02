#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define fr first
#define sc second
const ll inf = (ll)1e18+7;
const ll mo = (ll)1000000007;
using namespace std;

// ll modexpo(ll a,ll b,ll c)
// {
// 	ll ret=1;
// 	while(b)
// 	{
// 		if(b&1)
// 		{
// 			ret=(ret*a)%c;
// 		}
// 		a=(a*a)%c;
// 		b>>=1;
// 	}
// 	return ret;
// }

vector<ll> v;
void computeLPSArray(ll pat[], ll m, ll lps[]) 
{ 
    ll len = 0; 
  
    lps[0] = 0; 
    ll i = 1; 
    while(i < m) { 
        if(pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else
        { 
            if(len != 0) { 
                len = lps[len - 1]; 
            } 
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}
void KMPSearch(ll pat[], ll txt[],ll m, ll n) 
{ 
    ll lps[m],i=0,j=0; ; 
    computeLPSArray(pat, m, lps); 

    while(i<n) { 
        if(pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
        if (j==m) { 
            v.push_back(i-j);
            j = lps[j - 1]; 
        }  
        else if (i<n && pat[j] != txt[i]) {
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		v.clear();
		ll i,n,x,m,ans=0;
		cin>>x;
		cin>>n;
		ll arr[n+1];
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		cin>>m;
		ll bob[m+1];
		for(i=0;i<m;i++)
		{
			cin>>bob[i];
		}
		if(n==1)
		{
			for(i=0;i<m;i++)
			{
				if(abs(bob[i]-arr[0])<=x)
				{
					ans++;
				}
			}
			cout<<ans<<endl;
			continue;
		}
		ll pat[n+1],txt[m+1];
		for(i=0;i<n-1;i++)
		{
			pat[i]=arr[i+1]-arr[i];
		}
		for(i=0;i<m-1;i++)
		{
			txt[i]=bob[i+1]-bob[i];
		}
		KMPSearch(pat,txt,n-1,m-1);

		for(i=0;i<v.size();i++)
		{
			// cout<<v[i]<<" ";
			if(abs( bob[v[i]] - arr[0] ) <= x)
			{
				ans++;
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}
