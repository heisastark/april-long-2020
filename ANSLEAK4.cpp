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
    	int n, m, k; scanf("%d%d%d", &n, &m, &k);
    	int arr[n][k];
    	//vector<int> ans;
    	for(int i=0; i<n; i++){
            //ll rowsum = 0;
    		for(int j=0; j<k; j++){
    			scanf("%d", &arr[i][j]);
    		}
    		ll medianindex;
    		if(k%2!=0) medianindex=(k+1)/2;
    		else medianindex=k/2;
    		cout << arr[i][medianindex-1] << " ";
    	}
    	cout << "\n";
    }
    return 0;
}