#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
bool isOperator(char c) 
{
    return(!isalpha(c) && !isdigit(c));
}
int getPrecedence(char op) 
{
    if(op=='-' || op=='+')
        return 1;
    else if(op=='*' || op=='/')
        return 2;
    else if(op=='^')
        return 3;
    return 0;
}
//convert infix to postfix
string infixToPostfixConversion(string infixExpr)
 {
    infixExpr='(' + infixExpr + ')';
    int length=infixExpr.size();
    stack<char>charStack;
    string postfixOutput;
    for(int i=0;i<length;i++) 
	{
        if (isalpha(infixExpr[i]) || isdigit(infixExpr[i]))
            postfixOutput+=infixExpr[i];
        else if(infixExpr[i]=='(')
            charStack.push('(');
        else if(infixExpr[i]==')') 
		{
            while(charStack.top()!='(') 
			{
                postfixOutput+=charStack.top();
                charStack.pop();
            }
            charStack.pop();
        } 
		else 
		{
            if (isOperator(charStack.top())) 
			{
                if (infixExpr[i] == '^')
				 {
                    while (getPrecedence(infixExpr[i])<=getPrecedence(charStack.top())) 
					{
                        postfixOutput+=charStack.top();
                        charStack.pop();
                    }
                } 
				else 
				{
                    while (getPrecedence(infixExpr[i])<getPrecedence(charStack.top())) 
					{
                        postfixOutput+=charStack.top();
                        charStack.pop();
                    }
                }
                charStack.push(infixExpr[i]);
            }
        }
    }
    while(!charStack.empty())
	 {
        postfixOutput += charStack.top();
        charStack.pop();
    }
    return postfixOutput;
}
//convert infix to prefix
string infixToPrefixConversion(string infixExpr) 
{
    reverse(infixExpr.begin(),infixExpr.end());
    int length=infixExpr.size();
    for(int i=0;i<length;i++) 
	{
        if(infixExpr[i]=='(')
            infixExpr[i]=')';
        else if(infixExpr[i]==')')
            infixExpr[i]='(';
    }
    string prefixExpr=infixToPostfixConversion(infixExpr);
    reverse(prefixExpr.begin(),prefixExpr.end());
    return prefixExpr;
}
int main() 
{
    string infixExpr;
    cout<<"Enter the infix expression: ";
	cin>>infixExpr;
    string prefixExpr=infixToPrefixConversion(infixExpr);
    cout<<"Prefix expression: "<<prefixExpr<<endl;
    return 0;
}
 



