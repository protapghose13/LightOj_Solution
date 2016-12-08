#include <bits/stdc++.h>
#define mx 100011
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
//#define int long long
#define inf 1000000007

using namespace std;

int m,n,k;
string s[22];
pair<int,int> ara[20];
int s1,s2;

int dp[(1<<15)][15];

int calc(int n){
    int cnt=0;
    while(n){
        cnt += (n%2==1);
        n/=2;
    }
    return cnt;
}

int call(int mask,int id){
    if(calc(mask)==k)
        return max(abs(s1-ara[id].xx), abs(s2-ara[id].yy));
    if(dp[mask][id]!=-1)
        return dp[mask][id];
    int res=INT_MAX;
    for(int i=0;i<k;i++){
        if( (mask&(1<<i))==0 ){
            if(calc(mask)==0){
                res = min(res, max( abs(s1-ara[i].xx), abs(s2-ara[i].yy) ) + call( (mask|(1<<i)),i )  );
            }
            else{
                res = min(res, max( abs(ara[id].xx-ara[i].xx), abs(ara[id].yy-ara[i].yy) ) + call( (mask|(1<<i)),i )  );
            }
        }
    }
    return dp[mask][id]=res;
}

main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    cin>>t;
    int caseno=0;
    while(t--){
        cin>>n>>m;
        k=0;
        for(int i=0;i<n;i++){
            cin>>s[i];
            for(int j=0;j<m;j++){
                if(s[i][j]=='g'){
                    ara[k++]=mp(i,j);
                }
                if(s[i][j]=='x'){
                    s1=i,s2=j;
                }
            }
        }
        memset(dp,-1,sizeof(dp));
        int ans;
        if(k==0)ans=0;
        else ans=call(0,0);
        cout<<"Case "<<++caseno<<": "<<ans<<endl;
    }
    return 0;
}
