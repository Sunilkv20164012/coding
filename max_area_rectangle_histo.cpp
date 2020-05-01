#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = (ll)((1ll<<20)+5);

ll fun(ll arr[],ll n)
{
    ll ans=0,i=0,tp,max_area=0;
    stack<ll> st;
    while(i<n){
        if(st.empty() || arr[st.top()] <= arr[i]) 
            st.push(i++);
        else
        { 
            tp = st.top();  
            st.pop(); 
            ll area_with_top = arr[tp] * (st.empty() ? i : (i - st.top() - 1)); 
  
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    }
    while (!st.empty()) 
    { 
        tp = st.top(); 
        st.pop(); 
        ll area_with_top = arr[tp] * (st.empty() ? i : (i - st.top() - 1)); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    }
    return max_area;
}


int main () {
   
    ll t,T;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        ll i,j,r,c,k;
        cin>>r>>c>>k;
        ll v[r][c];

        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                cin>>v[i][j];
            }
        }
        ll mat[r][c];
        for(i=0;i<r;i++){
            map<ll,ll> mp;
            ll l=0;
            for(j=0;j<c;j++){

                mp[v[i][j]]++;
                while( (mp.rbegin()->first)-(mp.begin()->first)>k){
                    mp[v[i][l]]--;
                    if(mp[v[i][l]]==0){
                        mp.erase(v[i][l]);
                    }
                    l++;
                }
                // cout<<(j-l+1)<<endl;
                mat[i][j]=(j-l+1);
                // cout<<mat[i][j]<<" ";
            }
            // cout<<endl;
        }
        ll ans=0;
        for(j=0;j<c;j++){
            ll arr[r];
            for(i=0;i<r;i++)
            {
                arr[i]=mat[i][j];
            }
            // cout<<fun(arr,r)<<endl;
            ans = max(ans,fun(arr,r));
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
        

    }
    return 0;
}
