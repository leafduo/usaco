/* ID:leafduo1
   LANG:C++
   TASK:ride
 */

#include <fstream>
#include <string>

using namespace std;

ifstream fin("ride.in");
ofstream fout("ride.out");

int convert(string s)
{
    const int mod = 47;
    int result = 1;
    for (string::size_type st = 0;st != s.size(); ++st) {
        result *= s[st] - 'A' + 1;
        result %= mod;
    }
    return result;
}

int main()
{
    string s1, s2;
    fin >> s1 >> s2;
    if (convert(s1) == convert(s2))
        fout<<"GO"<<endl;
    else
        fout<<"STAY"<<endl;
    return 0;
}
