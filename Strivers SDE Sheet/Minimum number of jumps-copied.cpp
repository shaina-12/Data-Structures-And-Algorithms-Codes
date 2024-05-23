class Solution{
  public:
    // taken reference from https://discuss.geeksforgeeks.org/comment/b810b1b7-2c04-4177-97b5-f6edf778f9a1/practice
    int minJumps(int arr[], int n){
        // Your code here
        if(n==1){
            return 0;
        }
        if(arr[0]==0){
            return -1;
        }
        int count = 0;
        int After_Jump = 0;
        int current = 0;
        for(int i=0;i<n;i++){
            After_Jump = max(After_Jump, i+arr[i]);
            if(i==current){
                current = After_Jump;
                count++;
                if(After_Jump>=n-1){
                    return count;
                }
            }
        }
        return -1;
    }
};
