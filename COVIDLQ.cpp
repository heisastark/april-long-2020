#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define fin for(int i=0; i<n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 10000007

int main(){
	fast

    int t; cin>>t;
    while(t--){
    	ll n; cin>>n;
    	ll arr[n];
    	fin{
    		cin>>arr[i];
    	}
    	vector<ll> v;
    	fin{
    		if(arr[i]==1){
    			v.pb(i);
    		}
    	}
    	int min = INT_MAX;
    	for(int i=1; i<v.size(); i++){
    		if(min>(v[i]-v[i-1])){
    			min=v[i]-v[i-1];
    		}
    	}
    	if(min>=6){
    		cout << "YES" << "\n";
    	}
    	else{
    		cout << "NO" << "\n";
    	}
    }
    return 0;
}