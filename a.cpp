#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long LL;
#define MAXN 10010
int ptag[MAXN],plist[MAXN],pnum;
LL dp[MAXN];
void euler(int n,int *tag,int *prime,int &num){
    tag[1]=1;
    for(int i=2;i<=n;i++){
        if(!tag[i]) prime[++num]=i;
        int ed=n/i;
        for(int j=1;j<=num&&j<=ed;j++){
            tag[prime[j]*i]=1;
            if(!(i%prime[j])) break;
        }
    }
}
int main(){
    freopen("op","w",stdout);
    int n;
    cin>>n;
    euler(n,ptag,plist,pnum);
    for(int i=0;i<=n;i++) dp[i]=1;
    for(int i=1;i<=pnum;i++)
        for(int j=n;j>=1;j--)
            for(int k=plist[i];k<=j;k*=plist[i])
                if(dp[j-k]*k>dp[j]) dp[j]=dp[j-k]*k;
    for(int i=1;i<=n;i++) cout<<dp[i]<<"\n";
    
    return 0;
}