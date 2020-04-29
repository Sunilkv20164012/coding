#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define sc second
#define pii pair<ll,ll>
#define pb push_back
const ll mo = (ll)(1e9+7);
const ll N = (ll)(1000007);

ll mind[N],a[N];
pair<ll, ll> mins[N];
vector<pair<ll, ll> > divs;

void build_sieve() {
    vector<ll> pr;
    mind[0] = mind[1] = 1;
    for (ll i = 2; i < N; ++i) {
        if (mind[i] == 0) {
            pr.push_back(i);
            mind[i] = i;
        }
        for (ll j = 0; j < (ll)pr.size() && pr[j] <= mind[i] && i * pr[j] < N; ++j) {
            mind[i * pr[j]] = pr[j];
        }
    }
}

// void add_to_mins(int curd, int idx) {
//     if(mins[curd].first == -1)
//         mins[curd].first = idx;
//     else if(mins[curd].second == -1)
//         mins[curd].second = idx;
// }

void rec(ll pos, ll curd, ll idx) {   /// generate all the divisors recursively and stores in curd var
    if (pos == (ll)divs.size()) {
        // add_to_mins(curd, idx);
        return;
    }
    ll curm = 1;
    for (ll i = 0; i <= divs[pos].second; ++i) {
        rec(pos + 1, curd * curm, idx);
        curm *= divs[pos].first;
    }
}

void add(ll idx) {     // stores powers of primes and recursively calls for all divisors
    ll value = a[idx];
    divs.clear();
    while (value > 1) {
        ll d = mind[value];
        if (!divs.empty() && divs.back().first == d) {
            ++divs.back().second;
        } else {
            divs.push_back(make_pair(d, 1));
        }
        value /= d;
    }
    rec(0, 1, idx);
}

int main () {

    ll i,n;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    build_sieve();

    // for( i = 0; i < N; i++)
    //     mins[i] = make_pair(-1, -1); // stores two indexes having divisor i

    // vector<pair<ll, ll> > vals;      //array sorted
    // for( i = 0; i < n; i++)
    //     vals.push_back(make_pair(a[i], i));

    sort(vals.begin(), vals.end()); 
    reverse(vals.begin(), vals.end());

    for ( i = 0; i < n; ++i) {
        // if(i > 1 && vals[i].first == vals[i - 2].first) continue;
        add(vals[i].second);
    }

    return 0;
}
