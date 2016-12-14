#include <bits/stdc++.h>
#define mx 100011
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

#define BLOCK 320

int cnt[mx],answer,a[mx],ans[mx];

struct node {
    int L, R, i;
}q[mx];

bool cmp(node x, node y) {
    if(x.L/BLOCK != y.L/BLOCK) {
        return x.L/BLOCK < y.L/BLOCK;
    }
    return x.R < y.R;
}

void add(int pos){
    if(cnt[a[pos]]==0){
        answer++;
    }
    cnt[ a[pos] ]++;
}

void remove(int pos){
    if(cnt[a[pos]]==1){
        answer--;
    }
    cnt[ a[pos] ]--;
}

int main() {
    int n,c,m,t,l=0;
    scanf("%d",&t);
    while(t--){

        scanf("%d%d", &n,&m);
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);

        for(int i=0; i<m; i++){
            scanf("%d%d", &q[i].L, &q[i].R);
            q[i].L--; q[i].R--;
            q[i].i = i;
        }

        sort(q, q + m, cmp);

        int currentL = 0, currentR = 0;
        for(int i=0; i<m; i++) {
            int L = q[i].L, R = q[i].R;
            while(currentL < L) {
                remove(currentL);
                currentL++;
            }
            while(currentL > L) {
                add(currentL-1);
                currentL--;
            }
            while(currentR <= R) {
                add(currentR);
                currentR++;
            }
            while(currentR > R+1) {
                remove(currentR-1);
                currentR--;
            }
            ans[q[i].i] = answer;
        }

        printf("Case %d:\n",++l);
        for(int i=0; i<m; i++)
            printf("%d\n", ans[i]);

        answer=0;
        memset(cnt,0,sizeof(cnt));

    }
}
