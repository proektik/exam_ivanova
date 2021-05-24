#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("input.txt");

    string s;

    getline(fin, s);

    char currch = s[0], maxch = s[0];
    int currlen = 1, maxlen = 1;

    for(int i =0; i < s.size() - 1; i ++)
    {
        if(s[i] == s[i + 1])
        {
            currch = s[i];
            currlen ++;
        }
        else
        {
            currlen = 1;
            currch = s[i];
        }

        if(currlen > maxlen)
        {
            maxlen = currlen;
            maxch = currch;
        }
    }

    cout << maxch << " " << maxlen;
    fin.close();
    return 0;
}
