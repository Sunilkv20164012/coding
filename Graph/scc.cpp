#include<bits/stdc++.h>
using namespace std;
#define ll long long int

set<ll> g[200006];
set<ll> gr[200006];
stack<ll> st;
bool visited[200006];
ll comp[200006];

void dfs1(ll v,set<ll> g[])
{
	visited[v]=true;
	set<ll>::iterator it;
	for(it=g[v].begin();it!=g[v].end();it++)
	{
		if(visited[*it]==false)
		{
			dfs1(*it,g);
		}
	}
	st.push(v);
}
void dfs2(ll v,set<ll> g[],ll c)
{
	visited[v]=true;
	set<ll>::iterator it;
	comp[v]=c;
	for(it=g[v].begin();it!=g[v].end();it++)
	{
		if(visited[*it]==false)
		{
			dfs2(*it,g,c);
		}
	}
}
int main()
{
	ll n,k,i,u,v,w;
	cin>>n>>k;
	ll arr[n],brr[n];
	memset(visited,false,sizeof(visited));
	
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>brr[i];
	}
	for(i=0;i<n-1;i++)
	{
		g[arr[i]].insert(arr[i+1]);
		g[brr[i]].insert(brr[i+1]);
		
		gr[arr[i+1]].insert(arr[i]);
		gr[brr[i+1]].insert(brr[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(visited[i]==false)
		{
			dfs1(i,g);
		}
	}
	ll c=1;
	memset(visited,false,sizeof(visited));
	while(!st.empty())
	{
		ll source=st.top();
		st.pop();
		if(visited[source])continue;
		else dfs2(source,gr,c++);
	}
	c--;
	if(k>(c)){
		cout<<"No\n";
		return 0;
	}
	cout<<"YES\n";
	map<ll,char> mp;
	for(i=1;i<=c;i++)
	{
		if(i<=k) mp[i]=i+'a'-1;
		else mp[i]=k+'a'-1;
	}
	for(i=1;i<=n;i++)
	{
		cout<<(mp[comp[i]]);
	}
	cout<<endl;
	return 0;
	
}

