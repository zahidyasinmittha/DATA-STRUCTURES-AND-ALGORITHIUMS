#include <iostream>
#include <stack>
using namespace std;
//function for checking precedence of operator
int precedent(char a){
    if(a=='^'){
    return 3;
    }
    else if(a=='*' || a=='/'){
    return 2;
    }
    else if(a=='+' || a=='-'){
    return 1;
    }
    else{
    return -1;
    }
}
//main function which get the infix as argument 
void inf_to_pre(string input){
//declearing stack for storing operator
    stack <char> s;
//declearing string to store output
    string output;
//using loop to get each character of string 
    for(int i=0;i<input.length();i++){
//checking for alphabets
        if(isalpha(input[i])){
            output+=input[i];
        }
//checking for opening bracket and storing it in stack
        else if(input[i]=='('){
            s.push(input[i]);
        }
//checking for closing bracket
        else if(input[i]==')'){
//using while loop to pop out each operator from stack and storing it in our result
            while(s.top()!='('){
                output+=s.top();
                s.pop();
            }
//removing the opening bracket from stack
            s.pop();
        }
        else{
//checking precedent of top operator of stack to opertor which is stored in string and removing it from stack
            while( !s.empty() && precedent(input[i])<=precedent(s.top())){
                output+=s.top();
                s.pop();
            }
            s.push(input[i]);
        }
    }
//concatinating remaing operator in output string
    while (!s.empty()) {
        output+= s.top();
        s.pop();
    }
string output1;
//reversing the string like abc to cba
for(int i=(output.length()-1);i>=0;i--){
 output1+=output[i];
}
//printing our final output
    cout << output1<< endl;
}
int main(){
string exp;
cout<<"enter the string:";
cin>>exp;
string exp1;
//reversing the string like abc to cba
for(int i=(exp.length()-1);i>=0;i--){
  if(exp[i]=='(')
     exp1+=')';
  else if(exp[i]==')') 
     exp1+='(';
  else{
     exp1+=exp[i];
    }}
    // Function call
    inf_to_pre(exp1);
    return 0;
}