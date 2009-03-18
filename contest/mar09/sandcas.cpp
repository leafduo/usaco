/*ID:leafduo1
  TASK:sandcas
  LANG:C++
*/

#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("sandcas.in");
ofstream fout("sandcas.out");

vector<int> origin, final;
int N, X, Y;

void input()
{
        fin >> N >> X >> Y;
        for (int i = 0; i < N; ++i) {
                int temp;
                fin >> temp;
                origin.push_back(temp);
                fin >> temp;
                final.push_back(temp);
        }
}

inline int diff(int a, int b)
{
        return a < b ? X * (b - a):Y * (a - b);
}

int solve()
{
        sort(origin.begin(), origin.end());
        sort(final.begin(), final.end());
        int cost = 0;
        for (int i = 0; i < N; ++i)
                cost += diff(origin[i], final[i]);
        return cost;
}

int main()
{
        input();
        fout << solve() << endl;
        return 0;
}
