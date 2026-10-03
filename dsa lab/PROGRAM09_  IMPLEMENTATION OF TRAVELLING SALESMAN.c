#include <stdio.h>
#include <limits.h>
#include <string.h>

#define MAX_N 15

int n;
int cost[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N];

int min(int a, int b)
{
    return a < b ? a : b;
}

int tsp(int mask, int pos)
{
    int ans;
    int next;
    int newCost;

    /* All cities visited */
    if (mask == (1 << n) - 1)
    {
        return cost[pos][0];
    }

    /* Already calculated */
    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    ans = INT_MAX;

    for (next = 0; next < n; next++)
    {
        /* If city is not visited */
        if ((mask & (1 << next)) == 0)
        {
            newCost = cost[pos][next]
                    + tsp(mask | (1 << next), next);

            ans = min(ans, newCost);
        }
    }

    dp[mask][pos] = ans;

    return ans;
}

int main()
{
    int i, j;
    int minCost;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    /* Validate number of cities */
    if (n <= 0 || n > MAX_N)
    {
        printf("Invalid number of cities. Enter a value between 1 and %d.\n",
               MAX_N);
        return 1;
    }

    printf("Enter the cost matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    /* Initialize DP table */
    memset(dp, -1, sizeof(dp));

    /* Start from city 0 */
    minCost = tsp(1, 0);

    printf("Minimum cost of the TSP: %d\n", minCost);

    return 0;
}


OUTPUT :

Enter the number of cities: 4
Enter the cost matrix:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
Minimum cost of the TSP: 80
