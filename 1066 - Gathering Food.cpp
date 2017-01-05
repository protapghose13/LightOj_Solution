#include <bits/stdc++.h>
#define mx 20
#define mp make_pair
#define pb push_back
#define ll long long
#define mod 1000000007
#define N 10
//#define inf 100000000
#define xx first
#define yy second

using namespace std;

const int inf=1000000;

int fx[]={-1,1,0,0};
int fy[]={0,0,-1,1};

char ara[mx][mx];
int n,m;
int vis[mx][mx];
int vis1[mx][mx],ans[mx][mx];

bool ok(int x,int y,char des,int d){
    return ( x>=0 && x<n && y>=0 && y<n && ara[x][y]!='#' && ara[x][y]<=des && vis1[x][y]!=d );
}

int bfs(int s1,int s2,char des,int d){
    queue<pair<int,int> >myq;
    myq.push(mp(s1,s2));
    vis[s1][s2]=1;
    vis1[s1][s2]=d;
    while(!myq.empty()){
        int x=myq.front().xx;
        int y=myq.front().yy;
        if(ara[x][y]==des)
            return vis[x][y];
        myq.pop();
        for(int i=0;i<4;i++){
            int p=x+fx[i];
            int q=y+fy[i];
            if(ok(p,q,des,d)){
                vis[p][q]=1;
                vis1[p][q]=d;
                vis[p][q]=vis[x][y]+1;
                myq.push(mp(p,q));
            }
        }
    }
    return inf+1;
}



int main()
{
 //   freopen("in.txt","r",stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin>>t;
    int caseno=0;
    while(t--){
        cin>>n;
        int d1,d2;
        char aa='A';
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>ara[i][j];
                if(ara[i][j]>='A'&&ara[i][j]<='Z'){
                    aa = max(aa,ara[i][j]);
                }
            }
        }
        memset(vis1,0,sizeof(vis1));

        int k=1;
        int ans=0;
        for(char c='A';c<aa;c++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(ara[i][j]==c){
                        ans += bfs(i,j,c+1,k++)-1;
                    }
                }
            }
        }

        cout<<"Case "<<++caseno<<": ";
        if(ans>=inf)cout<<"Impossible"<<endl;
        else cout<<ans<<endl;

    }
}
