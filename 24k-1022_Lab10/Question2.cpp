#include <iostream>
using namespace std;
void swap(int& a,int& b){
    int temp = a;
    a = b;
    b = temp;
}
class MaxHeap{
    int arr[50];
    int size;
    public:
    MaxHeap(){
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
            while(i!=0 && arr[i]>arr[parent(i)]){
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
    void maxHeapify(int i){
        int largest=i;
        int left=leftChild(i);
        int right=rightChild(i);

        if(left<size && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<size && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[i],arr[largest]);
            maxHeapify(largest);
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

        maxHeapify(0);
    }

};
int main(){
    MaxHeap m;
    m.insert(2);
    m.insert(13);
    m.insert(4);
    m.insert(5);

    cout<<"Initial Heap: \n";
    m.display();

    m.insert(10);
    cout<<"Heap after Inserting 10: \n";
    m.display();

    m.remove();
    cout<<"Heap after severity is treated: \n";
    m.display();


}
