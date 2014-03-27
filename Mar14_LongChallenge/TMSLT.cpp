#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define RANGE 1000000
int a,b,c,d,n,t,x;
ll count1[RANGE + 1],s[3000005],ans;
ll countSort()
{
    int i;
        x=1;
        ans=0LL;
        for (i = 1; i <= RANGE; ++i)
        {
            if(count1[i]&1)
            {
              ans+=(x*i);
              x*=(-1);
            }

        }
        return ans;
}

int main()
{
scanf("%d",&t);
while(t--)
{
scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
memset(count1, 0, sizeof(count1));
s[0]=d;
++count1[s[0]];
for(int i=1;i<n;i++) {
s[i]=((a * s[i-1] *s[i-1])+ (b*s[i-1])+ c) % 1000000;
++count1[s[i]];
}
x=1;
ans=0LL;
int i;
        for (i = 1; i <= RANGE; ++i)
        {
            if(count1[i]&1)
            {
              ans+=(x*i);
              x*=(-1);
            }

        }
printf("%lld\n",abs(ans));
}
}
