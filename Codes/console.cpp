#include "graph.cpp"
using namespace std;

int main()
{
    Graph g;
    while (true)
    {
        cout << "##############################" << endl
             << "校园导游系统 console 版本 v0.9" << endl
             << "功能如下：" << endl
             << "1：输入景点信息（编号，名称，简介）" << endl
             << "2：查询景点信息（编号）" << endl
             << "3：输入路径（编号1，编号2，权重）" << endl
             << "4：查询最短路径（编号1，编号2）" << endl
             << "5：查询所有路径（编号1，编号2）" << endl
             << "0：退出" << endl
             << "##############################" << endl;
        int c;
        cin >> c;
        if (c == 0)
            return -1;
        else if (c == 1)
        {
            int num;
            string name, info;
            cin >> num >> name >> info;
            g.setInfo(num, name, info);
        }
        else if (c == 2)
        {
            int num;
            cin >> num;
            g.getInfo(num);
        }
        else if (c == 3)
        {
            int x, y, d;
            cin >> x >> y >> d;
            g.setPath(x, y, d);
        }
        else if (c == 4)
        {
            int x, y;
            cin >> x >> y;
            g.getPath(x, y);
        }
        else if (c == 5)
        {
            int x, y;
            cin >> x >> y;
            cout << "##############################" << endl;
            g.getAllPath(x, y, true);
            cout << "##############################" << endl;
        }
    }
}