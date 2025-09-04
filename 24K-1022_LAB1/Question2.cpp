#include <iostream>
using namespace std;
class Box{
    private:
    int* volume;
    public:
    Box(){
        volume=new int(0);
    }
    Box(int v){
    volume=new int(v);
    }
    Box(const Box& b){
        volume=new int(*(b.volume));
    }
    ~Box(){
        delete volume;
    }
    void SetVolume(int v){
        *volume=v;
    }
    int getVolume()const{
        return *volume;
    }
    void display()const{
        cout<<*volume<<endl;
    }
};
int main(){
    Box b1;
    cout<<"Box1 (Default Constructor): "<<endl<<"Box Volume: ";
    b1.display();
    cout<<endl;
    Box b2(40);
    cout<<"Box2 (Parametrize Constructor): "<<endl<<"Box Volume: ";
    b2.display();
    cout<<endl;
    Box b3=b2;
    cout<<"Box3 (Copied from Box 2): "<<endl<<"Box Volume: ";
    b3.display();
    cout<<endl;
    b3.SetVolume(150);
    cout<<"After Modifying Box 3 Volume: "<<endl<<"Box Volume: ";
    b3.display();
    cout<<endl<<"Box 2 Volume:"<<endl<<"Box Volume: ";
    b2.display();
}
