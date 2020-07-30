#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define fin for(int i=0; i<n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vi vector<int>
#define MOD 1000000007
using namespace std;
const int sp = 100005;
unordered_map<int, int> mapp[sp];

void dfs(int x, int y, int n);
//void fun(int n);
void chk(int check, int n);
void compute(vi st);
void DFS(int x, int y, vi v);
vi AA[sp];
bool v[sp], matrix[sp];
int arr[sp];

void fun(int n){
	for(int i=1;i<=n;i++){
		AA[i].clear();
		matrix[i] = false;
		mapp[i].clear();
	}
}

int main(){
	fast
    int t; scanf("%d", &t);
    while(t--){
    int n; scanf("%d", &n);
	int x,y;
	fun(n);
	for(int i=0;i<n-1;i++){
		scanf("%d%d", &x, &y);
		AA[x].pb(y);
		AA[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		scanf("%d", &arr[i]);
	}
	int q; scanf("%d", &q);
	while(q--){
		scanf("%d%d", &x, &y);
		dfs(x, y, n);
	}
    }
    return 0;
}

void compute(vi st){
	unordered_map<int, int> sum;
	for(auto x : st){
		if(!matrix[x]){
			chk(arr[x], x);
		}
		if(mapp[x].size() == 0){
			continue;
		}
		for(auto it: mapp[x]){
			sum[it.first] += it.second;
		}
	}
	ll ans = (ll)1;
	for(auto x : sum){
		ans = (ans%MOD * ((ll)x.second + (ll)1)%MOD)%MOD;
	}
	cout<<ans;
}
void DFS(int x, int y, vector<int> st){ 
    st.push_back(x); 
    if (x == y) { 
        compute(st);  
    } 
    v[x] = true; 
    int mark = 0; 
    if (!AA[x].empty()) { 
        for(auto e : AA[x]) { 
            if (!v[e]) { 
                DFS(e, y, st); 
                mark = 1; 
            } 
        } 
    }
    if (mark == 0) { 
        st.pop_back(); 
    } 
} 
void dfs(int x, int y, int n){
    vi st;
    for(int i=1;i<=n;i++){
    	v[i] = false;
	}
    DFS(x, y, st);
    st.clear();
	cout<<"\n"; 
}

void chk(int bhalu, int n){
	while(bhalu%2==0){
		mapp[n][2]++;
		bhalu/=2;
	}
	for(int i=3;i<=sqrt(bhalu);i=i+2){
		while(bhalu%i==0){
			mapp[n][i]++;
			bhalu/=i;
		}
	}
	if(bhalu>2){
		mapp[n][bhalu]++;
	}
	matrix[n] = true;
}