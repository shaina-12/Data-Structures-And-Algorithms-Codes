#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define size 50
int stack[size];
int top=-1;
void push(char p)
{
top++;
stack[top]=p;
}
void pop()
{
top--;
}
int peek()
{
return stack[top];
}
bool empty()
{
if(top==-1)
{
return true;
}
else
{
return false;
}
}
bool isBalanced(char expression[])
{
bool b=true;
if(expression[0]==')' || expression[0]==']' || expression[0]=='}')
{
b=false;
return b;
}
else
{
int len=strlen(expression);
for(int i=0;i<len;i++)
{
if(expression[i]=='(' || expression[i]=='[' || expression[i]=='{')
{
push(expression[i]);
}
else if(expression[i]==')')
{
char a=peek();
if(a=='(')
{
pop();
}
else
{
b=false;
return b;
}
}
else if(expression[i]==']')
{
char a=peek();
if(a=='[')
{
pop();
}
else
{
b=false;
return b;
}
}
else if(expression[i]=='}')
{
char a=peek();
if(a=='{')
{
pop();
}
else
{
false;
return b;
}
}
else
{
continue;
}
}
if(empty())
{
b=true;
return b;
}
else
{
b=false;
return b;
}
}
}
int main()
{
char input[40];
printf("Enter the expression (till 40 characters): ");
scanf("%s",&input);
bool b=isBalanced(input);
printf("\nThe expresion is ");
b?printf("balanced."):printf("not balanced");
return 0;
}
