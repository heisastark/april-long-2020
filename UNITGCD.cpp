#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define fin for(int i=0; i<n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000007

int main(){
	fast

    int t;
    scanf("%d", &t);
    while(t--){
    	ll n;
        scanf("%lld", &n);

    	if(n==1){
    		printf("1\n");
            printf("1 1\n");
    		continue;
    	}
    	if(n==2){
    		printf("1\n");
    		printf("2 1 2\n");
    		continue;
    	}
    	if(n==3){
    		printf("1\n");
    		printf("3 1 2 3\n");
    		continue;
    	}

    	if(n>=4){
            printf("%lld\n", n/2);
            printf("3 1 2 3\n");
            ll i = 4;
            while(i<=n){
                printf("%lld %lld\n", i, i+1);
                i+=2;
            }
        }
    }
    return 0;
}