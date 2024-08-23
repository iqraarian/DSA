#include <iostream>
#include <stack>
#include <cctype>
using namespace std;
bool isOperators(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int getprecedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}
	string infixToPostfix(const string & infix) {
    stack<char>dataoperator;
    string postfix;
    for (size_t i=0;i<infix.length();++i) 
	{
        char mineChar = infix[i];
        if (isalnum(mineChar)) 
		{
            postfix += mineChar;
        } 
		else if (mineChar == '(') 
		{
            dataoperator.push(mineChar);
        } 
		else if (mineChar == ')')
		 {
            while (!dataoperator.empty() && dataoperator.top() != '(') 
			{
                postfix += dataoperator.top();
                dataoperator.pop();
            }
            if (!dataoperator.empty() && dataoperator.top() == '(') 
			{
                dataoperator.pop();
            }
        } 
		else if (isOperators(mineChar)) 
		{
            while (!dataoperator.empty() && getprecedence(dataoperator.top()) >= getprecedence(mineChar)) 
			{
                postfix += dataoperator.top();
                dataoperator.pop();
            }
            dataoperator.push(mineChar);
        }
    }
    while (!dataoperator.empty())
	 {
        postfix += dataoperator.top();
        dataoperator.pop();
    }
    return postfix;
}
int main() 
{
	string infixExpression;
    cout<<"Enter the infix expression: ";
	cin>>infixExpression;
    string postfixExpression=infixToPostfix(infixExpression);
    cout<<"Postfix expression: "<<postfixExpression<<endl;
    return 0;
}



