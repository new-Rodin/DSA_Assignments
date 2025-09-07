#include <bits/stdc++.h>
using namespace std;
bool isOp (char s )
{
    return (s=='+' || s=='-' || s=='*' || s=='/' ) ;
}
int precedence (char s)
{
    if (s=='*' || s=='/') return 2 ;
    else if (s=='+' || s=='-') return 1;
    else return 0 ;
}

string Post(string infix)
{
    stack <char> s ;
    string postfix = "" ;
    for (int i = 0 ; i < infix.length() ; i++)
    {
        if(infix[i]==' ')continue ;
        else if (infix[i]=='(') s.push(infix[i]) ;
        else if (infix[i]==')') 
        {
            while(!s.empty() && s.top()!='(')
            {
                postfix += s.top() ;
                s.pop() ;
            }
            s.pop() ;
        }
        else if (isOp(infix[i]))
        {
            while(!s.empty() && precedence(s.top())>=precedence(infix[i]))
            {
                postfix += s.top() ;
                s.pop() ;
            }
            s.push(infix[i]) ;
        }
        else postfix += infix[i] ;
    }   
    while(!s.empty())
    {
        postfix += s.top() ;
        s.pop() ;
    }
    return postfix ; 

}
struct nodetype{
    int info ;
    struct nodetype *left,*right ;
};
typedef struct nodetype *ptr;
ptr root = NULL ;
ptr BuildTree(string postfix)
{
    stack <ptr> s ;
    for (int i = 0 ; i < postfix.length() ; i++)
    {
        if (isOp(postfix[i]))
        {
            ptr newNode = new nodetype{postfix[i], NULL, NULL} ;
            newNode->right = s.top() ; s.pop() ;
            newNode->left = s.top() ; s.pop() ;
            s.push(newNode) ;
        }
        else 
        {
            ptr newNode = new nodetype{postfix[i], NULL, NULL} ;
            s.push(newNode) ;
        }
    }
    root = s.top() ; s.pop() ;
    return root ;
}
int evaluate(ptr root)
{
    if (root==NULL) return 0 ;
    if (!isOp(root->info)) return root->info - '0' ;
    int leftVal = evaluate(root->left) ;
    int rightVal = evaluate(root->right) ;
    if (root->info=='+') return leftVal + rightVal ;
    else if (root->info=='-') return leftVal - rightVal ;
    else if (root->info=='*') return leftVal * rightVal ;
    else if (root->info=='/') return leftVal / rightVal ;
    
    return 0 ;
}
int main()
{
    string expr;
    cout << "Enter expression (single-digit, + - * /, parentheses allowed): ";
    getline(cin, expr);

    string postfix = Post(expr);
    cout << "Postfix: " << postfix << "\n";

    ptr root = BuildTree(postfix);
    cout << "Result: " << evaluate(root) << "\n";

    return 0;


}