#include <stdio.h>
#include<cmath>
#include<algorithm>
#include<iostream>
#define MAX 1000001
using namespace std;

int n,k;
bool hash_1[MAX];
int hash_2[MAX];
int A[500003];
int cnt(int arr[], int arr_size, int sum)
{
  int i, temp;
  std::fill(hash_2,hash_2+MAX,1000002);
  std::fill(hash_1,hash_1+MAX,0);
  int ans=1000003;
  bool flag=false;
  for(i = 0; i < arr_size; i++)
  {
    temp = sum - arr[i];
    if(temp >= 1 && hash_1[temp] == 1 && temp!=arr[i])
    {
      ans=min(ans,max(hash_2[temp],min(i+1,arr_size-i)));
      flag=true;
    }
    hash_1[arr[i]] = 1;
    hash_2[arr[i]]=min(hash_2[arr[i]],min(i+1,arr_size-i));

  }
  if(flag) return ans;
  else return -1;
}
int main()
{  scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("%d\n",cnt(A, n, k));


    return 0;
}
