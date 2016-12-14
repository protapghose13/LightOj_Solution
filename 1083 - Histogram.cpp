#include <bits/stdc++.h>
#define mx 30022
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

int tree[4*mx],ara[mx],n,m;

int histogram(){
    stack<int>mystk;
    int top;
    int ans=0;
    int area;
    for(int i=0;i<=n;){/// 0 based index & in the nth pos insert 0 or -1
        if(mystk.empty()){
            mystk.push(i);
            i++;
        }
        else if(ara[i]>=ara[mystk.top()]){
            mystk.push(i);
            i++;
        }
        else{
            top = mystk.top();
            mystk.pop();
            if(mystk.empty()){
                area = ara[top]*i;
            }
            else{
                area = ara[top] * (i-mystk.top()-1);
            }
            ans = max(ans,area);
        }
    }
    return ans;
}

int main() {
    int caseno=0,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        for(int i=1;i<=n;i++){
            scanf("%d",&ara[i-1]);
        }
        ara[n]=0;
        printf("Case %d: %d\n",++caseno,histogram());
    }
}
