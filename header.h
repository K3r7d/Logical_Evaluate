#include<string>
#include<sstream>
#include<vector>
#include<iterator>
#include<cmath>
#include<iomanip>
#include<stack>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib>  
using namespace std;

bool isOperator(char);
bool performOperationforpre(bool,bool,bool);
bool performOperationforpost(bool op1, bool op2, char op);
double evaluatePostfix(const string& postfix);
double evaluatePrefix(const string& prefix);
bool isPrefixExpression(const string& expression);