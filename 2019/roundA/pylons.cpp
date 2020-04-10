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
7:32 - 

r*c visit each cell 刚好1次

不能跳到
r = r'
c = c'
r - c = r' - c'
r + c = r' + c'
的地方

也就是不共行 共列 共对角线

小的 2..5 我又想枚举了emmm 忍住！
大的 2..20

1. 因为对称性 所以第一个点只用枚举左上角

本地跑着算 

7:48 开始

*/

const int N = 1e5 + 10; // 这样更好 防止下面弄着弄着就少了个0
int q,p1,p2,ans,T, m, n,cnt,  l,r;
bool flag;
bool debugg = false;
bool test =  false;
bool nmflag;

vector<pair<int, int> > ans_route,v,r34, r35, r36, r37, r43, r44, r45, r52, r53, r25, r26, r27, r28,r29;

void dfs(int x, int y, vector<pair<int, int> > route, set<int> visited){
    
    pair<int, int> p;
    p.first = x;
    p.second = y;
    route.pb(p);
    visited.insert(x*10+y);
    if (route.size() == m*n){
        flag = true;
        ans_route = route;
        return;
    }
    for(int i=1; i<=m; i++)
        if (i!=x)
            for( int j=1; j<=n; j++)
                if (j!=y && i+j!=x+y && i-j!=x-y && visited.find(i*10+j)==visited.end())
                    dfs(i, j, route, visited);
    route.pop_back();
    visited.erase(x*10+y);
}


