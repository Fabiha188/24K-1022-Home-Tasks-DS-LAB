
#include <iostream>
using namespace std;
#include <string>
class ResearchPaper{
    private:
    string* authorName;
    int count;
    public:
    ResearchPaper() {
        count = 0;
        authorName = nullptr;
    }

    ResearchPaper(string* n,int c){
        count=c;
        authorName=new string[count];
        for(int i=0;i<count;i++){
            authorName[i]=n[i];
        }
      }
    ~ResearchPaper(){
        delete[] authorName;
    }
    ResearchPaper(const ResearchPaper& other){
        count=other.count;
        authorName=new string[count];
        for(int i=0;i<count;i++){
            authorName[i]=other.authorName[i];
        }
    }
    ResearchPaper& operator=(const ResearchPaper& other){
        if(this!=&other){
            delete[] authorName;
            count=other.count;
            authorName=new string[count];
            for(int i=0;i<count;i++){
                authorName[i]=other.authorName[i];
            }
        }
        return *this;
    }
    void display(){
         cout<<"Total Author Names: "<<count<<endl;
         for(int i=0;i<count;i++){
            cout<<"Author "<<i+1<<": "<<authorName[i]<<endl;
         }
    }
    void setValues(string* n,int c){
        delete[] authorName;
        count=c;
        authorName=new string[count];
        for(int i=0;i<count;i++){
            authorName[i]=n[i];
        }
        cout<<"Changes Successfully Done!..."<<endl;
    }

};
int main() {
    string name1[]={"Murtajiz","Zohan","Arvish"};
    ResearchPaper r1(name1,3);
    cout<<"Original object 1: "<<endl;
    r1.display();
    ResearchPaper r2=r1;
    cout<<"After Deep Copy in Object 2: "<<endl;
    r2.display();
    string name3[]={"Zohan"};
    r1.setValues(name3,1);
    cout<<"After Changing in Object1: "<<endl;
    r1.display();
    cout<<"After Changing in Object1, Object2(Deep Copy): "<<endl;
    r2.display();


    string name2[]={"Hashir","Hamdan"};
    ResearchPaper r3(name2,2);
    cout<<"Original object 2: "<<endl;
    r3.display();
    ResearchPaper r4;
    r4=r3;
    cout<<"After Assignment of object3 into object4: "<<endl;
    r4.display();
    
    string name4[]={"Musfira","Zoraiz","Aayat"};
    r3.setValues(name4,3);
    cout<<"After Changing in Object3: "<<endl;
    r3.display();
    cout<<"After Changing in Object3, Object4(Assignment): "<<endl;
    r4.display();


    return 0;
}

