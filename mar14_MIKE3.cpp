#include<bits/stdc++.h>
using namespace std;

int pow_2[22]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
int dp[25][25];
int n,m,x,y;
vector<int> a[22];

vector<int> cnt(int i)
{
    vector<int> v;
    while(i)
    {
        int p=i & ~(i-1);
       // cout<<log2(p)+1<<" ";
        v.push_back((log2(p)+1));
        i=i & (i-1);
    }
   // cout<<"\n";
    return v;
}
int check(vector<int> a,vector<int> b)
{
    int sz1=a.size(),sz2=b.size();
  for(int i=0,j=0;i<sz1 && j<sz2;)
  {
      if(a[i]==b[j]) return 0;
      if(a[i]<b[j]) i++;
      else j++;
  }
  return 1;
}

int main()
{   // init();
    //cout<<"out"<<"\n";
    //int n,m;
    scanf("%d%d",&n,&m);
    memset(dp,-1,sizeof(dp));
    /*for(int i=0;i<=24;i++)
    for(int j=0;j<=24;j++)
        dp[i][j]=-1;*/
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        for(int j=1;j<=x;j++)
        {
            scanf("%d",&y);
            a[i].push_back(y);
        }
    }
    int ans=-1;
    bool flag;int sz;
    for(int i=0;i<pow_2[m];i++)
    {
       vector<int> v=cnt(i);
       flag=false;
       sz=v.size();
       if(sz==1) ans=max(ans,sz);
       else{
       for(int j=0;j<sz;j++)
       {
           for(int k=j+1;k<sz;k++)
           {
                if(dp[v[j]][v[k]]==-1)
                {
                    dp[v[j]][v[k]]=check(a[v[j]],a[v[k]]);
                    if(dp[v[j]][v[k]]==0) {
                    flag=true; break;
                }
                }
                else{
                    if(dp[v[j]][v[k]]==0) {
                    flag=true; break;
                }
                }

           }
           if(flag) break;
       }
       if(flag==false) { ans=max(ans,sz);}
       }
    }
    printf("%d\n",ans);
}