vector<pair<int, int> > solve_small(){
    ans_route.clear();
    set<int> s;
    if (m==4&&n==4){
            ans_route.pb(make_pair(1,1));
            ans_route.pb(make_pair(4,3));
            ans_route.pb(make_pair(3,1));
            ans_route.pb(make_pair(4,4));
            ans_route.pb(make_pair(3,2));
            ans_route.pb(make_pair(2,4));

            ans_route.pb(make_pair(4,1));
            ans_route.pb(make_pair(1,2));
            ans_route.pb(make_pair(3,3));
            ans_route.pb(make_pair(2,1));

            ans_route.pb(make_pair(1,4));
            ans_route.pb(make_pair(2,2));
            ans_route.pb(make_pair(3,4));
            ans_route.pb(make_pair(1,3));
            ans_route.pb(make_pair(4,2));
            ans_route.pb(make_pair(2,3));

            /*cout << "Case #" << it + 1 << ": POSSIBLE"<<endl;
            for(auto p: ans_route)
                cout<<p.first<<" "<<p.second<<endl;
            continue;*/
            return ans_route;
        } else{

        bool hyh = false;
        int aha[5][9];
        if (m==5 && n==5)
        {
            int t[5] = {11, 2, 14, 23, 17};
            //int aha[5][5];
            fto(i,0,5) aha[0][i] = t[i];
            int t1[5] = {22, 9, 6, 3,12}; fto(i,0,5) aha[1][i] = t1[i];
            int t2[5] = {19, 4, 1, 8,24}; fto(i,0,5) aha[2][i] = t2[i];
            int t3[5] = {16, 7, 10, 5,20}; fto(i,0,5) aha[3][i] = t3[i];
            int t4[5] = {13, 25, 21, 18,15}; fto(i,0,5) aha[4][i] = t4[i];
            //cout << "Case #" << it + 1 << ": POSSIBLE"<<endl;
            hyh = true;
            
        } else if ((m==4 && n == 5) or (m==5 && n==4)){
            int aha[4][5];
            int t[5] = {2,9,4,11,6}; fto(i,0,5) aha[0][i] = t[i];
            int t1[5] = {18, 12, 1, 8, 16}; fto(i,0,5) aha[1][i] = t1[i];
            int t2[5] = {14, 5, 10, 3,19}; fto(i,0,5) aha[2][i] = t2[i];
            int t3[5] = {7, 17, 20, 15,13}; fto(i,0,5) aha[3][i] = t3[i];
            //cout << "Case #" << it + 1 << ": POSSIBLE"<<endl;
            fto(step, 1, 26)
                fto(i, 0, 4)
                    fto(j,0,5)
                        if (aha[i][j] == step)
                            if (m==4) ans_route.pb(make_pair(i+1,j+1));
                                else ans_route.pb(make_pair(j+1,i+1));
            return ans_route;
            } else if (m == 3 && n==7){
                //int aha[3][7];
                int t[7] = {15, 4, 1, 6, 19, 21, 9}; fto(i,0,7) aha[0][i] = t[i];
                int t1[7] = {20, 11, 13, 3, 8, 16, 18};fto(i,0,7) aha[1][i] = t1[i];
                int t2[7] = {7, 2, 5, 17, 10, 14, 12};fto(i,0,7) aha[2][i] = t2[i];
                hyh = true;
            }
            else if (m == 3 && n==6){
                //int aha[3][6];
                int t[6] = {4, 11, 1, 14,17, 7}; fto(i,0,6) aha[0][i] = t[i];
                int t1[6] = {10,8, 6,3, 12, 15};fto(i,0,6) aha[1][i] = t1[i];
                int t2[6] = {18, 2, 13, 16, 5, 9};fto(i,0, 6) aha[2][i] = t2[i];
                hyh = true;
            } else if( m==3 && n == 5){
                //int aha[3][5];
                int t[5] = {1,15,12,8,10}; fto(i,0,n) aha[0][i] = t[i];
                int t1[5] = {7,9,3,14,5};fto(i,0,n) aha[1][i] = t1[i];
                int t2[5] = {4,13,6,11,2};fto(i,0, n) aha[2][i] = t2[i];
                hyh = true;
                
            } else if (m==2 && n == 8){
                //int aha[2][8];
                int t[8] = {11,9,7,1,15,3,13,5}; fto(i,0,n) aha[0][i] = t[i];
                int t1[8] = {16,14,12,4,10,6,8,2};fto(i,0,n) aha[1][i] = t1[i];
                hyh = true;
            } else if (m==2 && n == 9){
                //int aha[2][9];
                int t[9] = {9,11,5,3,1,7,13,15,17}; fto(i,0,n) aha[0][i] = t[i];
                int t1[9] = {16,14,18,8,12,4,2,6,10};fto(i,0,n) aha[1][i] = t1[i];
                hyh = true;
            }
            if (hyh){
                fto(step, 1, m*n+1)
                    fto(i, 0, m)
                        fto(j,0, n)
                        if (aha[i][j] == step)
                            ans_route.pb(make_pair(i+1,j+1));
                return ans_route;
            }

        }
        flag = false; ans_route.clear();
        fto(i, 1, (m+1)/2+1){
            fdto(j,(n+1)/2,0 ){
                v.clear();
                s.clear();
                ans_route.clear();
                if (debugg) cout<<"new Round"<<i<<","<<j<<m<<n<<endl;
                dfs(i,j, v, s);
                if (flag) break;
            }
            if (flag) break;
        }

        return ans_route;
}

vector<pair<int, int> > transfer(vector<pair<int, int> > ori, int shiftx, int shifty, int flipx, int flipy){
    if (flipx) 
        fto(i, 0, ori.size()){
            ori[i].first = flipx + 1- ori[i].first;
        }
    if (flipy)
        fto(i, 0, ori.size()){
            ori[i].second = flipy + 1- ori[i].second;
        }
    fto(i, 0, ori.size()){
            ori[i].first += shiftx;
            ori[i].second += shifty;
        }
    return ori;
}

bool judge(pair<int, int> p1, pair<int, int>  p2){
    if (p2.first==0) return true;
    return not(p1.first == p2.first or p1.second == p2.second or p1.first-p2.first == p1.second - p2.second or p1.first + p2.first == p1.second + p2.second);

}
void printRoute(vector<pair<int, int> > route){

    for(auto p: route)
        cout<<p.first<<","<<p.second<<" ";
    cout<<endl;
}

