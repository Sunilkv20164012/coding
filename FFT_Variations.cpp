#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define fr first
#define sc second
const ll inf = (ll)1e18+7;
const ll Mod = (ll)2e5+10;
using namespace std;
#define PI 3.14159265
#define N 100005

vector<ll> fft(vector<ll> v, bool rev=false) {
	ll n=v.size(),i,j,m;
	
	for(ll m=2; m<=n; m*=2) {
		for(i=0;i<n;i+=m) {
			for(ll j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				ll t1=v[j1],t2=v[j2];
				v[j1]=t1+t2;
				v[j2]=t1-t2;
			}
		}
	}
	if(rev) {
		for(i=0;i<n;i++) v[i]/=n;
	}
	return v;
}
vector<ll> MultPoly(vector<ll> P,vector<ll> Q,bool resize=false) {
	P=fft(P), Q=fft(Q);
	for(ll i=0;i<P.size();i++) P[i]*=Q[i];
	return fft(P,true);
}

vector<ll> fft2(vector<ll> v, bool rev=false) {
	ll n=v.size(),i,j,m;
	
	for(ll m=2; m<=n; m*=2) {
		for(i=0;i<n;i+=m) {
			for(ll j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				ll t1=v[j1],t2=v[j2];
				
				if(!rev) {
					v[j1]=t2;
					v[j2]=(t1+t2)%Mod;
				}
				else {
					v[j1]=(t2-t1+Mod)%Mod;
					v[j2]=t1;
				}
				
			}
		}
	}
	return v;
}
vector<ll> MultPoly2(vector<ll> P,vector<ll> Q,bool resize=false) {
	P=fft2(P), Q=fft2(Q);
	for(ll i=0;i<P.size();i++) P[i]*=Q[i];
	return fft2(P,true);
}

vector<ll> fft3(vector<ll> v, bool rev=false) {
	ll n=v.size(),i,j,m;
	
	for(ll m=2; m<=n; m*=2) {
		for(i=0;i<n;i+=m) {
			for(ll j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				ll t1=v[j1],t2=v[j2];
				
				if(!rev) {
					v[j2]=(t1+t2)%Mod;
				}
				else {
					v[j2]=(t2-t1+Mod)%Mod;
				}
				
			}
		}
	}
	return v;
}
vector<ll> MultPoly3(vector<ll> P, vector<ll> Q ,bool resize=false) {
	P=fft3(P), Q=fft3(Q);
	for(ll i=0;i<P.size();i++) P[i]*=Q[i];
	return fft3(P,true);
}
ll freq[1<<18];
int main()
{

	ll i,n;
	cin>>n;
	ll arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		freq[arr[i]]++;
	}

	vector<ll> D[4],v;

	for(i=0;i<1<<17;i++){
		v.push_back(freq[i]);
	}
	D[0]=MultPoly(v,v);    //D[0] is for Xor convolution
	D[1]=MultPoly2(v,v);   //D[1] is for And convolution
	D[2]=MultPoly3(v,v);   //D[2] is for Or convolution

	for(i=0;i<3;i++)
	{
		for(ll j=0;j<=20;j++)
		{
			cout<<D[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
