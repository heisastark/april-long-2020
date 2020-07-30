#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define fin for(int i=0; i<n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

int main(){
	fast

    int t; cin>>t;
    while(t--){
    	ll n; cin>>n;
        vector<ll> v;
        for(int i=0; i<n; i++){
            ll x; cin>>x;
            v.pb(x);
        }
        sort(v.begin(), v.end());
        
        vector<ll> ans;
        for(int i=0; i<n; i++){
            if(v[n-1-i]-i>0)
                ans.pb(v[n-1-i]-i);          
        }
        ll res=0;
        for(auto x: ans){
            res+=x;
        }

        cout << res%mod << "\n";
    }
    return 0;
}