#include<bits/stdc++.h>

using namespace std;
string a,b;
map<char,int> m1,m2;
int cnt1[65],cnt2[65];
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        cin>>a>>b;

        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
        for(int i=0;i<a.length();i++)
        {
            if(a[i]>='0' && a[i]<='9') cnt1[a[i]-'0']++;
            else if(a[i]>='A' && a[i]<='Z') cnt1[a[i]-'A' + 10]++;
            else cnt1[a[i] - 'a' + 36]++;
        }
        for(int i=0;i<b.length();i++)
        {
            if(b[i]>='0' && b[i]<='9') cnt2[b[i]-'0']++;
            else if(b[i]>='A' && b[i]<='Z') cnt2[b[i]-'A' + 10]++;
            else cnt2[b[i] - 'a' + 36]++;
        }
        int ans=0;
        for(int i=0;i<62;i++)
        {
            if(cnt1[i] && cnt2[i])
            {
                ans+=min(cnt1[i],cnt2[i]);
            }
        }
        printf("%d\n",ans);

    }
}
