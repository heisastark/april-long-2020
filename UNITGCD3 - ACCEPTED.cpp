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
    	int n;
        scanf("%d", &n);

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
            printf("%d\n", n/2);
            printf("3 1 2 3\n");
            int i = 4;

            if(n%2!=0){ 
                while(i<=n){
                    printf("2 %d %d\n", i, i+1);
                    i+=2;
                }
            }
            else{
                while(i<=n-1){
                    printf("2 %d %d\n", i, i+1);
                    i+=2;
                }
                printf("1 %d\n", n);
            }
        }
    }
    return 0;
}