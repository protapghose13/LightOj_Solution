#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define mx 61
#define xx first
#define yy second
#define int long long

using namespace std;

const int inf=1000000000000;

int arr[20][20];
int n,m;
int track[20];
int dp[(1<<16)];

int call(int mask){
    if(mask==(1<<n)-1)
        return 0;

    if(dp[mask]!=-1)
        return dp[mask];

    int res=inf;
    for(int i=0;i<n;i++){
        if(  (mask&(1<<i))==0 ){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if( (mask&(1<<j))==0 ){
                    res = min(res,arr[i][j]+call( ((mask|(1<<i))|(1<<j)) ) );
                }
            }
        }
    }
    return dp[mask]=res;
}

void clr(){
    for(int i=0;i<n;i++){
        track[i]=0;
        for(int j=0;j<n;j++){
            arr[i][j]=inf;
        }
    }
    memset(dp,-1,sizeof(dp));
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    cin>>t;
    int caseno=0;
    while(t--){
        cin>>n>>m;
        clr();
        int maxval=0;
        int ans=0;
        int mask=0;
        for(int i=0;i<m;i++){
            int u,v,a;
            cin>>u>>v>>a;
            u--,v--;
            track[u]++;
            track[v]++;
            ans+=a;
            arr[u][v]=min(arr[u][v],a);
            arr[v][u]=min(arr[v][u],a);
        }
        for(int i=0;i<n;i++){
            if(track[i]%2==0){
                mask=(mask|(1<<i));
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    arr[i][j] = min( arr[i][j] , arr[i][k]+arr[k][j] );
                }
            }
        }
        cout<<"Case "<<++caseno<<": "<<call(mask)+ans<<endl;
    }
    return 0;
}
