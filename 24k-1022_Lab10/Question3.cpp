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
    MaxHeap h;
    h.insert(5);
    h.insert(3);
    h.insert(8);
    cout<<"Heap after inserting A(5), B(3), C(8): ";
    h.display();

    h.remove();
    cout<<"After removing highest priority task: ";
    h.display();

   
    h.insert(6);
    cout<<"Insertion Of D(6): ";
    h.display();


}
