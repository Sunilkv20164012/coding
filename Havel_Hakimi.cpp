#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr first
#define sc second
#define Mod (ll)(1e9+7)


bool cmp(int a, int b) { return a > b; }
ll deg[200005];
ll sum, n, left_sum[200005];

ll search(ll L, ll R, ll k) {
    ll rs = L - 1;
    while (L <= R) {
        ll mid = (L + R) >> 1;
        if (deg[mid] >= k) {
            rs = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    return rs;
}
 
bool solve() {
    if (sum & 1) return false;
    sort(deg + 1, deg + n + 1, cmp);
    left_sum[n + 1] = 0;
    for (ll i = n; i >= 1; i--)
        left_sum[i] = left_sum[i + 1] + deg[i];
    ll left = 0, right;
    for(ll k=1;k<=n;k++){
        ll p = search(k + 1, n, k);
        //cout<<p<<" ";
        left += deg[k];
        right = k * (p - 1) + left_sum[p + 1];
        if (left > right) return false;
    }
    return true;
}

int main()
{
	ll i,k;
	cin>>n>>sum;
	set<pair<ll,ll> > st;
	for(i=1;i<=n;i++)
	{
		cin>>deg[i];
		st.insert({deg[i],i});
	}
	vector<pair<ll,ll> > v;
	
	bool ans = solve();
	
	if(ans==false)
	{
		cout<<"No\n";
	}
	else
	{
		cout<<"Yes\n";
		set<pair<ll,ll> >::iterator itf;
		while(!st.empty())
		{
			set<pair<ll,ll> >::reverse_iterator it=st.rbegin();
			
			ll l=(it->first);
			it++;
			vector<pair<ll,ll> > temp;
			for(i=0;it!=st.rend()&&i<l;it++,i++)
			{
				temp.push_back({it->first,it->second});
				v.push_back({st.rbegin()->second,it->second});
			}
			for(i=0;i<temp.size();i++)
			{
				itf = st.find({temp[i].first,temp[i].second});
				st.erase(itf);
				if(temp[i].first-1>0)
				st.insert({temp[i].first-1,temp[i].second});
			}
			itf=st.end();
			itf--;
			st.erase(itf);
		}
		cout<<v.size()<<endl;
		for(i=0;i<v.size();i++)
		{
			cout<<v[i].first<<" "<<v[i].second<<endl;
		}
	}
	return 0;
}









