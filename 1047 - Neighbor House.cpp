#include <bits/stdc++.h>
#define mx 30011
#define pb push_back
//#define int long long
#define mod 100000007

using namespace std;

int n,m,k;
int ara[21][3];
int dp[21][3][3];
string s1,s2;
int len;

int call(int pos,int id1,int id2){
    if(pos==n)
        return 0;

    if(dp[pos][id1][id2] != -1)
        return dp[pos][id1][id2];

    int res1=ara[pos][id1]+call(pos+1,(id1+1)%3,(id1+2)%3);
    int res2=ara[pos][id2]+call(pos+1,(id2+1)%3,(id2+2)%3);

    return dp[pos][id1][id2]=min(res1,res2);
}


main()
{
    int t;
    scanf("%d",&t);
    int caseno=0;
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                scanf("%d",&ara[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        for(int i=0;i<3;i++){
            ans = min(ans,ara[0][i]+call(1,(i+1)%3,(i+2)%3) );
        }
        printf("Case %d: %d\n",++caseno,ans);
    }
}
