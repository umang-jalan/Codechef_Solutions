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
    int n,m;

    scanf("%d %d",&n,&m);
    //getchar();
    string ch;
    cin>>ch;
    //char ch[n+1];
    int a[n+1][10],x;
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++)
    {
        //ch[i]=getchar();
        if(i>0)
        {
            for(int j=0;j<10;j++)
            {
                a[i][j]=a[i-1][j];
            }
        }
        a[i][ch[i]-'0']++;

    }
    //getchar();

    for(int i=0;i<m;i++)
    {  ll b1=0LL,b2=0LL;
        scanf("%d",&x);x--;
        for(int j=0;j<10;j++)
        {
            if(j>(ch[x]-'0'))
            {
                b2+=(a[x][j]*((ch[x]-'0')-j));
            }
            else{
                b1+=(a[x][j]*((ch[x]-'0')-j));
            }
        }
        printf("%lld\n",(b1-b2));
    }

}
