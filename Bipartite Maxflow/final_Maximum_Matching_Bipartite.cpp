#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())

#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))

ll inf = (1<<29);

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 400000;
	vector<edge> E[MV];
	int itr[MV],lev[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	void bfs(int cur) {
		MINUS(lev);
		queue<int> q;
		lev[cur]=0;
		q.push(cur);
		while(q.size()) {
			int v=q.front(); q.pop();
			ITR(e,E[v]) if(e->cap>0 && lev[e->to]<0) lev[e->to]=lev[v]+1, q.push(e->to);
		}
	}
	V dfs(int from,int to,V cf) {
		if(from==to) return cf;
		for(;itr[from]<E[from].size();itr[from]++) {
			edge* e=&E[from][itr[from]];
			if(e->cap>0 && lev[from]<lev[e->to]) {
				V f=dfs(e->to,to,min(cf,e->cap));
				if(f>0) {
					e->cap-=f;
					E[e->to][e->reve].cap += f;
					return f;
				}
			}
		}
		return 0;
	}
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			bfs(from);
			if(lev[to]<0) return fl;
			ZERO(itr);
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
	}
};
MaxFlow_dinic<ll> mf;

class KuhnImplementation
{
public:
	ll n, k;
	vector < vector<ll> > g;
	vector<ll> pairs;
	vector<bool> used;
 
 
	bool kuhn (ll v) 
        {
		if (used[v])  return false;
		used[v] = true;
		for (ll i = 0; i < g[v].size(); ++i) 
                {
			ll to = g[v][i]-n;
			if (pairs[to] == -1 || kuhn (pairs[to])) 
                        {
				pairs [to] = v;
				return true;
			}
		}
		return false;
	}
 
	vector<pair<ll, ll> > find_max_matching(vector<vector<ll> > &_g, ll _n, ll _k) 
        {
		g = _g;
		n = _n;
		k = _k;
 
		pairs = vector<ll> (k, -1);
		//pairs[i] is a neighbor of vertex i from right part, on marked edge
		used = vector<bool> (n, false);
		for (ll i = 0; i < n; ++i) 
                {
			fill(used.begin(), used.end(), false);
			kuhn (i);
		}
	
		vector<pair<ll, ll> > res;
		for(ll i = 0; i < k; i++)
			if(pairs[i] != -1)
				res.push_back(make_pair(pairs[i], i+n));
 
		return res;
 
	}
};
KuhnImplementation kmf;



int main()
{
	ll i,j,n,m,x,y,k,b;
	cin>>n>>m>>b;
	bool mat[n][m];
	memset(mat,false,sizeof(mat));
	vector<pair<ll,ll> > v;
	for(i=0;i<b;i++)
	{
		cin>>x>>y;
		mat[x][y]=true;
		
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mat[i][j]==false && (i+j)%2==1 )
			{
				v.push_back(make_pair(i,j));
			}
		}
	}
	ll Nx=v.size();
	ll Ny=n*m-b-v.size();
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(mat[i][j]==false && (i+j)%2==0 )
			{
				v.push_back(make_pair(i,j));
			}
		}
	}
	vector<vector<ll> > g(Nx);
	for(i=0;i<Nx;i++)
	{
		for(j=Nx;j<Nx+Ny;j++)
		{
			if( (abs(v[i].first-v[j].first) + abs(v[i].second-v[j].second)) ==1){
				
				g[i].push_back(j);
			}
		}
	}
//	for(i=0;i<Nx;i++)
//	{
//		mf.add_edge(n*m+1,i,1);
//	}
//	for(i=Nx;i<Nx+Ny;i++)
//	{
//		mf.add_edge(i,n*m+2,1);
//	}

	ll rem=n*m-b;
	ll ret = kmf.find_max_matching(g, Nx, Ny).size();
	
	//cout<<ret<<endl;
	if(2*ret==rem)
	{
		cout<<"Yes\n";
	}
	else 
	{
		cout<<"No "<<(rem-2*ret)<<endl;
	}
		
	return 0;
}


