#include <bits/stdc++.h>
#define mx 200011
#define pb push_back
#define mp make_pair
#define mod 100000007
#define xx first
#define yy second
//#define int long long
#define inf 20000000000000009

using namespace std;

typedef pair<int,int> pp;

int ara[101][101];
int n,m;
int dp[101][101][202];

int call(int i,int p,int step){

    int j=step-i+2;
    int q=step-p+2;

    if(i>n || j>m || p>n || q>m)
        return 0;

    if(i==p && j==q )
        return 0;

    if(dp[i][p][step]!=-1){
        return dp[i][p][step];
    }

    int res=ara[i][j]+ara[p][q] + max( max(call(i+1,p,step+1),call(i+1,p+1,step+1)),max(call(i,p,step+1),call(i,p+1,step+1)));

    return dp[i][p][step]=res;
}

 main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

    int t;
    scanf("%d",&t);
    int caseno=0;
    while(t--){

        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&ara[i][j]);
            }
        }
        memset(dp,-1,sizeof(dp));
        int res=call(2,1,1)+ara[n][m]+ara[1][1];
        printf("Case %d: %d\n",++caseno,res);
    }
    return 0;
}

