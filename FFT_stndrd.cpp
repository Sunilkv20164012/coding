#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define fr first
#define sc second
const ll inf = (ll)1e18+7;
const ll Mod = (ll)998244353;
using namespace std;

// ll modexpo(ll a,ll b)
// {
// 	ll ret=1;
// 	while(b)
// 	{
// 		if(b&1)
// 		{
// 			ret=(ret*a)%Mod;
// 		}
// 		a=(a*a)%Mod;
// 		b>>=1;
// 	}
// 	return ret;
// }


typedef complex<double> Comp;
 
vector<Comp> fft(vector<Comp> v, bool rev=false) {
	ll n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(ll k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(ll m=2; m<=n; m*=2) {
		double deg=(rev?-1:1) * 2*acos(-1)/m;             //PI=3.14... = acos(-1);
		Comp wr(cos(deg),sin(deg));
		for(i=0;i<n;i+=m) {
			Comp w(1,0);
			for(ll j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				Comp t1=v[j1],t2=w*v[j2];
				v[j1]=t1+t2, v[j2]=t1-t2;
				w*=wr;
			}
		}
	}
	if(rev) for(i=0;i<n;i++) v[i]*=1.0/n;
	return v;
}
 
vector<Comp> MultPoly(vector<Comp> P,vector<Comp> Q,bool resize=false) {
	if(resize) {
		ll maxind=0,pi=0,qi=0,i;
		ll s=2;
		for(i=0;i<P.size();i++) if(norm(P[i])) pi=i;
		for(i=0;i<Q.size();i++) if(norm(Q[i])) qi=i;
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		P.resize(s*2);Q.resize(s*2);
	}
	P=fft(P), Q=fft(Q);
	for(ll i=0;i<P.size();i++) P[i]*=Q[i];
	return fft(P,true);
}

int main()
{
	
}
