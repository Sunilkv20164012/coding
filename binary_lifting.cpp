#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define fr first
#define sc second
const ll inf = (ll)1e18+7;
const ll mo = (ll)1000000007;
#define N 1000006
using namespace std;


vector<ll> prime;
ll minp[N];
void seive(ll n)
{
	memset(minp,0,sizeof(minp));
	for(ll i=2;i<=n;i++)
	{
		if(minp[i]==0)
		{
			prime.push_back(i);
			for(ll j=i;j<=n;j+=i)
			{
				minp[j]=i;
			}
		}
	}
	return;
}

vector<ll> g[N];
ll a[N], lvl[N], P[N][22];

void dfs(ll u, ll par){
    lvl[u] = 1+lvl[par];
    P[u][0] = par;
	for(ll i=0;i<g[u].size();i++){
		ll v=g[u][i];
		if (v == par) continue;
		dfs(v, u);
	}
}

ll lca(ll u, ll v){
    ll i, lg;
    if (lvl[u] < lvl[v]) swap(u, v);

    for(lg = 0; (1<<lg) <= lvl[u]; lg++);
    lg--;

    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= lvl[v])
            u = P[u][i];
    }

    if (u == v)
    	return u;

    for(i=lg; i>=0; i--){
        if (P[u][i] != -1 and P[u][i] != P[v][i])
            u = P[u][i], v = P[v][i];
    }

    return P[u][0];
}

ll getAncestor(ll u, ll dis){
    dis = lvl[u] - dis;
    ll i, lg = 0;
    for(; (1<<lg) <= lvl[u]; lg++); lg--;

    for(i=lg; i>=0; i--){
        if (lvl[u] - (1<<i) >= dis)
            u = P[u][i];
    }

    return u;
}

ll dis(ll u, ll v){
    if (lvl[u] < lvl[v]) swap(u, v);
    ll w = lca(u, v);
    return lvl[u] + lvl[v] - 2*lvl[w];
}

int main()
{
	ll t;
	cin>>t;
	seive(1000000);
	while(t--)
	{
		ll i,j,n,q,u,v;
		cin>>n;
		ll arr[n+1];
		for(i=0;i<n-1;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		for(i=0;i<21;i++){
			for(j=0;j<n+1;j++){
				P[j][i]=-1;
			}
		}
		lvl[0] = -1;

		dfs(1, 0);

		for(i=1; i<21; i++){
	      for(j=1;j<n+1;j++){
	         if (P[j][i-1] != -1)
	          P[j][i] = P[P[j][i-1]][i-1];
	      }
		}
		cin>>q;
		while(q--)
		{
			cin>>u>>v;
			cout<<(lca(u,v))<<endl;
		}
	}
	return 0;
}
