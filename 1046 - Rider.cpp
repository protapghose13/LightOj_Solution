#include <bits/stdc++.h>
#define mx 20011
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define xx first
#define yy second
//#define int long long
#define SIZE 100011
#define ll long long

using namespace std;

const int inf=1000000000;

int fx[]={1,1,2,2,-1,-1,-2,-2};
int fy[]={2,-2,1,-1,2,-2,1,-1};


int n,m;
map<string,int>mymap,mymap1;
int vis[22][22];
int ans[22][22];

bool ok(int x,int y){
    return (  x>=0 && x<n && y>=0 && y<m && vis[x][y]==0 );
}

void bfs(int s1,int s2){
    queue< pair<int, pair<int,int> > >myq;
    memset(vis,0,sizeof(vis));
    vis[s1][s2]=1;
    myq.push(mp(1,mp(s1,s2)));
    while(!myq.empty()){
        int d=myq.front().xx;
        int x=myq.front().yy.xx;
        int y=myq.front().yy.yy;
        myq.pop();
        for(int i=0;i<8;i++){
            int p=fx[i]+x;
            int q=fy[i]+y;
            if(ok(p,q)){
                vis[p][q]=vis[x][y]+1;
                myq.push(mp(vis[p][q],mp(p,q)));
            }
        }
    }
    return;
}

void solve(int x,int y,int p){
    bfs(x,y);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j]==0)ans[i][j]=inf;
            else{
                vis[i][j]--;
                ans[i][j] += (vis[i][j]/p)+(vis[i][j]%p!=0);
            }
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
        memset(ans,0,sizeof(ans));
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            for(int j=0;j<m;j++){
                if( s[j] != '.'){
                    solve(i,j,s[j]-48);
                }
            }
        }
        int ans1=inf;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans1=min(ans1,ans[i][j]);
            }
        }
        cout<<"Case "<<++caseno<<": ";
        if(ans1==inf)cout<<"-1"<<endl;
        else cout<<ans1<<endl;
    }
    return 0;
}
