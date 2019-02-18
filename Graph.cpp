#include "Headers/Graph.h"

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
string Graph::getInfo(int num)
{
    string result = "";
    result += "##############################";
    result += "\n景点编号：" + to_string(num);
    result += "\n景点名称：" + vertex[num].place;
    result += "\n景点介绍：" + vertex[num].info;
    result += "\n##############################\n";
    return result;
}
// 输入新的路径
void Graph::setPath(int x, int y, int dis)
{
    AdjacencyMatrix[x][y] = dis;
    AdjacencyMatrix[y][x] = dis;
}
// 寻找路径
void Graph::getPath(int x, int y, string result)
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
    DFS(x, y, result);
}
// 深度优先搜索输出路径
void Graph::DFS(int x, int y, string result)
{
    if (dis[y].previous.empty())
        result += "\n" + vertex[x].place + " -> " + vertex[y].place;
    // 将节点所有分支搜索完
    while (!dis[y].previous.empty())
    {
        DFS(x, dis[y].previous.top(), result);
        result += " -> " + vertex[y].place;
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
void Graph::getAllPath(int x, int y, bool refresh, string result)
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
                result += vertex[start].place;
                for (int p = 0; path[p] != INT_MAX; p++)
                    result += " -> " + vertex[path[p]].place;
                result += "\n";
                mark[i] = 0;
                path[--count] = INT_MAX;
                return;
            }
            getAllPath(i, y, false, result);
            // 删除标记
            mark[i] = 0;
            path[--count] = INT_MAX;
        }
    }
}
//多景点查询
void Graph::multiPath(int x, int y, int z, string result)
{
    string r1 = "";
    string r2 = "";
    getPath(x, y, r1);
    getPath(y, z, r2);
    result = r1 + " -> " + r2;
}
