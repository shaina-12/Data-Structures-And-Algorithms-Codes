//implementation of max priority queue
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
class PriorityQueue{
    vector <int> pq;
public:
    //to get the size of max priority queue
    int getSize(){
        return pq.size();
    }
    //to check whether the max priority queue is empty or not
    bool isEmpty(){
        return pq.empty();
    }
    //to get the maximum element in the max priority queue
    int getMax(){
        if(isEmpty()){
            return INT_MIN;
        }
        return pq[0];
    }

    //to insert the element in the max priority queue
    void insert(int element){
        pq.push_back(element);
        int child = pq.size()-1;
        while(child>0){
            int parent = (child-1)/2;
            if(pq[parent]<pq[child]){
                swap(pq[parent],pq[child]);
            }
            else{
                break;
            }
            child = parent;
        }
    }
    //to delete the element in the max priority queue
    int removeMax(){
        if(isEmpty()){
            return INT_MIN;
        }
        int li = pq.size()-1;
        int ans = pq[0];
        pq[0] = pq[li];
        pq.pop_back();
        int pi = 0;
        int ci1 = 2*pi+1;
        int ci2 = 2*pi+2;
        while(ci1<li+1){
            int mi = pi;
            if(pq[mi] < pq[ci1]){
                mi = ci1;
            }
            if(ci2 < li+1 && pq[mi] < pq[ci2]){
                mi = ci2;
            }
            if(pi == mi){
                break;
            }
            int temp = pq[mi];
            pq[mi] = pq[pi];
            pq[pi] = temp;
            pi = mi;
            ci1 = 2*pi+1;
            ci2 = 2*pi+2;
        }
        return ans;
    }
};
int main(){
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMax
                cout << pq.getMax() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.removeMax() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }

        cin >> choice;
    }
}
