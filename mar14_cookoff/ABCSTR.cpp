#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char str[1000005];
int a[1000005],b[1000005],c[1000005];
int main()
{
    //freopen("C:/Users/UMANG JALAN/Desktop/CODE/inp.txt","r",stdin);
    //freopen("C:/Users/UMANG JALAN/Desktop/CODE/out.txt","w",stdout);
    scanf("%s",str);
    int len=strlen(str);
    //memset(a,0,sizeof(a));
    //memset(b,0,sizeof(b));
    //memset(c,0,sizeof(c));
    vector<pair<int,int> > v;
    v.push_back(make_pair(0,0));
    if(str[0]=='A') a[0]++;
    else if(str[0]=='B') b[0]++;
    else c[0]++;
    v.push_back(make_pair(a[0]-b[0],a[0]-c[0]));
    for(int i=1;i<len;i++) {
    a[i]=a[i-1];
    b[i]=b[i-1];
    c[i]=c[i-1];
    if(str[i]=='A') a[i]++;
    else if(str[i]=='B') b[i]++;
    else c[i]++;
    v.push_back(make_pair(a[i]-b[i],a[i]-c[i]));
    }
    sort(v.begin(),v.end());
   // for(int i=0;i<v.size();i++) cout<<v[i].first<<"'"<<v[i].second<<"\n";
    ll cnt=0LL,ans=0LL;
    int j,i;
    for(i=0;i<v.size();)
    {cnt=0;j=i;
        while(v[j]==v[i])
        {
                i++;
                cnt++;

        }
        ans+=(cnt*(cnt-1))/2;
    }
    printf("%lld\n",ans);


}
