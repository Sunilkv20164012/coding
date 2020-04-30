#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = (ll)((1ll<<20)+5);

ll dp0[(1ll<<20)][22];
ll supermasks[(1ll<<20)];
ll arr[(1ll<<20)],brr[(1ll<<20)];

int main () {
   
    ll t,T;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        
        ll i,j,n,h,k;
        cin>>n>>h;
        ll a[n],b[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>b[i];
        }
        
        memset(arr,0,sizeof(arr));
        memset(brr,0,sizeof(brr));
        for(i=0;i<(1ll<<n);i++)
        {
            ll suma=0,sumb=0;
            for(ll k=0;k<n;k++)
            {
                if((i&(1ll<<k))>0){
                    suma+=a[k];
                    sumb+=b[k];
                }
            }
            if(suma>=h)arr[i]=1;
            if(sumb>=h)brr[i]=1;
        }
        

        memset(dp0,0,sizeof(dp0));
        memset(supermasks,0,sizeof(supermasks));

        supermasks[(1ll<<n)-1]=arr[(1ll<<n)-1];
        for(i=(1ll<<n)-2;i>=0;i--)
        {
            k=0;      // # 0 bits in i
            for(j=1<<(n-1); j>0; j>>=1){
                if((j&i)==0)
                    k++;
            }
            ll q,p;
            dp0[i][k] = arr[i];
            for(j=1<<(n-1); j>0; j>>=1){
                if((i&j)==0){
                    q = i|j;
                    break;
                }
            }

            for(j=j>>1, p=k-1; j>0 && p>0; j>>=1)          
            {
                if((i & j) == 0){
                    dp0[i][p] = dp0[i][p+1] + dp0[q][p]; 
                    p--;
                    q=i|j;
               }
            }
            supermasks[i] = arr[i];        
            for(j=1,p=0; j<(1ll<<n); j<<=1){
                if((i&j)==0){
                    if(p==0)
                        supermasks[i] += supermasks[i|j];
                    else
                        supermasks[i] += dp0[i|j][p];
                    p++;
                }
            }
        }
        ll ans=0;
        for(i=0;i<(1ll<<n);i++){
            // cout<<supermasks[i]<<" ";
            ans+=(brr[i]*(supermasks[ ((1ll<<n)-1)^i]));
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
        

    }
    return 0;
}
