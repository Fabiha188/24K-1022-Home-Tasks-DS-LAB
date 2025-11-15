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
            cout<<endl;
        }
    }

};
int main(){
    MinHeap m;
    m.insert(1);
    m.insert(3);
    m.insert(4);
    m.insert(5);

    cout<<"Initial Heap: \n";
    m.display();

    m.insert(2);
    cout<<"Heap after Inserting 2: \n";
    m.display();


}
