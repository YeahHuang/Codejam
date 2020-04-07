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

23 - 57 34min
S string of digits 

d exactly d pairs of ()

small: 直接连续的1两边加括号即可

large: 
两个相同的可以直接当成一个整体
3 1 2
(((3))1(2))

((22)1) 似乎可以直接推倒？

left 
*/


const int N = 1e5 + 10; // 这样更好 防止下面弄着弄着就少了个0
int q,p1,p2,T,  n,cnt,delta, l,r;
bool flag;
string s,ans;
vector<int> m[100015];
bool debugg = true;
bool test = true;



int main(){
    ios_base::sync_with_stdio(0);
    cin>>T;
    fto(it,0,T){

        cin>>s;
        n = s.size();       
        ans = "";
        fto(i,0,s[0]-'0')  
            ans += '(';
        ans += s[0];
        fto(i,1,n){
            delta = s[i] - s[i-1];
            if (delta > 0){
                fto(j,0,delta) 
                    ans += '(';
            } else if (delta < 0){
                delta *= -1;
                fto(j,0,delta)
                    ans += ')';
            }
            ans += s[i];
        }
        fto(j,0,s[n-1]-'0')
            ans += ')';
        cout << "Case #" << it + 1 << ": "<<ans<<endl;
    }
}
