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
cart: street intersection

正方形 边长为q 0..Q [0,Q]


distance: xi - xj + yi - yj

P people

north: y+1
south: y-1
east: x+1
west: x-1

crepe: instersection 大多数人travelling去的地方
多个接的时候 x尽量小 然后y尽量小

p, q
p more lines xi, yi, di(direction)

线段树？ 每一个就能弄一片 

或者因为P<=500 

吃到1.5min
12:10开始写


12:59 提交large 一直WA
 13:23 pass
*/

const int N = 100; // 这样更好 防止下面弄着弄着就少了个0
int q,p1,p2,T, x,y, n,cnt[N][N], dx, dy, l,r;
bool flag;
char d;
string s;
bool debugg = false;
bool test = true;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>T;
    fto(it,0,T){

        cin>>n>>q;
        fto(i,0,N)
            fto(j,0,N)
                cnt[i][j] = 0;
        
        vector<int> N, S, E, W;
        N.clear();S.clear();E.clear();W.clear();
        //N.pb(0);
        //E.pb(0);
        fto(i,0,n){
            cin>>x>>y>>d;
            switch (d){
                case 'N':{N.pb(y+1);break;}
                case 'S':{S.pb(y); break;}
                case 'E':{E.pb(x+1);break;}
                case 'W':{W.pb(x);break;}
                default: cout<<"ERROR d not in N, E, S, W"<<endl;
            };
        }

        pair<int, int> ans = make_pair(0,0);
        sort(N.begin(), N.end());sort(S.begin(), S.end());
        sort(W.begin(), W.end());sort(E.begin(), E.end());

        if (debugg) {
            debuga1(N, 0, N.size());
            debuga1(S, 0, S.size());
        }
        int idx = 0, maxX = S.size();
        fto(i, 0, N.size())
        {
            //make sure N[i] < S[idx]
            while (idx < S.size() && N[i] >= S[idx])
            //while (idx < S.size() && N[i] > S[idx])
            //while (N[i] >= S[idx] && idx < S.size()) 
                idx ++;
            //if idx == S.size()
            if (i+1 + S.size()-idx <= maxX){
                //ans.second = N[i-1];
                //break;
            } else{
                maxX = i+1 + S.size() - idx;
                //if (i == N.size()-1)
                    ans.second = N[i];
            }
        }

        idx = 0, maxX = W.size();
        fto(i, 0, E.size())
        {
            //make sure N[i] < S[idx]
            while (idx < W.size() && E[i] >= W[idx]) 
                idx ++;
            if (i+1 + W.size() - idx <= maxX){
                //ans.first= E[i-1];
                //break;
            } else{
                maxX = i+1 + W.size() - idx;
                //if (i == E.size()-1){
                    ans.first = E[i];
                }
            
        }
        /*int maxCnt = 0;
        fto(i,0,q+1)
            fto(j,0,q+1)
                if (cnt[i][j] > maxCnt)
                {
                    maxCnt = cnt[i][j];
                    ans.first = i;
                    ans.second = j;
                }*/


    
        cout << "Case #" << it + 1 << ": "<<ans.first<<" "<<ans.second<<endl;
    }
}

            /*switch (d){
                case 'N': fto(i, 0, q+1)
                            fto(j, y+1, q+1)
                                cnt[i][j]++;
                          break;

                case 'S': fto(i, 0, q+1)
                            fto(j, 0, y)
                                cnt[i][j]++;
                          break;

                case 'E': fto(i, x+1, q+1)
                            fto(j, 0, q+1)
                                cnt[i][j]++;
                          break;
                case 'W': fto(i, 0, x)
                            fto(j, 0, q+1)
                                cnt[i][j]++;
                          break;
                default:cout<<"ERROR d not in N, E, S, W"<<endl;
    
            };*/
            /*switch (d){
                case 'N':{dx = 0; dy = 1; break;}
                case 'S':{dx = 0; dy = -1; break;}
                case 'E':{dx = 1; dy = 0; break;}
                case 'W':{dx = -1; dy = 0; break;}
                default: cout<<"ERROR d not in N, E, S, W"<<endl;
            };
            if (debugg) debug(i);
            x += dx;
            y += dy;
            //while (0<=x<=q && 0<=y<=q){
            while (0<=x && x<=q && 0<=y && y<=q){
                cnt[x][y]++;
                x += dx;
                y += dy;
                if (debugg) {cout<<x<<","<<y<<" ";};
            }*/