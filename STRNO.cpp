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
    	ll x, k; cin>>x>>k;
    	int chk=0;
        while(x%2==0){
            chk++;
            x/=2;
        }
        for(int i=3; i<=sqrt(x); i+=2){
            while(x%i==0){
                x/=i;
                chk++;
            }
        }
        if(x>2)
            chk++;
        
        if(!(chk<k))
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
}