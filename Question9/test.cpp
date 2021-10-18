#include <bits/stdc++.h>

using namespace std;

int b, c;
vector<vector<int>> inp;

int solve(int prev_banker, int curr_client, int mask)
{
    if (curr_client == c)
        return 0;

    int ans = INT_MAX;

    for (int i = 0; i < b; ++i)
    {
        bool cur_mask = ((1 << i) & mask);

        if (cur_mask && (i == prev_banker))
            ans = min(ans, solve(i, curr_client + 1, mask) + inp[i][curr_client]);
        else if (!cur_mask)
            ans = min(ans, solve(i, curr_client + 1, mask | (1 << i)) + inp[i][curr_client]);
    }

    return ans;
}

int main()
{
    cin >> c >> b;
    inp = std::vector<std::vector<int>>(b, std::vector<int>(c));
    for (int i = 0; i < b; i++)
    {

        for (int j = 0; j < c; j++)
        {
            cin >> inp[i][j];
        }
    }
    cout << solve(-1, 0, 0) << endl;
    return 0;
}
