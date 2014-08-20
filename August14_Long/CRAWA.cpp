#include<iostream>
#include<cmath>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<map>
#include<bitset>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define MOD 1000000009


template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}

int find_quad(ll x,ll y)
{
    if(x>=0 && y>=0) return 1;
    if(x<=0 && y>=0) return 2;
    if(x<=0 && y<=0) return 3;
    if(x>=0 && y<=0) return 4;
}

bool check_horizontal(ll x,ll y)
{   int quad=find_quad(x,y);
    switch(quad){
    case 1:
            if(y&1) return false;
            if(x>=(-1LL)*y && x<=(y-1LL)) return true;
            return false;
            break;
    case 2:
            if(abs(y)&1) return false;
            if(x>=(-1)*y && x<=(y-1)) return true;
            return false;
            break;
    case 3:
            if(y&1) return false;
            if(x>=y && x<=(abs(y)+1)) return true;
            return false;
            break;
    case 4:
            if(y&1) return false;
            if(x>=y && x<=(abs(y)+1)) return true;
            return false;
            break;
    }

}

bool check_vertical(ll x,ll y)
{   int quad=find_quad(x,y);
    switch(quad){
    case 1:
            if(x%2==0) return false;
            if(y<=x+1LL && y>=(-1LL)*(x-1LL)) return true;
            return false;
            break;
    case 2:
            if(abs(x)&1) return false;
            if(y<=abs(x) && y>=x) return true;
            return false;
            break;
    case 3:
            if(abs(x)&1) return false;
            if(y<=abs(x) && y>=x) return true;
            return false;
            break;
    case 4:
            if(x%2==0) return false;
            if(y<=x+1 && y>=(-1)*(x-1)) return true;
            return false;
            break;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    ll x,y;
    for(int i=0;i<t;i++)
    {

        scanf("%lld %lld",&x,&y);
        if((x==0 && y==0) || (x==1 && y==0)) cout<<"YES\n";
        else if(check_horizontal(x,y) || check_vertical(x,y)) cout<<"YES\n";
        else cout<<"NO\n";
    }
}
