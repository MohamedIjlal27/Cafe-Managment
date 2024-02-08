#include <iostream>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	string cname;
	int cid;
	Node *link;
};

Node *front = NULL;
Node *rear = NULL;

bool isempty()
{
 if(front == NULL && rear == NULL)
 return true;
 else
 return false;
}

void enqueue (string name, int id)
{
	
 Node *ptr = new Node();
 ptr->cname= name;
 ptr->cid = id;
 ptr->link = NULL;

 if( front == NULL )
 {
  front = ptr;
  rear = ptr;
 }
 else
 {
  rear ->link = ptr;
  rear = ptr;
 }
}




void dequeue() 
{ 
	int id;
	cout<<"Enter Customer ID: ";
	cin>>id;

	if(isempty()) 
		cout<<"Queue is empty\n"; 
	else 
	{ 
		ofstream tempFileWrite;
		tempFileWrite.open("temp.txt");
		ifstream read;
		read.open("Data.txt");
		
		Node *ptr = front; 
		while (ptr != NULL && ptr->cid != id){
			tempFileWrite<<endl<<ptr->cid<< endl;
			tempFileWrite<<ptr->cname<<endl;
			ptr = ptr->link; 				
		}			
		if (ptr == NULL) 
			cout<<"Customer not found\n"; 
		else if (ptr == front) 
		{ 
			front = front->link; 
			
			free(ptr); 
		} 
		else
		{ 
			Node *temp = front; 
			while (temp->link != ptr) 
				temp = temp->link; 
			temp->link = ptr->link; 
			free(ptr); 
		} 
		//Write the remaining customers in the queue to the file
		ptr = front;
		while (ptr != NULL){
			tempFileWrite<<endl<<ptr->cid<< endl;
			tempFileWrite<<ptr->cname<<endl;
			ptr = ptr->link; 
		}
		//Close the files
		read.close();
		tempFileWrite.close();
		//Delete the data file
		remove("Data.txt");
		//Rename the temp file to data file
		rename("temp.txt", "Data.txt");
	} 
}
	
	void showfront( )
	{
	 if( isempty())
	 cout<<"Queue is empty\n";
	 else
	 cout<<"element at front is:"<<front->cname<<"\n";
}

void displayQueue()
{  
	cout<<"Customer ID\t\tCustomer Name"<<endl;
 if (isempty())
  cout<<"Queue is empty\n";
 else
 {
  Node *ptr = front;
  while( ptr !=NULL)
  {
    cout<<ptr->cid<<"\t\t\t\t"<<ptr->cname<<endl;   
    ptr= ptr->link;
  
  }
 }
}




void reopenqueue(){
	Node* temp = front;
	
	ifstream read("Data.txt");
	if(read.is_open()){
		string cname;
		
		while(!read.eof()){
			Node* ptr = new Node;
			read>>ptr->cid;
			read>>ptr->cname;
			if(temp==NULL){
				ptr->link = NULL;
				front = ptr;
				rear = ptr;				
			}
			else{
				while(temp->link!=NULL){
					temp=temp->link;
				}
				temp->link = ptr;
	  			rear = ptr;
			}
			temp = ptr;
		}
	}
	else{
		cout<<"  File is Empty so Cannot open...Sorry"<<endl;
	}  
}

