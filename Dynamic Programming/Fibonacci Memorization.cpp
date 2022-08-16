#include <iostream>
#include <map>
using namespace std;
int fibonacci(int n, map<int,int> m){
    if(m.find(n)!=m.end()){
        return m[n];
    }
    if(n<=2){
        return 1;
    }
    m[n] = fibonacci(n-1,m) + fibonacci(n-2,m);
    return m[n];
}
int main(){
    map<int,int> m;
    cout<<fibonacci(6,m)<<endl;
    m.clear();
    cout<<fibonacci(7,m)<<endl;
    m.clear();
    cout<<fibonacci(8,m)<<endl;
    m.clear();
    cout<<fibonacci(50,m)<<endl;
    m.clear();
    return 0;
}