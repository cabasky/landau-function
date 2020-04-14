#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <gmp.h>
using namespace std;
#define MAXN 50010
int ptag[MAXN],plist[MAXN],pnum;
mpz_t dp[MAXN];
void euler(int n,int *tag,int *prime,int &num){
    for(int i=2;i<=n;i++){
        if(!tag[i]) prime[++num]=i;
        for(int j=1;j<=num&&prime[j]*i<=n;j++){
            tag[prime[j]*i]=1;
            if(!(i%prime[j])) break;
        }
    }
}
int main(){
    freopen("op2","w",stdout);
    mpz_t tmp;
    int n;
    scanf("%d",&n);
    euler(n,ptag,plist,pnum);
    for(int i=0;i<=n;i++) mpz_init_set_si(dp[i],1);
    for(int i=1;i<=pnum;i++)
        for(int j=n;j>=1;j--)
            for(int k=plist[i];k<=j;k*=plist[i]){
                mpz_mul_si(tmp,dp[j-k],k);
                if(mpz_cmp(tmp,dp[j])>0) mpz_set(dp[j],tmp);
            }
    for(int i=1;i<=n;i++){
        mpz_out_str (stdout,10,dp[i]);
        printf("\n");
    }
    return 0;
}