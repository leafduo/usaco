/*ID:leafduo1
PROG:plumb
LANG:C++
*/

#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("plumb.in");
ofstream fout("plumb.out");

const int maxn = 50;

int R,C;
int f[maxn][maxn];

void input()
{
        fin>>R>>C;
        for (int i=0;i<R;++i)
                for (int j=0;j<C;++j)
                        fin>>f[i][j];
}

inline bool verify(int x, int y)
{
        int v = f[x][y];
        if (x-1>=0&&v==f[x-1][y])
                return true;
        if (y-1>=0&&v==f[x][y-1])
                return true;
        if (x+1<R&&v==f[x+1][y])
                return true;
        if (y+1<C&&v==f[x][y+1])
                return true;
        if (x-1>=0&&y-1>=0&&v==f[x-1][y-1])
                return true;
        if (x+1<R&&y+1<C&&v==f[x+1][y+1])
                return true;
        if (x-1>=0&&y+1<C&&v==f[x-1][y+1])
                return true;
        if (x+1<R&&y-1>=0&&v==f[x+1][y-1])
                return true;
        return false;
}

int solve()
{
        vector<int> arr;
        for (int i=0;i<R;++i)
                for (int j=0;j<C;++j)
                        if (verify(i,j))
                                arr.push_back(f[i][j]);
        sort(arr.begin(), arr.end());
        return arr.back();
}

int main()
{
        input();
        fout<<solve()<<endl;
        return 0;
}
