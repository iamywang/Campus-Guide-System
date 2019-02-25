#include "Headers/Graph.h"

// 初始化地图
Graph::Graph()
{
    // 初始化邻接矩阵为∞
    for (int i = 0; i < PLACES; i++)
        for (int j = 0; j < PLACES; j++)
            AdjacencyMatrix[i][j] = INT_MAX;
    // 对角线初始化为0
    for (int i = 0; i < PLACES; i++)
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
    result = result + "景点编号：" + to_string(num) + "\n";
    result = result + "景点名称：" + vertex[num].place + "\n";
    result = result + "景点介绍：" + vertex[num].info + "\n";
    return result;
}

// 查询道路信息
string Graph::getPathInfo(int x, int y)
{
    string result = "";
    result = result + "道路起点：" + to_string(x) + " " + vertex[x].place + "\n";
    result = result + "道路终点：" + to_string(y) + " " + vertex[y].place + "\n";
    result = result + "道路长度：" + to_string(AdjacencyMatrix[x][y]) + "\n";
    return result;
}

// 删除景点及其道路
void Graph::delInfo(int num)
{
    for (int i = 0; i < PLACES; i++)
        AdjacencyMatrix[i][num] = INT_MAX;
    for (int j = 0; j < PLACES; j++)
        AdjacencyMatrix[num][j] = INT_MAX;
    AdjacencyMatrix[num][num] = 0;
    vertex[num].place = "";
    vertex[num].info = "";
}

// 输入新的路径
void Graph::setPath(int x, int y, int dis)
{
    AdjacencyMatrix[x][y] = dis;
    AdjacencyMatrix[y][x] = dis;
}

// 删除路径
void Graph::delPath(int x, int y)
{
    AdjacencyMatrix[x][y] = INT_MAX;
    AdjacencyMatrix[y][x] = INT_MAX;
}

// 寻找路径
void Graph::getPath(int x, int y, string &result, int &sum, int (&v)[PLACES])
{
    int rest[PLACES] = {0};
    rest[x] = 1;
    // 初始化路径权值
    for (int i = 0; i < PLACES; i++)
    {
        dis[i].weight = AdjacencyMatrix[x][i];
        cleanStack(dis[i].previous);
        cleanStack(dis[i].backup);
    }

    for (int count = 1; count != PLACES; count++)
    {
        // 寻找权值最小顶点
        int min = INT_MAX;
        for (int i = 0; i < PLACES; i++)
            if (rest[i] == 0)
            {
                min = i;
                for (i += 1; i < PLACES; i++)
                    if (rest[i] == 0 and dis[min].weight > dis[i].weight)
                        min = i;
            }
        if (min == INT_MAX)
            return;
        else
            rest[min] = 1;

        // 更新路径权值
        for (int i = 0; i < PLACES; i++)
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
    int c = 0;
    DFS(x, y, result, sum, v, c);
}

// 深度优先搜索输出路径
void Graph::DFS(int x, int y, string &result, int &sum, int (&v)[PLACES], int &c)
{
    if (dis[y].previous.empty())
    {
        result = result + "\n" + to_string(x) + " " + vertex[x].place + " -> " + to_string(y) + " " + vertex[y].place;
        sum += AdjacencyMatrix[x][y];
        v[c++] = x;
        v[c++] = y;
    }
    // 将节点所有分支搜索完
    while (!dis[y].previous.empty())
    {
        DFS(x, dis[y].previous.top(), result, sum, v, c);
        result = result + " -> " + to_string(y) + " " + vertex[y].place;
        sum += AdjacencyMatrix[dis[y].previous.top()][y];
        v[c++] = y;
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
void Graph::getAllPath(int x, int y, bool refresh, string &result)
{
    // 用数组保存简单路径
    static int path[PLACES], count = 0, mark[PLACES] = {0}, start = x;
    // 在反复调用递归函数时刷新静态变量
    if (refresh)
    {
        for (int i = 0; i < PLACES; i++)
        {
            path[i] = INT_MAX;
            mark[i] = 0;
        }
        count = 0;
        start = x;
    }
    for (int i = 0; i < PLACES; i++)
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
                result = result + to_string(start) + " " + vertex[start].place;
                int sum = 0;
                int pos = start;
                for (int p = 0; path[p] != INT_MAX; p++)
                {
                    result = result + " -> " + to_string(path[p]) + " " + vertex[path[p]].place;
                    sum += AdjacencyMatrix[pos][path[p]];
                    pos = path[p];
                }
                result = result + "\n路径长度：" + to_string(sum) + "\n";
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
void Graph::multiPath(int x, int y, int z, string &result)
{
    // 保存每条路径
    MultiRoad mr[ROADS];
    for (int i = 0; i < ROADS; i++)
    {
        mr[i].flag = false;
        mr[i].sum = 0;
        mr[i].result = "";
    }
    int c1 = 0;
    MultiRoad min;
    min.flag = true;
    min.sum = INT_MAX;
    min.result = "";
    multiGetAllPath(x, y, z, true, c1, mr);
    for (int i = 0; i < c1; i++)
    {
        if (mr[i].flag == true && mr[i].sum < min.sum)
            min = mr[i];
    }
    int c2 = c1;
    multiGetAllPath(x, y, z, true, c2, mr);
    for (int i = c1; i < c2; i++)
    {
        if (mr[i].flag == true && mr[i].sum < min.sum)
            min = mr[i];
    }
    if (min.result == "")
    {
        string r1 = "";
        string r2 = "";
        int s1 = 0;
        int s2 = 0;
        int tmp[PLACES];
        getPath(x, y, r1, s1, tmp);
        getPath(y, z, r2, s2, tmp);
        min.sum = s1 + s2;
        min.result = r1 + r2;
        getPath(x, z, r1, s1, tmp);
        getPath(z, y, r2, s2, tmp);
        if ((s1 + s2) < min.sum)
        {
            min.sum = s1 + s2;
            min.result = r1 + r2;
        }
        else if ((s1 + s2) == min.sum)
        {
            min.result = min.result + "\n" + r1 + r2;
        }
        result = min.result + "\n路径长度：" + to_string(min.sum);
    }
    else
        result = "\n" + min.result + "\n路径长度：" + to_string(min.sum);
}

// 多景点遍历路径
void Graph::multiGetAllPath(int x, int y, int z, bool refresh, int &c, MultiRoad (&mr)[ROADS])
{
    // 用数组保存简单路径
    static int path[PLACES], count = 0, mark[PLACES] = {0}, start = x;
    // 在反复调用递归函数时刷新静态变量
    if (refresh)
    {
        for (int i = 0; i < PLACES; i++)
        {
            path[i] = INT_MAX;
            mark[i] = 0;
        }
        count = 0;
        start = x;
    }
    for (int i = 0; i < PLACES; i++)
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
                mr[c].result = mr[c].result + to_string(start) + " " + vertex[start].place;
                int pos = start;
                for (int p = 0; path[p] != INT_MAX; p++)
                {
                    if (path[p] == z)
                        mr[c].flag = true;
                    mr[c].result = mr[c].result + " -> " + to_string(path[p]) + " " + vertex[path[p]].place;
                    mr[c].sum += AdjacencyMatrix[pos][path[p]];
                    pos = path[p];
                }
                c++;
                mark[i] = 0;
                path[--count] = INT_MAX;
                return;
            }
            multiGetAllPath(i, y, z, false, c, mr);
            // 删除标记
            mark[i] = 0;
            path[--count] = INT_MAX;
        }
    }
}