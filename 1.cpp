#include <iostream>
#include <cmath>
#include <stack>

#define S (2)

using namespace std;

string per(int n, int &ch)
{
    stack <char> c;
    int nn = n;
    n = int(abs(n));

    while(n > S-1)
    {
        int cif = n % S;
        if(cif > 0) ch += cif;
        c.push(char(int('0') + cif));
        n /= S;
    }

    string ans;

    if(n > 0) ch += n;

    if(nn == 0) ans = "0";
    else
    {
        while(!c.empty())
        {
            ans += c.top();
            c.pop();
        }
    }
    return ans;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0, m = -1;

    for(int i = a; i <= b; i ++)
    {
        if(i % 10 != 0)
        {
            int ch = 0;
            string y;
            y = per(i, ch);

            //cout << i << " " << y << " " << ch < "\n";
            if(ch == 5 && y[y.size() - 1] == '0')
            {
                ans ++;
                m = i;
            }
    }
    }

    if(m == -1)
    {
        cout << "0 0";
    }
    else cout << ans << " " << m;
    return 0;
}
