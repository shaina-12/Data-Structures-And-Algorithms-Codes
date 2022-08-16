#include <iostream>
using namespace std;
int fibonacci(int n){
    if(n<=2){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
int main(){
    cout<<fibonacci(6)<<endl;
    cout<<fibonacci(7)<<endl;
    cout<<fibonacci(8)<<endl;
    cout<<fibonacci(50)<<endl;
    return 0;
}