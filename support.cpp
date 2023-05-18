#include "header.h"
bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}
 int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string Arithmetic_InfixToPostfix(string infix){
    std::stack<char> s;
    std::stringstream postfix;

    for (size_t i = 0; i < infix.size(); i++) {
        if (infix[i] == ' ') {
            continue;
        } else if (std::isdigit(infix[i])) {
            // If the character is a digit, it may be part of a multi-character number
            while (i < infix.size() && std::isdigit(infix[i])) {
                postfix << infix[i];
                i++;
            }
            i--; // Move back one character to account for the increment in the loop
            postfix << ' ';
        } else if (infix[i] == '(') {
            s.push(infix[i]);
        } else if (infix[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix << s.top();
                postfix << ' ';
                s.pop();
            }
            s.pop();
        } else if (infix[i] == '+' || infix[i] == '-') {
            while (!s.empty() && s.top() != '(') {
                postfix << s.top();
                postfix << ' ';
                s.pop();
            }
            s.push(infix[i]);
        } else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '%'|| infix[i] == '^') {
            while (!s.empty() && (s.top() == '*' || s.top() == '/' || s.top() == '%'|| s.top() == '^')) {
                postfix << s.top();
                postfix << ' ';
                s.pop();
            }
            s.push(infix[i]);
        }
    }

    while (!s.empty()) {
        postfix << s.top();
        postfix << ' ';
        s.pop();
    }

    std::string result = postfix.str();
    result = result.substr(0, result.size() - 1);
    return result;
}

string Arithmetic_InfixToPrefix(string infix)
{
    // Reverse String and replace ( with ) and vice versa
    // Get Postfix
    // Reverse Postfix
    int l = infix.size();
 
    // Reverse infix
    reverse(infix.begin(), infix.end());
 
    // Replace ( with ) and vice versa
    for (int i = 0; i < l; i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
 
    string prefix = Arithmetic_InfixToPostfix(infix);
 
    reverse(prefix.begin(), prefix.end());
 
    return prefix;
}
string PostfixtoInfix(string postfix){
    stack<string> s;
    string temp;
    for(int i = 0;i<postfix.length();i++){
        if(postfix[i] == ' '){
            continue;
        }else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%'){
            string temp1 = s.top();
            s.pop();
            string temp2 = s.top();
            s.pop();
            temp = '(' + temp2 + postfix[i] + temp1 + ')';
            s.push(temp);
        }else{
            temp = postfix[i];
            s.push(temp);
        }
    }
    return s.top();
}

string PrefixtoInfix(string prefix){
    stack<string> s;
    string temp;
    for(int i = prefix.length() - 1;i>=0;i--){
        if(prefix[i] == ' '){
            continue;
        }else if(prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '%'){
            string temp1 = s.top();
            s.pop();
            string temp2 = s.top();
            s.pop();
            temp = '(' + temp1 + prefix[i] + temp2 + ')';
            s.push(temp);
        }else{
            temp = prefix[i];
            s.push(temp);
        }
    }
    return s.top();
}

