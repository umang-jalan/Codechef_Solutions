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
bitset<1000000> bs;
vector<int> prime;
void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;
    for(int i=2;i<=3000;i++)
    {
        if(bs[i])
        {
        for(int j=i+i;j<=3000;j+=i)
            if(bs[j]) bs[j]=0;
        prime.push_back(i);
        }
    }
}

int main()
{   sieve();
    //print();
    int t,x,y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&x,&y);
        int p=x+y;
        int l=lower_bound(prime.begin(),prime.end(),p) - prime.begin();
        if(prime[l]==p) l++;
        printf("%d\n",prime[l]-p);


    }
}
