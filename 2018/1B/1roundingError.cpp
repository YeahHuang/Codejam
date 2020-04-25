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
#include <numeric>
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
12:05 - 

N people 

T 
N L(language数量)
C1..CL 数量

25 250 1e5

1<=L<N
Ci>=1 且一定有多

贪心 sumCi < N

25可以dfs 纯暴力


*/
const int N = 1e5 + 10; // 这样更好 防止下面弄着弄着就少了个0
int q,p1,p2,ans,T, c[N], d[N], idx[N],n,cnt,  want[N],l,r;
bool flag;
string s;
bool debugg = false;
bool test = true;


bool cmp(const int i, const int j)
{
    return ((want[i] < want[j]) || (want[i]==want[j] && d[i] < d[j]));
    //return ((d[i] < d[j]) || (d[i]==d[j] && want[i] < want[j])); //从大到小排序
}


int main(){
    ios_base::sync_with_stdio(0);
    cin>>T;
    fto(it,0,T){

        cin>>n>>l;
        fto(i,0,l)
            cin>>c[i];
        int sum = accumulate(c, c+l, 0);
        if (100%n==0) {
            ans = 100;
            cout << "Case #" << it + 1 << ": "<<ans<<endl;
            continue;
        }

        fto(i,0,n+1)
            if (i*100%n * 2 >= n){
                d[i] =  n - i*100%n; //赚了 + 
                idx[i] = i;
                want[i] = 0;
            } else{
                d[i] = - i*100%n; //赔了 - 
                fto(j, i+1, i+n){
                    if (j*100%n*2>=n){
                        want[i] = j - i;
                        break;
                    }

                }
                idx[i] = i;
            }

        //sort(idx, idx+n, cmp);

        sort(c, c+l, cmp);

        if (debugg){
            debuga1(c, 0, l);
            debuga1(d, 0, n+1);
            debuga1(want, 0, n+1);
        }
        int left = n - sum;

        fto(i, 0, l){

            if (left >= want[c[i]]){
                left -= want[c[i]];
                c[i] += want[c[i]]; 
                //left -= want[c[i]];  一开始这么写 顺序就错了嘛 
            }
        }

        if (debugg){
            cout<<"After: "<<endl;
            debug(left);
            debuga1(c, 0, l);
        }

        int maxi = 0; p1 = 0;
        //while (left*100%n * 2>=n){
        while (left*100*2>=n){
            maxi = -1 * n;
            fto(i, 1, left+1){
            //fdto(i, left+1, 0){
                if (d[i] * (left / i) > maxi){
                    maxi = d[i] * (left / i);
                    p1 = i;
                }
            }
            /*if (maxi==-1) 加了这一行之后从RE 变成了WA
                break; */
            c[l] = p1;
            left -= p1;
            l++;
        }

        ans = 0;
        fto(i,0,l){
            ans += c[i] * 100 / n;
            if (c[i]*100%n * 2 >= n)
                ans += 1;
        }
        
    
        cout << "Case #" << it + 1 << ": "<<ans<<endl;
    }
}



