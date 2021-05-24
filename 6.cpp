#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

int main()
{
    stack <int> c;
    string s;
    int x;
    bool err = 0;

    while(cin >> s)
    {
        bool cif = 0;
        x = 0;
        int a, b;
        x = atoi(s.c_str());
        if(s[0] == '0')
        {
            c.push(0);
            cif = 1;
        }
        if(x != 0)
        {
            c.push(x);
            cif = 1;
        }

        if(s[0] == '+' && c.size() >= 2)
        {
            b = c.top();
            c.pop();
            a = c.top();
            c.pop();
            c.push(a + b);
        }
        else if(s[0] == '-' && c.size() >= 2)
        {
            b = c.top();
            c.pop();
            a = c.top();
            c.pop();
            c.push(a - b);
        }
        else if(s[0] == '*' && c.size() >= 2)
        {
            b = c.top();
            c.pop();
            a = c.top();
            c.pop();
            c.push(a * b);
        }
        else if(s[0] == '/' && c.size() >= 2)
        {
            b = c.top();
            c.pop();
            a = c.top();
            c.pop();
            if(a / b < 0)
            {
                c.push(a / b - 1);
            }
            else
                c.push(a / b);
        }
        else if(!cif)
        {
            cout << "ERROR";
            err = 1;
            break;
        }
    }

    int ans = c.top();
    c.pop();

    if(!c.empty() && !err) cout << "ERROR";
    else if(!err) cout << ans;

    return 0;
}
