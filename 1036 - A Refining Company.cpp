#include <bits/stdc++.h>
#define mx 1000001
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define inf 1000000000000000
#define int long long

using namespace std;

int n,m,len,uranium[502][502],radium[502][502];
string s;
int dp[502][502];

int call(int row,int col){
    if(row<0 || col<0)
        return 0;

    if(dp[row][col]!=-1)
        return dp[row][col];


    int res=0;

    res = max(res,radium[row][col]+uranium[row+1][col]+call(row-1,col-1));
    res = max(res,radium[row][col]+uranium[row+1][col]+call(row,col-1));
    res = max(res,call(row-1,col));

    return dp[row][col]=res;
}

void clr(){
    memset(uranium,0,sizeof(uranium));
    memset(radium,0,sizeof(radium));
    memset(dp,-1,sizeof(dp));
}

main()
{
//    freopen("inp.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t,caseno=0;
    cin>>t;
    while(t--){
        cin>>n>>m;
        clr();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>uranium[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>radium[i][j];
                radium[i][j] += radium[i-1][j];
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++){
                uranium[i][j] += uranium[i+1][j];
            }
        }

        cout<<"Case "<<++caseno<<": "<<call(n,m)<<endl;
    }
    return 0;
}
