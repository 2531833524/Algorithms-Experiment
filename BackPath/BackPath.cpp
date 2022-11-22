#include <iostream>
using namespace std;
const int MAX = 1000;
const int N = 20;
int arc[N][20] = { 0 };
//int arc[10][10] = {
//    {MAX,4  ,2  ,3  ,MAX,MAX,MAX,MAX,MAX,MAX},
//    {MAX,MAX,MAX,MAX,9  ,8  ,MAX,MAX,MAX,MAX},
//    {MAX,MAX,MAX,MAX,6  ,7  ,8  ,MAX,MAX,MAX},
//    {MAX,MAX,MAX,MAX,MAX,4  ,7  ,MAX,MAX,MAX},
//    {MAX,MAX,MAX,MAX,MAX,MAX,MAX,5  ,6  ,MAX},
//    {MAX,MAX,MAX,MAX,MAX,MAX,MAX,8  ,6  ,MAX},
//    {MAX,MAX,MAX,MAX,MAX,MAX,MAX,6  ,5  ,MAX},
//    {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,7  },
//    {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,3  },
//    {MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX,MAX}
//};
int CreatGraph()
{
    int i, j, k;
    int weight;
    int vnum, arcnum;
    cout << "请输入顶点的个数和边的个数" << endl;
    cin >> vnum >> arcnum;
    
    for (i = 0; i < vnum; i++)
        for (j = 0; j < vnum; j++)
            arc[i][j] = MAX;
    for (k = 0; k < arcnum; k++)
    {
        cout << "请输入边的两个顶点和权值:";
        cin >> i >> j >> weight;
        arc[i][j] = weight;
    }
    return vnum;
}
int BackPath(int n)
{
    int i, j, temp;
    int cost[N], path[N];
    for (i = 0; i < n; i++)
    {
        cost[i] = MAX; path[i] = -1;
    }

    cost[n - 1] = 0;
    for (j = n - 1; j >= 0; j--)
    {
        for (i = j - 1; i >= 0; i--)
        {
            if (arc[i][j] + cost[j] < cost[i])
            {
                cost[i] = arc[i][j] + cost[j];
                path[i] = j;
            }
        }
    }
    cout << "0";
    i = 0;
    while (path[i] >= 0)
    {
        cout << "<-" << path[i];
        i = path[i];
    }
    cout << endl;
    return cost[0];
}
int main()
{
    int i = CreatGraph();
    cout<<"最短路径长度为："<<BackPath(i);
    return 0;
}

/*int arc[6][6] = {
    {MAX,2,  3,  MAX,MAX,MAX},
    {MAX,MAX,MAX,4,  6,  MAX},
    {MAX,MAX,MAX,5,  MAX,MAX},
    {MAX,MAX,MAX,MAX,MAX,10},
    {MAX,MAX,MAX,MAX,MAX,7},
    {MAX,MAX,MAX,MAX,MAX,MAX}
};
*/
/*
int BackPath(int n)
{
    int i, j, temp;
    int cost[N], path[N];
    for (i = 0; i < n; i++)
    {
        cost[i] = MAX; path[i] = -1;
    }

    cost[n - 1] = 0; 
    for (j = n - 2; j >= 0; j--)
    {
        for (i = j+1; i <= n-1; i++)
        {
            if (arc[i][j] + cost[i] < cost[j])
            {
                cost[j] = arc[i][j] + cost[i];
                path[j] = i;
            }
        }
    }
    cout <<"0";
    i = 0;
    while (path[i] >= 0)
    {
        cout << "<-" << path[i];
        i = path[i];
    }
    return cost[0];
}*/