#include <iostream>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    bool pr = 0;

    for( int i = a; i <= b; i ++ )
    {
        int k = 0;

        for(int j = 1; j * j <= i; j += 1)
        {
            if(i % j == 0)
            {
                if(j % 2 == 0)
            {
                k ++;
            }
            if((i / j) % 2 == 0 && j != i / j)
            {
                k ++;
            }
            }
        }

        if(k == 3)
        {
            cout << i << endl;
            pr = 1;
        }
    }

    if(!pr) cout << "0";
    return 0;
}
