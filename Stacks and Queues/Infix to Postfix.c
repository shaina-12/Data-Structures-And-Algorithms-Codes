#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#define size 50
#define size2 50
char stack[size];
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
char peek()
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
int stack2[size2];
int top2=-1;
void push2(int p)
{
top2++;
stack2[top2]=p;
}
void pop2()
{
top2--;
}
int peek2()
{
return stack2[top2];
}
bool empty2()
{
if(top2==-1)
{
return true;
}
else
{
return false;
}
}
void infix2postfix(char input[],char output[])
{
int len=strlen(input);
int k=0;
for(int i=0;i<len;i++)
{
if(input[i]=='(')
{
push(input[i]);
}
else if(input[i]==')')
{
while(!empty() && peek()!='(')
{
output[k]=peek();
pop();
k++;
}
pop();
}
else if(input[i]=='^')
{
char a=peek();
if(empty())
{
push(input[i]);
}
else if(a=='^')
{
output[k]=a;
pop();
k++;
while(!empty())
{
char b=peek();
if(b=='^')
{
output[k]=b;
pop();
k++;
}
else
{
break;
}

}
push(input[i]);
}
else
{
push(input[i]);
}
}
else if(input[i]=='*')
{
char a=peek();
if(empty())
{
push(input[i]);
}
else if(a=='^'||a=='/'||a=='*')
{
output[k]=a;
pop();
k++;
while(!empty())
{
char b=peek();
if(b=='^'||b=='/'||b=='*')
{
output[k]=b;
pop();
k++;
}
else
{
break;
}

}
push(input[i]);
}
else
{
push(input[i]);
}
}
else if(input[i]=='/')
{
char a=peek();
if(empty())
{
push(input[i]);
}
else if(a=='^'||a=='/'||a=='*')
{
output[k]=a;
pop();
k++;
while(!empty())
{
char b=peek();
if(b=='^'||b=='/'||b=='*')
{
output[k]=b;
pop();
k++;
}
else
{
break;
}

}
push(input[i]);
}
else
{
push(input[i]);
}
}
else if(input[i]=='+')
{
char a=peek();
if(empty())
{
push(input[i]);
}
else if(a=='^'||a=='/'||a=='*'||a=='+'||a=='-')
{
output[k]=a;
pop();
k++;
while(!empty())
{
char b=peek();
if(b=='^'||b=='/'||b=='*'||b=='+'||b=='-')
{
output[k]=b;
pop();
k++;
}
else
{
break;
}

}
push(input[i]);
}
else
{
push(input[i]);
}
}
else if(input[i]=='-')
{
char a=peek();
if(empty())
{
push(input[i]);
}
else if(a=='^'||a=='/'||a=='*'||a=='+'||a=='-')
{
output[k]=peek();
pop();
k++;
while(!empty())
{
char b=peek();
if(b=='^'||b=='/'||b=='*'||b=='+'||b=='-')
{
output[k]=b;
pop();
k++;
}
else
{
break;
}

}
push(input[i]);
}
else
{
push(input[i]);
}
}
else
{
output[k]=input[i];
k++;
}
}
while(!empty())
{
output[k]=peek();
pop();
k++;
}
}
int evapostfix(char output[])
{
int ans;
//int len=strlen(output);
//puts(output);
for(int i=0;output[i]!='\0';i++)
{
if(isdigit(output[i]))
{
push2(output[i]-48);
}
else
{
int a=peek2();
//printf("%d ",a);
pop2();
int b=peek2();
//printf("%d ",b);
pop2();
int c;
if(output[i]=='+')
{
c=b+a;
}
else if(output[i]=='-')
{
c=b-a;
}
else if(output[i]=='*')
{
c=b*a;
}
else if(output[i]=='/')
{
c=b/a;
}
else
{
c=pow(b,a);
}
push2(c);
}
}
ans=peek2();
pop2();
return ans;
}
int main()
{
char input[40],output[40];
printf("Enter the infix expression (till 40 characters): ");
scanf("%s",&input);
infix2postfix(input,output);
printf("\nThe postfix expression is: ");
for(int i=0;output[i]!='\0';i++)
{
printf("%c",output[i]);
}
int a=evapostfix(output);
printf("\nThe evaluated postfix expression is: %d",a);
return 0;
}