string Logical_InfixToPostfix(string infix){
    stack<char> s;
    string postfix;
    for(int i = 0;i<infix.length();i++){
        if(infix[i] == ' '){
            continue;
        }else if(infix[i] == '('){
            s.push(infix[i]);
        }else if(infix[i] == ')'){
            while(s.top() != '('){
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.pop();
        }else if(infix[i] == '&' || infix[i] == '|'){
            while(!s.empty() && s.top() != '('){
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(infix[i]);
        }else if(infix[i] == '!'){
            while(!s.empty() && s.top() != '('){
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(infix[i]);
        }else{
            postfix += infix[i];
            postfix += ' ';
        }
    }
    while(!s.empty()){
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }
    postfix = postfix.substr(0,postfix.size() - 1);
    return postfix;
}

string Logical_InfixToPrefix(string infix){
    stack<char> s;
    string prefix;
    for(int i = infix.length() - 1;i>=0;i--){
        if(infix[i] == ' '){
            continue;
        }else if(infix[i] == ')'){
            s.push(infix[i]);
        }else if(infix[i] == '('){
            while(s.top() != ')'){
                prefix += s.top();
                prefix += ' ';
                s.pop();
            }
        }else if(infix[i] == '&' || infix[i] == '|'){
            while(!s.empty() && s.top() != ')'){
                prefix += s.top();
                prefix += ' ';
                s.pop();
            }
            s.push(infix[i]);
        }else if(infix[i] == '!'){
            while(!s.empty() && s.top() != ')'){
                prefix += s.top();
                prefix += ' ';
                s.pop();
            }
            s.push(infix[i]);
        }else{
            prefix += infix[i];
            prefix += ' ';
        }
    }
    while(!s.empty()){
        prefix += s.top();
        prefix += ' ';
        s.pop();
    }
    prefix = prefix.substr(0,prefix.size() - 1);
    string temp;
    for(int i = prefix.length() - 1;i>=0;i--){
        if(prefix[i] == ')'||prefix[i] == '('){
            continue;
        }
        temp += prefix[i];
    }
    return temp;
}

string Arithmetic_PostfixPrefixCalculator(std::string input)
{
    try
    {
        if (input.empty())
            return "Error: Invalid input";

        std::istringstream iss(input);
        std::stack<int> stack;
        std::string token;

        if (input[0] == '+' || input[0] == '-' || input[0] == '*' || input[0] == '/')
        {
            // Prefix expression
            std::vector<std::string> tokens;
            while (iss >> token)
                tokens.push_back(token);

            for (int i = tokens.size() - 1; i >= 0; i--)
            {
                token = tokens[i];
                if (isdigit(token[0]))
                {
                    stack.push(std::stoi(token));
                }
                else
                {
                    int a = stack.top();
                    stack.pop();
                    int b = stack.top();
                    stack.pop();
                    switch (token[0])
                    {
                        case '+':
                            stack.push(a + b);
                            break;
                        case '-':
                            stack.push(a - b);
                            break;
                        case '*':
                            stack.push(a * b);
                            break;
                        case '/':
                            if (b == 0)
                                return "Error: Division by zero";
                            stack.push(a / b);
                            break;
                        default:
                            return "Error: Invalid operator";
                    }
                }
            }
        }
        else
        {
            // Postfix expression
            while (iss >> token)
            {
                if (isdigit(token[0]))
                {
                    stack.push(std::stoi(token));
                }
                else
                {
                    int b = stack.top();
                    stack.pop();
                    int a = stack.top();
                    stack.pop();
                    switch (token[0])
                    {
                        case '+':
                            stack.push(a + b);
                            break;
                        case '-':
                            stack.push(a - b);
                            break;
                        case '*':
                            stack.push(a * b);
                            break;
                        case '/':
                            if (b == 0)
                                return "Error: Division by zero";
                            stack.push(a / b);
                            break;
                        default:
                            return "Error: Invalid operator";
                    }
                }
            }
        }

        return std::to_string(stack.top());
    }
    catch (const std::exception& ex)
    {
        return "Error: " + std::string(ex.what());
    }
}

string Logical_PostfixPrefixCalculator(string input) {
    return"";
}


int main(){
    string infix("(120+212)-(343*432)");
    string infix_logical("!(12&3|4)");
    cout<<"The postfix expression is: "<<Arithmetic_InfixToPostfix(infix)<<endl;
    cout<<"The prefix expression is: "<<Arithmetic_InfixToPrefix(infix)<<endl;
    
    cout<<"The postfix expression is: "<<Logical_InfixToPostfix(infix_logical)<<endl;
    cout<<"The prefix expression is: "<<Logical_InfixToPrefix(infix_logical)<<endl;
    
    cout<<"The infix expression is: "<<PostfixtoInfix(Arithmetic_InfixToPostfix(infix))<<endl;
    cout<<"The infix expression is: "<<PrefixtoInfix(Arithmetic_InfixToPrefix(infix))<<endl;


    cout<<"The arithmetic result is: "<<Arithmetic_PostfixPrefixCalculator("12 34 *")<<endl;
    cout<<"The logical result is:"<<Logical_PostfixPrefixCalculator("1&0")<<endl;


    return 0;
}