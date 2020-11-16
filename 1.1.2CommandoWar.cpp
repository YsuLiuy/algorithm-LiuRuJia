#include <iostream>
#include <algorithm>
#include <vector>

struct Job
{
    int b;
    int j;
    
    bool operator <(const Job &x) const // 不要忘记 const
    {
        return j > x.j;
    }
};

const int maxn = 1000;
Job v[maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int kase = 0;
    int b, j;
    
    while (scanf("%d", &n) == 1 && n)
    {
        std::vector<Job> v;

        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &b, &j);
            v.push_back({b, j});
        }

        std::sort(v.begin(), v.end());

        int costb = 0;
        int total = 0;

        for (int i = 0; i < n; ++i)
        {
            costb += v[i].b;
            total = std::max(total, costb + v[i].j);
        }
        printf("Case %d: %d\n", kase++, total);
    }

    return 0;
}