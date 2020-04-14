#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
typedef long long LL;
LL dp[10010];
LL gcd(LL a,LL b){
    if(!b) return a;
    return gcd(b,a%b);
}
LL lcm(LL a,LL b){
    return a*b/gcd(a,b);
}
int main(){
    freopen("op2","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<=n;i++) dp[i]=1;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=i;j--){
            LL temp=lcm(dp[j-i],i);
            if(temp>dp[j]) dp[j]=temp;
        }
        for(int j=1;j<=n;j++) cout<<dp[j]<<" ";
        cout<<endl;
    }
    for(int i=0;i<=n;i++) cout<<dp[i]<<"\n";
    return 0;
}