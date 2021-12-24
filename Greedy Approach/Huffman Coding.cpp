#include<iostream>
#include<queue>
using namespace std;
//Huffman Tree Node
struct Node{
    //input data
    char data;
    //frequrncy
    unsigned freq;
    Node *left, *right;
    Node(char data, unsigned freq){
        left = right = NULL;
        this->data = data;
        this-> freq = freq;
    }
};
//used for comparison
struct cmp{
    bool operator()(Node *l, Node *r){
        return (l->freq > r->freq);
    }
};
//used for printing the codes
void printCodes(struct Node *root, string str){
    if(!root){
        return;
    }
    if(root->data != '$'){
        cout<<root->data<<": "<<str<<endl;
    }
    printCodes(root->left,str+"0");
    printCodes(root->right,str+"1");
}
//used for building the Huffman tree and print codes by traversing the built Huffman tree
void huffmanCodes(char data[], int freq[], int size){
    struct Node *left, *right, *top;
    //create a min heap and insert all the characters of data[] along with their frequency
    priority_queue <Node*,vector<Node*>,cmp> heap;
    for(int i=0;i<size;i++){
        heap.push(new Node(data[i],freq[i]));
    }
    //iterate when size of the heap does mot become 1
    while(heap.size()>1){
        //extracting two frequency items from min heap
        left = heap.top();
        heap.pop();
        right = heap.top();
        heap.pop();
        //create an internal node with freqency equal to the sum of frequency of two node frequencies.
        top = new Node('$',left->freq+right->freq);
        //make the two extracted node as left and right children of this new node.
        //add this node to the min heap '$' is a special value for the internal nodes, not used
        top->left = left;
        top->right = right;
        heap.push(top);
    }
    //print the huffman codes using the huffman tree built above
    printCodes(heap.top(),"");
}
int main(){
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = { 5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    huffmanCodes(arr,freq,size);
}