vector<pair<int, int> > solve3(int shiftx, int n){
    if (debugg)
        cout<<"solve3: "<<shiftx<<endl;
    vector<pair<int, int> > tmps, ori, flipx, flipy, t;
    tmps.clear();
    int shifty = 0;
    pair<int, int> pre;

    switch (n%4){
        case 1:{t = transfer(r35, shiftx, 0, 0, 0);tmps.insert(tmps.end(),t.begin(), t.end()); pre = t.back(); shifty = 5; break;}
        case 2:{t = transfer(r36, shiftx, 0, 0, 0);tmps.insert(tmps.end(),t.begin(), t.end()); pre = t.back();  shifty = 6; break;}
        case 3:{t = transfer(r37, shiftx, 0, 0, 0);tmps.insert(tmps.end(),t.begin(), t.end()); pre = t.back();  shifty = 7; break;}
        default: break;
    }

    if (debugg) {debug(shifty);cout<<"pre:"<<pre.first<<" "<<pre.second<<endl;};
    for (int i = shifty; i<n; i+=4){
        ori = transfer(r34, shiftx, i, 0,0);
        flipx = transfer(r34, shiftx, i, 3, 0);
        flipy = transfer(r34, shiftx, i, 0, 4);
        if (judge(ori[0], pre)) {tmps.insert(tmps.end(), ori.begin(), ori.end()); pre = ori.back();}
        else if (judge(flipx[0], pre)){tmps.insert(tmps.end(), flipx.begin(), flipx.end());pre = flipx.back();}
        else if (judge(flipy[0], pre)) {tmps.insert(tmps.end(), flipy.begin(), flipy.end());pre = flipy.back();}
        else cout<<"ERROR!!!"<<endl;
        if (debugg) printRoute(tmps);
    }
    if (debugg) cout<<"solve3 ends size=" << tmps.size() << " last element is" <<pre.first <<" "<<pre.second<<endl;
    return tmps;
}

vector<pair<int, int> > solve4(int shiftx, int n){
    if (debugg)
        cout<<"solve4: "<<shiftx<<endl;
    vector<pair<int, int> > tmps, ori, flipx, t, flipy;
    tmps.clear();
    int shifty = 0;
    pair<int, int> pre = make_pair(0,0);
    switch (n%3){
        case 1:{t = transfer(r44, shiftx, 0, 0, 0);tmps.insert(tmps.end(),t.begin(), t.end()); pre = t.back(); shifty = 4; break;}
        case 2:{t = transfer(r45, shiftx, 0, 0, 0);tmps.insert(tmps.end(),t.begin(), t.end()); pre = t.back();shifty = 5; break;}
        default: break;
    }

    if (debugg) {debug(shifty);cout<<pre.first<<" "<<pre.second<<endl;};
    for (int i = shifty; i<n; i+=3){
        ori = transfer(r43, shiftx, i, 0,0);
        flipx = transfer(r43, shiftx, i, 3,0);
        flipy = transfer(r43, shiftx, i, 0,4);
        if (judge(ori[0], pre)) {tmps.insert(tmps.end(), ori.begin(), ori.end()); pre = ori.back();}
        else if (judge(flipx[0], pre)){tmps.insert(tmps.end(), flipx.begin(), flipx.end());pre = flipx.back();}
        else if (judge(flipy[0], pre)) {tmps.insert(tmps.end(), flipy.begin(), flipy.end());pre =  flipy.back();}
        else cout<<"ERROR!!!"<<endl;
    }

    if (debugg) cout<<"solve4 ends size=" << tmps.size() << "last element is" <<pre.first <<pre.second<<endl;
    return tmps;
}

void pv(pair<int, int> p){
    cout<<p.first<<","<<p.second<<" ";
}
bool check(vector<pair<int, int> >  final, int m, int n){
    set<int> s;
    s.clear();
    pair<int, int> pre;
    pre.first = 0; pre.second = 0;
    for( auto p: final){
        if (judge(p, pre) == false) {cout<<"Too close between "; pv(p); pv(pre); cout<<endl;return false;};
        if (p.first<1 || p.first>m){cout<<"OUT_OF_BOUND x"; return false;};
        if (p.second<1 || p.second>n) {cout<<"OUT_OF_BOUND y"; return false;};
        if (s.find(p.first*100 + p.second) == s.end())
            s.insert(p.first*100 + p.second);
        else{
            cout<<"DOUBLE x, y exists! " <<p.first<<" "<<p.second<<endl;
            return false;
        }
    };
    if (s.size()!=m*n)   {
        cout << "SIZE not equal"; return false;
    };
    return true;
}


