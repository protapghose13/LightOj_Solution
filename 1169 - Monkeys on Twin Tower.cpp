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


int n;
int floor1[mx],floor2[mx],jto2[mx],jto1[mx];
int dp[mx][3];

int call(int id,int no){
    if(id==n-1){
        if(no==1)return floor1[id];
        return floor2[id];
    }

    if(dp[id][no]!=-1)
        return dp[id][no];

    int res=INT_MAX;

    if(no==1){
        res = min(res,floor1[id]+call(id+1,1));
        res = min(res,floor1[id]+jto2[id]+call(id+1,2));
    }
    else{
        res = min(res,floor2[id]+call(id+1,2));
        res = min(res,floor2[id]+jto1[id]+call(id+1,1));
    }
    return dp[id][no]=res;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    cin>>t;
    int caseno=0;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++)cin>>floor1[i];
        for(int i=0;i<n;i++)cin>>floor2[i];
        for(int i=0;i<n-1;i++)cin>>jto2[i];
        for(int i=0;i<n-1;i++)cin>>jto1[i];
        cout<<"Case "<<++caseno<<": ";
        memset(dp,-1,sizeof(dp));
        int ans=min(call(0,1),call(0,2));
        cout<<ans<<endl;
    }
    return 0;
}
