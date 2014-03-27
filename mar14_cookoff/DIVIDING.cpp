#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[100005];
ll cnt(ll n)
{
    if(n&1) return ((ll)((n+1LL)/2LL) * n);
    return ((n+1LL) * (n/2LL));
}
int main()
{
    scanf("%lld",&n);
    ll sum=0LL;
    for(int i=0;i<n;i++) {scanf("%lld",&a[i]); sum+=a[i];}
    if(sum==cnt(n)) cout<<"YES\n";
    else cout<<"NO\n";

}
