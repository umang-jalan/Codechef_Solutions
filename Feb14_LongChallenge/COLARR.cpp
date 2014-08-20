#include<bits/stdc++.h>
using namespace std;
#define MAX 1002

int t,n,m,k,tot_earn;
int b[MAX][MAX],c[MAX][MAX],d,color[MAX];
#define LOCAL 0
#define DEBUG 0
#define trace(msg,...) if(DEBUG) fprintf(stderr, "[line %d]: "msg,__LINE__,__VA_ARGS__);

//#if LOCAL
#define Get getchar()
//#else
//#define Get getchar_unlocked()
//#endif
/*inline int inp()
{
    register int noRead=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked());
    for(;p<48 || p>57;p=getc(stdin));
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};*/
int getInt() { int a=0,s=1; char c=0; while(c<33) c=Get; if(c=='-') {s=-1; c=Get;} while(c>33) {a=(a<<3)+(a<<1)+c-'0'; c=Get;} return a*s; }
bool cmp(pair<int,int> e,pair<int,int> f)
{   int temp1=e.second-b[e.first][color[e.first]];
    int temp2=f.second-b[f.first][color[f.first]];
    if(temp1==temp2)
    {
        return e.second > f.second;
    }
    return temp1 > temp2;
}
int main()
{
     t=getInt();
    //scanf("%d",&t);
    while(t--)
    {
    n=getInt();
    m=getInt();
    k=getInt();
        //scanf("%d %d %d",&n,&m,&k);
        tot_earn=0;
        for(int i=1;i<=n;i++) color[i]=getInt();//scanf("%d",&color[i]);

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++) b[i][j]=getInt();//scanf("%d",&b[i][j]);
        }
        vector<pair<int,int> > v;
        for(int i=1;i<=n;i++)
        {   d=-1;
            for(int j=1;j<=m;j++) {scanf("%d",&c[i][j]); d=max(d,b[i][j]-c[i][j]);}
            if(b[i][color[i]] < d) v.push_back(make_pair(i,d));
        }
       sort(v.begin(),v.end(),cmp);
       bitset<MAX> bs; bs.set();
       for(int i=0;i<k && i<v.size() ;i++)
       {
           tot_earn+=v[i].second;
           bs[v[i].first]=0;
       }
       for(int i=1;i<=n ;i++)
       {
           if(bs[i]) tot_earn += b[i][color[i]];
       }
       printf("%d\n",tot_earn);

}
return 0;
}
