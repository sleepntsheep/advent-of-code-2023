#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>
#include <set>
#include <utility>
#include <array>
#include <complex>

using i64 = long long;
using u64 = unsigned long long;
using f64 = double;
using f80 = long double;

using namespace std;
using pt = complex<f80>;
#define ALL(x) x.begin(), x.end()
#define ShinLena cin.tie(nullptr)->sync_with_stdio(false);
#define N 200005

int main()
{
    ShinLena;
    i64 z{0},z2{0};
    string s;

    string t[10] = {"---", "one", "two", "three", "four","five","six","seven","eight","nine"};

    while (cin >> s)
    {
        int aa{0},bb{0},a{0},b{0};
        for (int i=0;i<s.size();++i)
        {
            if (s[i]>='0'&&s[i]<='9')b=s[i]-'0',bb=s[i]-'0';
            else
            {
                for (int j=1;j<10;++j)
                    if (t[j] == s.substr(i, t[j].length()))
                    {
                        b = j;
                        break;
                    }
            }
        }
        for (int i=s.size(); i--;)
        {
            if (s[i]>='0'&&s[i]<='9')a=s[i]-'0',aa=s[i]-'0';
            else
            {
                for (int j=1;j<10;++j)
                {
                    if (t[j]==s.substr(i,t[j].length()))
                    {
                        a=j;
                        break;
                    }
                }
            }
        }
        z2+=10*a+b;
        z+=10*aa+bb;
    }
    cout<<z<<endl<<z2;

    return 0;
}


