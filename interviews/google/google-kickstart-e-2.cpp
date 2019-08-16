#include <cstdio>
#include <algorithm>
#include <cstring>

#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)

using namespace std;

const int N=205;

int n,m,p,c[N],idcnt[N],mapid[N];
char s[N][N],f[N][N];
char ac[N];

struct node{
 char ans[N];
 int cost, pos;
 
 void rever(int i){
  if(ans[i]=='1')
   ans[i]='0';
  else ans[i]='1';
 }
}cc[N*N],*ccp[N];

inline bool cmp(const node *i,const node *j){
 return i->cost<j->cost;
}

bool check(char *a){
 rep(i,1,m){
  bool flag=true;
  rep(j,1,p){
   if(a[j]!=f[i][j])
    break;
   if(j==p) flag=false;
  }
  if(!flag)
   return false;
 }
 return true;
}

void solve(){
 memset(cc,0,sizeof(cc));
 memset(ccp,0,sizeof(ccp));
 memset(s,0,sizeof(s));
 memset(f,0,sizeof(f));
 memset(ac,0,sizeof(ac));
 memset(idcnt,0,sizeof(idcnt));
 memset(mapid,0,sizeof(mapid));
 memset(c,0,sizeof(c));

 scanf("%d%d%d",&n,&m,&p);
 //printf("%d\n",n);
 //exit(0);
 rep(i,1,n)
  scanf("%s",s[i]+1);
 rep(i,1,m)
  scanf("%s",f[i]+1);
 int ans=0;
 rep(i,1,p){
  c[i]=0;
  rep(j,1,n) if(s[j][i]=='1') ++c[i];
  //printf("~ %d\n",c[i]);
  if (c[i] > n-c[i]){
   ans+=n-c[i];
   c[i]=c[i]-(n-c[i]);
   ac[i]='1';
  }
  else{
   ans+=c[i];
   c[i]=(n-c[i])-c[i];
   ac[i]='0';
  }
 //printf("%d %d\n",n,c[i]);
 }
 rep(i,1,p){
  memcpy(cc[i].ans, ac, sizeof(ac));
  cc[i].cost=ans+c[i];
  cc[i].pos=i;
  cc[i].rever(i);
 }
 if(check(ac)){
  printf("%d\n",ans);
  return;
 }
 //printf("%d\n",ans);
 rep(i,1,p) ccp[i]=cc+i;
 sort(ccp+1,ccp+1+p,cmp);
 rep(i,1,p){
  idcnt[i]=ccp[i]->pos;
  mapid[ccp[i]->pos]=i;
 }
 
 int maxcnt=p, ccpcnt=p;
 //exit(0);
 //return;
 // printf("! %d %d\n",maxcnt,ccpcnt);
 rep(i,1,100){
  if(check(ccp[1]->ans)){
   printf("%d\n",ccp[1]->cost);
   //exit(0);
   return;
  }
  //puts("hereis");
  int mapi = mapid[ccp[1]->pos];
  //printf("%d\n",mapi);
  rep(j,mapi+1,p){
   int idi = idcnt[j];
   memcpy(cc[++maxcnt].ans,ccp[1]->ans,sizeof(ac));
   cc[maxcnt].rever(idi);
   cc[maxcnt].cost=ccp[1]->cost+c[idi];
   cc[maxcnt].pos=idi;
   ccp[++ccpcnt]=cc+maxcnt;
  }
  //printf("~~ %d %d\n",maxcnt,ccpcnt);
  rep(j,2,ccpcnt)
   ccp[j-1]=ccp[j];
  ccpcnt--;
  sort(ccp+1,ccp+1+ccpcnt,cmp);
  if(ccpcnt>100) ccpcnt=100;
  //printf("!! %d %d\n",maxcnt,ccpcnt);
 }
 puts("error!");
}

int main(){
 freopen("1.txt","r",stdin);
 freopen("2.txt","w",stdout);
 
 int t;
 scanf("%d",&t);
 rep(ca,1,t){
  printf("Case #%d: ", ca);
  solve();
 }
}