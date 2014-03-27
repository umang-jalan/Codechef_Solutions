#include<bits/stdc++.h>

using namespace std;

long long calc(int n)
{
    if(n&1) return (long long)n*((long long)(n+1)/2);
    return (long long)(n/2)*((long long)(n+1));
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int  a[n+1];
        long long cnt_1=0LL,cnt_2=0LL,cnt_0=0LL,cnt_11=0,cnt_22=0,cnt_00=0LL;
        //vector<int> v;
        for(int i=0;i<n;i++) {scanf("%d",&a[i]);
        if(a[i]==2) {cnt_22++;cnt_2++;}
        else if(a[i]==1) {cnt_1+=(i-cnt_11-cnt_00); cnt_1+=(n-i-1);cnt_11++;}
        else if(a[i]==0) { cnt_0+=(i-cnt_11-cnt_00);cnt_0+=(n-i-1); cnt_00++;}

        }
       // cout<<calc(n-1)<<" "<<calc(cnt_2-1)<<" "<<cnt_1<<" "<<cnt_0<<"\n";
        long long ans=(calc(n-1) - calc(cnt_2-1) - cnt_1 - cnt_0);
        printf("%lld\n",ans);


    }
}
