class Solution {
public:
    int myAtoi(string s) {
    long long int result = 0;
    int indicator = 1;

    int i = s.find_first_not_of(' ');
        if (i < 0)
        return 0;
    if(s[i] == '-' || s[i] == '+')
        indicator = (s[i++] == '-')? -1 : 1;
        
    while('0'<= s[i] && s[i] <= '9') 
    {
        result = result*10 + (s[i++]-'0');
        if(result*indicator >= INT_MAX) return INT_MAX;
        if(result*indicator <= INT_MIN) return INT_MIN;                
    }
        
    return result*indicator;
    }
};
