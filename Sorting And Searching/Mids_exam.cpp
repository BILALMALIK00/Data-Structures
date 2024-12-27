#include<iostream>
using namespace std;
class teams{
	public:
		int matches;
		string name;
		teams(int m,string n):matches(m),name(n){
		};
};
int search(teams t1[],int n,int target){
	int s=0;
	int e=n-1;
	int mid=(s+e)/2;
	while(s<=e){
		if(t1[mid].matches==target){
			return mid;
		}else if(t1[mid].matches>target){
			s=mid+1;
		}else{
			e=mid-1;
		}
		mid=(s+e)/2;
	}
	return -1;
}
void sort(teams team[],int n){
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
		if(team[j].matches>team[min].matches||team[j].matches==team[min].matches&&team[j].name.length()>team[min].name.length()||team[j].matches==team[min].matches&&team[j].name.length()==team[min].name.length())
		
		{
				min=j;
			}
		}
		swap(team[i].matches,team[min].matches);
		swap(team[i].name,team[min].name);	
	}
}
void display(teams t1[],int n){
	for(int i=0;i<n;i++){
		cout<<t1[i].matches<<" ";
		cout<<endl;
		cout<<t1[i].name<<endl;
	}
}
int main(){
	teams t1[7]={{1,"pakistan"},{2,"india"},{3,"sp"},{3,"germeny"},{57,"turkey"},{3,"mongol"},{1,"saudia"}};
	sort(t1,7);
	display(t1,7);
	int index=search(t1,7,57);
	if(index!=-1){
	cout<<"team name:"<<t1[index].name<<endl;
	cout<<"	Team matches:"<<t1[index].matches<<endl;
	}else{
		cout<<"Team Not present"<<endl;
	}
}
