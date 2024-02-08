#include<iostream>
#include<string>
#include<fstream>
#include<windows.h>
#include"stackme.h"

using namespace std;


int search(int);
int display();
string check(int);  //check  quant
void administator();
void mainfunction();

////////////////////////////////////////////////////////////////////////////

struct Node
{
	int cid;
	string cname;
	string productname;
	double proprice;
	int proquantity;
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

void enqueue (int id, string name, double price, int quantity)
{
	
 Node *ptr = new Node();
 ptr->cid = id;
 ptr->cname= name;
 ptr->proprice = price;
 ptr->proquantity = quantity;
 ptr->link = NULL;

 if( front == NULL )
 {
  front = ptr;
  rear = ptr;
 }
 else
 {
 	Node* temp = front;
 	while(temp->link != NULL){
 		temp=temp->link;
	}
	
	temp->link = ptr;
	rear = ptr;
	 
//  rear ->link = ptr;
//  rear = ptr;
 }
}




void deletecx()
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
			tempFileWrite<<ptr->cid<< endl;
			tempFileWrite<<ptr->cname<<endl;
			tempFileWrite<<ptr->productname<<endl;
			tempFileWrite<<ptr->proprice<<endl;
			tempFileWrite<<ptr->proquantity;
			tempFileWrite<<endl; 
			
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
			tempFileWrite<<ptr->cid<< endl;
			tempFileWrite<<ptr->cname<<endl;
			tempFileWrite<<ptr->productname<<endl;
			tempFileWrite<<ptr->proprice<<endl;
			tempFileWrite<<ptr->proquantity;
			tempFileWrite<<endl; 
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
	
void showfront()
	{
	 if( isempty())
	 cout<<"Queue is empty\n";
	 else
	 cout<<"element at front is:"<<front->cname<<"\n";
}

void displayQueue()
{  
	cout<<setw(22)<<"Customer ID"<<setw(22)<<"Customer Name"<<setw(22)<<"Product Price"<<setw(22)<<"Quantity"<<endl;
 if (isempty())
  cout<<"Queue is empty\n";
 else
 {
  Node *ptr = front;
  while( ptr !=NULL)
  {
    cout<<setw(20)<<ptr->cid<<setw(20)<<ptr->cname<<setw(21)<<ptr->proprice<<setw(23)<<ptr->proquantity<<endl;   
    ptr= ptr->link;
  
  }
 }
 
}

void reopenqueue(){
    Node* temp = front;	
	ifstream read("Data.txt");
	if(read.is_open()){		
		while(!read.eof()){
			Node* ptr = new Node;
			read>>ptr->cid;
			read>>ptr->cname;
			read>>ptr->proprice;
			read>>ptr->proquantity;
			if(temp == NULL){
				ptr->link = NULL;
				front = ptr;
				rear = ptr;				
			}
			else{
				while(temp->link != NULL){
					temp = temp->link;
				}
				
				temp->link = ptr;
				rear = ptr;
				//rear->link = ptr;
				//rear = ptr;
			}
			temp = ptr;
		}
		rear->link = NULL;
	}
	else{
		cout<<"  File is Empty so Cannot open...Sorry"<<endl;
	}  
}




////////////////////////////////////////////////////////////////////
struct node
{
	int ID;
	string proName;
	double proPrice;
	int proQuantity;
	node *next;
	node *prev;
};



node *head = NULL;
int id;
string pname;
double pprice;
int pquantity;

////////////////////////////////////////////////////////////////////

void insertRecord(){
	system("cls");
	
	display();
	int choice;
	int NoItem;
	cout<<"\n\t\t\tEnter 0 For Main Menu or Press 1 to continue:-";
	cin>>choice;
	while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"\t\tYou have entered wrong input Please type only Numbers"<<endl;
				display();
				system("cls");
				cout<<"\n\t\t\tEnter 0 For Main Menu or Press 1 to continue:-";
				cin>>choice;
			}
			if(!cin.fail())
				break;
			}
	if(choice == 0){
		system("cls");
		administator();
	}
	else if(choice == 1){
		system("cls");
		display();
		
        srand (time(NULL));
        id = rand();
        
		node *newer= new node;
		cout<<"\t\t\tProduct ID:-"<<id<<endl;
		newer->ID = id;
		
		cout<<"\t\t\tEnter product Name:-";
		cin.ignore();
		getline(cin,pname);
		//cin>>pname;
		newer->proName = pname;
			
		cout<<"\t\t\tEnter product price:-";
		cin>>pprice;
		newer->proPrice = pprice;
			
		cout<<"\t\t\tEnter product quantity:-";
		cin>>pquantity;		
		newer->proQuantity = pquantity;
			
			
		if(head == NULL){
			newer->next = NULL;
			newer->prev = NULL;
			head = newer;
		}
		else{
			node* temp = head;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = newer;
			newer->next = NULL;
			newer->prev = temp;
		}
			
		system("cls");
		cout<<"\n\n\t\t\t\tThis product is Inserted!\n\n\n";		
		
	}else{
		cout<<"Invalid Input try again\n";
		system("pause");
		system("cls");
		insertRecord();
	}	
	
	
		
	

}
///////////////////////////////////////////////////////////////////////////////////////////
int search(int id){
	int count=1;
 	node *temp=head;
 	while(temp!=NULL)
 	{
 		if(temp->ID==id)
 			break;
 		else
 			count++;
 			temp=temp->next;
	}
 	return count;
}
 
 ///////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////

