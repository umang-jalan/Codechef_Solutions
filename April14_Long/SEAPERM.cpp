#include<bits/stdc++.h>
using namespace std;
int cal_f(int S,vector<int> A,int i)
{int sum=0;
    if(A[i-1]>S) return S;
    for(int j=i-1;j<A.size();j++)
    {
        if(sum+A[j]>S) return S-sum;
        sum+=A[j];
    }
    return S-sum;
}
int main()
{
int t,y;
scanf("%d",&t);
while(t--){
long long s;
int n,k;
scanf("%d %d %lld",&n,&k,&s);
vector<int> v;
int a[10003]={0};
vector<int> v1[10003];
for(int i=1;i<=n;i++)
{
scanf("%d",&y);
v.push_back(y);
a[y]++;
v1[y].push_back(i);
}
int visited[10003]={0};
sort(v.begin(),v.end(),std::greater<int>());
int x;
for(x=0;x<v.size();x++)
{
    if(v[x]<s) break;
}
sort(v.begin()+x,v.end());
int cnt=0;
do{
    if(cnt>=500) break;
    cnt++;
}while(std::next_permutation(v.begin()+x,v.end()));
vector<int> ans;
for(int i=0;i<v.size();i++)
{
    ans.push_back(v1[v[i]][visited[v[i]]]);visited[v[i]]++;

}
for(int i=0;i<ans.size();i++)
{
    printf("%d",ans[i]);
    if(i<ans.size()-1) printf(" ");
}
printf("\n");
}
}
