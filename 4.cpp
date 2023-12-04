#include <iostream>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

struct Card
{
    set<int> winning;
    vector<int> have;
    int pts;

    Card(string s) : pts(0)
    {
        string _;
        stringstream ss(s);
        ss >> _;
        if (_ != "Card") return;
        ss >> _;
        int mode = 1;
        while (ss >> _)
        {
            if (mode == 1)
            {
                if (_ == "|") mode = 2;
                else winning.insert(stoi(_));
            }
            else
                have.push_back(stoi(_));
        }
        sort(have.begin(), have.end());
        have.resize(unique(have.begin(), have.end()) - have.begin());
        for (auto x : have) if (winning.count(x)) ++pts;
    }
};

int main()
{
    vector<Card> a;
    for (string line; getline(cin, line);) a.push_back(Card(line));

    long long z { 0 }, z2 { 0 };
    vector<int> add(a.size(), 1);
    for (auto i = 0; auto x : a)
    {
        if (x.pts) z += 1 << (x.pts - 1);

        for (int j = i + 1; j <= i + x.pts; ++j) add[j] += add[i];
        if (x.pts)
            z2 += add[i] * (1 << (x.pts - 1));

        ++i;
    }
    cout << z << endl << accumulate(add.begin(), add.end(), 0ll);

    return 0;
}

