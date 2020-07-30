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
            ll rowsum = 0;
    		for(int j=0; j<k; j++){
    			scanf("%d", &arr[i][j]);
                rowsum+=arr[i][j];
    		}
            int mean = rowsum/k;
            cout << mean << " ";
    	}
        cout << "\n";
    }
    return 0;
}

/*1            
7 3 3
1 2 3
2 3 1
3 1 2
1 2 3
2 3 1
3 1 2
1 2 3*/