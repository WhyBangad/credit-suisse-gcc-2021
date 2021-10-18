#pragma GCC optimize("O3")

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string solution(std::string n)
{
    std::vector<int> segs;
    int curr = 0;
    for (char c : n)
    {
        if (c == '1')
        {
            segs.push_back(curr);
            curr = 0;
        }
        else
        {
            ++curr;
        }
    }
    segs.push_back(curr);
    std::sort(segs.begin(), segs.end());
    int a_score = (segs[segs.size() - 1] + 1) / 2;
    if (segs.size() >= 2 && segs[segs.size() - 2] >= a_score)
    {
        return "B";
    }
    if (segs[segs.size() - 1] & 1)
    {
        return "A";
    }
    else
    {
        return "B";
    }
}

/*  Do not edit below code */
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::string n;
    std::cin >> n;
    std::cout << solution(n) << '\n';
}
