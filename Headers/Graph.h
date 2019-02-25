#include <iostream>
#include <stack>
#include <climits>
#define PLACES 20
#define ROADS 50
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

// 保存路径
typedef struct
{
  int sum;
  bool flag;
  string result;
} MultiRoad;

class Graph
{
public:
  TVertex vertex[PLACES];
  // 用于储存搜索中路径的权值
  Path dis[PLACES];
  int AdjacencyMatrix[PLACES][PLACES];
  stack<int> stk;

public:
  // 初始化地图
  Graph();
  // 输入地点信息
  void setInfo(int num, string name, string info);
  // 删除景点及其道路
  void delInfo(int num);
  // 查询地点信息
  string getInfo(int num);
  // 查询道路信息
  string getPathInfo(int x, int y);
  // 输入新的路径
  void setPath(int x, int y, int dis);
  // 删除路径
  void delPath(int x, int y);
  // 寻找路径
  void getPath(int x, int y, string &result, int &sum, int (&v)[PLACES]);
  // 深度优先搜索输出路径
  void DFS(int x, int y, string &result, int &sum, int (&v)[PLACES], int &c);
  // 将栈清空
  void cleanStack(stack<int> &stack)
  {
    while (!stack.empty())
      stack.pop();
  }
  // 输出所有简单路径
  void getAllPath(int x, int y, bool refresh, string &result);
  // 多景点查询
  void multiPath(int x, int y, int z, string &result);
  // 多景点遍历路径
  void multiGetAllPath(int x, int y, int z, bool refresh, int &c, MultiRoad (&mr)[ROADS]);
};
