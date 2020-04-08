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



const int N = 1e5 + 10; // 这样更好 防止下面弄着弄着就少了个0
int q,p1,p2,T, s[5][N], idx, n,cnt, B, step,l,r;
bool flag;
char ret;
string ans;
vector<int> m[100015];
bool debugg = false;
bool test = true;
const int NA = -1;

string solve10(){
    ans = "";
        fto(i,0,140)
            {
                cout<<"1"<<endl;
                cin>>ret;
                if (ret=='N') {cout<<i<<endl;return 0;}
            }
        fto(i,1,11){
            cout<<i<<endl;
            cin>>ret;
            if (ret=='N') {cout<<i<<endl;return 0;};
            ans += ret;

        }
    return ans;
}

char getRet(){
    cin>>ret;
    if (ret=='N') {cout<<"ERROR! "<<endl;return 0;};
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>T>>B;

    fto(it,0,T){
        ans = "";
        fto(i,1,B+1)
            s[0][i] = NA;

        
        fto(i, 1, 6){                
            cout<<i<<endl;
            cin>>ret;
            if (ret=='N') {cout<<"ERROR! "<<i<<endl;return 0;};
            s[0][i] = ret - '0';
        }
        fdto(i, B, B-5){
            cout<<i<<endl;
            cin>>ret;
            if (ret=='N') {cout<<"ERROR! "<<i<<endl;return 0;};
            s[0][i] = ret - '0';
        }

        step = 6;

        fto(hyh, 1, 15){
            
            fto(i, 1, B+1){
                if (s[0][i]!=NA){
                    s[1][i] = 1 - s[0][i]; //complemented
                    s[2][B+1-i] = s[0][i]; //reversed;
                    s[3][B+1-i] = 1 - s[0][i]; //reversed + complemented
                }
            }
            bool flag = false;
            fto(i,1, B+1){
                if (s[0][i]!=NA)
                    if (s[0][i] + s[1][i] + s[2][i] + s[3][i] == 2) {
                        cout<<i<<endl;
                        cin>>ret;
                        if (ret=='N') {cout<<"check 2: "<<i<<endl;return 0;};
                        fto(choice, 0, 4)
                            if (s[choice][i]==ret - '0')
                                {
                                    p1 = choice;
                                    break;
                                }
                        fdto(choice,  3, -1){
                            if (s[choice][i]==ret - '0')
                                {
                                    p2 = choice;
                                    break;
                                };
                        }
                        flag = true;
                        break;
                    }
            };
            if (flag==false)
            {
                cout<<"No 2s in ";
                fto(i,1,B+1) cout<<s[0][i];
                cout<<endl;
                return 0;
            }
            q = p1;
            if (debugg){
                cout<<p1<<" "<<p2<<endl;
            }
            idx = 1;
            fto(i, 1, B+1){
                if (s[p1][i]!=s[p2][i]){
                    idx = i;
                    break;
                }
            }


            cout<<idx<<endl;
            cin>>ret;
            if (ret=='N') {cout<<"check 1-1: "<<idx<<endl;return 0;};
            if (ret - '0' ==s[p2][idx]) q  = p2;

            fto(i, 1, B+1)
                s[0][i] = s[q][i];

            if (step <= B/2) {
                fto(i, step, step+4){
                    cout<<i<<endl;
                    cin>>ret;
                    if (ret=='N') {cout<<"ERROR! "<<i<<endl;return 0;};
                    s[0][i] = ret - '0';
                }
                fdto(i, B-step+1, B-step-3){
                    cout<<i<<endl;
                    cin>>ret;
                    if (ret=='N') {cout<<"ERROR! "<<i<<endl;return 0;};
                    s[0][i] = ret - '0' ;
                }
                step += 4;
            } else{
                fto(i, 1, 9){
                    cout<<i<<endl;
                    cin>>ret;
                    if (ret=='N') {cout<<"ERROR! "<<i<<endl;return 0;};
                }
            }
    }
        //ans = solve10();
        fto(i, 1, B+1)
            ans += char('0' + s[0][i]);
        cout<<ans<<endl;
        cin>>ret;
        if (ret=='N') {cout<<ans<<endl;return 0;};
    }
}