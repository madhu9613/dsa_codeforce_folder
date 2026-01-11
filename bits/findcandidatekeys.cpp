#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define max3(a, b, c) max(max(a, b), c)
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const ll LINF = 1e18;

const int MAXN = 40005;

set<char> findclosure(set<char> attributs, vector<pair<set<char>, set<char>>> fds)
{
    bool cont = true;
    while (cont)
    {
        cont = false;
        for (auto &fd : fds)
        {
            set<char> lhs = fd.first;
            set<char> rhs = fd.second;

            bool contains = true;
            for (char x : lhs)
            {
                if (attributs.find(x) == attributs.end())
                {
                    contains = false;
                    break;
                }
            }

            if (contains)
            {
                for (char y : rhs)
                {
                    if (attributs.find(y) == attributs.end())

                    {
                        attributs.insert(y);
                        cont = true;
                    }
                }
            }
        }
    }
    return attributs;
}

bool isminimal(set<char> key, vector<set<char>> &superkeys)
{
    for (char a : key)
    {
        set<char> subset = key;
        subset.erase(a);
        for (auto &sk : superkeys)
        {
            if (sk == subset)
            {
                return false;
            }
        }
    }
    return true;
}

bool isSubset(const set<char> &small, const set<char> &big)
{
    for (char ch : small)
    {
        if (big.find(ch) == big.end())
            return false;
    }
    return true;
}

void checkNF(const vector<pair<set<char>, set<char>>> &fds,
             const vector<set<char>> &candidateKeys,
             const set<char> &attributes_set)
{

    set<char> primeattributes;
    for (auto &ck : candidateKeys)
    {
        for (char ch : ck)
        {
            primeattributes.insert(ch);
        }
    }

    bool is2NF = true;
    bool is3NF = true;
    bool isBCNF = true;

    for (auto &fd : fds)
    {
        set<char> lhs = fd.first;
        set<char> rhs = fd.second;
        bool lhsSuperkey = false;

        for (auto &sk : candidateKeys)
        {
            if (isSubset(sk, lhs))
            {
                lhsSuperkey = true;
                break;
            }
        }

        bool rhsNonPrime = false;
        for (char y : rhs)
        {
            if (primeattributes.find(y) == primeattributes.end())
            {
                rhsNonPrime = true;
                break;
            }
        }


        if (!lhsSuperkey)
        {
            isBCNF = false;
        }

        if (!lhsSuperkey && rhsNonPrime)
        {
            is3NF = false;
        }

        for (auto &ck : candidateKeys)
        {
            if (isSubset(lhs, ck) && lhs != ck && rhsNonPrime)
            {
                is2NF = false;
                break;
            }
        }

    }

    cout << "\nNormal Form:\n";
    if (!is2NF)
        cout << "1NF (Violates 2NF due to partial dependency)" << endl;
    else if (!is3NF)
        cout << "2NF (Violates 3NF due to transitive dependency)" << endl;
    else if (!isBCNF)
        cout << "3NF (Violates BCNF)" << endl;
    else
        cout << "BCNF" << endl;
}
void solve()
{

    string atrs;
    cout << "Enter all attributes as a string ";
    cin >> atrs;

    int n;
    cout << "Enter number of Fds: ";
    cin >> n;

    vector<pair<set<char>, set<char>>> fds;
    cout << "Enter FDs in format lhs,rhs :\n";
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        set<char> lhs, rhs;
        bool comma = false;
        for (char ch : s)
        {
            if (ch == ',')
            {
                comma = true;
                continue;
            }
            if (!comma)
                lhs.insert(ch);
            else
                rhs.insert(ch);
        }
        fds.push_back({lhs, rhs});
    }
    vector<char> attributes(all(atrs));
    set<char> attributes_set(all(atrs));

    vector<set<char>> superkeys;
    vector<set<char>> candidateKeys;

    int total = attributes.size();
    for (int mask = 1; mask < (1 << total); mask++)
    {
        set<char> subset;
        for (int i = 0; i < total; i++)
        {
            if (mask & (1 << i))
                subset.insert(attributes[i]);
        }
        set<char> closure = findclosure(subset, fds);
        if (closure == attributes_set)
        {
            superkeys.pb(subset);
        }
    }
    for (auto &sk : superkeys)
    {
        if (isminimal(sk, superkeys))

        {
            candidateKeys.pb(sk);
        }
    }

    cout << "\nSuperkeys:\n";
    for (auto &sk : superkeys)
    {
        for (char ch : sk)
            cout << ch;
        cout << "\n";
    }

    cout << "\nCandidate Keys:\n";
    for (auto &ck : candidateKeys)
    {
        for (char ch : ck)
            cout << ch;
        cout << "\n";
    }

    checkNF(fds, candidateKeys, attributes_set);
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}