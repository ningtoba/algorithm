#include <iostream>
#include <string>
#include <stdlib.h>
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
		linklistf() {
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
//			string s1 = to_string(rand()%1000+1000); 
//		    string s2 = to_string(mYearReleased); 
		  
		    // Concatenate both strings 
//		    string s = s1 + s2; 
		  
		    // Convert the concatenated string 
		    // to integer 
			temp->data.id = rand()%1000+1000;
			temp->next = NULL;
			if(head == NULL) {
				head = temp;
				tail = temp;
			} else {
				tail->next = temp;
				tail = tail->next;
			}
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
	cout<<" | 1. Add new book                    |"<<endl; //add plus random plus year hashing
	cout<<" | 2. Buy a book                      |"<<endl; //delete
	cout<<" | 3. Borrow a book                   |"<<endl; //borrow
	cout<<" | 5. Return a book                   |"<<endl; //return
	cout<<" | 6. Search a book                   |"<<endl; //search
	cout<<" | 7. Display all book                |"<<endl; //file & sort & display
	cout<<" | 8. Exit Program                    |"<<endl;
	cout<<" --------------------------------------"<<endl;
	cout<<"Select your operation from the list : ";
	cin>>choice;
	
	while(choice != 8) {
		if(choice == 1 ) {
			fflush(stdin);
			cout<<"Add title of book : ";
			getline(cin, mTitle);
			cout<<"Author of the book : ";
			getline(cin, mAuthor);
			cout<<"Price of the book : ";
			cin>>mPrice;
			cout<<"Year of book released : ";
			cin>>mYearReleased;
			cout<<"Enter quantity of book : ";
			cin>>mQty;
			b.add(mTitle, mAuthor, mPrice, mYearReleased, mQty);
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
