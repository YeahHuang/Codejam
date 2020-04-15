// <bits/stdc++.h>
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
12:59 开始

1-day ... 6day

x-day ring produce one more x-day ring every x days


Ri i-day rings i [1,6]  Ri [0,100] at least one Ri > 0

1:53 开始

0 1 2 3 4 5
*/

const int N = 1e5 + 10; // 这样更好 防止下面弄着弄着就少了个0
int q,p1,p2,ans,T, res, n,cnt,summ[10],w,  l,r;
bool flag;
string s;
bool debugg = true;
bool test = true;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>T>>w;
    fto(it,0,T){

        fto(i, 1, 7){
            cout<<i<<endl;
            cin>>summ[i];
        }

        int d[7];
        d[1] = summ[1] - summ[0];
        d[2] = summ[2] - summ[1] - d[1];
        d[3] = summ[3] - summ[2] - d[1];
        d[4] = summ[4] - summ[3] - d[1] - d[2];
        d[5] = summ[5] - summ[4] - d[1];
        d[6] = d[0] - d[1] - d[2] - d[3] - d[4] - d[5];
    
        fto(i, 1, 6)
            cout <<d[i]<< " ";
        cout<<d[6]<<endl;
        cin>>res;
        if (res == 1)
            return 1;
        //cout << "Case #" << it + 1 << ": "<<ans<<endl;
    }
}