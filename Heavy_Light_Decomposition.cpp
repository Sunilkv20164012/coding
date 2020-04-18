/*
  Here hld is used to find max value in the path from u to v.
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
const ll mo = (ll)1000000007;
#define N 1000006
using namespace std;

#define pb push_back
#define mp make_pair
#define double long double
#define F first
#define S second


ll n, m;
vector<ll> g[N];
ll val[N];
ll nxt[N], size[N], p[N], depth[N];
ll chain[N], num[N], csz[N], top[N], baseArray[N] ;
ll all=1, cnt = 1;
ll st[400005];
ll arr[N];

void build(ll v, ll tl, ll tr)
{
	if(tl==tr){
		st[v]=baseArray[tl];
	}
	else{
		ll tm = (tl+tr)/2;
		build(2*v,tl,tm);
		build(2*v+1,tm+1,tr);
		st[v]=max(st[2*v],st[2*v+1]);
	}
	return;
}
void upd(ll v, ll tl, ll tr, ll pos, ll d){
  if(tl == tr){
    st[v] += d;
    return;
  }
  ll tm = (tl + tr)/2;
  if(pos <= tm) upd(2*v, tl, tm, pos, d); 
  else
    upd(2*v+1, tm + 1, tr, pos, d);
  st[v] = max(t[2*v], t[2*v+1]);
}

ll go(ll v, ll tl, ll tr, ll l, ll r){
	if(l > tr || r < tl){
		return 0;
	}
	if(l <= tl && r >= tr){
		return st[v];
	}
	ll tm = (tl + tr)/2;

	return max(go(2*v,tl,tm,l,r), go(2*v+1,tm+1,tr,l,r));
}

void dfs(ll v, ll pr){
	p[v] = pr;
	size[v] = 1;
	for(auto to:g[v]){
		if(to == pr){
		 	continue;
		}
		depth[to] = depth[v] + 1;
		dfs(to, v);
		size[v] += size[to];
		if(nxt[v] == -1 || size[to] > size[nxt[v]]){
		 	nxt[v] = to;
		}
	}
	return;
}

void hld(ll v, ll pr){
	chain[v] = cnt;
	baseArray[all]=arr[v];
	num[v] = all++;
	if(!csz[cnt]){
		top[cnt] = v;
	}
	++csz[cnt];
	if(nxt[v] != -1){
		hld(nxt[v], v);
	}
	for(auto to:g[v]){
		if(to == pr || to == nxt[v]){
	  		continue;
		}
		++cnt;
		hld(to, v);
	}
	return;
}

ll go(ll a, ll b){

	ll res=0;
	while(chain[a] != chain[b]){
		
		if(depth[top[chain[a]]] < depth[top[chain[b]]]) swap(a, b);
		ll start = top[chain[a]];
		res +=  go(1,1,n,num[start],num[a]);
		a = p[start];
	}
	if(depth[a] > depth[b]) 
		swap(a, b);
	res +=  go(1,1,n, num[a], num[b]);
	return res;
}

int main() {

	ll t;
	cin>>t;
	while(t--)
	{
		ll i;
		cin>>n;
		all=1,cnt=1;
		for(i=0;i<=n;i++)
		{
			g[i].clear();
			csz[i]=0;
		}
		for(i=1;i<n;i++){
			ll a, b; 
			cin>>a>>b;
			g[a].pb(b); 
			g[b].pb(a);
		}
		for(i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		memset(nxt, -1, sizeof nxt);
		dfs(1,-1);
		hld(1,-1);
		build(1,1,n);
		cin>>m;
		while(m--){
			ll a, b;
			cin>>a>>b;
			ll ans = go(a, b);
			cout<<ans<<endl;
		}
	}
	return 0;
}
