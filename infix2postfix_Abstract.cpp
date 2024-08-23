// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int getPrecedence(char op) {
    if (op == '^') {
        return 3; // Highest precedence for the power operator
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    }
    return 0; // Default precedence for other characters
}

std::string infixToPostfix(const std::string& infix) {
    std::string postfix;
    std::stack<char> operatorStack;

    for (char c : infix) {
        if (isalnum(c)) {

        } else if (c == '(') {

        } else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {

            }

        } else {
            // Operator
            while (!operatorStack.empty() && operatorStack.top() != '(' && getPrecedence(c) <= getPrecedence(operatorStack.top())) {

            }

        }
    }

    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {
    std::string infixExpression;
    std::cout << "Enter an infix expression: ";
    std::cin >> infixExpression;

    std::string postfixExpression = infixToPostfix(infixExpression);

    std::cout << "Postfix expression: " << postfixExpression << std::endl;

    return 0;
}
