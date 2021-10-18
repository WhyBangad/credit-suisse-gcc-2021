#pragma GCC optimize("O2")

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <sstream>

std::vector<std::pair<int, int>> values;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int z;
    std::cin >> z;
    std::vector<int> security_value;
    std::string buffer;
    int data;
    getline(std::cin, buffer);
    getline(std::cin, buffer);
    std::istringstream iss(buffer);

    while (iss >> data)
        security_value.push_back(data);
    int stocks = 0, n = security_value.size();
    for (int i = 0; i < n; ++i)
    {
        values.push_back({security_value[i], i + 1});
    }
    std::sort(values.begin(), values.end());
    for (int i = 0; i < n; ++i)
    {
        long long purchased = std::min(values[i].second, z / values[i].first);
        stocks += purchased;
        z -= purchased * values[i].first;
        if (purchased < values[i].second)
        {
            break;
        }
    }
    std::cout << stocks << '\n';
}
