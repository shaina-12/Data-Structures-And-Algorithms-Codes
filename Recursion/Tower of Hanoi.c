//Tower of Hanoi
#include <stdio.h>
int TowerofHanoi(int n);
void TOH(int n,char s,char a,char d);
int main()
{
    int n;
    printf("enter the no of disc to be moved");
    scanf("%d",&n);
    char s='a';
    char a='b';
    char d='c';
    int moves=TowerofHanoi(n);
    TOH(n,s,d,a);
    printf("\n the no of moves is %d",moves);
    return 0;
}
int TowerofHanoi(int n)
{
    if(n==1)
    {
        return 1;
    }
    int c=2*TowerofHanoi(n-1)+1;
    return c;
}
void TOH(int n,char s,char a,char d)
{
    if(n==0)
    {
        return;
    }
    if(n==1)
    {
        printf("\n %c %c",s,d);
        return;
    }
    TOH(n-1,s,d,a);
    printf("\n %c %c",s,d);
    TOH(n-1,a,s,d);
}

