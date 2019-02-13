#include <iostream>
#include <stack>
#include <climits>
using namespace std;

// 构造表节点
typedef struct
{
    string place, info;
} TVertex;

// 记录权值及传递过来的节点
typedef struct
{
    int weight;
    stack<int> previous;
    // 作为路径栈的备份
    stack<int> backup;
} Path;

class Graph
{
    TVertex vertex[20];
    // 用于储存搜索中路径的权值
    Path dis[20];
    int AdjacencyMatrix[20][20];
    stack<int> stk;
  public:
    string res = "";
    // 初始化地图
    Graph();
    // 输入地点信息
    void setInfo(int num, string name, string info);
    // 查询地点信息
    string getInfo(int num);
    // 输入新的路径
    void setPath(int x, int y, int dis);
    // 寻找路径
    string getPath(int x, int y);
    // 深度优先搜索输出路径
    void DFS(int x, int y);
    // 将栈清空
    void cleanStack(stack<int> &stack)
    {
        while (!stack.empty())
            stack.pop();
    }
    // 输出所有简单路径
    void getAllPath(int x, int y, bool refresh);
};
