#include <bits/stdc++.h>
#define mx 44
#define pb push_back
#define mp make_pair
#define mod 100000007
#define xx first
#define yy second

using namespace std;

int n,m;
int val[101],freq[101];
bool dp[100001];
int needcoins[100001];

int  solve(){
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(dp[j])needcoins[j]=0;
            else needcoins[j]=10000;
        }
        for(int j=0;j<=(m-val[i]);j++){
            int k=j+val[i];
            if( dp[k]==0 && dp[j] && needcoins[j]<freq[i] ){
                needcoins[k]=needcoins[j]+1;
                dp[k]=1;
            }
        }
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(dp[i])cnt++;
    }
    return cnt;
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

    int t;
    scanf("%d",&t);
    int caseno=0;
    while(t--){
        scanf("%d%d",&n,&m);

        for(int i=1;i<=n;i++){
            scanf("%d",&val[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&freq[i]);
        }

        printf("Case %d: %d\n",++caseno,solve());
    }
    return 0;
}
