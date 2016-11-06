//http://lightoj.com/volume_showproblem.php?problem=1159

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define mx 100010
#define mod 1000000007
//#define int long long
#define pi acos(-1.0)
#define inf 1000000000000000001

using namespace std;

string s1,s2,s3;
int l1,l2,l3;

int dp[51][51][51];

int call(int x,int y,int z){
    if(x==l1 || y==l2 || z==l3)
        return 0;

    if(dp[x][y][z]!=-1)
        return dp[x][y][z];

    int res;
    if(s1[x]==s2[y] && s2[y]==s3[z]){
        res = 1+call(x+1,y+1,z+1);
    }
    else{
        res = max(max(call(x+1,y,z),call(x,y+1,z)),call(x,y,z+1));
    }
    return dp[x][y][z]=res;
}


main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin>>t;
    int caseno=0;
    while(t--){
        cin>>s1>>s2>>s3;
        l1=s1.length();
        l2=s2.length();
        l3=s3.length();
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<++caseno<<": "<<call(0,0,0)<<endl;
    }
}
