#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> name(n);
    map<string, int> id;

    vector<vector<int>> dp(n, vector<int>(2, 0));

    vector<string> type(n); // CONST or OP
    vector<string> op(n), left(n), right(n);

    for (int i = 0; i < n; i++)
    {
        cin >> name[i];
        id[name[i]] = i;

        string tmp;
        cin >> tmp; // :=

        cin >> tmp;

        if (tmp == "0" || tmp == "1" || tmp.size() > 1)
        {
            type[i] = "CONST";
            op[i] = tmp;
        }
        else
        {
            type[i] = "OP";
            left[i] = tmp;
            cin >> op[i];
            cin >> right[i];
        }
    }

    string min_ans = "", max_ans = "";

    for (int bit = 0; bit < m; bit++)
    {

        vector<vector<int>> val(n, vector<int>(2));

        for (int i = 0; i < n; i++)
        {

            if (type[i] == "CONST")
            {
                int b = op[i][bit] - '0';
                val[i][0] = val[i][1] = b;
            }
            else
            {
                for (int t = 0; t < 2; t++)
                {

                    int x = (left[i] == "?") ? t : val[id[left[i]]][t];
                    int y = (right[i] == "?") ? t : val[id[right[i]]][t];

                    if (op[i] == "AND")
                        val[i][t] = x & y;
                    else if (op[i] == "OR")
                        val[i][t] = x | y;
                    else
                        val[i][t] = x ^ y;
                }
            }
        }

        int sum0 = 0, sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            sum0 += val[i][0];
            sum1 += val[i][1];
        }

        // min
        if (sum0 <= sum1)
            min_ans += '0';
        else
            min_ans += '1';

        // max
        if (sum0 >= sum1)
            max_ans += '0';
        else
            max_ans += '1';
    }

    cout << min_ans << "\n";
    cout << max_ans << "\n";
}