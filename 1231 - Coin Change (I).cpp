#include <bits/stdc++.h>
#define mx 30011
#define pb push_back
#define mod 100000007

using namespace std;

int n;
int coin[51],freq[51];
int dp[51][1011];

int call(int pos,int val){
    if(pos==n+1)
        return val==0;

    if(val<0)
        return 0;

    if(val==0)
        return 1;

    if(dp[pos][val]!=-1)
        return dp[pos][val];

    int res=0;
    for(int i=0;i<=freq[pos];i++){
        res = (res+call(pos+1,val-(coin[pos]*i)))%mod;
    }
    return dp[pos][val]=res%mod;
}


int main()
{
    int t,k;
    scanf("%d",&t);
    int caseno=0;
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&coin[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&freq[i]);
        }
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",++caseno,call(1,k));
    }
}
