#include<bits/stdc++.h>
#define ll long long int
#define db double
#define pb push_back
#define fin for(int i=0; i<n; i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 998244353
using namespace std;

ll power(ll x, ll y, ll p);
ll modInverse(ll n, ll p);
bool isChar(char o);
vector<ll> solve(vector<ll> v1, vector<ll> v2, char ch);
int preference(char ch);
void evaluate(string s);

int main()
{
     int t; scanf("%d", &t);
     while(t--)
      {
          string s; cin>>s;
          evaluate(s);
      }
     return 0;
}


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
  
// Returns n^(-1) mod p 
ll modInverse(ll n, ll p){ 
    return power(n, p-2, p); 
}


bool isChar(char o)
{
     switch (o) {
        case '&': return true;
        case '|': return true;
        case '^': return true;
        case '(': return true;
        case ')': return true;
        default: return false;
    }
}

vector<ll> solve(vector<ll> v1, vector<ll> v2, char ch)
{
  vector<ll> v;
          if(ch=='&'){v.pb((v1[0]*v2[0]+v1[1]*v2[0]+v1[0]*v2[1]+v1[2]*v2[0]+v1[0]*v2[2]+v1[3]*v2[2]+v1[2]*v2[3]+v1[0]*v2[3]+v1[3]*v2[0])%MOD);
                    v.pb((v1[1]*v2[1])%MOD);
                    v.pb((v1[1]*v2[2]+v1[2]*v2[1]+v1[2]*v2[2])%MOD);
                    v.pb((v1[3]*v2[3]+v1[1]*v2[3]+v1[3]*v2[1])%MOD);
                    }
          if(ch=='|'){v.pb((v1[0]*v2[0])%MOD);
                    v.pb((v1[0]*v2[1]+v1[1]*v2[0]+v1[1]*v2[1]+v1[1]*v2[2]+v1[1]*v2[3]+v1[2]*v2[1]+v1[3]*v2[1]+v1[3]*v2[2]+v1[2]*v2[3])%MOD);
                    v.pb((v1[0]*v2[2]+v1[2]*v2[0]+v1[2]*v2[2])%MOD);
                    v.pb((v1[0]*v2[3]+v1[3]*v2[0]+v1[3]*v2[3])%MOD);
                    }
          if(ch=='^'){v.pb((v1[0]*v2[0]+v1[1]*v2[1]+v1[2]*v2[2]+v1[3]*v2[3])%MOD);
                    v.pb((v1[0]*v2[1]+v1[1]*v2[0]+v1[2]*v2[3]+v1[3]*v2[2])%MOD);
                    v.pb((v1[0]*v2[2]+v1[1]*v2[3]+v1[2]*v2[0]+v1[3]*v2[1])%MOD);
                    v.pb((v1[0]*v2[3]+v1[1]*v2[2]+v1[2]*v2[1]+v1[3]*v2[0])%MOD);
                    }
     return v;
}

int preference(char ch)
{

          if(ch=='&' || ch=='|' || ch=='^')
            return 1;
          if(ch=='(')
            return 0;
}

void evaluate(string s)
{
     stack<char> operators;
     stack<vector<ll>> operands;

     for(auto o: s)
     {
          if(isChar(o))
          {
               if(o=='(') operators.push('(');
               else if(o==')')
               {
                    while(operators.top()!='(')
                    {
                         char ch=operators.top(); operators.pop();
                         vector<ll> op2=operands.top(); operands.pop();
                         vector<ll> op1=operands.top(); operands.pop();

                         operands.push(solve(op1,op2,ch));
                    }
                    //remove this extra pop operation
                    operators.pop(); //operators.pop();
               }
               else
               {
                    while(!operators.empty() && preference(o) <= preference(operators.top()))
                    {
                         char ch=operators.top(); operators.pop();
                         vector<ll> op2=operands.top(); operands.pop();
                         vector<ll> op1=operands.top(); operands.pop();

                         operands.push(solve(op1,op2,ch));

                    }
                    operators.push(o);
               }
          }
          else
          {
            vector<ll> v{1, 1, 1, 1};
            operands.push(v);
          }

     }

     while(!operators.empty())
     {
          char ch=operators.top(); operators.pop();
          vector<ll> op2=operands.top(); operands.pop();
          vector<ll> op1=operands.top(); operands.pop();

          operands.push(solve(op1,op2,ch));
     }

     vector<ll> ans = operands.top();
     ll total=0;
     for(auto x: ans)
            total+=x;

        ll p1 = ans[0];
        ll p2 = ans[1];
        ll p3 = ans[2];
        ll p4 = ans[3];
        //cout<<total<<endl;
        //cout<<((p1%MOD)*(modInverse(total, MOD)))%MOD<<" "<<((p2%MOD)*(modInverse(total, MOD)))%MOD<<" "<<((p3%MOD)*(modInverse(total, MOD)))%MOD<<" "<<((p4%MOD)*(modInverse(total, MOD)))%MOD<<endl;
        printf("%lld %lld %lld %lld\n",((p1%MOD)*(modInverse(total, MOD)))%MOD, ((p2%MOD)*(modInverse(total, MOD)))%MOD, ((p3%MOD)*(modInverse(total, MOD)))%MOD, ((p4%MOD)*(modInverse(total, MOD)))%MOD);
}