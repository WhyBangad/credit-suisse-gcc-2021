#pragma GCC optimize("O2")

#include <iostream>

int main()
{
    int n;
    scanf("%d", &n);
    int values[n];
    int st[n], top = -1;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &(values[i]));
    }
    int result = n - 1;
    for (int i = 0; i < n; ++i)
    {
        int cnt = 0;
        while (top != -1 && st[top] < values[i])
        {
            --top;
            ++cnt;
        }
        if (cnt)
        {
            if (top != -1)
                cnt += 1;
            result += cnt - 1;
        }
        ++top;
        st[top] = values[i];
    }
    printf("%d", result);
    return 0;
}