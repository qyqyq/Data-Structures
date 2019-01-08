#include<sstream>
#include<stack>
#include "arithmeticExpression.h"

using namespace std;

void arithmeticExpression::buildTree()
{
    string postfix = infix_to_postfix();
    //cout << postfix << endl;

    stack<TreeNode>T;
    TreeNode tmp;
    TreeNode* lft;
    TreeNode* rgt;

    for(unsigned i = 0; i< postfix.size();i++)
    {
        if(postfix[i] >= 'a' && postfix[i] <= 'z')
        {
            tmp = TreeNode(postfix[i],postfix[i]);
            T.push(tmp);
        }
        else
        {
            tmp = T.top();
            T.pop();
            rgt = new TreeNode(tmp.data, tmp.key, tmp.left, tmp.right);
            tmp = T.top();
            T.pop();
            lft = new TreeNode(tmp.data, tmp.key, tmp.left, tmp.right);
            tmp = TreeNode(postfix[i],postfix[i],lft,rgt);
            //cout << tmp.data << ' ' << tmp.left->data << ' ' << tmp.right->data << endl;
            T.push(tmp);

        }
    }
    tmp = T.top();
    //cout << tmp.data << ' ' << tmp.left->data << ' ' << tmp.right->data << endl;
    root = new TreeNode(tmp.data, tmp.key, tmp.left, tmp.right);
}

void arithmeticExpression::prefix(TreeNode *rt)
{
    cout << rt->data;
    if(rt->left)
        prefix(rt->left);
    if(rt->right)
        prefix(rt->right);
}
void arithmeticExpression::prefix()
{
    if(root)
        prefix(root);
}
void arithmeticExpression::infix(TreeNode *rt)
{
    if(rt->left!=nullptr)
    {
        cout << "(";
        infix(rt->left);
    }

    cout << rt->data;
    if(rt->right!=nullptr)
    {
        infix(rt->right);
        cout << ")";
    }
}
void arithmeticExpression::infix()
{
    if(root == nullptr)
        return;
    infix(root);
}
void arithmeticExpression::postfix(TreeNode *rt)
{
    if(rt->left)
        postfix(rt->left);
    if(rt->right)
        postfix(rt->right);
    cout << rt->data;
}
void arithmeticExpression::postfix()
{
    if(root)
        postfix(root);
}

int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

/*
void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}
*/


