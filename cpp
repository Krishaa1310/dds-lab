#include <iostream>
#include <stack>
#include <string>
#include <cctype>  // For isdigit()

using namespace std;

int priority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (size_t i = 0; i < infix.length(); ++i) {
        char c = infix[i];
        cout << "working on character: " << c << endl;

        if (isdigit(c)) {
            postfix += c;
        } 
        else if (c == '(') {
            st.push(c);
        } 
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                st.pop();
                postfix += top;
            }
            if (!st.empty() && st.top() == '(') {
                st.pop(); // Remove '('
            }
        } 
        else {
            while (!st.empty() && priority(st.top()) >= priority(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop remaining operators
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Final postfix expression: " << postfix << endl;

    return 0;
}