int main(){
    ios_base::sync_with_stdio(0);
    
    
    m = 2; n = 5; r25 = solve_small();
    m = 2; n = 6; r26 = solve_small();
    m = 2; n = 7; r27 = solve_small();
    m = 2; n = 8; r28 = solve_small();
    m = 2; n = 9; r29 = solve_small();
    m = 3; n= 4; r34 = solve_small();
    m = 3; n= 5; r35 = solve_small();
    m = 3; n= 6; r36 = solve_small();
    m = 3; n = 7; r37 = solve_small();
    m = 4; n = 3; r43 = solve_small();
    m = 4; n = 4; r44 = solve_small();
    m = 4; n = 5; r45 = solve_small();
    //m = 5; n = 3; r53 = solve_small();
    for (auto p: r35){
        r53.pb(make_pair(p.second,p.first));
    };

    m = 5; n = 2; r52 = solve_small();
    //printRoute(r52);
    if (test == false)
        cin>>T;
    else T = 1;
    fto(it,0,T){
        cin>>m>>n;
        

        flag = false;
        nmflag = false;
        
        int startx = 0;
        if (m>n){
            nmflag = true;
            int tmp = n;
            n = m;
            m = tmp;
        }
        vector<pair<int, int> > final; 
        if (n<=5)
            final = solve_small();
        else{
            if (m==2){
                int shifty = 0;
                if (n%5 == 1) {final = r26; shifty = 6;};
                if (n%5 == 2) {final = r27; shifty = 7;};
                if (n%5 == 3) {final = r28; shifty = 8;};
                if (n%5 == 4) {final = r29; shifty = 9;};
                for (int i = shifty; i < n; i+= 5){
                    vector<pair<int, int> > ori = transfer(r25, 0, i, 0, 0);
                    final.insert(final.end(),ori.begin(), ori.end());
                }
            }
            else if (m == 5){
                    int shifty = 0;
                    if (n%2 == 1){
                        final.insert(final.end(), r53.begin(), r53.end());
                        shifty = 3;
                    }
                    for (int i = shifty; i < n; i+= 2){
                        vector<pair<int, int> > ori = transfer(r52, 0, i, 0, 0);
                        final.insert(final.end(), ori.begin(), ori.end());
                        // debug(i);
                        // printRoute(ori);
                        // printRoute(final);
                    }
                }
                else{ if (m%3 == 2){
                    vector<pair<int, int> > tmps = solve4(0, n);
                    final.insert(final.end(), tmps.begin(), tmps.end());
                    tmps = solve4(4, n);
                    final.insert(final.end(), tmps.begin(), tmps.end());
                    startx = 8;
                } else if (m%3 == 1){
                    vector<pair<int, int> > tmps = solve4(0, n);
                    final.insert(final.end(), tmps.begin(), tmps.end());
                    startx = 4;
                }

                for( int i=startx; i<m; i+=3){
                    vector<pair<int, int> > tmps = solve3(i, n);
                    final.insert(final.end(), tmps.begin(), tmps.end());
                }
            }

        }

        if (nmflag){
            fto(i, 0, final.size()){
                int ty = final[i].second;
                final[i].first = final[i].second;
                final[i].second = ty;
            };
        }
        
        if (test){
            if (check(final, m, n) == false){
                cout<<"ERROR in"<<m<<" "<<n<<endl;
                printRoute(final);}
        } else{
        if (final.size() == 0)
            cout << "Case #" << it + 1 << ": IMPOSSIBLE"<<endl;
        else{
            cout << "Case #" << it + 1 << ": POSSIBLE"<<endl;
            for(auto p: final)
                cout<<p.first<<" "<<p.second<<endl;
        }}
    }
}
