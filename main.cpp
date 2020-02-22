#include <iostream>
#include <string.h>
using namespace std;

struct content {
	string title, author;
	float price;
	int yearReleased, qty, id, rent;
};

struct node {
	content data;
	node *next;
};

class linklistf {
	private:
		node *head, *tail, *prev, *temp;
	public:
		linklist() {
			head = NULL;
			tail = NULL;
		}
		
		void add(string mTitle, string mAuthor, float mPrice, int mYearReleased, int mQty) {
			node *temp = new node;
			temp->data.title = mTitle;
			temp->data.author = mAuthor;
			temp->data.price = mPrice;
			temp->data.yearReleased = mYearReleased;
			temp->data.qty = mQty;
			temp->next = NULL;
			
			//add hashing to generate id
			temp->data.id = hash(mTitle);
			
			if(head == NULL) {
				head = temp;
				tail = temp;
			} else {
				tail->next = temp;
				tail = tail->next;
			}
		}
		
		int hash(const char* str) {
		    int hash = 0;
		    int c = 0;
		
		    while (c < strlen(str)) {
		        hash += (int)str[c] << (int)str[c+1];
		        c++;
		    }
		    return hash;
		}
		
		//show first and choose which to delete based on title
//		void delete() {
//			
//		}
		
		void display() {
			temp = head;
			while(temp!=NULL) {
				cout<<"Book ID : "<<temp->data.id<<endl;
				cout<<"Book title : "<<temp->data.title<<endl;
				cout<<"Book author : "<<temp->data.author<<endl;
				cout<<"Book price : "<<temp->data.price<<endl;
				cout<<"Book year released : "<<temp->data.yearReleased<<endl;
				cout<<"Quantity available : "<<temp->data.qty<<endl<<endl;
				temp=temp->next;
			}
		}
		
};

int main() {
	node *head, *temp,*prev;
	string mTitle, mAuthor;
	float mPrice;
	int mYearReleased, choice, mQty;
	linklistf b;
	cout<<" --------------------------------------"<<endl;
	cout<<" | MMU LIBRARY BOOK MANAGEMENT SYSTEM |"<<endl;
	cout<<" --------------------------------------"<<endl;
	cout<<" | 1. Add new book                    |"<<endl; //add
	cout<<" | 2. Buy a book                      |"<<endl; //delete
	cout<<" | 3. Borrow a book                   |"<<endl; //borrow
	cout<<" | 5. Return a book                   |"<<endl; //return
	cout<<" | 6. Search a book                   |"<<endl; //search
	cout<<" | 7. Display all book                |"<<endl; //file & sort & display
	cout<<" | 8. Exit Program                    |"<<endl;
	cout<<" --------------------------------------"<<endl;
	cout<<"Select your operation from the list : ";
	cin>>choice;
	
	while(choice != 5) {
		if(choice == 1 ) {
			cout<<"Add title of book : ";
			cin>>mTitle;
			cout<<"Author of the book : ";
			cin>>mAuthor;
			cout<<"Price of the book : ";
			cin>>mPrice;
			cout<<"Year of book released : ";
			cin>>mYearReleased;
			cout<<"enter quantity of book : ";
			cin>>mQty;
			b.add(mTitle, mAuthor, mPrice, mYearReleased);
			cout<<"\nSelect your operation from the list : ";
			cin>>choice;
		} 
//		else if (choice == 2) {
//			b.buy();
//		} 
		else if (choice == 4) {
			b.display();
			cout<<"\nSelect your operation from the list : ";
			cin>>choice;
		} else {
			return 0;
		}
	}
//	node a = new node;
//	cin>>a->data.title;

//create while loop to accept until exit

	
	
	
	
	
} 


//program can add, delete, display, search

//will use linked list

//sorting when display
//linear search for search
//hashing to produce book code

//book will accept name, price, author, release date
//and then product id from name+author+releasedate

//if possible, show rented book by students
//void rent() {
//	set rent = 1;
//}

//also can generate text file for report/sticker
//void generateDocs() {
//	
//}
