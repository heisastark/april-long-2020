#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define fin for(int i=0; i<n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
const int mod = 998244353;

int main(){
	fast

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

        for(auto x: s){
            if(x=='^'){
                v[0]+=(v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2]+v1[3]*v2[3]+3*mod)%mod;
                v[1]+=(v1[0]*v2[1]+v1[1]*v2[0]+v1[2]*v2[3]+v1[3]*v2[2]+3*mod)%mod;
                v[2]+=(v1[0]*v2[2]+v1[1]*v2[3]+v1[2]*v2[0]+v1[3]*v2[1]+3*mod)%mod;
                v[3]+=(v1[0]*v2[3]+v1[1]*v2[2]+v1[2]*v2[1]+v1[3]*v2[0]+3*mod)%mod;
                v1[0]=v[0];
                v1[1]=v[1];
                v1[2]=v[2];
                v1[3]=v[3];
            }
            else if(x=='&'){
                v[0]=(v1[0]*v2[0]+v1[1]*v2[0]+v1[0]*v2[1]+v1[2]*v2[0]+v1[0]*v2[2]+v1[3]*v2[2]+v1[2]*v2[3]+v1[0]*v2[3]+v1[3]*v2[0]+3*mod)%mod;
                v[1]=(v1[1]*v2[1]+3*mod)%mod;
                v[2]=(v1[1]*v2[2]+v1[2]*v2[1]+v1[2]*v2[2]+3*mod)%mod;
                v[3]=(v1[3]*v2[3]+v1[1]*v2[3]+v1[3]*v2[1]+3*mod)%mod;
                v1[0]=v[0];
                v1[1]=v[1];
                v1[2]=v[2];
                v1[3]=v[3];
            }
            else if(x=='|'){
                v[0]=(v1[0]*v2[0]+3*mod)%mod;
                v[1]=(v1[0]*v2[1]+v1[1]*v2[0]+v1[1]*v2[1]+v1[1]*v2[2]+v1[1]*v2[3]+v1[2]*v2[1]+v1[3]*v2[1]+v1[3]*v2[2]+v1[2]*v2[3]+3*mod)%mod;
                v[2]=(v1[0]*v2[2]+v1[2]*v2[0]+v1[2]*v2[2]+3*mod)%mod;
                v[3]=(v1[0]*v2[3]+v1[3]*v2[0]+v1[3]*v2[3]+3*mod)%mod;
                v1[0]=v[0];
                v1[1]=v[1];
                v1[2]=v[2];
                v1[3]=v[3];
            }
        }
        ll total=0;
        for(auto x: v1){
            printf("%lld ", (x+3*mod)/mod);
        }
        /*double p1 = v1[0]/(float)total;
        double p2 = v1[1]/(float)total;
        double p3 = v1[2]/(float)total;
        double p4 = v1[3]/(float)total;

        printf("%lf %lf %lf %lf\n", p1, p2, p3, p4);*/

    }

    return 0;
}