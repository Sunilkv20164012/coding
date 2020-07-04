/*
how many numbers x exist, such that number x occurs exactly x times among numbers in range [l,r].
*/

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

struct node {
	ll L, R, i;
}q[N];

ll BLOCK;

bool cmp(node x, node y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		return x.L/BLOCK<y.L/BLOCK;
	}
	return x.R < y.R;
}

ll a[100005],answer=0,ans[100005];
unordered_map<ll,ll> ans1;

void add(ll p){
	if(ans1[a[p]]==a[p])answer--;
	ans1[a[p]]++;
	if(ans1[a[p]]==a[p])answer++;
}
void remove(ll p){
	if(ans1[a[p]]==a[p])answer--;
	ans1[a[p]]--;
	if(ans1[a[p]]==a[p])answer++;
}
int main()
{//_
	ll n,m;
	cin>>n>>m;
	for(ll i=0; i<n; i++){
		cin>>a[i];
	}
	for(ll i=0; i<m; i++) {
		cin>>q[i].L>>q[i].R;
		q[i].L--; q[i].R--;
		q[i].i = i;
	}
	BLOCK=sqrt(n);
	sort(q, q + m, cmp);
	ll currentL = 0, currentR = -1;
	for(ll i=0; i<m; i++) {
		ll L = q[i].L, R = q[i].R;
		while(currentR < R) {
			add(currentR+1);
			currentR++;}
		while(currentR > R) {
			remove(currentR);
			currentR--;
		}
		while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		ans[q[i].i] = answer;
	}
	for(ll i=0; i<m; i++)
		cout<<ans[i]<<endl;	
}
