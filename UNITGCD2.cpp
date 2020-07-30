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

    	if(n>=4){
            printf("%d \n", n/2);
            printf("3 1 2 3");
    		ll i = 4;
    		while(i<=n){
    			printf("%d %d", i, i+1);
    			i+=2;
    		}
    	}
    	else{
    		cout << 1 << "\n";
    		cout << n << " ";
    		while(n){
    			cout << n << " ";
    			n--;
    		}
            cout << "\n";
    	}
    }
    return 0;
}