#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll ans = 0;

    regex mul_pattern(R"((\w*mul)\((\d+),(\d+)\))"); 
    string line;
    char c;


    while (scanf("%c", &c) != EOF)
    {
        line += c;
    }

    bool enable = true;
    size_t i = 0;

    while (i < line.size())
    {
       
        if (line.substr(i, 4) == "do()")
        {
            enable = true;
            i += 4;
            continue;
        }
        if (line.substr(i, 7) == "don't()")
        {
            enable = false;
            i += 7;
            continue;
        }

       
        smatch match;
        string sub = line.substr(i);
        if (regex_search(sub, match, mul_pattern) && match.position() == 0)
        {
            string func_name = match[1];
            ll a = stoll(match[2]);
            ll b = stoll(match[3]);

            if (enable)
                ans += a * b;

            i += match.length();
        }
        else
        {
            i++; 
        }
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