void deleteProduct(){
	system("cls");
	display();
	int id;
	node *cur=head;
	node *pre=head;
	cout<<"\n\nEnter ID to delete that product:\n";
	cin>>id;
	if (head == NULL){
		system("cls");
	    cout<<"List is empty"<<endl;
	    cout<<endl;
	    return;
	}
	int pos=0;
	int count=display();               //   for load no of nodes
	pos=search(id); 
	if(pos<=count){
		ofstream tempFileWrite;
		tempFileWrite.open("temp.txt");
		ifstream read;
		read.open("Record_Store.txt");
		while(cur->ID!=id){
			tempFileWrite<<cur->ID<<endl;
			tempFileWrite<<cur->proName<<endl;
			tempFileWrite<<cur->proPrice<<endl;
			tempFileWrite<<cur->proQuantity;
			tempFileWrite<<endl;
			pre=cur;
			cur=cur->next;
		}
		pre->next=cur->next;
		delete cur;
		
		tempFileWrite.close();
		read.close();
		remove("Record_Store.txt");
		rename("temp.txt", "Record_Store.txt");
		cout << "\n\tData deleted successfuly\n\t";
		system("pause");
		administator();
	}	
	else{
		cout<<"\n<<<Not found>>\n\n";
	}
}
	
	
//////////////////////////////////////////////////////////////////////////////////
void modify(){
	int id;
	double pre;        //    pre for price
	string pName;
	int nid; int nq;     //   pName for new name
	if (head == NULL){
		system("cls");
        cout<<"List is empty"<<endl;
    }
    else{    
	    display();
		cout<<"\n\nEnter ID to modify product Name and its price:\n";
		cin>>id;
		node *cur=head;
		int pos=0;
		int count=display();               //   for load no of nodes
	    pos=search(id);
	    if(pos<=count){
	    	ofstream tempFileWrite;
			tempFileWrite.open("temp.txt");
			ifstream read;
			read.open("Record_Store.txt");
			while (!read.eof()){
				while(cur->ID!=id){
					tempFileWrite<<cur->ID<<endl;
					tempFileWrite<<cur->proName<<endl;
					tempFileWrite<<cur->proPrice<<endl;
					tempFileWrite<<cur->proQuantity;
					tempFileWrite<<endl;
					cur=cur->next;
				}
				cout<<"\nOld ID : "<<cur->ID<<endl;
				cout<<"Old Name : "<<cur->proName<<endl;
				cout<<"Old Price : "<<cur->proPrice<<endl;
				cout<<"Old Quantity : "<<cur->proQuantity<<endl;
	
				cout<<endl<<endl;
				cout<<"Enter new ID:";
				cin>>nid;
				cur->ID=nid;
			
				cout<<"Enter new Name:";
				cin.ignore();
				getline(cin,pName);
				//cin>>pName;
				cur->proName=pName;
				cout<<"Enter new Price:";
				cin>>pre;
				cur->proPrice=pre;
				cout<<"Enter new Quantity:";
				cin>>nq;
				cur->proQuantity=nq;
			
				tempFileWrite<<cur->ID<<endl;
				tempFileWrite<<cur->proName<<endl;
				tempFileWrite<<cur->proPrice<<endl;
				tempFileWrite<<cur->proQuantity;
				tempFileWrite<<endl;
			
				tempFileWrite.close();
				read.close();
				remove("Record_Store.txt");
				rename("temp.txt", "Record_Store.txt");
				cout << "\n\tData Updated successfuly";
			
				administator();
			
			
		    } 

		
	    }  
        else{
			cout<<id<<" is <<<Not found>>\n\n";
	    }
	}
}

