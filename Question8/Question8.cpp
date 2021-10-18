#pragma GCC optimize("O3")

#include <iostream>
#include <vector>

const int inf = INT32_MIN;

int solve(std::vector<int> &returns, int last_inv, int d, int m, int inv_left, int curr)
{
    if (curr == returns.size())
    {
        if (inv_left != 0)
        {
            return inf;
        }
        return 0;
    }
    if (inv_left == 0)
    {
        if (last_inv != -1 && curr - last_inv <= d)
        {
            return m * returns[curr] + solve(returns, last_inv, d, m, inv_left, curr + 1);
        }
        return returns[curr] + solve(returns, last_inv, d, m, inv_left, curr + 1);
    }
    if (last_inv != -1 && curr - last_inv <= d)
    {
        return std::max(solve(returns, curr, d, m, inv_left - 1, curr + 1), m * returns[curr] + solve(returns, last_inv, d, m, inv_left, curr + 1));
    }
    return std::max(solve(returns, curr, d, m, inv_left - 1, curr + 1), returns[curr] + solve(returns, last_inv, d, m, inv_left, curr + 1));
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, k, d, m;
    std::cin >> n >> k >> d >> m;
    std::vector<int> returns(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> returns[i];
    }
    std::cout << solve(returns, -1, d, m, k, 0) << '\n';
    return 0;
}
