// C++ implementation to convert infix to postfix//
#include<bits/stdc++.h>
using namespace std;
 
//return precedence of operators
int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}
 
//Function to convert infix expression to postfix expression
void infixToPostfix(string s)
{
    stack<char> p;
    p.push('E');
    int l = s.length();
    string n;
    for(int i = 0; i < l; i++)
    {
        // If the scanned character is an operand, add it to output string.
        if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z'))
        n+=s[i];
 
        // If the scanned character is an ‘(‘, push it to the stack.
        else if(s[i] == '(')
         
        p.push('(');
         
        // If the scanned character is an ‘)’, pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(s[i] == ')')
        {
            while(p.top() != 'E' && p.top() != '(')
            {
                char c = p.top();
                p.pop();
               n+= c;
            }
            if(p.top() == '(')
            {
                char c = p.top();
                p.pop();
            }
        }
         
        //If an operator is scanned
        else{
            while(p.top() != 'E' && prec(s[i]) <= prec(p.top()))
            {
                char c = p.top();
                p.pop();
                n+= c;
            }
            p.push(s[i]);
        }
 
    }
    //Pop all the remaining elements from the stack
    while(p.top() != 'E')
    {
        char c = p.top();
        p.pop();
        n+= c;
    }
     
    cout << n << endl;
 
}
 
//Driver program to test above functions
int main()
{
    string exp = "a+c(b*g+h)/d-e^f";
    infixToPostfix(exp);
    return 0;
}
