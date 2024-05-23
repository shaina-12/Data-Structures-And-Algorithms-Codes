class Solution {
  public:
    int dataTypeSize(string str) {
        // your code here
        int val;
        if(str.compare("Character")==0){
            val=sizeof(char);
        }
        else if(str.compare("Integer")==0){
            val=sizeof(int);
        }
        else if(str.compare("Long")==0){
            val=sizeof(long);
        }
        else if(str.compare("Float")==0){
            val=sizeof(float);
        }
        else{
            val=sizeof(double);
        }
        return val;
    }
};
