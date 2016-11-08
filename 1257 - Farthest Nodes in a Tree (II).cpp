#include <bits/stdc++.h>
#define mx 30011
#define pb push_back

using namespace std;

vector<int>vec[mx],cost[mx];
int dp[mx];
int maxval,maxnode;

void dfsAns(int node,int par,int cst){
    if(cst>maxval){
        maxval=cst;
        maxnode=node;
    }
    dp[node]=max(dp[node],cst);
    int sz=vec[node].size();
    for(int i=0;i<sz;i++){
        int v=vec[node][i];
        if(v==par)continue;
        dfsAns(v,node,cst+cost[node][i]);
    }
}


void clr(int n){
    for(int i=0;i<n;i++){
        vec[i].clear();
        cost[i].clear();
        dp[i]=0;
    }
}

int main()
{
    int t,n;
    scanf("%d",&t);
    int caseno=0;
    while(t--){
        scanf("%d",&n);
        clr(n);
        for(int i=1;i<n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            vec[u].pb(v);
            vec[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        maxval=-1;
        dfsAns(0,-1,0);
        maxval=-1;
        dfsAns(maxnode,-1,0);
        dfsAns(maxnode,-1,0);
        printf("Case %d:\n",++caseno);
        for(int i=0;i<n;i++){
            printf("%d\n",dp[i]);
        }
    }
}
