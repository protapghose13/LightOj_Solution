#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define inf 1000000
#define mod 1000000007

using namespace std;

const int MAXN = 30;
const int MAXE = 1001;

struct dir_eulerian
{
    size_t ne;
    int N, last[MAXN],to[MAXE],next[MAXE],cur[MAXN];
    int in[MAXN],out[MAXN];
    int start,end;
    vector<int> path;

    dir_eulerian() {}

    void clear(int V_)
    {
        N = V_;
        ne = 0;
        memset(last,-1,sizeof last);
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
    }

    void add_edge(int u, int v)
    {
        to[ne] = v;
        next[ne] = last[u];
        last[u] = ne++;
        ++out[u];
        ++in[v];
        start = u;
    }

    bool check()
    {
        int cont = 0, aux = start;
        start = end = -1;
        for (int i = 0; i < N; ++i)
        {
            if (in[i] == out[i]) ++cont;
            else if (out[i] == in[i] + 1) start = i;
            else if (in[i] == out[i] + 1) end = i;
            else return false;
        }

        if (cont == N)
        {
            start = end = aux;
            return true;
        }

        return (cont == N - 2 && start != -1 && end != -1);
    }

    bool build()
    {
        stack<int> s;
        s.push(start);
        memcpy(cur, last, sizeof last);
        path.clear();

        while (!s.empty())
        {
            int u = s.top();

            if (cur[u] == -1)
            {
                path.push_back(u);
                s.pop();
            }
            else
            {
                int v = to[ cur[u] ];
                cur[u] = next[ cur[u] ];
                s.push(v);
            }
        }

        reverse(path.begin(),path.end());
        return path.size() == ne + 1;
    }
};

dir_eulerian vc;

vector<string>graph[30][30];

void solve(){
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            graph[i][j].clear();
        }
    }

    int n;
    cin>>n;
    vc.clear(26);
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        int u=s[0]-'a';
        int v=s[s.length()-1]-'a';
        vc.add_edge(u,v);
        graph[u][v].pb(s);
    }
    if( vc.check() && vc.build() ){
        cout<<"Yes"<<endl;
        int sz=vc.path.size();
        for(int i=1;i<sz;i++){
            if(i>1)cout<<" ";
            int u=vc.path[i-1];
            int v=vc.path[i];
            cout<<graph[u][v].back();
            graph[u][v].pop_back();
        }
        cout<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}

//http://www.graph-magics.com/articles/euler.php

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(false);
//    cout.tie(false);

    int t,caseno=0;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<++caseno<<": ";
        solve();
    }
    return 0;
}