//////////////////////////////////////////////////////////////////////////////////////

int display()
{
	system("cls");
	int c=0;             //   c for count products
	struct node *pro=head;
	cout<<endl;
	cout<<setw(30)<<"Existing products are:\n";
	cout<<setw(21)<<"ID"<<setw(24)<<"Product Name"<<setw(22)<<"Price"<<setw(23)<<"Quantity\n";
	cout<<"\t\t|===========================================================================|\n";		
	while(pro!=NULL){
		cout<<setw(22)<<pro->ID<<setw(22)<<pro->proName<<setw(22)<<pro->proPrice<<setw(22)<<check(pro->proQuantity)<<"\n"; //    call   check func and pass quantity
		pro=pro->next;
		c = c+1;
	}
	cout<<"\n\t\t     Total products in our store is : "<<c<<"\n\n\n";
	return c;
}
////////////////////////////////////////////////////////////////////////////////////////
string check(int quant){
	int a = quant;
    stringstream ss;
   
    ss << a;
    string quantity = ss.str();

	if(quant<=0)
	return "out of stock!";
	else
	return quantity;	
}

	
///////////////////////////////////////////////////////////////////////

void buy(){
	system("cls");
    display();
	string products[100];
	int unit[100];
	int quan[100];
	int total[100];
	int sum = 0;
	ofstream myfile("sold_items.txt",ios::app);
	myfile<<"Product Name\t\tPrice\t\tQuantity\n"; 
	ofstream cx("Data.txt",ios::app);

	int pay=0,no,c=0,d=0,e=0,f=0,id,i=1;
	double price;
    if(head==NULL){
	    cout<<"\n<<<<There is no items to buy>>>>\n\n";
    }
	else{
		cout<<"Enter the Numbers of Items that you want to buy! or Enter 0 to Main menu\n";
		cin>>no; 
		while(1){
			if(cin.fail()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout<<"\t\tYou have entered wrong input Please type only Numbers"<<endl;
				display();
				system("cls");
				cout<<"Enter the Numbers of Items that you want to buy! or Enter 0 to Main menu\n";
				cin>>no; 
			}
			if(!cin.fail())
				break;
			}
		if(no == 0){
				system("cls");
			mainfunction();
		}
		else{
			int count=display();   
		struct node *cur=head;  
		int quant,cho;        //   for store no of nodes  in c
		while (i<=no){
			
                        //   quant   for quantity  and cho for choice
            cout<<"Enter id of item that you want to buy: ";
            int id,pos=0;
            cin>>id;
            if(id==-1){
				system("cls"); return;	
			}
	        pos=search(id);
	        if(pos<=count){
	        	while(cur->ID!=id){
					cur=cur->next;
		        }
           		cout<<"How many quantities you want:";
	       		cin>>quant;
	       		if(cur->proQuantity<quant){
	                cout<<"\n\n\t\t\t----The Quantity You Entered is not available---"<<endl;
	                cout<<"\n\t\t\t-----(Press -1 for Back to Main Menu)------"<<endl;
                }
		        products[c]=cur->proName;   // this will conatin the items buy names in array; 
				c++;
				
				unit[d] = cur->proPrice;
				d++;
				
				quan[e] = quant;
				e++;
				
				//pay1 = cur->proPrice*quant;
				   
				pay=cur->proPrice*quant;  
				
				total[f] = pay;
				f++;
				
				
				       //     calculate Bill
			    cur->proQuantity=cur->proQuantity-quant;           //    change quantity
			    i++;
			    
        
        
        
		        for(int i =0; i<no; i++){
		        	sum+=total[i];
				}
			    
			    price=sum*(0.90); 
			    
                // save data to file
                         
                myfile<<cur->proName<<"\t\t"<<price<<"\t\t"<<cur->proQuantity<<endl;
                

	        }
	   		else{              
				cout<<"\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";
		    }
        }
        
        string customer;
        int cid;
        srand (time(NULL));
        cid = rand();
        
        
		
		cout<<"\n\t\t Customer ID No :"<<cid;
        cout<<"\n\t\t Enter Customer Name :"; 
		cin.get();  
		getline(cin,customer);
		cx<<endl<<cid<<"\t"<<customer<<"\t"<<pay<<"\t\t"<<no;
		
        enqueue(cid, customer,price, quant);
	    system("cls");
	    cout<<setw(24)<<"=====================Oder Summary====================="<<endl<<endl;
	    cout<<"\t\t|=====================================================================|\n";
	    cout<<"\t\t"<<"| Item No"<<setw(16)<<"Product Name"<<setw(14)<<"Unit Price"<<setw(16)<<"Quantity"<<setw(16)<<"Total |"<<endl;
	    cout<<"\t\t|=====================================================================|\n";
        //cout<<"\n\n\n\n\t\t\tYou have bought : ";
        for(int i=0; i<no; i++){
			cout<<setw(22)<<i<<setw(16)<<products[i]<<setw(15)<<unit[i]<<setw(15)<<quan[i]<<setw(16)<<total[i]<<endl;
			
        }        
        
                 
	    cout<<"\n\nTotal Amount    : "<<sum;
        cout<<"\nwith 10% discount : "<<price<<"\nThank you! "<<customer <<" for the shopping\n\nCome Again"<<endl;
    	}
    
    myfile.close();
	}			
        
}
	
            
            
            

