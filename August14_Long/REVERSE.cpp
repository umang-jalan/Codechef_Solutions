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
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define MOD 1000000009


template <typename X> X gcd(X a, X b){if(!b)return a; else return gcd(b, a%b);}

vector<ii> adj[100005];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int x,y;
    std::vector<ii>::iterator it,it1;
    for(int i=0;i<m;i++)
    {
         scanf("%d %d",&x,&y);
         it=find(adj[x].begin(),adj[x].end(),ii(0,y));
         it1=find(adj[x].begin(),adj[x].end(),ii(1,y));
         if(it!=adj[x].end()){
                continue;
         }
         else if(it1!=adj[x].end())
         {
             it1->first=0;
         }
         else if(x!=y)
            {
                adj[x].push_back(ii(0,y));
                adj[y].push_back(ii(1,x));
            }
    }
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0,1));
    int cost[100005];
    for(int i=1;i<=n;i++)
    {
        cost[i]=INT_MAX;
    }
    cost[1]=0;
    while(!pq.empty())
    {
        ii s = pq.top();
        pq.pop();
        int newcost;
        if(s.second==n) break;
        for(int i=0;i<adj[s.second].size();i++)
        {
            ii p=adj[s.second][i];
            newcost=cost[s.second] + p.first;
            if(cost[p.second]==INT_MAX || newcost<cost[p.second])
                {
                    cost[p.second]=newcost;
                    pq.push(ii(newcost,p.second));
                }

        }
    }
     if(cost[n]==INT_MAX) printf("-1\n");
     else printf("%d\n",cost[n]);



}
