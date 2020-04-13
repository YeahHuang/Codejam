//#include <bits/stdc++.h>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
#include <unordered_map>
#include <memory.h>
#include <set>
#include <functional>
using namespace std;



#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pli pair<ll, int>
#define pil pair<int, ll>
#define clr(a, x) memset(a, x, sizeof(a))
#define sz(a) (int)a.size()
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i > (l); --i)
#define fto(i, l, r) for(int i = (l); i < (r); ++i)

const double pi = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}
/*

10:27 - 

r-th row, k-th position 从1开始计数

(r,k) = (r-1, k-1) + (r-1, k)

That is, for all i ≥ 1, (ri + 1, ki + 1) must be one of the following that is within the triangle: 
(ri - 1, ki - 1), (ri - 1, ki), (ri, ki - 1), (ri, ki + 1), (ri + 1, ki), (ri + 1, ki + 1).

不能重复走
保证存在
走<=500 

small1: 直接 1 2 1 1 1 1 1 1
假定不往回走

dp[i][j][num] = dp[i-1][j-1][num - t[i][j]]
i-1, j
i, j-1

1 1
3 2
5 3

7 4

*/


const int N = 30; // 这样更好 防止下面弄着弄着就少了个0
int q,p1,p2,T, n,cnt, l,r;
bool flag;
string s;
bool debugg = true;
bool test = true;
vector<int> ans;
const int NOT_EXIST = -1;
const int maxN = 1005;

int trans(int i,int j){
    return i*500 + j;
}

int main(){
    //ios_base::sync_with_stdio(0);
    cin>>T;

    int tr[N][N];
    int fa[N][N][maxN];

    int dabiao[maxN];
    clr(dabiao,0);
    fto(i, 0, N)
        fto(j,0,N)
            fto(k, 0, maxN)
                fa[i][j][k] = NOT_EXIST;
    tr[1][1] = 1;    
    fto(i, 2, N){
        tr[i][1] = 1;
        tr[i][i] = 1;
        fto(j, 2, i)
            tr[i][j] = tr[i-1][j-1] + tr[i-1][j];  
    }



    fa[1][1][1] = 0;
    int sum = 1;
    fto(i, 2, N){
        sum += 1;
        fa[i][1][i] = trans(i-1,1);
        if (dabiao[i] ==0 ) 
            dabiao[i] = trans(i,1);

        /*for (int num = i; num <= min(1000,sum); num ++){
            if ((fa[i-1][1][num-1])!=-1)
                fa[i][1][num] = trans(i-1, 1);
            if (dabiao[num]==0 && fa[i])
        }*/
        //if (debugg) debug(i);
        fto(j, 2, i){
            sum += tr[i][j];
            for (int num = max(tr[i][j], i); num <= min(1000,sum); num ++){
                if ((fa[i-1][j-1][num-tr[i][j]])!=-1)
                    {
                        fa[i][j][num] = trans(i-1, j-1);
                    }
                else if ((fa[i-1][j][num-tr[i][j]])!=-1)
                    {
                        fa[i][j][num] = trans(i-1, j);
                    }
                else if ((fa[i][j-1][num-tr[i][j]])!=-1)
                    {
                        fa[i][j][num] = trans(i, j-1);
                    }
                if (dabiao[num]==0 && fa[i][j][num]!=NOT_EXIST)
                    dabiao[num] = trans(i,j);
            }
        }

        sum += tr[i][i];
        int j = i; 
        for (int num = max(tr[i][j], i); num <= min(1000,sum); num ++){
                if ((fa[i-1][j-1][num-tr[i][j]])!=-1)
                    {
                        fa[i][j][num] = trans(i-1, j-1);
                    }
                else if ((fa[i][j-1][num-tr[i][j]])!=-1)
                    {
                        fa[i][j][num] = trans(i, j-1);
                    }
                if (dabiao[num]==0 && fa[i][j][num]!=NOT_EXIST)
                    dabiao[num] = trans(i,j);
            }
    }

    if (test)
        fto(n, 1, 1001){
            cout<<dabiao[n]/500<<","<<dabiao[n]%500<<" ";
            if (n%10==0)
                cout<<endl;
        }

void dfs(ll n, int x, int y){
    if (y<=1 || y>x) return;
    if (x<N)
        if (fa[x][y][n]!=NOT_EXIST){
            found = true;
            return;
        }
    if (rand()%2 == 1){
        dfs(n-tr[x][y], x-1, y);
        if (found) return;
        dfs(n-tr[x][y], x, y-1);
    }
    else{
        dfs(n-tr[x][y], x-1, y-1);
        if (found) return;
        dfs(n-tr[x][y], x, y-1);
    }
    if (found) return;
}

    fto(it,0,T){

        cin>>n;

        ans.clear();
        bool found = false;
        int next = 0;

        int father = dabiao[n];
        int cur = n;
        while (father != 0)
        {
            ans.pb(father);
            next = fa[father/500][father%500][cur];
            cur -= tr[father/500][father%500];
            father = next;
        }
                
        if (n==1){
            ans.pb(trans(1,1));
        }
        reverse(ans.begin(), ans.end());
    
        cout << "Case #" << it + 1 << ": "<<endl;
        for (auto p: ans){
            cout<<p/500<<" "<<p%500<<endl;
        }
        
    }
}
