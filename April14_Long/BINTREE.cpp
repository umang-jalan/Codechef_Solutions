#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define MOD 1000000009


template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}

int main()
{
    int n;
    ll i,j;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld %lld",&i,&j);
        int cnt=0;
        while(1)
        {
            if(i>j)
            {
                if(i&1) i=(i-1)>>1;
                else i>>=1;
                cnt++;
            }
            if(i<j)
            {
                if(j&1) j=(j-1)>>1;
                else j>>=1;
                cnt++;
            }
            if(i==j) { printf("%d\n",cnt); break;}
        }
    }
}
