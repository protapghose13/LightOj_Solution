#include <bits/stdc++.h>
#define mx 750011
#define mp make_pair
#define pb push_back
//#define int  long long
#define mod 1000000007
//#define inf 100000000
#define xx first
#define yy second
//#define N 3

using namespace std;

int n,m,cs,k,val;
int fx[]={-2,-2,-3,-1,-1,1};
int fy[]={-1,1,-1,-2,-3,-2};
int dp[511][511];


int check(set<int> Set){
    int res=0;
    while( Set.find(res)!= Set.end() ){
        res++;
    }
    return res;
}

int grundy(int x,int y){
    if(x<0 || y<0 || x>=510 || y>=510)
        return -1;

    if(dp[x][y]!=-1)
        return dp[x][y];

    set<int>Set;
    for(int i=0;i<6;i++){
        Set.insert(grundy(x+fx[i],y+fy[i]));
    }
    return dp[x][y] = check(Set);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;

    memset(dp,-1,sizeof(dp));
    for(int i=0;i<510;i++){
        for(int j=0;j<510;j++){
            if(dp[i][j]==-1)
                dp[i][j] = grundy(i,j);
        }
    }

    cin>>t;
    int caseno=0;
    while(t--){
        cin>>n;
        int res=0;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            res ^= dp[x][y];
        }
        cout<<"Case "<<++caseno<<": ";
        if(res)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}
