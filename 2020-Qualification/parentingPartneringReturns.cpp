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
n activites
not responsible for activerty overlap

不太懂 直接分配会怎么样？  贪心

57min - 1'20 AC了

*/
const int N = 1e3+10; // 这样更好 防止下面弄着弄着就少了个0
int q,p1,p2,T,  n,cnt, tc,tj, l,r;
char flag[N];
string s,ans;
vector< pair<int,int> > m;
vector<int> idx;

bool debugg = true;
bool test = true;

bool cmp(int i, int j){
    return (m[i].first < m[j].first || (m[i].first==m[j].first && m[i].second<m[j].second));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>T;
    fto(it,0,T){

        cin>>n;
        tc=0; tj=0;
        m.clear();
        idx.clear();
        fto(i,0,n){
            pair<int,int> p;
            cin>>p.first>>p.second;
            m.push_back(p);
            idx.push_back(i);
        }
        sort(idx.begin(),idx.end(), cmp);
        ans = "";
        fto(i,0,n){
            l = m[idx[i]].first; r = m[idx[i]].second;
            if (l>=tc){
                tc = r;
                flag[idx[i]] = 'C';
            } else if (l>=tj){
                tj = r;
                flag[idx[i]] = 'J';
            } else{
                ans = "IMPOSSIBLE";
                break;
            }
        }
        if (ans!="IMPOSSIBLE")
            fto(i,0,n){
                ans += flag[i];
            };
        cout << "Case #" << it + 1 << ": "<<ans<<endl;
    }
}
