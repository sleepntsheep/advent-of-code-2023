#include <iostream>
#include <numeric>
#include <map>
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

using bag = array<int, 3>;

bag merge(bag a, bag b)
{
    bag c;
    for (auto j : {0, 1, 2}) c[j] = max(a[j], b[j]);
    return c;
}

map<string, int> col = {{"blue", 0}, {"red", 1}, {"green", 2}};

bag read_bag(string line)
{
    bag a {0};
    const char *p = strchr(line.c_str(), ':') + 1;
    while (1)
    {
        bag tmp{0};

        while (1)
        {
            int cnt, mode = 0;
            char c[8]{0};
            sscanf(p, "%d %s", &cnt, c);
            int n = strlen(c);
            if (c[n-1] == ',') c[n-1] = 0, mode = 1, p = strchr(p, ',') + 1;
            else if (c[n-1] == ';') c[n-1] = 0, mode = 2, p = strchr(p, ';') + 1;
            tmp[col[c]] = cnt;
            a = merge(a, tmp);

            if (mode == 2) break;
            if (mode == 0) return a;
        }
    }
    return a;
}

int main()
{
    vector<bag> a;
    string line;
    while (getline(cin, line))
        a.push_back(read_bag(line));

    int z{0};
    i64 z2{0};
    for (auto i = 0; auto [b, r, g] : a)
    {
        ++i;
        if (!(b > 14 || g > 13 || r > 12)) z += i;
        z2 += 1ll*b*r*g;
    }

    cout << z <<endl;
    cout << z2;
    return 0;
}


