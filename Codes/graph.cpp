#include "graph.h"

// 初始化地图
Graph::Graph()
{
    // 初始化邻接矩阵为∞
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            AdjacencyMatrix[i][j] = INT_MAX;
    // 对角线初始化为0
    for (int i = 0; i < 20; i++)
    {
        AdjacencyMatrix[i][i] = 0;
        vertex[i].place = "";
        vertex[i].info = "";
    }
}
// 输入地点信息
void Graph::setInfo(int num, string name, string info)
{
    vertex[num].place = name;
    vertex[num].info = info;
}
// 查询地点信息
void Graph::getInfo(int num)
{
    cout << "景点编号：" << num << endl
         << "景点名称：" << vertex[num].place << endl
         << "景点介绍：" << vertex[num].info << endl;
}
// 输入新的路径
void Graph::setPath(int x, int y, int dis)
{
    AdjacencyMatrix[x][y] = dis;
    AdjacencyMatrix[y][x] = dis;
}
// 寻找路径
void Graph::getPath(int x, int y)
{
    int rest[20] = {0};
    rest[x] = 1;
    // 初始化路径权值
    for (int i = 0; i < 20; i++)
    {
        dis[i].weight = AdjacencyMatrix[x][i];
        cleanStack(dis[i].previous);
        cleanStack(dis[i].backup);
    }

    for (int count = 1; count != 20; count++)
    {
        // 寻找权值最小顶点
        int min = INT_MAX;
        for (int i = 0; i < 20; i++)
            if (rest[i] == 0)
            {
                min = i;
                for (i += 1; i < 20; i++)
                    if (rest[i] == 0 and dis[min].weight > dis[i].weight)
                        min = i;
            }
        if (min == INT_MAX)
            return;
        else
            rest[min] = 1;

        // 更新路径权值
        for (int i = 0; i < 20; i++)
        {
            if (rest[i] == 1)
                continue;
            if (AdjacencyMatrix[min][i] <= dis[i].weight - dis[min].weight)
            {
                if (AdjacencyMatrix[min][i] != dis[i].weight - dis[min].weight)
                    cleanStack(dis[i].previous);
                dis[i].weight = dis[min].weight + AdjacencyMatrix[min][i];
                dis[i].previous.push(min);
            }
        }
        rest[min] = 1;
    }

    // 递归输出最短路径
    cout << "-----------------------" << endl
         << endl;
    cout << "从 " << vertex[x].place << " 到 " << vertex[y].place << " 的最短路线为：";
    DFS(x, y);
    cout << endl
         << endl
         << "-----------------------" << endl;
}
// 深度优先搜索输出路径
void Graph::DFS(int x, int y)
{
    if (dis[y].previous.empty())
        cout << endl
             << vertex[x].place << " -> " << vertex[y].place;
    // 将节点所有分支搜索完
    while (!dis[y].previous.empty())
    {
        DFS(x, dis[y].previous.top());
        cout << " -> " << vertex[y].place;
        dis[y].backup.push(dis[y].previous.top());
        dis[y].previous.pop();
    }
    // 将前驱信息还原
    while (!dis[y].backup.empty())
    {
        dis[y].previous.push(dis[y].backup.top());
        dis[y].backup.pop();
    }
}
// 输出所有简单路径
void Graph::getAllPath(int x, int y, bool refresh)
{
    // 用数组保存简单路径
    static int path[20], count = 0, mark[20] = {0}, start = x;
    // 在反复调用递归函数时刷新静态变量
    if (refresh)
    {
        for (int i = 0; i < 20; i++)
        {
            path[i] = INT_MAX;
            mark[i] = 0;
        }
        count = 0;
        start = x;
    }
    for (int i = 0; i < 20; i++)
    {
        if (AdjacencyMatrix[x][i] != INT_MAX and mark[i] == 0)
        {
            // 标记该节点以搜索过
            mark[i] = 1;
            if (x == i)
                continue;
            path[count++] = i;
            // 输出路径
            if (i == y)
            {
                // start 静态变量保存路径起始点
                cout << vertex[start].place;
                for (int p = 0; path[p] != INT_MAX; p++)
                    cout << " -> " << vertex[path[p]].place;
                cout << endl;
                mark[i] = 0;
                path[--count] = INT_MAX;
                return;
            }
            getAllPath(i, y, false);
            // 删除标记
            mark[i] = 0;
            path[--count] = INT_MAX;
        }
    }
}
