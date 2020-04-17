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
1:35 - 

S road signs 

Di distance        1e6  有序 
Ai face-west num
Bi face-east num 不一定符合

连续的subsequence

m, n 不一定 + 不一定不同

一个为true Di + Ai = M
Di - Bi = N

largest & different


small s<=100
large 有3个是s = 1e5

T
S lines follow: Di, Ai, Bi
*/
const int N = 1e5 + 10; // 这样更好 防止下面弄着弄着就少了个0
int q,p1,p2,ans,T, s, m[N],n[N],cnt, m1,m2,n1,n2,len[N], l,r;
bool flag;

bool debugg = true;
bool test = true;
const int NO = -3e6;
const int NA = 3e6;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>T;
    fto(it,0,T){

        cin>>s;
        fto(i,0,s){
            cin>>q>>p1>>p2;
            m[i] = q+p1;
            n[i] = q-p2;
        }

        clr(len,0);
        int i,j;
        i = 0;
        while (i<s-1){
            
            int startIdx = i;
            j = i;
            while (j<s-1 && m[j]==m[j+1] && n[j]==n[j+1]){
                j++;
            }
            if (j>i){
                cnt = j - i;
            } else cnt = 0;


            if (j == s-1){
                len[startIdx] = s-1 - startIdx + 1;
                break;
            }
            if (m[j] == m[j+1]){
                m1 = m[j]; m2 = NO; 
                while (j<s-1 && m[j]==m[j+1]){
                    j++;
                }
                if (j<s-1){
                    len[startIdx] = s-1 - startIdx + 1;
                    //continue;
                }
                else{
                    n1 = n[j+1];
                    }
            }
            else if (n[j]==n[j+1]){
                n1 = n[j]; n2 = NO;
                while (j<s-1 && n[j]==n[j+1]){
                    j++;
                }
                if (j<s-1){
                    len[startIdx] = s-1 - startIdx + 1;
                    //continue;
                }
                else{
                    m1 = m[j+1];
                    }
            } else{
                m1 = m[j]; m2 = m[j+1];
                n1 = n[j]; n2 = n[j+1];
                if (j+2 < s){
                    if (m[j+1] == m1) {n1 = n2;} //m1, n2
                    else if (m[j+1]==m2) {m1 = m2;} // m2, n1
                    else if (n[j+1]==n1) {m1 = m2;} // m2, n1
                    else if (n[j+1]==n2) {n1 = n2;} //m1, n2
                    else len[startIdx] = j+1 - startIdx + 1;

                }
                else{
                    len[startIdx] = j+1 - startIdx + 1;
                }

            };

            if (len[startIdx]==0){
                while (j<s){
                    if (m[j]!=m1 && n[j] != n1)
                        break;
                }
                j -= 1;
                len[startIdx] = j-startIdx + 1;
            }

            if (cnt)
                i += cnt;
            i++;
        }
        /*fto(i, 0, s-1){
            if (m[i]==m[i+1]){
                m1 = m[i];
                m2 = NO;
                n1 = NAN;
            }  else if (n[i]==n[i+1]){
                n1 = n[i];
                n2 = NAN;

            }
        }*/

        int maxi = 0;
        int ans = 0;
        fto(i,0,s){
            if (len[i] > maxi){
                maxi = len[i];
                ans = 1;
            } else if (len[i] == maxi){
                ans ++;
            }
        }

        if (maxi<=1){
            maxi = 1;
            ans = s;
        }
        cout << "Case #" << it + 1 << ": "<<maxi<<" "<<ans<<endl;
    }
}