#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long int
#define F first
#define S second
#define mod 1000000007
#define Max 200005
const int LG = 20;


int main()
{
	ll n,m,i,j,ans=0;
	cin>>n>>m;
	map<ll,vector<ll> > h,v;
	map<ll,set<pair<ll,ll> > > dd,db;
	string s[n];

	for(j=0;j<m;j++)
	{
		v[j].push_back(-1);
	}
	for(i=0;i<n;i++)
	{
		h[i].push_back(-1);
		cin>>s[i];		
		for(j=0;j<s[i].length();j++)
		{
			if(s[i][j]=='R'||s[i][j]=='B'||s[i][j]=='Q')
			{
				h[i].push_back(j);
				v[j].push_back(i);
				dd[i+j].insert({i,j});
				db[i-j].insert({i,j});
			}
		}
		h[i].push_back(m);
	}
	for(j=0;j<m;j++)
	{
		v[j].push_back(n);
	}
	for(auto p:dd)
	{
		if(p.first<=m-1)
			{
				dd[p.first].insert({-1,0});
				dd[p.first].insert({p.first+1,0});
			}
		else
			{
				dd[p.first].insert({p.first-m,0});
				dd[p.first].insert({n,0});
			}
	}
	for(auto p:db)
	{
		if(p.first<0)
			{
				db[p.first].insert({-1,0});
				db[p.first].insert({p.first+m,0});
			}
		else	
			{
				db[p.first].insert({p.first-1,0});
				db[p.first].insert({n,0});
			}
	}
	// for(auto p:db)
	// {
	// 	for(auto x:db[p.first])
	// 	{
	// 		cout<<x.first<<" ";
	// 	}
	// 	cout<<endl;
	// }
	for(i=0;i<n;i++)
	{
		for(j=0;j<s[i].length();j++)
		{
			if(s[i][j]=='R'||s[i][j]=='Q')
			{
				ll li = lower_bound(h[i].begin(),h[i].end(),j)-h[i].begin();
				ans += h[i][li+1]-1-h[i][li-1]-1;

				ll vi = lower_bound(v[j].begin(),v[j].end(),i)-v[j].begin();
				ans += v[j][vi+1]-1-v[j][vi-1]-1;

			}
			if(s[i][j]=='B'||s[i][j]=='Q')
			{
				set<pair<ll,ll> >::iterator itu,itl,it=dd[i+j].lower_bound({i,j});
				itu = it;itu--;
				itl = it;itl++;
				ans+= (itl->first-1 -itu->first-1);

				it=db[i-j].lower_bound({i,j});
				itu = it;itu--;
				itl = it;itl++;
				ans+= (itl->first-1 -itu->first-1);
			}
		}
	}
	cout<<ans<<endl;
	return 0 ;
}
