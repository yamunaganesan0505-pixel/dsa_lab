#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

#define V 9

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX;
    int min_index = -1;
    int v;

    for (v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[])
{
    int i;

    printf("Vertex\t\tDistance from Source\n");

    for (i = 0; i < V; i++)
    {
        if (dist[i] == INT_MAX)
            printf("%d\t\tINF\n", i);
        else
            printf("%d\t\t%d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];

    int i;
    int count;
    int u;
    int v;

    /* Initialize distances and shortest path set */
    for (i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    /* Distance of source from itself is 0 */
    dist[src] = 0;

    /* Find shortest paths */
    for (count = 0; count < V - 1; count++)
    {
        u = minDistance(dist, sptSet);

        /* No reachable vertex remains */
        if (u == -1)
            break;

        sptSet[u] = true;

        for (v = 0; v < V; v++)
        {
            if (!sptSet[v] &&
                graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main()
{
    int graph[V][V] =
    {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);

    return 0;
}


OUTPUT :

Vertex          Distance from Source
0               0
1               4
2               12
3               19
4               21
5               11
6               9
7               8
8               14
