#include "sub.cpp"

int main() {
    try{
        string logic("~t->t&~w|(z&(p&(w&(p|p&q)|y&z&z)<->x&(~p|z)&~y))");
        string arithmetic("(133+179)/60*(157*133+(177*19^(10-2*4)))");
        cout<<"Exercise 1: "<<endl;
        cout<<"Postfix: "<<Arithmetic_InfixToPostfix("2^(5-3)*9/3")<<endl;
        cout<<"Prefix:"<<Arithmetic_InfixToPrefix(arithmetic)<<endl;
        cout<<PostfixPrefixCalculator("* / + 133 179 60 + * 157 133 * 177 ^ 19 - 10 * 2 4")<<endl;

        cout<<"Exercise 2: "<<endl;
        cout<<"Postfix: "<<LogicInfix2Postfix(logic)<<endl;
        // cout<<"Prefix: "<<LogicInfix2PreFix(logic)<<endl;
        // cout<<LogicPostfixPrefixCalculator("")<<endl;
    }
    catch(const runtime_error& e){
        cout<<"Error"<<e.what()<<endl;
    }
    
    return 0;
}
