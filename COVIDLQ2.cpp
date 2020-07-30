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
    	ll n, x; cin>>n;
        int m=7;
        int a=-1;

        for(int i=0; i<n; i++){
            cin>>x;
            if(x==0){
                continue;
            }
            if(x==1 && a==-1){
                a=i;
            }
            if(x==1 && a!=-1){
                m=min(m, i-a);
                a=i;
            }
        }
    	
    	if(m>=6){
    		cout << "YES" << "\n";
    	}
    	else{
    		cout << "NO" << "\n";
    	}
    }
    return 0;
}