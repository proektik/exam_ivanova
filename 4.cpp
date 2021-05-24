#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int j = 0, n,a[1000];

void rec(int x, int y, int z,ofstream & fout)
{
    if(y == 0)
    {
        j ++;
        for(int i = x - 1; i >= 0; i --)
        {
            fout << a[i] << " ";
        }
        fout << endl;
        return;
    }

    for(int i = z; i <= y; i ++)
    {
        if(i >= z)
        {
            a[x] = i;
            rec(x + 1, y - i, i,fout);
        }
    }
}
int main()
{
    ofstream fout;
    fout.open("data.txt");

    cin >> n;

    rec(0, n, 1, fout);

    fout.close();

    ifstream fin;
    fin.open("data.txt");

    string s[j];

    for(int i = 0; i < j; i ++) getline(fin, s[i]);

    for(int i = 0; i < j; i ++)
    {
        for (int q = i; q < j; q ++)
        {
            string s1 = s[i], s2 = s[q];
            if(s2 < s1) swap(s[i], s[q]);
        }
    }

    for(int i = 0; i < j; i ++)
        cout << s[i] << endl;
    return 0;
}
