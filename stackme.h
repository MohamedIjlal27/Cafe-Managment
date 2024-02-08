#include <bits/stdc++.h> 
using namespace std; 
 

struct bucket
 { 
	int data; 
   bucket* next; 
   };
    
struct bucket* top; 
 
void push(int data) 
{  
	struct bucket* temp; 
	temp = new bucket(); 

	if (!temp) { 
		cout << "\nHeap Overflow"; 
		exit(1); 
	} 

	temp->data = data; 

	temp->next = top; 

	top = temp; 
} 
 
int isEmpty() 
{ 
	return top == NULL; 
} 
 
int peek() 
{ 
	 
	if (!isEmpty()) 
		return top->data; 
	else
		exit(1); 
} 


void bpop() 
{ 
	struct bucket* temp; 

	
	if (top == NULL) { 
		cout << "\nStack Underflow" << endl; 
		exit(1); 
	} 
	else { 
		
		temp = top; 
		top = top->next;  
		temp->next = NULL; 
		
		// release memory of top node 
		free(temp); 
		
	}
		cout<<"Your Table No is :"<<top->data<<endl; 
    			cout<<"\t\t  ______________  ____"<<endl;
			    cout<<"\t\t |              |/   \\\\ "<<endl;     
			    cout<<"\t\t |    COFFEE    |    ||"<<endl;        
			    cout<<"\t\t |______________|___//"<<endl;     
			    cout<<"\t\t \\______________/      "<<endl;
			    cout<<endl;
} 

void bdisplay() 
{ 
	struct bucket* temp; 

	 
	if (top == NULL) { 
		cout << "\nStack Underflow"; 
		exit(1); 
	} 
	else { 
		temp = top; 
		while (temp != NULL)
 { 
	cout << temp->data << " ";  
			temp = temp->next; 
		} 
	} 
} 


