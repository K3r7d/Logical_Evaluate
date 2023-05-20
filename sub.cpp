#include"header.h"


//--------------------------------------------------------//
// Arithmetic
//--------------------------------------------------------//
string Arithmetic_InfixToPostfix(string infix) {
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
        } else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '%') {
            while (!s.empty() && (s.top() == '*' || s.top() == '/' || s.top() == '%')) {
                postfix << s.top();
                postfix << ' ';
                s.pop();
            }
            s.push(infix[i]);
        } else if (infix[i] == '^') {  // Handle exponentiation operator
            while (!s.empty() && s.top() == '^') {
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
    for(size_t i = 0;i<postfix.size();i++){
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

double performOperation(double op1, double op2, char op) 
{
    switch (op) 
    {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/':
            if (op2 == 0)
                throw runtime_error("Divided-by-0");
            return op1 / op2;
        case '^':
            if (op1 == 0 && op2 == 0)
                throw runtime_error("Undefined");
            return pow(op1, op2);
    }
    return -1;
}

double evaluatePostfix(const string & postfix) 
{
    stack <double> operands;
    stringstream   ss(postfix);
    string         token;

    while (ss >> token) 
    {
        if (isOperator(token[0])&&(!token[1]&&!isdigit(token[1]))) 
        {
            double op2 = operands.top(); operands.pop();
            double op1 = operands.top(); operands.pop();
            double result = performOperation(op1, op2, token[0]);
            operands.push(result);
        } 
        else operands.push(stod(token));
    }
    return operands.top();
}

double evaluatePrefix(const string & prefix) 
{
    stack <double> operands;
    stringstream   ss(prefix);

    istream_iterator <string> begin(ss), end;
    vector           <string> tokens(begin, end);

    for (auto it = tokens.rbegin(); it != tokens.rend(); ++it) 
    {
        if (isOperator((*it)[0]) && !(*it)[1]) 
        {
            double op1 = operands.top(); operands.pop();
            double op2 = operands.top(); operands.pop();
            double result = performOperation(op1, op2, (*it)[0]);
            operands.push(result);
        }
        else operands.push(stod(*it));
    }
    return operands.top();
}


bool isPrefixExpression(const string & expression) {
    for (size_t i = 0; i < expression.size(); i++) 
    {
        if (isspace(expression[i])) 
            continue;
        if (isOperator(expression[i]) && isspace(expression[i+1]))
            return true;
        if (isdigit(expression[i]))
            return false;
    }
    return false;
}

string PostfixPrefixCalculator(string expression) 
{
    double result = isPrefixExpression(expression) ? 
                    evaluatePrefix(expression) : evaluatePostfix(expression);
    stringstream ss;
    ss << fixed << setprecision(4) << result;
    string FinalResult = ss.str();

    for (size_t i = FinalResult.size()-1;i>=0;i--)
    {
        if (FinalResult[i]!='0' && FinalResult[i]!='.')
            break;
        if (FinalResult[i]=='.')
        {
            FinalResult.pop_back();
            break;
        }
        FinalResult.pop_back();
    }
    return FinalResult;
}


//--------------------------------------------------------//
// Logic
//--------------------------------------------------------//
bool isOperator(char c) {
    return (c == '&' || c == '|' || c == '-' || c == '<');
}

int getPrecedence(char c) {
    if (c == '&') return 3;
    if (c == '|') return 2;
    if (c == '-') return 1;
    if (c == '<') return 0;
    return -1;
}

std::string Infix2PostFix(const std::string& infix) {
    std::stack<char> s;
    std::string postfix;
    
    for (size_t i = 0; i < infix.size(); i++) {
        if (infix[i] == ' ') {
            continue;
        }
        
        if (isOperator(infix[i])) {
            while (!s.empty() && s.top() != '(' && getPrecedence(s.top()) >= getPrecedence(infix[i])) {
                postfix += s.top();
                s.pop();
            }
            
            s.push(infix[i]);
        }
        else if (infix[i] == '(') {
            s.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            
            if (!s.empty()) {
                s.pop(); // Discard the opening parenthesis
            }
        }
        else {
            postfix += infix[i];
        }
    }
    
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

std::string Infix2PreFix(const string & infix){
    string prefix;
    stack<char> s;
    for (int i = infix.size()-1; i >=0; i--) {
        if (infix[i] == ' ') {
            continue;
        }
        
        if (isOperator(infix[i])) {
            while (!s.empty() && s.top() != ')' && getPrecedence(s.top()) > getPrecedence(infix[i])) {
                prefix += s.top();
                s.pop();
            }
            
            s.push(infix[i]);
        }
        else if (infix[i] == ')') {
            s.push(infix[i]);
        }
        else if (infix[i] == '(') {
            while (!s.empty() && s.top() != ')') {
                prefix += s.top();
                s.pop();
            }
            
            if (!s.empty()) {
                s.pop(); // Discard the opening parenthesis
            }
        }
        else {
            prefix += infix[i];
        }
    }
    
    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }
    reverse(prefix.begin(),prefix.end());
    return prefix;
}

bool performOperationforpre(bool op1, bool op2, char op) {
    switch (op) {
        case '&': return (op2 && op1);
        case '|': return (op2 || op1);
        case '-': return (!op2 || op1);
        case '<': return ((!op2 || op1) && (!op1 || op2));
    }
    return -1;
}
bool performOperationforpost(bool op1, bool op2, char op) {
    switch (op) {
        case '&': return (op1 && op2);
        case '|': return (op1 || op2);
        case '-': return (!op1 || op2);
        case '<': return ((!op1 || op2) && (!op2 || op1));
    }
    return -1;
}

bool Logic_evaluatePostfix(const string& postfix) {
    stack<bool> operands;
    
    for (size_t i = 0; i < postfix.size(); ++i) {
        bool value;
        if (postfix[i]=='1')value=true;
        if (postfix[i]=='0')value=false;
        if (postfix[i]=='~'){operands.top()=!operands.top();continue;}
        if (isOperator(postfix[i])) {
            bool op2 = operands.top(); operands.pop();
            bool op1 = operands.top(); operands.pop();
            bool result = performOperationforpost(op1, op2, postfix[i]);
            if (postfix[i]=='-')i++;
            if (postfix[i]== '<')i+=2;
            operands.push(result);
        } else {
            operands.push(value);
        }
    }

    return operands.top();
}

bool Logic_evaluatePrefix(const string& prefix) {
    stack<bool> operands;
    
    for (int i = prefix.size()-1; i >=0 ; i--) {
        bool value;
        if (prefix[i]=='1')value=true;
        if (prefix[i]=='0')value=false;
        if (prefix[i]=='~'){operands.top()=!operands.top();continue;}
        if (isOperator(prefix[i])) {
            if (prefix[i]=='-')
            if (prefix[i-1])
            if (prefix[i-1]=='<')
            i--;
            bool op2 = operands.top(); operands.pop();
            bool op1 = operands.top(); operands.pop();
            bool result = performOperationforpre(op1, op2, prefix[i]);
            operands.push(result);
        } else if (prefix[i]!='>') {
            operands.push(value);
        }
    }

    return operands.top();
}

bool Logic_isPrefixExpression(const string& expression) {
    if (expression[0]=='~')
        return true;
    return isOperator(expression[0]);
}
string assignValue(string input, string value){
    string s="";
    int midpoint=value.size()/2+1;
    for (size_t i=0;i<input.size();++i){
        if (isalpha(input[i])){
            for (size_t j=0;j<value.size();++j){
                if (input[i]==value[j]){
                    s+=value[midpoint+j];
                    break;
                    }
            }
        }else{
            s+=input[i];
        }
    }
    return s;
}
string LogicPostfixPrefixCalculator(string input, string value) {
bool isPrefix = Logic_isPrefixExpression(input);
    bool result = isPrefix ? Logic_evaluatePrefix(assignValue(input,value)) : Logic_evaluatePostfix(assignValue(input,value));
    
    if (result)
        return "TRUE";
    return "FALSE";
}






