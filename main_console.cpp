#include "Graph.cpp"
using namespace std;

int console()
{
    Graph g;
    string result = "";
    cout << "##############################" << endl
         << "校园导游系统 Console 版本 v1.3" << endl
         << "功能如下：" << endl
         << "1：输入景点信息（编号，名称，简介）" << endl
         << "2：查询景点信息（编号）" << endl
         << "3：输入路径（编号1，编号2，权重）" << endl
         << "4：查询最短路径（编号1，编号2）" << endl
         << "5：查询所有路径（编号1，编号2）" << endl
         << "6：多景点查询（三景点，编号1，编号2，编号3）" << endl
         << "7：关于" << endl
         << "0：退出" << endl
         << "##############################" << endl;
    while (true)
    {
        int c;
        cin >> c;
        if (c == 0)
            return -1;
        else if (c == 7)
        {
            cout << "##############################" << endl
                 << "关于" << endl
                 << "校园导游系统 Console 版本 v1.3" << endl
                 << "本程序由GitHub用户 iamywang 独立开发" << endl
                 << "为数据结构课程设计题目，提供校园导游服务" << endl
                 << "遵循 GNU General Public License 3.0 通用公共许可协议" << endl
                 << "##############################" << endl;
        }
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
            cout << g.getInfo(num);
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
            result = "";
            g.getPath(x, y, result);
            cout << "##############################" << endl
                 << "从 " << g.vertex[x].place << " 到 " << g.vertex[y].place << " 的最短路径为："
                 << result << endl
                 << "##############################" << endl;
        }
        else if (c == 5)
        {
            int x, y;
            cin >> x >> y;
            result = "";
            g.getAllPath(x, y, true, result);
            cout << "##############################" << endl
                 << "从 " << g.vertex[x].place << " 到 " << g.vertex[y].place << " 的所有路径为：" << endl
                 << result
                 << "##############################" << endl;
        }
        else if (c == 6)
        {
            int x, y, z;
            cin >> x >> y >> z;
            result = "";
            g.multiPath(x, y, z, result);
            cout << "##############################" << endl
                 << "从 " << g.vertex[x].place << " 经过 " << g.vertex[y].place << " 到 " << g.vertex[z].place << " 的最短路径为："
                 << result << endl
                 << "##############################" << endl;
        }
    }
}
