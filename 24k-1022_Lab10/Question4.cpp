#include <iostream>
using namespace std;
void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}
class MinHeap{
    int arr[50];
    int size;
    public:
    MinHeap(){
        size=0;
    }
    int parent(int i){
        return (i-1)/2;
    }
    void insert(int p){
        if(size>=50){
            cout<<"Heap Overflow";
            return;
        }
    
        else{
            arr[size]=p;
            size++;

            int i=size-1;
            while(i!=0 && arr[i]<arr[parent(i)]){
                swap(arr[i],arr[parent(i)]);
                i=parent(i);
            }
        }
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
            
        }
        cout<<endl;
    }
    int leftChild(int i){
        return 2*i+1;
    }
    int rightChild(int i){
        return 2*i+2;
    }
    void minHeapify(int i){
        int smallest=i;
        int left=leftChild(i);
        int right=rightChild(i);

        if(left<size && arr[smallest]>arr[left]){
            smallest=left;
        }
        if(right<size && arr[smallest]>arr[right]){
            smallest=right;
        }
        if(smallest!=i){
            swap(arr[i],arr[smallest]);
            minHeapify(smallest);
        }
    }
    void remove(){
        if(size<=0){
            cout<<"Heap is Empty\n";
            return;
        }
        if(size==1){
            size--;
            return;
        }
        arr[0]=arr[size-1];
        size--;

        minHeapify(0);
    }

};
int main(){
    MinHeap h;
    h.insert(100);
    h.insert(50);
    h.insert(75);
    h.insert(60);
    cout<<"Heap After Initializing: ";
    h.display();

    h.insert(55);
    cout<<"After New Order 55 Arrived: ";
    h.display();

    h.remove();
    cout<<"After removing highest priority : ";
    h.display();

   
    
}
