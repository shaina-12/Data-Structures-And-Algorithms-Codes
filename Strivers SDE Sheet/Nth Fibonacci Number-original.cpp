#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){
        if(n<=2){
                return 1;
        }
        return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;
        int output = fibonacci(n);
        cout<<output<<endl;
}
