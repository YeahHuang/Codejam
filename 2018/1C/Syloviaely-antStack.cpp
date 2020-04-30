#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int lim=200,N=100010;
long long dp[lim+2];
int n,w[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	memset(dp,0x3f,sizeof dp); dp[0]=0;
	for (int i=1;i<=n;i++){
		for (int j=lim;j>=0;j--)
			if (dp[j]<=6ll*w[i]) dp[j+1]=min(dp[j+1],dp[j]+w[i]);
	}
	int ans=0;
	while (dp[ans]<=1e18) ans++;
	printf("%d\n",ans-1);
}
int main(){
	int t; scanf("%d",&t);
	for (int i=1;i<=t;i++){
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}