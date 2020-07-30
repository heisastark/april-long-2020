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
    	vector<int> ans;
    	for(int i=0; i<n; i++){
    		for(int j=0; j<k; j++){
    			scanf("%d", &arr[i][j]);
    		}
    	}

    	for(int i=0; i<n; i++){
    		unordered_map<int,int> mp;
    		for(int j=0; j<k; j++){
    			mp[arr[i][j]]++;
    		}
    		int mode, fcount=0;
    		for(auto it: mp){
    			if(it.second>fcount)
    				{
    					fcount=it.second;
    					mode=it.first;
    				}
    		}
    		ans.pb(mode);
    	}

	for(int i=0; i<ans.size(); i++){
		if(i==ans.size()-1){
			break;
		}
		printf("%d ", ans[i]);
	}
	printf("%d\n", ans[ans.size()-1]);
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
