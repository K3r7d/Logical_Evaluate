#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<math.h>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#include<cstdlib>

using namespace std;

string Arithmetic_InfixToPostfix(string infix);
string Arithmetic_InfixToPrefix(string infix);
string Arithmetic_PostfixPrefixCalculator(string input);
string Logical_InfixToPostfix(string infix);
string Logical_InfixToPrefix(string infix);
string Logical_PostfixPrefixCalculator(string input);
string PostfixtoInfix(string postfix);
int precedence(char op);