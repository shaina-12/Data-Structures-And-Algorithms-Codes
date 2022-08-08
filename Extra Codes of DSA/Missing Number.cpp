#include <algorithm>
#include <cmath>
int binToInt(string str){
    int len = str.length();
    int num = 0;
    for(int i = len - 1; i >= 0; i--) 
    {
        if(str[i]=='1') 
        {
            num += (1 << (len - i - 1));
        }
    }
    return num;
}
string intToBinary(int ans){
    if(ans == 0) 
    {
        return "0";
    }
    string res = "";
    int a = ans;
    while(a>0){
        string b = (a&1)?"1":"0";
        res += b;
        a=a/2;
    }
    reverse(res.begin(),res.end());
    return res;
}
string findMissingNumber(vector<string> &binaryNums, int n) 
{
    // Write your code here.
    vector<int> v;
    for(int i=0;i<n;i++){
        v.push_back(binToInt(binaryNums[i]));
    }
    sort(v.begin(),v.end());
    int ans = n;
    for(int i = 0; i < n; i++) 
    {
        if(v[i] != i) 
        {
           ans = i;
            break;
        }
    }
    string finalAns = intToBinary(ans);
    return finalAns;
}