void OflineSave(){
	node *temp=head;
    ofstream myfile ("Record_Store.txt");
    if (myfile.is_open())
    {
        while(temp!=NULL)
	    {
	    	
	    	myfile<<endl<<temp->ID<<endl;
			myfile<<temp->proName<<endl;
			myfile<<temp->proPrice<<endl;
			myfile<<temp->proQuantity<<endl;
		
    	temp=temp->next;
		}
        myfile.close();
        //administration();
    }
    else
    {
       	cout<<"  Thanks file is empty."<<endl;
	}
    //administration();    
}   	
		
		
void reopenRS(){
	bool isEmpty;
	node* temp = head;
	ifstream read("Record_Store.txt");
	if(read.is_open()){
		while(!read.eof()){
			node* newNode = new node;
			read>>newNode->ID;
			read.ignore();
			getline(read, newNode->proName);
			//read>>newNode->proName;
			read>>newNode->proPrice;
			read>>newNode->proQuantity;
			if(temp==NULL){
				newNode->next = NULL;
				newNode->prev = NULL;
				head = newNode;				
			}
			else{
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=newNode;
				newNode->prev=temp;
			}
			temp = newNode;
		}
	}
	else{
		cout<<"  File is Empty so Cannot open...Sorry"<<endl;
	}  
}

		
		
 /////////////////////////////////////////////////////////////////////////////////////////
    void administator()
	{
		system("cls");
			int ch;

 
		do {
		
			cout<<"\t\t\t\t============================================"<<endl;
			cout<<"\t\t\t\t|          Administator Portal             |"<<endl;
			cout<<"\t\t\t\t============================================"<<endl;
			cout<<"\t\t\t\t|    Enter 1 - Adding prodcut              |"<<endl;
			cout<<"\t\t\t\t============================================"<<endl;
			cout<<"\t\t\t\t|    Enter 2 - Displaying products   	   |"<<endl;
			cout<<"\t\t\t\t============================================"<<endl;
			cout<<"\t\t\t\t|    Enter 3 - Modifying existing product  |"<<endl;
			cout<<"\t\t\t\t============================================"<<endl;
			cout<<"\t\t\t\t|    Enter 4 - Deleting an item            |"<<endl;
			cout<<"\t\t\t\t============================================"<<endl;
			cout<<"\t\t\t\t|    Enter 5 - Customers list              |"<<endl;
			cout<<"\t\t\t\t============================================"<<endl;
			cout<<"\t\t\t\t|    Enter 6 - Deleting customer           |"<<endl;
			cout<<"\t\t\t\t============================================"<<endl;
			cout<<"\t\t\t\t|    Enter 0 - Main Menu                   |"<<endl;
			cout<<"\t\t\t\t============================================"<<endl;
			
			
			cout<<"\nEnter Your choice >>>";   cin>>ch;
			switch(ch){
			case 1:
				insertRecord();
				OflineSave();
				break;
			case 2:
				system("cls");
			    display();
			    break;
			case 3:
				system("cls");
				modify();
				OflineSave();
				break;
			case 4:
				system("cls");
				deleteProduct();
				OflineSave();
				cout<<"\n-------Product is Deleted-------\n";
				break;
			case 5:
				system("cls");
				cout<<endl;
			    cout<<setw(22)<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
				displayQueue();
				break;
			case 6:
				system("cls");
				cout<<"|============CUSTOMERS NAMES LIST==============|"<<endl;
			    displayQueue();
				deletecx();
			    displayQueue();
				break;
				
			default:
			    system("cls");
	
		}
		
	}while(ch!=0);
}

