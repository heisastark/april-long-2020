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
        ll v[n]; 
        vector<ll> index;

        for(ll i=0; i<n; i++){
            cin>>v[i];
            if(v[i]%4==2 || v[i]%4==-2){
                index.pb(i);
            }
        }

        ll ans = (n*(n+1))/2;
        

        for(auto x: index){
            ll l=0, r=0;
            //check left odd contiguous elements
            ll i=x-1, j=x+1;
            while(v[i]%2 && i>=0){
                i--;
                l++;
            }
            //check right odd contiguous elements
            while(v[j]%2 && j>=0){
                j++;
                r++;
            }
            ans-=((l+1)*(r+1));
        }
        
        cout << ans << "\n";
        
    }

    return 0;
}