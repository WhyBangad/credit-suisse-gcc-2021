#pragma GCC optimize("O3")

#include <iostream>
#include <vector>

int recursive_solve(int maxSum, std::vector<int> &a, int ai, std::vector<int> &b, int bi, int **dp)
{
    if (ai == a.size() && bi == b.size())
        return 0;
    if (dp[ai][bi] != -1)
        return dp[ai][bi];
    int result = 0;

    if (bi != b.size() && b[bi] <= maxSum)
    {
        result = std::max(result, 1 + recursive_solve(maxSum - b[bi], a, ai, b, bi + 1, dp));
    }
    if (ai != a.size() && a[ai] <= maxSum)
    {
        result = std::max(result, 1 + recursive_solve(maxSum - a[ai], a, ai + 1, b, bi, dp));
    }
    return dp[ai][bi] = result;
}

int portfolio_profit_maximisation(int maxSum, std::vector<int> &a, std::vector<int> &b)
{
    int **dp;
    dp = (int **)malloc((a.size() + 1) * sizeof(int *));
    for (int i = 0; i < a.size() + 1; ++i)
    {
        dp[i] = (int *)malloc((b.size() + 1) * sizeof(int));
        for (int j = 0; j < b.size() + 1; ++j)
        {
            dp[i][j] = -1;
        }
    }
    return recursive_solve(maxSum, a, 0, b, 0, dp);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, m, x;
    std::cin >> n >> m >> x;

    std::vector<int> a(n);
    std::vector<int> b(m);

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; ++i)
    {
        std::cin >> b[i];
    }
    std::cout << portfolio_profit_maximisation(x, a, b) << '\n';
    return 0;
}