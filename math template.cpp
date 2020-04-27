#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define sc second
#define pii pair<ll,ll>
#define pb push_back
const ll mo = (ll)(1e9+7);
const ll N = (ll)(1000005);

ll modexpo(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)
        {
            res=(res*a)%mo;
        }
        a=(a*a)%mo;
        b>>=1;
    }
    return res;
}

ll fact[N],invf[N];
// ll C[20][20];
void init() {
    ll i;
    fact[0]=1;
    for(i=1;i<N;i++)
    {
        fact[i]=(fact[i-1]*i)%mo;
    }
    invf[N-1]=modexpo(fact[N-1],mo-2);

    for(i=N-2;i>=0;i--)
    {
        invf[i]=(invf[i+1]*(i+1))%mo;
    }

//     for(ll i=0;i<=18;i++) C[i][0]=1;
//     for(ll i=0;i<=18;i++) 
//         for(ll j=1;j<=i;j++) 
//             C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo; 
}

ll ncr(ll n,ll r)
{
    if(n<0||r<0||r>n)
        return 0;
    ll ret = fact[n];
    ret=(ret*invf[r])%mo;
    ret=(ret*invf[n-r])%mo;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin>>t;
    init();

    while(t--){
        
    }
    return 0;
}
