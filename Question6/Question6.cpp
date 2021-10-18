#pragma GCC optimize("O3")

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <unordered_map>

int assign, n, depts = 3;
std::unordered_map<std::string, int> value;
std::unordered_map<int, std::string> key;
std::vector<int> parent, size;
std::vector<std::vector<int>> deptwise;

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void make_set(std::string name, int deptno)
{
    value[name] = assign;
    key[assign] = name;
    parent[assign] = assign;
    size[assign] = 1;
    for (int i = 0; i < depts; ++i)
        deptwise[assign][i] = 0;
    deptwise[assign][deptno] += 1;
    ++assign;
}

void union_sets(std::string namea, std::string nameb, int maxsize, std::vector<int> &maxdeptsize)
{
    int a = value[namea], b = value[nameb];
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (size[a] + size[b] > maxsize)
            return;
        for (int i = 0; i < depts; ++i)
        {
            if (deptwise[a][i] + deptwise[b][i] > maxdeptsize[i])
                return;
        }
        if (size[a] < size[b])
            std::swap(a, b);
        parent[b] = a;
        for (int i = 0; i < depts; ++i)
        {
            deptwise[a][i] += deptwise[b][i];
        }
        size[a] += size[b];
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int n, m, a, b, f, s, t;
    std::cin >> n >> m >> a >> b >> f >> s >> t;

    parent = std::vector<int>(n);
    size = std::vector<int>(n);
    deptwise = std::vector<std::vector<int>>(n, std::vector<int>(depts));
    assign = 0;

    std::vector<int> maxdeptsize({f, s, t});
    std::string name, namea, nameb;
    int dept;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> name >> dept;
        make_set(name, dept - 1);
    }
    for (int i = 0; i < m; ++i)
    {
        std::cin >> namea >> nameb;
        union_sets(namea, nameb, b, maxdeptsize);
    }
    std::set<std::pair<int, int>> gset;
    std::unordered_map<int, std::vector<std::string>> belongsto;
    for (int i = 0; i < n; ++i)
    {
        int gno = find_set(i);
        belongsto[gno].push_back(key[i]);
        if (size[gno] < a)
            continue;
        gset.insert({-size[gno], gno});
    }
    if (gset.empty())
    {
        printf("no groups\n");
        return 0;
    }
    int maxcap = ((*gset.begin()).first);
    std::set<std::string> result;
    for (auto curr : gset)
    {
        if (curr.first != maxcap)
            break;
        for (std::string s : belongsto[curr.second])
        {
            result.insert(s);
        }
    }
    char buff[10000];
    int cons = 0;
    for (std::string s : result)
    {
        sprintf(buff + cons, "%s\n", s.c_str());
        cons += s.length() + 1;
    }
    printf("%s", buff);
    return 0;
}