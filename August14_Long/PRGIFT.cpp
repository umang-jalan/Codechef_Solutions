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
#include<limits.h>
#include<string.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define MOD 1000000009


template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}

int cnt[105];
int main()
{
    int t;
    scanf("%d",&t);
    int n,k;
    while(t--)
    {
        scanf("%d %d",&n,&k);
        int a[n+1];
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&a[0]);
        int no_odd=0;
        if(a[0]%2==0) cnt[0]=1;
        else no_odd++;
        for(int i=1;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]%2==0) cnt[i]=cnt[i-1]+1;
            else {no_odd++;cnt[i]=cnt[i-1];}
        }
       //for(int i=0;i<n;i++) cout<<cnt[i]<<" ";
       // cout<<"\n";
       if(k==0) {
        if(no_odd==0) {printf("NO\n");}
        else {
        printf("YES\n");
       }
    }
    else{
        int u=*std::max_element(cnt,cnt+n);
        if(u>=k) printf("YES\n");
        else printf("NO\n");
    }
    }
}
