/*ID:leafduo1
  PROG:iou
  LANG:C++
*/

#include <fstream>

using namespace std;

ifstream fin("iou.in");
ofstream fout("iou.out");

const int maxn = 100000;

int f[maxn + 1];
int N;

void input()
{
	fin >> N;
	for (int i=1;i<=N;++i)
		fin>>f[i];
}

int move()
{
	int now = 0, pay = 0, dis = 0, money = 0;
	while(pay <= N) {
		if (f[now]>0) {
                        money += f[now];
                        f[now] = 0;
                        ++now;
                        ++pay;
                        ++dis;
                }
                else if (money >= -f[now]) {
                        money += f[now];
                        f[now] = 0;
                        ++now;
                        ++pay;
                        ++dis;
                }	
                else {
                        int wait = now;
                        while (money<-f[wait]) {
                                ++dis;
                                ++now;
                                if (f[now]>0)
                                {
                                        money += f[now];
                                        f[now] = 0;
                                }
                        }

                        money += f[wait];
                        f[wait] = 0;
                        dis += now - wait;
                        now = wait;
                        pay = now;
                }
        }
        return --dis;
}

int main()
{
        input();
        fout<< move() <<endl;
        return 0;
}

