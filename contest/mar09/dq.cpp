/*ID:leafduo1;
PROG:dq
LANG:C++
*/

#include <fstream>

using namespace std;

ifstream fin("dq.in");
ofstream fout("dq.out");

const int maxc = 8;
const int maxn = 300;

int N,C;
int coin[maxc],f[maxn+1];

void input()
{
        fin>>N>>C;
        for (int i=0;i<C;++i)
                fin>>coin[i];
}

int solve()
{
        f[0] = 1;
        for (int j=0;j<C;++j)
                for (int i=0;i<=N;++i) 
                        //for (int j=0;j<C;++j)
                        if (i-coin[j]>=0)
                                f[i]+=f[i-coin[j]];
        return f[N];
}

int main()
{
        input();
        fout<<solve()<<endl;
        return 0;
}
