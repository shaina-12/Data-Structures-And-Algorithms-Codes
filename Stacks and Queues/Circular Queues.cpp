# include <iostream>
using namespace std;
class CircularQueues{
    int front, rear;
    int size;
    int maxCapacity;
    int *arr;
    public:
    CircularQueues(int maxCapacity){
        this->front = 0;
        this->rear = -1;
        this->size = 0;
        this->maxCapacity = maxCapacity;
    } 
    int length(){
        return size;
    }
    void enqueue(int element){
        if(front==rear+1 && (front==0 && rear==maxCapacity-1)){
            cout<<"Overflow!!!!"<<endl;
            return;
        }
        rear = (rear+1)%maxCapacity;
        arr[rear] = element;
        size++;
    }
    void dequeue(){
        if(front == (rear+1)%maxCapacity){
            cout<<"Underflow!!!"<<endl;
            return;
        }
        int temp = arr[front];
        cout<<"The item "<<temp<<" is deleted from the queue."<<endl;
        front = (front+1)%maxCapacity;
        size--;
    }
    int peek(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }
    void traverse(){
        if(isEmpty()){
            cout<<"Impossible to traverse the circular queue."<<endl;
            return;
        }
        cout<<"The elements present in the circular queue are: ";
        if(front<=rear){
            for(int i=front;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else{
            for(int i=front;i<maxCapacity;i++){
                cout<<arr[i]<<" ";
            }
            for(int i=0;i<=rear;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    }
    bool isEmpty(){
        if(length()!=0){
            return false;
        }
        return true;
    }
};
int main(){
    CircularQueues q(5);
    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(6);
    //cout<<q.length()<<endl;
    q.traverse();
    q.dequeue();
    q.dequeue(); 
    //cout<<q.length()<<endl;
    q.traverse();
    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);
    //cout<<q.length()<<endl;
    q.traverse();
}