#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define mx 100001
#define xx first
#define yy second
#define int long long

using namespace std;

const int inf=1000000000000;

vector<int>vec[mx],cost[mx];
int maxval;

int n,k,m;
int dp[mx];

int call(int id){
    if(id>maxval)
        return 0;

    if(dp[id]!=-1)
        return dp[id];

    int res=0;
    int sz=vec[id].size();
    bool flag=0;
    for(int i=0;i<sz;i++){
        flag=1;
        int next=vec[id][i];
        int val=cost[id][i];
        res = max( res , val+call(id+next) );
        res = max( res , call(id+1) );
    }
    if(flag==0)
        res = max(res,call(id+1));

    return dp[id]=res;
}

void clr(){
    for(int i=0;i<mx;i++){
        vec[i].clear();
        cost[i].clear();
        dp[i]=-1;
    }
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
        clr();
        scanf("%lld",&n);
        for(int i=0;i<n;i++){
            int p,q,r;
            scanf("%lld%lld%lld",&p,&q,&r);
            vec[p].pb(q);
            cost[p].pb(r);
            maxval=max(maxval,p);
        }
        printf("Case %lld: ",++caseno);
        int ans=call(0);
        printf("%lld\n",ans);
    }
    return 0;
}
