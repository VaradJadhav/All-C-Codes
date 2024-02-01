
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define see(x) cin >> x
#define sees(x, y) cin >> x >> y
#define put(x) cout << x << " "
#define puts(x) cout << x << endl
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define endl '\n'
const int M = 1e9 + 7, N = 2e5 + 7;

int get_diameter(int nn, vector<vector<int>> &adj)
{
    int a, b, c, i, j, k, id, INF = nn + 100, ans;
    vector<int> dist(nn), last(nn);
    queue<int> q;

    if (nn == 1)
        return 0;

    // first pass, start with 1 -- any node
    a = 0;
    dist.assign(nn, INF);
    dist[a] = 0;
    q.push(a);

    while (!q.empty())
    {
        id = q.front();
        q.pop();

        for (auto p : adj[id])
        {
            if (dist[p] == INF)
            {
                dist[p] = dist[id] + 1;
                q.push(p);
            }
        }
    }

    // second pass, start from the most remote node id, collect last to get ID
    a = id;
    dist.assign(nn, INF);
    last.assign(nn, -1);
    dist[a] = 0;
    q.push(a);

    while (!q.empty())
    {
        id = q.front();
        q.pop();

        for (auto p : adj[id])
        {
            if (dist[p] == INF)
            {
                dist[p] = dist[id] + 1;
                last[p] = id;
                q.push(p);
            }
        }
    }

    // a and id forms the diameter
    ans = dist[id];

    // construct the path of diamter in path
    vector<int> path;
    b = id;
    c = id;
    do
    {
        path.push_back(b);
        b = last[b];
    } while (b != -1);

    for (auto it : path)put(it+1);
    cout<<endl;
    return ans;
}

void solve()
{
    int n, x, y;
    see(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        sees(x, y);
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    puts(get_diameter(n, adj));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    // check();
    while (t--)
    {
        solve();
    }
}
