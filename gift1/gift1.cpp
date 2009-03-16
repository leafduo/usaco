/*ID:leafduo1
  PROG:gift1
  LANG:C++
*/

#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

ifstream fin("gift1.in");
ofstream fout("gift1.out");

int NP;
map<string, int> initial, final;
vector<string> nameList;

void solve()
{
        fin>>NP;
        for (int i=0;i<NP;++i) {
                string name;
                fin>>name;
                nameList.push_back(name);
                initial[name] = 0;
        }
        while (!fin.eof()) {
                string giver;
                fin>>giver;
                int money, num;
                fin>>money>>num;
                initial[giver]=money;
                if (num) {
                        final[giver] += money % num;
                        money /= num;
                } else
                        money = 0;
                for (int j=0;j<num;++j) {
                        string receiver;
                        fin>>receiver;
                        final[receiver]+=money;
                }
        }
        for (int i=0;i<NP;++i) {
                string name = nameList[i];
                fout<<nameList[i]<<" "<<final[name] - initial[name]<<endl;
        }
}

int main()
{
        solve();
        return 0;
}
