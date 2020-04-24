/// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define sc second
#define pii pair<ll,ll>
#define pb push_back
const ll mo = (ll)(1e9+7);
const ll N = (ll)(50005);

vector<ll> num;
ll a, b, d, k;
ll DP[12][12][2];

ll call(ll pos, ll cnt, ll f){
    if(cnt > k) return 0;

    if(pos == num.size()){
        if(cnt == k) return 1;
        return 0;
    }

    if(DP[pos][cnt][f] != -1) return DP[pos][cnt][f];
    ll res = 0;

    ll LMT;

    if(f == 0){
        LMT = num[pos];
    } else {
        LMT = 9;
    }
    for(ll dgt = 0; dgt<=LMT; dgt++){
        ll nf = f;
        ll ncnt = cnt;
        if(f == 0 && dgt < LMT) nf = 1;
        if(dgt == d) ncnt++;
        if(ncnt <= k) res += call(pos+1, ncnt, nf);
    }

    return DP[pos][cnt][f] = res;
}

ll solve(ll b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());

    memset(DP, -1, sizeof(DP));
    ll res = call(0, 0, 0);
    return res;
}

int main () {

    cin >> a >> b >> d >> k;
    ll res = solve(b) - solve(a-1);
    cout << res << endl;

    return 0;
}
