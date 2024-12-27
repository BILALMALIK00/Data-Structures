#include<iostream>
using namespace std;

class hash_entry{
	public:
		int key;
		int value;
		hash_entry*next;
		hash_entry(int k,int v){
		key=k;
		value=v;
		next=NULL;
		}
};
class hash_Table{
	public:
		hash_entry**Table;
		int max_size;
		int elements_count;
		hash_Table(){
			max_size=11;
			Table=new hash_entry*[max_size];
			elements_count=0;
			for(int i=0;i<11;i++){
				Table[i]=0;
			}
		}
			int load_factor(){
		return 1.0*(elements_count/max_size);	
		}
		int hash_fun(int k){
			return k%max_size;
		}
		void insert(int k,int v){
			hash_entry*temp=new hash_entry(k,v);
			int hash=hash_fun(k);
			if(Table[hash]==NULL){
				Table[hash]=temp;
			}else{
				hash_entry*curr=Table[hash];
				while(curr->next!=NULL){
					curr=curr->next;
				}
				curr->next=temp;
			}
			elements_count++;
			if(load_factor()>0.7){
				int newsize=max_size*2;
				resize(newsize);
			}
			
		}
		void resize(int newsize){
			hash_entry**newTable=new hash_entry*[newsize];
			for(int i=0;i<newsize;i++){
				newTable[i]=0;
			}
			for(int i=0;i<max_size;i++){
				hash_entry*curr=Table[i];
				while(curr!=NULL){
					hash_entry*next=curr->next;
					int newhash=curr->key%newsize;
					curr->next=newTable[newhash];
					newTable[newhash]=curr;
					curr=next;
				}
			}
			delete[]Table;
		}
		
		
};
int main(){
}

