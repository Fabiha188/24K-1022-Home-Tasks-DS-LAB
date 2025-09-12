#include <iostream>
using namespace std;
#include <string>
int main(){
	int r,c;
	cout<<"Number of teams: ";
	cin>>r;
	int** scores=new int*[r];
	int size[r];
	for(int i=0;i<r;i++){
		cout<<"Enter Number of Score of Team "<<i+1<<" :";
		cin>>size[i];
		scores[i]=new int[size[i]];

	}
	for(int i=0;i<r;i++){
		cout<<"Enter Team "<<i+1<<" scores:\n";
		for(int j=0;j<size[i];j++){
			cin>>scores[i][j];
		}
	}
	cout<<"Displaying Scores: \n";
	for(int i=0;i<r;i++){
		cout<<"Team "<<i+1<<" : ";
		for(int j=0;j<size[i];j++){
			cout<<scores[i][j]<<" ";
		}
		cout<<endl;
	}
    int arr[r];
  
    for(int i=0;i<r;i++){
          int sum=0;
        for(int j=0;j<size[i];j++){
            sum+=scores[i][j];
        }
        arr[i]=sum;
    }
    cout<<"Sum Of Scores:\n";
    for(int i=0;i<r;i++){
        cout<<"Team "<<i+1<<": ";
        cout<<arr[i];
        cout<<endl;
    }
	for(int i=0;i<r;i++){
		delete[] scores[i];
	}
	delete[] scores;
}
