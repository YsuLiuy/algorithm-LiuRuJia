#include <cstdio>
#include <algorithm>
#include <vector>
#include <numeric>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;

    while (scanf("%d", &n) == 1 && n > 0)
    {
        std::vector<int> A(n);
        std::vector<int> C(n);

        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &A[i]);
        }
        std::for_each(A.begin(), A.end(), [](int a){printf("%d\t", a);});
        printf("\n");
        
        int sum = std::accumulate(A.begin(), A.end(), 0);
        int M = sum / n;

        // C[0] = A[0] - M;
        C[0] = 0;

        for (int i = 1; i < n; ++i)
        {
            C[i] = C[i - 1] + A[i] - M;
        }
        
        std::for_each(C.begin(), C.end(), [](int c){printf("%d\t", c);});
        printf("\n");
        
        int mid = C[n / 2];

        int distance = std::accumulate(C.begin(), C.end(), 0, [mid](int sum, int c) {
            return sum + abs(c - mid);
        });

        printf("%d\n", distance);
    }

    return 0;
}