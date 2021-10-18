#pragma GCC optimize("O3")

#include <iostream>
#include <vector>

const int INF = 1e5 + 10, max_client = 21, max_banker = 11;
int allset;
std::vector<std::vector<std::vector<int>>> dp;
std::vector<std::vector<int>> timevec;

int min_time_taken(int taken, int last, int client)
{
    if (client == (int)timevec[0].size())
        return 0;
    int ans = INF;
    if (last != -1 && dp[taken ^ allset][client][last] != -1)
    {
        return dp[taken ^ allset][client][last];
    }
    for (int i = 0; i < (int)timevec.size(); ++i)
    {
        if ((taken & (1 << i)) && last != i)
        {
            continue;
        }
        ans = std::min(ans, timevec[i][client] + min_time_taken((taken | (1 << i)), i, client + 1));
    }
    return dp[taken ^ allset][client][last] = ans;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int b, c;
    std::cin >> c >> b;
    timevec = std::vector<std::vector<int>>(b, std::vector<int>(c));
    for (int i = 0; i < b; i++)
    {

        for (int j = 0; j < c; j++)
        {
            std::cin >> timevec[i][j];
        }
    }
    allset = (1 << b) - 1;
    dp = std::vector<std::vector<std::vector<int>>>((1 << b), std::vector<std::vector<int>>(c, std::vector<int>(b, -1)));
    std::cout << min_time_taken(0, -1, 0) << std::endl;
    return 0;
}