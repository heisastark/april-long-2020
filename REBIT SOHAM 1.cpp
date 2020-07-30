#include<bits/stdc++.h>
#define ll long long int
#define db double
#define pb push_back
#define fin for(int i=0; i<n; i++)
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define MOD 998244353
using namespace std;
ll power(ll x, ll y, ll p){ 
    ll res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or 
                // equal to p 
  
    while (y > 0){ 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
ll modInverse(ll n, ll p){ 
    return power(n, p-2, p); 
} 
int main(){
	FASTIO;
    int t;
    scanf("%d", &t);
    while(t--){
        string s; cin>>s;
        //vector<int> v1{1,1,1,1}, v2{1,1,1,1}, v{0,0,0,0};
        ll v1[4],v2[4],v[4];
        for(int i=0; i<4; i++){
            v1[i]=1;
            v2[i]=1;
            v[i]=0;
        }
        ll count = 1;
        for(auto x: s){
            if(x=='^'){
                v[0]+=(v1[0]*v2[0]%MOD +v1[1]*v2[1]%MOD +v1[2]*v2[2]%MOD +v1[3]*v2[3]%MOD)%MOD;
                v[1]+=(v1[0]*v2[1]%MOD +v1[1]*v2[0]%MOD +v1[2]*v2[3]%MOD +v1[3]*v2[2]%MOD)%MOD;
                v[2]+=(v1[0]*v2[2]%MOD +v1[1]*v2[3]%MOD +v1[2]*v2[0]%MOD +v1[3]*v2[1]%MOD)%MOD;
                v[3]+=(v1[0]*v2[3]%MOD +v1[1]*v2[2]%MOD +v1[2]*v2[1]%MOD +v1[3]*v2[0]%MOD)%MOD;
                v1[0]=v[0]%MOD;
                v1[1]=v[1]%MOD;
                v1[2]=v[2]%MOD;
                v1[3]=v[3]%MOD;
                count++;
            }
            else if(x=='&'){
                v[0]+=(v1[0]*v2[0]%MOD +v1[1]*v2[0]%MOD +v1[0]*v2[1]%MOD +v1[2]*v2[0]%MOD +v1[0]*v2[2]%MOD +v1[3]*v2[2]%MOD +v1[2]*v2[3]%MOD +v1[0]*v2[3]%MOD +v1[3]*v2[0]%MOD)%MOD;
                v[1]+=v1[1]*v2[1]%MOD;
                v[2]+=(v1[1]*v2[2]%MOD +v1[2]*v2[1]%MOD +v1[2]*v2[2]%MOD)%MOD;
                v[3]+=(v1[3]*v2[3]%MOD +v1[1]*v2[3]%MOD +v1[3]*v2[1]%MOD)%MOD;
                v1[0]=v[0]%MOD;
                v1[1]=v[1]%MOD;
                v1[2]=v[2]%MOD;
                v1[3]=v[3]%MOD;
                count++;
            }
            else if(x=='|'){
                v[0]+=v1[0]*v2[0] % MOD;
                v[1]+=(v1[0]*v2[1]%MOD +v1[1]*v2[0]%MOD +v1[1]*v2[1]%MOD +v1[1]*v2[2]%MOD +v1[1]*v2[3]%MOD +v1[2]*v2[1]%MOD +v1[3]*v2[1]%MOD +v1[3]*v2[2]%MOD +v1[2]*v2[3]%MOD)%MOD;
                v[2]+=(v1[0]*v2[2]%MOD +v1[2]*v2[0]%MOD +v1[2]*v2[2]%MOD)%MOD;
                v[3]+=(v1[0]*v2[3]%MOD +v1[3]*v2[0]%MOD +v1[3]*v2[3]%MOD)%MOD;
                v1[0]=v[0]%MOD;
                v1[1]=v[1]%MOD;
                v1[2]=v[2]%MOD;
                v1[3]=v[3]%MOD;
                count++;
            }
        }
        ll total=0;
        for(auto x: v1){
            total+=x;
        }
        count = power(4, count, MOD);
        ll p1 = v1[0];
        ll p2 = v1[1];
        ll p3 = v1[2];
        ll p4 = v1[3];
        //cout<<total<<endl;
        cout<<((p1%MOD)*(modInverse(count, MOD)))%MOD<<" "<<((p2%MOD)*(modInverse(count, MOD)))%MOD<<" "<<((p3%MOD)*(modInverse(count, MOD)))%MOD<<" "<<((p4%MOD)*(modInverse(count, MOD)))%MOD<<endl;
        //printf("%lf %lf %lf %2f\n", p1, p2, p3, p4);
    }
    return 0;
}
