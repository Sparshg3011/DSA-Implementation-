#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st;

bool IsMatched(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return true;
    }
    if (a == '{' && b == '}')
    {
        return true;
    }
    if (a == '[' && b == ']')
    {
        return true;
    }
    return false;
}

bool IsBalanced(string exp)
{
    int n = exp.length();
    char ch;
    char a;
    for (int i = 0; i < n; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            st.push(exp[i]);
            continue;
        }

        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (st.empty())
            {
                return false;
            }
            a = st.top();
            st.pop();
            if (!IsMatched(a , exp[i]))
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
}

int main()
{
    string expression;
    cout << "Enter the Expression : " << endl;
    cin >> expression;
    if (IsBalanced(expression))
    {
        cout << "Balanced Expression" << endl;
    }
    else
    {
        cout << "Unbalanced Expression" << endl;
    }

    return 0;
}