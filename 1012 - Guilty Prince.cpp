#include <bits/stdc++.h>
#define mx 20011
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
#define inf 1000000000000000
//#define int long long
#define SIZE 100011
#define ll long long

using namespace std;

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};

vector<int>vec[mx];
bool vis[22][22];
int n,m;
int cnt1,cnt2;
string s[22];
int ans;

bool ok(int x,int y){
    return (  x<m && x>=0 && y>=0 && y<n && vis[x][y]==0 && s[x][y]!='#' );
}

void dfs(int x,int y){
    for(int i=0;i<4;i++){
        int p=fx[i]+x;
        int q=fy[i]+y;
        if(ok(p,q)){
            ans++;
            vis[p][q]=1;
            dfs(p,q);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t,caseno=0;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        int x,y;
        for(int i=0;i<m;i++){
            cin>>s[i];
            for(int j=0;j<n;j++){
                if(s[i][j]=='@'){
                    x=i,y=j;
                }
            }
        }
        ans=1;
        vis[x][y]=1;
        dfs(x,y);
        cout<<"Case "<<++caseno<<": "<<ans<<endl;
    }
    return 0;
}
