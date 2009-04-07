/* ID:leafduo1
TASK:friday
LANG:C++
*/

#include <fstream>

using namespace std;

ifstream fin("friday.in");
ofstream fout("friday.out");

int week[7];

void zeller()
{
        int year;
        fin >> year;
        year += 1900;
        const int d = 13;
        for (int y = 1899; y != year - 1; ++y) //for Jan. & Feb.
                for (int m = 13; m <= 14; ++m)
                        ++week[(d + (m+1)*26/10 + y + y/4 + 6*(y/100) + y/400) % 7];
        for (int y = 1900; y != year;  ++y) //for other months
                for (int m = 3; m <= 12; ++m)
                        ++week[(d + (m+1)*26/10 + y + y/4 + 6*(y/100) + y/400) % 7];

}

void output()
{
        for (int i = 0; i != 6; ++i)
                fout << week[i] << " ";
        fout << week[6] << endl;
}

int main()
{
        zeller();
        output();
        return 0;
}
