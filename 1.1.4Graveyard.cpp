#include <cstdio>
#include <cmath>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;

    while (scanf("%d%d", &n, &m) != EOF)
    {
        double ans = 0;
        for (int i = 1; i < n; ++i)
        {
            double pos = double(i) / n * (n + m);
            ans += std::abs(pos - round(pos)) / (n + m);
        }
        printf("%.4lf\n", ans * 10000);
    }

    return 0;
}