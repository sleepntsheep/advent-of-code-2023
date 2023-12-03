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

    vector<string> S;
    vector<vector<int>> C;
    for (string line; getline(cin, line);) S.push_back(line);

    auto xisdigit = [](char c) { return c >= '0' && c <= '9'; };
    auto xissymbol = [&xisdigit](char c) { return c != '.' and c != '\0' and !xisdigit(c); };

    while (S.size() > 1 && end(S)[-1].size() != end(S)[-2].size()) S.pop_back();
    C.resize(S.size() * S[0].size());

    i64 sum { 0 };
    for (size_t i = 0; i < S.size(); ++i)
    {
        for (size_t j = 0; j < S[i].size();)
        {
            if (!xisdigit(S[i][j]))
            {
                ++j;
                continue;
            }
            int sj = j;
            while (sj < S[i].size() && xisdigit(S[i][sj])) ++sj;
            int part_number { 0 };

            const auto num { stoi(S[i].substr(j, sj - j)) };

            auto xmark = [&](int i, int j) {
                part_number = num;
                if (S[i][j] == '*') C[i*S[0].size()+j].push_back(num);
            };

            for (int k = (int) j - 1; k <= sj; ++k)
            {
                if (k < 0 || k >= S[i].size()) continue;
                if (i && xissymbol(S[i-1][k])) xmark(i-1, k);
                if (i + 1 < S.size() && xissymbol(S[i+1][k])) xmark(i+1, k);
            }
            if (j && xissymbol(S[i][j-1])) xmark(i, j-1);
            if (sj < S[i].size() && xissymbol(S[i][sj])) xmark(i, sj);

            sum += part_number;

            j = sj + 1;
        }
    }

    i64 sum_gear { 0 };
    for (auto &x : C) if (x.size() == 2) sum_gear += 1ll * x[0] * x[1];

    cout << sum << endl << sum_gear;

    return 0;
}


