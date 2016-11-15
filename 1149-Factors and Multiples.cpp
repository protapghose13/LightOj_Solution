#include <bits/stdc++.h>
#define mx 1001
#define pb push_back
//#define int long long
#define mod 100000007

using namespace std;

int n,m;
int ara[101],ara1[201];
bool arr[210][210];
bool vis[210];
int par[210];

int bfs(int src,int des){
    memset(vis,0,sizeof(vis));
    memset(par,0,sizeof(par));
    queue<int>myqueue;
    myqueue.push(src);
    vis[src]=1;
    par[src]=src;
    while(!myqueue.empty()){
        int u=myqueue.front();
        myqueue.pop();
        for(int i=0;i<210;i++){
            if(arr[u][i] && vis[i]==0){
                vis[i]=1;
                par[i]=u;
                myqueue.push(i);
                if(i==des)return 1;
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int t;
    cin>>t;
    int caseno=0;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>ara[i+1];
        }
        cin>>m;
        for(int i=0;i<m;i++){
            cin>>ara1[i+101];
        }
        for(int i=0;i<m;i++){
            for(int j=1;j<=n;j++){
                if(ara1[i+101]%ara[j]==0){
                    arr[j][i+101]=1;
                }
                arr[0][j]=1;
            }
            arr[i+101][205]=1;
        }
        int ans=0;
        while(1){
            int p=bfs(0,205);
            if(p==0)break;
            ans++;
            int u=205;
            while(par[u]!=u){
                int v=par[u];
                arr[v][u]=0;
                arr[u][v]=1;
                u=v;
            }
        }
        cout<<"Case "<<++caseno<<": "<<ans<<endl;
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
