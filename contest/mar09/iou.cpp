/*ID:leafduo1
  TASK:iou
  LANG:C++
*/

#include <fstream>

using namespace std;

ifstream fin("iou.in");
ofstream fout("iou.out");

int main()
{
        int N;
        fin >> N;
        int money = 0, pay = 0;
        int dis = N;
        for (int i = 1; i <= N; ++i) {
                int now;
                fin >> now;
                money += now;
                if (money < 0 && 0 == pay)
                        pay = i;
                else if (money > 0 && 0 != pay) {
                        dis += (i - pay) * 2;
                        pay = 0;
                }
        }
        fout << dis << endl;
        return 0;
}
