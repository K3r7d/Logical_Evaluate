#include "sub.cpp"

int main() {
    try{
        string logic("a&b");
        string arithmetic("(133+179)/60*(157*133+(177*19^(10-2*4)))");
        cout<<"Exercise 1: "<<endl;
        cout<<"Postfix: "<<Arithmetic_InfixToPostfix(arithmetic)<<endl;
        cout<<"Prefix:"<<Arithmetic_InfixToPrefix(arithmetic)<<endl;
        // cout<<PostfixPrefixCalculator("* / + 133 179 60 + * 157 133 * 177 ^ 19 - 10 * 2 4")<<endl;

        cout<<"Exercise 2: "<<endl;
        cout<<"Postfix: "<<Infix2PostFix(logic)<<endl;
        cout<<"Prefix: "<<Infix2PreFix(logic)<<endl;
        cout<<LogicPostfixPrefixCalculator("a&b")<<endl;
    }
    catch(const runtime_error& e){
        cout<<"Error"<<e.what()<<endl;
    }
    
    return 0;
}
