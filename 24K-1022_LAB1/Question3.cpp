#include <iostream>
using namespace std;
class Exam{
    private:
    int* marks;
    int count;
    public:
    Exam(){
        marks=nullptr;
        count=0;
    }
    Exam(int* m,int c){
        count=c;
        marks=new int[count];
        for(int i=0;i<count;i++){
            marks[i]=m[i];
        }
    }
    ~Exam(){
        delete[] marks;
        count=0;
    }
    void setMarks(int index,int v){
        if(index>=0 && index<count){
            marks[index]=v;
        }
    }
    void displayMarks(){
        for(int i=0;i<count;i++){
           cout<<marks[i]<<endl;
        }
    }
};
int main(){
    int m1[3]={23,79,80};
    Exam e1(m1,3);
    Exam e2=e1;
    cout<<"Shallow of Copy Done!..."<<endl;
    cout<<"Display object1's Marks Before Changes:"<<endl;
    e1.displayMarks();
    cout<<"Display of object1's Marks Before Changes:"<<endl;
    e2.displayMarks();
    e1.setMarks(1,30);

    cout<<"Display of object1's Marks After Changes:"<<endl;
    e1.displayMarks();
    cout<<"Display of object1's Marks After Changes:"<<endl;
    e2.displayMarks();
}
