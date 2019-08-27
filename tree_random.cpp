#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define int long long int
#define F first
#define S second
#define mod 1000000007
#define Max 200005
void fast(){
   ios_base::sync_with_stdio(false);
   cin.tie(0); cout.tie(0);
}
int ans=0,arr[Max];
void ini(){
   for(int i=0;i<=Max;i++)
      arr[i]=i;
}
int root(int i){
   if(arr[i]==i)return i;
   return arr[i]=root(arr[i]);
}

int union1(int x,int y,int val1,int val2)
{
   int xx=root(x);
   int yy=root(y);
   if(xx!=yy){
      ans+=val1;
      arr[xx]=yy;
      cout<<x<<" "<<y<<" "<<val1<<" "<<val2<<endl;return 1;
   }
   else {
   	return 0;
      // have cycle
   }
}
main() {
   //fast();
   ini();
   freopen("test19.txt","w",stdout);
	srand(time(NULL));
	//fclose(stdout);
	//freopen("test1.txt","w",stdout);
	int n=20000;
	int i=1;
	cout<<n<<" "<<(rand()%1000)<<endl;
	while(i<n){
		int x=rand()%n;x++;
		int y=rand()%n;y++;
		int w1=rand()%100;
		int w2=rand()%100;
		if(w2>w1)swap(w1,w2);
		i+=union1(x,y,w1,w2);
	}
	fclose(stdout);
	
	return 0;
}








