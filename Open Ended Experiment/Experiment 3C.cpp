/* Given two sequences, a subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example,  
“abc”, “abg”, “bdf”, “aeg”, „”acefg”, .. etc are subsequences of “abcdefg”. So a string of length n has 2^n different possible subsequences. 
It is a classic computer science problem, the basis of file comparison programs and has applications in bioinformatics. 
Develop a program to implement the solution of Longest Common Sub-sequence problem. */
//Solution
//To implement Least Common Subsequence Problem using Dynamic Programming
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class LCS{
    string seq1;
    string seq2;
    //int len_seq1;
    //int len_seq2;
public:
    LCS(string s1, string s2){
       seq1 = s1;
       seq2 = s2;
       //this.len_seq1 = seq1.length();
       //this.len_seq2 = seq2.length();
    }
    void PrintLCS(){
        cout<<seq1<<" "<<seq2<<endl;
        int m = seq1.size();
        int n = seq2.size();
        int **ans = new int*[m+1];
        for(int i=0;i<=m;i++){
            ans[i] = new int[n+1];
        }
        for(int j=0;j<=n;j++){
            ans[0][j]=0;
        }
        for(int i=1;i<=m;i++){
            ans[i][0]=0;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(seq1[i-1] == seq2[j-1]){
                    ans[i][j] = ans[i-1][j-1] + 1;
                }
                else{
                    //ans[i][j] = max(ans[i-1][j],max(ans[i][j-1],ans[i-1][j-1]));
                    ans[i][j] = max(ans[i-1][j],ans[i][j-1]);                }
            }
        }
        int index = ans[m][n];
        cout<<"The lenght of LCS is: "<<index<<endl;
        //char *res_seq = new char [index+1];
        //res_seq[index] = '\0';
        string res_seq = "";
        int i=m, j=n;
        while(i>0 && j>0){
            if(seq1[i-1]==seq2[j-1]){
                res_seq +=  seq1[i-1];
                i--;
                j--;
                index--;
            }
            else if(ans[i-1][j] > ans[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        reverse(res_seq.begin(),res_seq.end());
        cout << "LCS of " << seq1 << " and " << seq2 << " is " << res_seq;
        for(int i=0;i<=m;i++){
            delete [] ans[i];
        }
        delete [] ans;
        //delete res_seq;
    }
};
int main(){
    string seq1, seq2;
    cout<<"Enter the sequence 1: "<<endl;
    cin>>seq1;
    cout<<"Enter the sequence 2: "<<endl;
    cin>>seq2;
    LCS l = LCS(seq1,seq2);
    l.PrintLCS();
    /*
    int len_seq1, len_seq2;
    len_seq1 = seq1.length()
    len_sqe2 = seq2.length()
    int **a = new int*/
}

