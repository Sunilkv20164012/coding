#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 200009;
const ll MAXlogN = 19;
ll ara[MAX];
ll A[MAX];
ll Log[MAX];
ll M[MAX][MAXlogN];
vector < pair < ll , ll > > perPos[MAX];
void buildSparse(ll n){
    for(ll i=1;i<=n;i++) M[i][0]=A[i];
    for(ll i=2;i<=n;i++) Log[i]=Log[i-1] + !(i&(i-1));
    for(ll j=1; (1<<j)<=n ;j++){
        for(ll i=1; (i+ (1<<j)-1) <=n; i++)
            M[i][j]=__gcd(M[i][j-1],M[i + (1<<(j-1))][j - 1]);
    }
}
ll Query(ll i,ll j){
    ll k=Log[j-i+1];
    return __gcd(M[i][k],M[j-(1<<k)+1][k]);
}
ll anss[MAX];
ll segtree[4 * MAX], lazy[4 * MAX];
void relax(ll node, ll beg, ll ed)
{
    segtree[node] += lazy[node] * (ed - beg + 1);
    if(beg != ed){
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
}
void update(ll node, ll beg, ll ed, ll i, ll j, ll val)
{
    if(lazy[node]) relax(node, beg, ed);
    if(beg > j || ed < i || beg > ed) return;
    if(beg >= i && ed <= j){
        lazy[node] += val;
        relax(node, beg, ed);
        return;
    }
    ll mid = (beg + ed) / 2;
    ll lft = 2 * node;
    ll rgh = lft + 1;
    update(lft, beg, mid, i, j, val);
    update(rgh, mid + 1, ed, i, j, val);
    segtree[node] = segtree[lft] + segtree[rgh];
}
ll query(ll node, ll beg, ll ed, ll i, ll j)
{
    if(lazy[node]) relax(node, beg, ed);
    if(beg > j || ed < i || beg > ed) return 0;
    if(beg >= i && ed <= j) return segtree[node];
    ll mid = (beg + ed) / 2;
    ll lft = 2 * node;
    ll rgh = lft + 1;
    ll p = query(lft, beg, mid, i, j);
    ll q = query(rgh, mid + 1, ed, i, j);
    return (p + q);
}
int main()
{
//    freopen("samplein01.txt", "r", stdin);
//    freopen("sampleout01.txt", "w", stdout);
    ll n, m;
    scanf("%lld %lld", &n, &m);
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &ara[i]);
        A[i] = ara[i];
    }
    for(ll i = 1; i <= m; i++){
        ll L, R;
        scanf("%lld %lld", &L, &R);
        perPos[L].push_back({R, i});
    }
    buildSparse(n);
    for(ll i = n; i >= 1; i--){
        for(ll j = i; j <= n; ){
            ll lo = j, hi = n;
            ll nxt = lo;
            while(lo <= hi){
                ll mid = (lo + hi) / 2;
                if(Query(i, mid) == Query(i, j)){
                    nxt = mid;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
            update(1, 1, n, j, nxt, Query(i, j));
            j = nxt + 1;
        }
        for(auto el : perPos[i]){
            ll l = i;
            ll r = el.first;
            ll id = el.second;
            anss[id] = query(1, 1, n, l, r);
        }
    }
    for(ll i = 1; i <= m; i++) printf("%lld\n", anss[i]);
    return 0;
}
/*
6 21
90 120 15 36 20 6
1 1
1 2
1 3
1 4
1 5
1 6
2 2
2 3
2 4
2 5
2 6
3 3
3 4
3 5
3 6
4 4
4 5
4 6
5 5
5 6
6 6
*/
