#include <bits/stdc++.h>
#define mx 201
#define mp make_pair
#define pb push_back
#define ll long long
#define mod 1000000007
#define N 10
#define inf 100000000
#define xx first
#define yy second

using namespace std;


int fx[]={-1,1,0,0};
int fy[]={0,0,-1,1};

char ara[mx][mx];
int n,m;
int vis[mx][mx];
int vis1[mx][mx],ans[mx][mx];
vector<int>vec,vec1;

bool ok(int x,int y,int d){
    return ( x>=0 && x<n && y>=0 && y<m && ara[x][y]!='#' && vis[x][y]!=d );
}

void bfs(int s1,int s2,int d){
    queue<pair<int,int> >myq;
    myq.push(mp(s1,s2));
    vis1[s1][s2]=1;
    vis[s1][s2]=d;
    vec.clear();
    vec1.clear();
    bool flag=0;
    while(!myq.empty()){
        int x=myq.front().xx;
        int y=myq.front().yy;
        myq.pop();
        for(int i=0;i<4;i++){
            int p=x+fx[i];
            int q=y+fy[i];
            if(ok(p,q,d)){
                vis[p][q]=d;
                vis1[p][q]=vis1[x][y]+1;
                myq.push(mp(p,q));
                if(ara[p][q]=='J'){
                    vec.pb(vis1[p][q]);
                }
                if(ara[p][q]=='F'){
                    vec1.pb(vis1[p][q]);
                    flag=1;
                }
                if(vec.size()){
                    if(vis1[p][q]>vec[0])
                        flag=1;
                }
            }
            if(flag)break;
        }
        if(flag)break;
    }
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
        cin>>n>>m;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>ara[i][j];
            }
        }
        memset(vis,0,sizeof(vis));
        int k=1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( (i==0 || j==0 || i==n-1 || j==m-1) && ara[i][j]=='.'){
                    bfs(i,j,k);
                    k++;
                    if(vec1.size()==0){
                        if(vec.size())
                            ans = min(ans,vec[0]);
                    }
                    else{
                        if(vec.size()==0)continue;
                        else{
                            if(vec[0]<vec1[0])ans=min(ans,vec[0]);
                        }
                    }
                }
            }
        }
        cout<<"Case "<<++caseno<<": ";
        if(ans==INT_MAX)cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans<<endl;

    }
}