void login();

void mainfunction(){

    int ch;
	while(ch!=3){
		cout<<"\t\t\t\t============================================="<<endl;		
    	cout<<" \t\t\t\t|\t--------<Main Menu>-----------	    |"<<endl;
	    cout<<"\t\t\t\t============================================="<<endl;
		cout<<"\t\t\t\t|\t 1) Administator of Market          |"<<endl;
		cout<<"\t\t\t\t============================================="<<endl;
		cout<<"\t\t\t\t|\t 2) Customer                 	    |"<<endl;
		cout<<"\t\t\t\t============================================="<<endl;
		cout<<"\t\t\t\t|\t 3) Exit                    	    |"<<endl;
		cout<<"\t\t\t\t============================================="<<endl;



	cout<<"\nEnter Your choice >>>";cin>>ch;
	switch(ch){
	case 1:
		system("cls");
		login();
		//administator();
		break;

	case 2:
		system("cls");
		cout<<endl<<endl;
		bpop();	    
		system("pause");
	    buy();
	    OflineSave();
	    break;

    case 3:
    	system("cls");
    	cout<<"\n\n\t\t\t\t\tThank You\t\t\t\t";
    	break;
   
	}
  }
}




void login(){
	string username;
	string password;
	int num;
	
	cout<<"Please Enter Your User Name: ";
	cin>>username;
	cout<<"Please Enter Your Password: ";
	cin>>password;
	if(username == "Admin" && password == "admin@123"){
		system("cls");
		administator();
	}else{
		system("cls");
		cout<<"Wrong Password Or Username "<<endl;
		cout<<"Enter 1 For Try agin \nEnter 2 For Main Menu\nEnter 3 For Exit "<<endl;
		cin>>num;
		switch(num){
			case 1:
				system("cls");
				login();
				break;
			
			case 2:
				system("cls");
				mainfunction();
				break;		
				
		}
	}
}



int main(){
	system("COLOR 71");
	
	
	reopenRS();
	reopenqueue();

	
	
	
	for(int i=0;i<=51;i++)
     {
     
     	push(i);
	 }

      
       cout<<"\n\t\t\t%%      %%  %%%%%%%  %%       %%%%%%   %%%%%%  %%%%  %%%%  %%%%%%%";
       cout<<"\n\t\t\t%%      %%  %%       %%       %%       %%  %%  %%  %%% %%  %%       ";
       cout<<"\n\t\t\t%%  %%  %%  %%%%%    %%       %%       %%  %%  %%  %%% %%  %%%%%      ";
       cout<<"\n\t\t\t%%  %%  %%  %%       %%       %%       %%  %%  %%      %%  %%           ";
       cout<<"\n\t\t\t%%%%%%%%%%  %%%%%%%  %%%%%%%  %%%%%%%  %%%%%%  %%      %%  %%%%%%%     \n\n";


	cout<<"\t\t\t\t--------------------------------------------------"<<endl;
	cout<<"\t\t\t\t||                 HOUSE OF CAFE                ||"<<endl;
	cout<<endl;
	
			    cout<<"\t\t\t\t\t\t  ______________  ____"<<endl;
			    cout<<"\t\t\t\t\t\t |              |/   \\\\ "<<endl;     
			    cout<<"\t\t\t\t\t\t |    COFFEE    |    ||"<<endl;        
			    cout<<"\t\t\t\t\t\t |______________|___//"<<endl;     
			    cout<<"\t\t\t\t\t\t \\______________/      "<<endl;
			    cout<<endl;
	cout<<"\t\t\t\t--------------------------------------------------"<<endl;
   	cout<<"\t\t\t\t>>>---------- Project Implemented By ----------<<<"<<endl;
   	cout<<endl;
    cout<<"\t\t\t\tMohamed Ijlal"<<endl;
   	cout<<"\t\t\t\tAbdur Rahman"<<endl;
   	cout<<endl;
   	
	system("pause");
	system("cls");
	mainfunction();	
	
}
