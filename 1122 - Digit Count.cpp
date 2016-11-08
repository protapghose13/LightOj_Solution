#include <bits/stdc++.h>
#define mx 30011
#define pb push_back
#define int long long
#define mod 100000007

using namespace std;

int ara[11];
int n,m;
int dp[11][11];

int call(int pos,int prev){
    if(pos==0)
        return 1;
    if(dp[pos][prev]!=-1)
        return dp[pos][prev];
    int res=0;
    for(int i=0;i<n;i++){
        if(prev==0)
            res+=call(pos-1,ara[i]);
        else if(abs(prev-ara[i])<=2)
            res += call(pos-1,ara[i]);
    }
    return dp[pos][prev]=res;
}

main()
{
    int t,k;
    scanf("%lld",&t);
    int caseno=0;
    while(t--){
        scanf("%lld%lld",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%lld",&ara[i]);
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n",++caseno,call(m,0));
    }
}
