#include<iostream>
#include<stack>
#include<string>
using namespace std;

int prec(char ch)
{
    if(ch == '*' || ch == '/')
    {
        return 3;
    }
    if(ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

string infixtopostfix(string infix)
{
    stack <char> st;
    string postfix;
    
    for(int i = 0 ; i < infix.length() ; i++)
    {
        if((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
        {
            postfix+= infix[i];
        }
        else if (infix[i] == '(')
        {
            st.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                postfix+= st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            if(!st.empty() && prec(st.top()) > prec(infix[i]))
            {
                postfix+= st.top();
                st.pop();
            }
            st.push(infix[i]);
        }
    }
    while(!st.empty())
    {
        postfix+= st.top();
        st.pop();
    }
    return postfix;
}

int main()
{
    string infix;
    cout<<"Enter the infix expression : "<<endl;
    cin>>infix;
    cout<<"The postfix expression of the entered infix is "<< infixtopostfix(infix)<<endl;

    return 0;
}
