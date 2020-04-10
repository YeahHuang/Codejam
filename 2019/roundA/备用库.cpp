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



const int N = 1e5 + 10; // 这样更好 防止下面弄着弄着就少了个0
int q,p1,p2,ans,T,  n,cnt,  l,r;
bool flag;
string s;
vector<int> m[100015];
bool debugg = true;
bool test = true;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>T;
    fto(it,0,T){

        cin>>n>>q;
        cin>>s;
        //clr(f[0],0);
        ans = 0;
    
        cout << "Case #" << it + 1 << ": "<<ans<<endl;
    }
}

string J;
unordered_set<char> setJ(J.begin(), J.end());

unordered_map<Word, int> dic;
auto it = dic.find(tmp);
                if (it != dic.end()){
                //ans += dic[tmp]; 
                   // debug(i);
                    //debug(it->second);
                    ans += it->second;
                    dic.erase(it);
            }
                tmp.key[ss[i]-'a'] --;

class Word{
public:
    int s, e, l;
    //string w; 
    unsigned short key[26];
    Word(string word){
        s = word[0];
        e = word[word.size()-1];
        l = word.size();
        //sort(word.begin(), word.end());
        //w = word;
        clr(key,0);
        for (auto &c: word)
            key[c-'a']++;
    }
    /*bool operator == (const Word &b) const{
        return (s == b.s && e = b.e && w ==b.w);
    };*/
    bool operator == (const Word &w) const{
        if (s == w.s && e == w.e){
            fto(i,0,26){
                if (key[i]!=w.key[i])
                    return false;
            }
            return true;
        };
        return false;
    }

};


//没加这一段的时候会报error： implicit instantiation of undefined template 'std::__1::hash<Word>'
namespace std{
    template <>
    class hash<Word>{
    public:
        size_t operator() (const Word &w) const{ 
        //2个const 一定要加 不然会报错no matching function for call to object of type 'conststd::__1::hash<Word>'
            auto ih = hash<int>();
            auto sh = hash<unsigned short>();
            //size_t ans = hash<int>(w.s); 
            //一定要命名 不然会报错 no matching conversions from int to hash<int>
            size_t ans = ih(w.s);

            ans ^= ih(w.e);
            for (auto &c: w.key){
                ans ^= sh(c);
            }
            return ans;
        }
    };
}
