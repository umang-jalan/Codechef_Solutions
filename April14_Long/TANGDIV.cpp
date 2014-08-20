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
inline int inp()
{
    register int noRead=0;
    //register char p=getchar_unlocked();
    register char p=getc(stdin);
    //for(;p<48 || p>57;p=getchar_unlocked());
    for(;p<48 || p>57;p=getc(stdin));
    //while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getchar_unlocked();}
    while(p>47 && p<58){ noRead = (noRead << 3) + (noRead << 1) + (p - '0');p=getc(stdin);}
    return noRead;
};

int main()
{
    int t,n,k,p,x,y;
    //freopen("C:/Users/UMANG JALAN/Desktop/CODE/inp.txt","r",stdin);
    //freopen("C:/Users/UMANG JALAN/Desktop/CODE/out.txt","w",stdout);
    t=inp();
    while(t--)
    {
        n=inp();
        k=inp();
        p=inp();
        vii a,b;
        for(int i=0;i<k;i++)
        {
            x=inp();
            y=inp();
            a.push_back(make_pair(x,y));
        }
        for(int i=0;i<p;i++)
        {
            x=inp();
            y=inp();
            b.push_back(make_pair(x,y));
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        bool flag;
        int sz1=a.size(),sz2=b.size();
        for(int i=0;i<sz1;i++)
        {   flag=false;
            for(int j=0;j<sz2;j++)
            {
                if(a[i].first==a[i].second)
                {
                    if((b[j].first==a[i].first || b[j].second==a[i].second)) { flag=true;break;}
                    //if(b[j].first>a[i].first){ flag=false; break;}
                }
                if(a[i].first<=a[i].second)
                {
                    if(a[i].first>=b[j].first && a[i].second<=b[j].second &&  b[j].first<b[j].second) { flag=true;break;}
                    if(b[j].first> a[i].second && (b[j].second >= a[i].second && b[j].second<=b[j].first-1)) { flag=true;break;}
                    if(b[j].first<= a[i].first && b[j].first>b[j].second) { flag=true;break;}
                    //if(b[j].first>a[i].first){ flag=false; break;}
                }
               else{
                    if(a[i].first>=b[j].first && a[i].second<=b[j].second &&  b[j].first>b[j].second) { flag=true;break;}
                    //if(b[j].first<a[i].first){ flag=false; break;}
               }

            }
            if(flag==false) {break;}

        }
        if(flag) printf("Yes\n");
        else printf("No\n");




    }

}
