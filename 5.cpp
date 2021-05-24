#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;


bool delit(char c)
{
    return c == ' ';
}

bool oper( char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int pr(char op)
{
    if(op == '*' || op == '/')
    {
        return 2;
    }
    else if(op == '+' || op == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void proc(vector <int> &st, char op)
{
    int r = st.back();
    st.pop_back();
    int l = st.back();
    st.pop_back();

    switch(op)
    {
        case '+': st.push_back(l + r); break;
        case '-': st.push_back(l - r); break;
        case '*': st.push_back(l * r); break;
        case '/': st.push_back(floor(double(l) / double(r))); break;
    }
}

int cal(string &s)
{
    vector <int> st;
    vector <char> op;

    for(int i = 0; i < s.length(); i ++)
        if(!delit(s[i]))
            if(s[i] == '(')
               op.push_back('(');
        else if(s[i] == ')')
        {
            while(op.back()!= '(')
                proc(st, op.back()), op.pop_back();
            op.pop_back();
        }
        else if(oper(s[i]))
        {
            char cur = s[i];
            while(!op.empty() && pr(op.back()) >= pr(s[i]))
                proc(st, op.back()), op.pop_back();
            op.push_back(cur);
        }
        else
        {
            string operand;

            while(i < s.size() && isalnum(s[i]))
                operand += s[i++];
            i--;

            if(isdigit(operand[0]))
                st.push_back(atoi(operand.c_str()));
            else
                st.push_back(operand[0]);
        }

        while(!op.empty())
            proc(st, op.back()), op.pop_back();

        return st.back();


}

int main()
{
    string s;
    getline(cin, s);

    for(int i = 0; i < s.size() - 1; i ++)
    {
        if(((s[i] >= '0' && s[i] <= '9') || s[i] == ')') && s[i+ 1] == '(')
        {
            s = s.substr(0, i + 1) + '*' + s.substr(i + 1, s.size());
        }
    }

    cout << cal(s) << '\n';
    return 0;
}
