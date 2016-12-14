#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define mx 1001
#define xx first
#define yy second
#define int long long

using namespace std;

const int inf=1000000000000;


int n,k,m;
int dp[51][51][51];

int call(int id,int no){
    if(id<0||no<0)return 0;
    if(id==0)return (no==0);
    if(no==0)return 0;

    if(dp[id][no][m]!=-1)
        return dp[id][no][m];

    int res=0;
    for(int i=1;i<=m;i++){
        res += call(id-i,no-1);
    }
    return dp[id][no][m]=res;
}


main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

    int t;
    scanf("%lld",&t);
    int caseno=0;
    memset(dp,-1,sizeof(dp));
    while(t--){
        scanf("%lld%lld%lld",&n,&k,&m);
        printf("Case %lld: ",++caseno);
        dp[n][k][m]=call(n,k);
        printf("%lld\n",dp[n][k][m]);
    }
    return 0;
}
