#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int  w[n+1];
        for(int i=0;i<n;i++) scanf("%d",&w[i]);
        int ans=w[0];
        int temp=ans;
        for(int i=1;i<n;i++)
        {
            temp--;
            if(temp<w[i]) { ans+=(w[i]-temp); temp=w[i];}
        }
        printf("%d\n",ans);
    }
}
