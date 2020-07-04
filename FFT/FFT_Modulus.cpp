#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define fr first
#define sc second
const ll inf = (ll)1e18+7;
const ll mo = (ll)998244353;
using namespace std;
 
ll modexpo(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
		{
			ret=(ret*a)%mo;
		}
		a=(a*a)%mo;
		b>>=1;
	}
	return ret;
}
 
ll getRoot()
{
    ll prims[] = {2, 7, 17};              // for 998244353 - 1 which is 2^23,7^1,17^1 ;
    for (ll i = 2; ; i++) {
        bool ok = true;
        for (ll j = 0; j < 3 && ok; j++)
            ok = modexpo(i, (mo - 1) / prims[j]) != 1;
        if (ok) return i;
    }
}
 
vector<ll> fft(vector<ll> v, bool rev=false) {
	ll n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(ll k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
 
	ll c = getRoot();
 
	for(ll m=2; m<=n; m*=2) {
		ll wn=modexpo(5,(mo-1)/m);					//	double ang = 2*PI/len * (rev?-1:+1); Comp wlen (cos(ang), sin(ang));
		if(rev) wn=modexpo(wn,mo-2);
 
		for(i=0;i<n;i+=m) {
			ll w=1;
			for(ll j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				ll t1=v[j1],t2=w*v[j2]%mo;
				v[j1]=t1+t2;
				v[j2]=t1+mo-t2;
				while(v[j1]>=mo) v[j1]-=mo;
				while(v[j2]>=mo) v[j2]-=mo;
				w=w*wn%mo;
			}
		}
	}
	if(rev) {
		ll rv = modexpo(n,mo-2);
		for(i=0;i<n;i++) v[i]=v[i]*rv%mo;
	}
	return v;
}
 
vector<ll> MultPoly(vector<ll> P,vector<ll> Q,bool resize=false) {
	if(resize) {
		ll maxind=0,pi=0,qi=0,i;
		ll s=2;
		for(i=0;i<P.size();i++) if(P[i]) pi=i;
		for(i=0;i<Q.size();i++) if(Q[i]) qi=i;
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		P.resize(s*2);Q.resize(s*2);
	}
	P=fft(P), Q=fft(Q);
	for(ll i=0;i<P.size();i++) P[i]=P[i]*Q[i]%mo;
	return fft(P,true);
}
 
vector<ll> modexpop(vector<ll> a,ll b)
{
	vector<ll> ret(1,1);
	while(b)
	{
		if(b&1)
		{
			ret=MultPoly(ret,a,true);
		}
		a=MultPoly(a,a,true);
		b>>=1;
	}
	return ret;
}
