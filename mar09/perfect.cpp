/*ID:leafduo1
  PROG:perfect
  LANG:C++
  */

#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("perfect.in");
ofstream fout("perfect.out");

const int maxn = 99;

int N;
int f[maxn][maxn];

void input()
{
        fin >> N;
        for (int i=0;i<N;++i)
                for (int j=0;j<N;++j)
                        fin>>f[i][j];
}

int solve()
{
        const int mid = N/2;
        for (int i=0;i<N;++i) {
                int* begin = f[i];
                int* end = f[i] + N;
                sort(begin, end);
        }
        int g[maxn];
        for (int i=0;i<N;++i)
                g[i]=f[i][mid];
        sort(g,g+N);
        return g[mid];
}

int main()
{
        input();
        fout<<solve()<<endl;
        return 0;
}
