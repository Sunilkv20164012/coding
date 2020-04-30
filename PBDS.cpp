#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = (ll)((1ll<<20)+5);

#include <ext/pb_ds/assoc_container.hpp>// Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less

using namespace __gnu_pbds;
// a new data structure defined. Please
// refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<ll, null_type, less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main () {

    ordered_set X;
   
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    cout<<*X.find_by_order(1)<<endl; // 2
    cout<<*X.find_by_order(2)<<endl; // 4
    cout<<*X.find_by_order(4)<<endl; // 16
    cout<<(end(X)==X.find_by_order(6))<<endl; // true

    cout<<X.order_of_key(-5)<<endl;  // 0
    cout<<X.order_of_key(1)<<endl;   // 0
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5
    return 0;
}
