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
pattern  p
name m
p&m matches

n 个 patterns
pi <=100

small1: 直接看最小的是否包含全部就行

small2:
三类 0 中 n

startswith endwith

0: 定义了endwith
n： 定义了startwith
中： 定义了

所有的必须为
最长的startwith

large： 其实就是分解 一个一个去掉 dfs

*/

const int N = 1e5 + 10; // 这样更好 防止下面弄着弄着就少了个0
int q,p1,p2,T,  n,cnt,  l,r;
bool flag;
string ans,s;
bool debugg = false;
bool test = true;

string checkSub(vector<string> startWith){
        string maxSt = "";
        for (auto st: startWith){
            if (st.size()>maxSt.size())
                maxSt = st;
        }
        for (auto st: startWith)
            if (maxSt.find(st) == string::npos)
                return "*";
        return maxSt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>T;
    fto(it,0,T){
        vector<string> startWith;
        vector<string> endWith;
        startWith.clear(); endWith.clear();
        cin>>n;
        fto(i, 0, n){
            string s;
            cin>>s;
            if (s.front() == '*'){
                endWith.push_back(s.substr(1));
            }
            else if (s.back() == '*'){
                startWith.push_back(s.substr(0, s.size()-1));
            }
                else{
                    int pos = s.find("*");
                    startWith.push_back(s.substr(0, pos));
                    endWith.push_back(s.substr(pos+1));
                }
        }
        string maxSt = "";
        for (auto st: startWith){
            if (st.size()>maxSt.size())
                maxSt = st;
        }
        for (auto st: startWith){
            string sub = maxSt.substr(0, st.size());
            if (strcmp(sub.c_str(), st.c_str()) != 0){
                maxSt = '*';
                break;
            }
        }
            


        string maxEn = "";
        for (auto en: endWith){
            if (en.size()>maxEn.size())
                maxEn = en;
        }
        for (auto en: endWith){
            string sub = maxEn.substr(maxEn.size() - en.size());
            if (strcmp(sub.c_str(), en.c_str()) != 0){
                maxEn = '*';
                break;
            }
            
        }


        if (debugg)
        {
            for (auto ss: endWith) cout<<ss<<" ";
            debug(maxSt);
            debug(maxEn);
        }
       /*
        for (auto st: startWith){
            if (st.size()>maxSt.size())
                maxSt = st;
        }
        for (auto en: endWith){
            if (en.size()>maxEn.size())
                maxEn = en;
        }*/

        if (strcmp(maxSt.c_str(),"*")==0 || strcmp(maxEn.c_str(), "*")==0 )
            ans = "*";
        else 
            ans = maxSt + maxEn;
    
        cout << "Case #" << it + 1 << ": "<<maxEn<<endl;
    }
}