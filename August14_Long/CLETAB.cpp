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

 int occupied[405],person[405];
int main(){
int t,n,m,c;
scanf("%d",&t);
while(t--)
{
    scanf("%d %d",&n,&m);
    int c[m+1];
    for(int i=0;i<m;i++) scanf("%d",&c[i]);
    memset(occupied,0,sizeof(occupied));
    memset(person,0,sizeof(person));
    int cnt=1,i;
    for(i=0;i<m && cnt<=n;i++){
        if(occupied[c[i]]==0) {
            occupied[c[i]]=cnt;
            person[cnt]=c[i];
            cnt++;
        }
    }
    cnt--;
    //cout<<i<<" "<<cnt<<"\n";
    int ans=0,temp;
    for(int j=i;j<m;j++)
    {
        if(occupied[c[j]]==0){
            bitset<405> bs;
            bs.set();
            temp=1;
            for(int k=j+1;k<m && temp<n;k++)
            {
                if(occupied[c[k]] && bs[occupied[c[k]]]){
                    //cout<<"In1"<<" "<<c[k]<<"\n";
                    bs[occupied[c[k]]]=0;
                    temp++;
                }
            }
            for(int l=1;l<=n;l++)
            {
                if(bs[l]){
                    //cout<<"in"<<" "<<l<<"\n";
                    ans++;
                    occupied[person[l]]=0;
                    occupied[c[j]]=l;
                    person[l]=c[j];
                    break;

                }
            }
        }
    }
    printf("%d\n",cnt+ans);

}

}
