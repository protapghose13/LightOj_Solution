#include <bits/stdc++.h>
#define mx 9
#define mp make_pair
#define pb push_back
#define ll long long
#define mod 1000000007
#define N 10
#define inf 100000000

using namespace std;

struct node{
    int x,y;
};
bool cmp1(node p,node q){
    return p.x<q.x;
}
bool cmp2(node p,node q){
    return p.x>q.x;
}
bool cmp3(node p,node q){
    return p.y<q.y;
}
bool cmp4(node p,node q){
    return p.y>q.y;
}


int fx[]={-1,1,0,0};
int fy[]={0,0,-1,1};

char ara[mx][mx];
int n;
int a1,a2,b1,b2,c1,c2;
int flag[mx][mx][mx][mx][mx][mx];
int ans;

bool isValid(int x1,int x2,int y1,int y2,int z1,int z2){
    if(x1==y1 && x2==y2)return false;
    else if(y1==z1 && y2==z2)return false;
    else if(x1==z1 && x2==z2)return false;
    else if(flag[x1][x2][y1][y2][z1][z2])return false;
    else return true;
}

bool Ok(int x1,int x2,int y1,int y2,int z1,int z2){
    if(ara[x1][x2]!='X')return false;
    else if(ara[y1][y2]!='X')return false;
    else if(ara[z1][z2]!='X')return false;
    else return true;
}

bool isRight(int x,int y){
    if(x<0)return true;
    else if(x>=n)return true;
    else if(y<0)return  true;
    else if(y>=n) return true;
    return false;
}

bool Set(int p1,int p2,int q1,int q2,int r1,int r2,int val){
    flag[p1][p2][q1][q2][r1][r2] = val;
    flag[p1][p2][r1][r2][q1][q2] = val;
    flag[q1][q2][p1][p2][r1][r2] = val;
    flag[q1][q2][r1][r2][p1][p2] = val;
    flag[r1][r2][q1][q2][p1][p2] = val;
    flag[r1][r2][p1][p2][q1][q2] = val;
}

int bfs(){
    queue<int>myqueue;
    myqueue.push(a1);
    myqueue.push(a2);
    myqueue.push(b1);
    myqueue.push(b2);
    myqueue.push(c1);
    myqueue.push(c2);
    Set(a1,a2,b1,b2,c1,c2,1);
    int x1,x2,y1,y2,z1,z2;
    int p1,p2,q1,q2,r1,r2;
    while(!myqueue.empty()){
        x1=myqueue.front();myqueue.pop();
        x2=myqueue.front();myqueue.pop();
        y1=myqueue.front();myqueue.pop();
        y2=myqueue.front();myqueue.pop();
        z1=myqueue.front();myqueue.pop();
        z2=myqueue.front();myqueue.pop();

        for(int i=0;i<4;i++){
            node data[3];
            data[0].x=x1+fx[i],data[0].y=x2+fy[i];
            data[1].x=y1+fx[i],data[1].y=y2+fy[i];
            data[2].x=z1+fx[i],data[2].y=z2+fy[i];

            if(i==0)sort(data,data+3,cmp1);
            else if(i==1)sort(data,data+3,cmp2);
            else if(i==2)sort(data,data+3,cmp3);
            else sort(data,data+3,cmp4);

            int tt1=0,tt2=0;
            p1=data[0].x,p2=data[0].y,q1=data[1].x,q2=data[1].y,r1=data[2].x,r2=data[2].y;
            if(isRight(p1,p2) || ara[p1][p2]=='#') {
                p1=p1-fx[i],p2=p2-fy[i],tt1=1;
            }
            if( isRight(q1,q2) || ara[q1][q2]=='#' ||(tt1&&q1==p1 && q2==p2)) {
                q1=q1-fx[i],q2=q2-fy[i],tt2=1;
            }
            if(isRight(r1,r2) || ara[r1][r2]=='#' || (tt2&&q1==r1 && q2==r2) || (tt1&&p1==r1 && p2==r2)) {
                r1=r1-fx[i],r2=r2-fy[i];
            }

            if(isValid(p1,p2,q1,q2,r1,r2)){
                Set(p1,p2,q1,q2,r1,r2,flag[x1][x2][y1][y2][z1][z2]+1);
                if(Ok(p1,p2,q1,q2,r1,r2)) return flag[p1][p2][q1][q2][r1][r2];
                myqueue.push(p1);
                myqueue.push(p2);
                myqueue.push(q1);
                myqueue.push(q2);
                myqueue.push(r1);
                myqueue.push(r2);
            }
        }
    }
    return -1;
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

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>ara[i][j];
                if(ara[i][j]=='A'){
                    a1=i,a2=j;
                }
                else if(ara[i][j]=='B'){
                    b1=i,b2=j;
                }
                else if(ara[i][j]=='C'){
                    c1=i,c2=j;
                }
            }
        }

        memset(flag,0,sizeof(flag));
        ans=INT_MAX;

        int p=bfs();
        cout<<"Case "<<++caseno<<": ";
        if(p==-1)cout<<"trapped"<<endl;
        else cout<<p-1<<endl;
    }
}
