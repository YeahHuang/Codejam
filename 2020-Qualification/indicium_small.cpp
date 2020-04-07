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

const int N = 100; // 这样更好 防止下面弄着弄着就少了个0
int q,p1,p2,ans,T, t[N][N],k, n,cnt,  l,r;
bool flag,found;
string s;
vector<int> m[100015];
bool debugg = false;
bool test = true;

/*
        if (n==2){
            if (k==3) flag = false;
            if (k==2){
                t[0][0] = 1;
                t[0][1] = 2;
                t[1][0] = 2;
                t[1][1] = 1;}
                else{
                t[0][0] = 2;
                t[0][1] = 1;
                t[1][0] = 1;
                t[1][1] = 2;    
                }
        } else if (n==3)

4 13
4 4 2 3

4   2   3   1
3   4   1   2
1   3   2   4
2   1   4   3
*/




void dfs(int x, int y){
    //if (debugg) cout<<x<<" "<<y<<endl;
    if (x==y){
        y += 1;
    }
    if (y==n){
        if (x==n-1){
            found = true;
            return;
        }
        x += 1;
        y = 0;
    }
    if (found)
        return;
    fto(num,1,n+1){
        if (t[x][x]!=num && t[y][y]!=num)
        {
            bool f = true;
            fto(j,0,y)
                if (t[x][j] == num)
                    {
                        f = false;
                        break;
                    };
            fto(i,0,x){
                if (t[i][y]==num){
                        f = false;break;
                }
            }
            if (f)
            {
                //if (debugg) cout<<"t["<<x<<","<<y<<"]="<<num<<endl;
                t[x][y] = num;
                dfs(x,y+1);
                if (found)
                    return;
            }

        }

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    if (test){
        fto(nn,2,6)
            fto(kk,n, n*n+1);

    }

    cin>>T;
    fto(it,0,T){

        cin>>n>>k;
        flag = true;
        found = false;
        bool choice1 = false;
        if (choice1){
        if (n<=3){
            if (k%n!=0) flag=false;
        }
        if (n==4){
            if (k==5 || k==15) flag = false;
        }
        if (n==5){
            if (k==6 || k==24) flag = false;
        }
        if (flag==false){
            cout << "Case #" << it + 1 << ": IMPOSSIBLE"<<endl;
            continue;
        }
        if (k%n==0)
        {
            fto(i,0,n)
                t[i][i] = k/n;
        }
        else if (n==4){
            if (k%2==0){
                t[0][0] = t[1][1] = k/2/2;
                t[2][2] = t[3][3] = k/2/2+1;
            } else{
                if (k==7 || k==9){
                    t[0][0] = t[1][1] = 1;
                    t[2][2] = 3;t[3][3] = 4;
                    if (k==7) t[3][3] = 2;
                } 
                if (k==11){
                    t[0][0] = 2;
                    t[1][1] = 2;
                    t[2][2] = 3;
                    t[3][3] = 4;
                } else{
                    t[0][0] = 2;
                    t[1][1] = 3;
                    t[2][2] = 4;
                    t[3][3] = 4;
                }
            }
        } else if (n==5){
            if (k==7){
                t[0][0] = 1;
                t[1][1] = 1;
                t[2][2] = 1;
                t[3][3] = 2;
                t[4][4] = 2;
            } else if (k==8){
                t[0][0] = 1;
                t[1][1] = 1;
                t[2][2] = 1;
                t[3][3] = 2;
                t[4][4] = 3;
            }else if (k==9){
                t[0][0] = 1;
                t[1][1] = 1;
                t[2][2] = 1;
                t[3][3] = 2;
                t[4][4] = 4;
            }else if (k==11){
                t[0][0] = 1;
                t[1][1] = 1;
                t[2][2] = 1;
                t[3][3] = 4;
                t[4][4] = 4;
            }else if (k==12){
                t[0][0] = 1;
                t[1][1] = 1;
                t[2][2] = 1;
                t[3][3] = 4;
                t[4][4] = 5;
            } else if (k==13){
                t[0][0] = 1;
                t[1][1] = 1;
                t[2][2] = 1;
                t[3][3] = 5;
                t[4][4] = 5;
            } else if (k==14){
                t[0][0] = 1;
                t[1][1] = 1;
                t[2][2] = 2;
                t[3][3] = 5;
                t[4][4] = 5;
            } else if (k==16){
                t[0][0] = 2;
                t[1][1] = 2;
                t[2][2] = 2;
                t[3][3] = 5;
                t[4][4] = 5;
            } else if (k==17){
                t[0][0] = 3;
                t[1][1] = 3;
                t[2][2] = 3;
                t[3][3] = 4;
                t[4][4] = 4;
            } else if (k==18){
                t[0][0] = 3;
                t[1][1] = 3;
                t[2][2] = 3;
                t[3][3] = 4;
                t[4][4] = 5;
            } else if (k==19){
                t[0][0] = 3;
                t[1][1] = 3;
                t[2][2] = 3;
                t[3][3] = 5;
                t[4][4] = 5;
            } else if (k==21){
                t[0][0] = 5;
                t[1][1] = 5;
                t[2][2] = 5;
                t[3][3] = 3;
                t[4][4] = 3;
            } else if (k==22){
                t[0][0] = 5;
                t[1][1] = 5;
                t[2][2] = 5;
                t[3][3] = 3;
                t[4][4] = 4;
            }else if (k==23){
                t[0][0] = 5;
                t[1][1] = 5;
                t[2][2] = 5;
                t[3][3] = 4;
                t[4][4] = 4;
            }

        }
        dfs(0,1);
        } else{
        if (k%n==0)
        {
            fto(i,0,n)
                t[i][i] = k/n;
            dfs(0,1);
        } else if (n==3){
            fto(i,1,4){
                fto(j,i,4){
                    if (k-i-j>=j && k-i-j<4){
                        t[0][0] = i;
                        t[1][1] = j;
                        t[2][2] = k-i-j;
                        dfs(0,1);
                        if (found) break;
                    }
                    //else break;
                };
                if (found) break;
            }
        } else if (n==4){
            for(int i=1;i<5;i++){
                for(int j=i; j<5;j++){
                    for(int l=j; l<5;l++){
                        if (debugg) cout<<i<<j<<l<<k-i-j-l<<endl;
                        if (k-i-j-l>=l && k-i-j-l<5){
                            t[0][0] = i;
                            t[1][1] = j;
                            t[2][2] = l;
                            t[3][3] = k-i-j-l;
                            
                            dfs(0,1);
                            if (found) break;
                        }
                        //else break;
                    }
                    if (found) break;
                }
                if (found) break;
            }
        } else{
            fto(i,1,6){
                fto(j,i,6){
                    fto(l,j,6){
                        fto(o, l,6){
                        if (k-i-j-l-o>=o && k-i-j-l-o<6 ){
                            t[0][0] = i;
                            t[1][1] = j;
                            t[2][2] = l;

                            t[3][3] = o;
                            t[4][4] = k-i-j-l-o;
                            dfs(0,1);
                            if (found) break;
                        }
                        //else break;
                    }
                        if (found) break;
                    }
                    if (found) break;
                }
                if (found) break;
            }
        }}
        
        if (found==false){
            cout << "Case #" << it + 1 << ": IMPOSSIBLE"<<endl;
            continue;
        }
        cout << "Case #" << it + 1 << ": POSSIBLE"<<endl;
        fto(i,0,n){
            cout<<t[i][0];
            fto(j,1,n)
                cout<<" "<<t[i][j];
            cout<<endl;
        }
    }
}





