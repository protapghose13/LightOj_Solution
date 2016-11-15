#include <bits/stdc++.h>
#define mx 20001
#define pb push_back
//#define int long long
#define mod 100000007

using namespace std;

vector<int>vec[mx],graph[mx],rev_vec[mx];
bool vis[mx];
stack<int>st;
int n,m;
int scc;
int belong[mx];
bool in[mx],out[mx];

void dfs(int node){
    vis[node]=1;
    int sz=vec[node].size();
    for(int i=0;i<sz;i++){
        int v=vec[node][i];
        if(vis[v]==0){
            dfs(v);
        }
    }
    st.push(node);
}

void dfs1(int node){
    vis[node]=1;
    belong[node]=scc;
    int sz=rev_vec[node].size();
    for(int i=0;i<sz;i++){
        int v=rev_vec[node][i];
        if(vis[v]==0){
            dfs1(v);
        }
    }
}

void dfs2(int node){
    vis[node]=1;
    int sz=vec[node].size();
    for(int i=0;i<sz;i++){
        int v=vec[node][i];
        if(belong[node]!=belong[v]){
            graph[ belong[node] ].pb(belong[v]);
        }
        if(vis[v]==0){
            dfs2(v);
        }
    }
}

void dfs3(int node){
    vis[node]=1;
    int sz=graph[node].size();
    for(int i=0;i<sz;i++){
        int v=graph[node][i];
        out[node]=1;
        in[v]=1;
        if(vis[v]==0){
            dfs3(v);
        }
    }
}

void clr(){
    for(int i=0;i<mx;i++){
        vec[i].clear();
        graph[i].clear();
        rev_vec[i].clear();
    }

}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(false);

    int t;
    cin>>t;
    int caseno=0;
    while(t--){
        cin>>n>>m;
        clr();
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            vec[u].pb(v);
            rev_vec[v].pb(u);
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                dfs(i);
            }
        }
        memset(vis,0,sizeof(vis));
        scc=0;
        while(!st.empty()){
            if(vis[st.top()]==0){
                scc++;
                dfs1(st.top());
            }
            st.pop();
        }
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                dfs2(i);
            }
        }
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=scc;i++){
            if(vis[i]==0){
                dfs3(i);
            }
        }
        int ind=0,outd=0;

        for(int i=1;i<=scc;i++){
            if(in[i]==0)ind++;
            if(out[i]==0)outd++;
        }
        if(scc==1){
            cout<<"Case "<<++caseno<<": 0"<<endl;
        }
        else{
            cout<<"Case "<<++caseno<<": "<<max(ind,outd)<<endl;
        }

    }
}
