#include <iostream>
using namespace std;

struct content {
	string title, author;
	float price;
	int yearReleased, id, rent;
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
		
		void add(string mTitle, string mAuthor, float mPrice, int mYearReleased) {
			node *temp = new node;
			temp->data.title = mTitle;
			temp->data.author = mAuthor;
			temp->data.price = mPrice;
			temp->data.yearReleased = mYearReleased;
			temp->next = NULL;
			
			//add hashing to generate id
			
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
				cout<<"Book title : "<<temp->data.title<<endl;
				cout<<"Book author : "<<temp->data.author<<endl;
				cout<<"Book price : "<<temp->data.price<<endl;
				cout<<"Book year released : "<<temp->data.yearReleased<<endl<<endl;;
				temp=temp->next;
			}
		}
		
};

int main() {
	node *head, *temp,*prev;
	string mTitle, mAuthor;
	float mPrice;
	int mYearReleased, choice;
	linklistf b;
	cout<<" --------------------------------------"<<endl;
	cout<<" | MMU LIBRARY BOOK MANAGEMENT SYSTEM |"<<endl;
	cout<<" --------------------------------------"<<endl;
	cout<<" | 1. Add new book                    |"<<endl;
	cout<<" | 2. Delete a book                   |"<<endl;
	cout<<" | 3. Search a book                   |"<<endl;
	cout<<" | 4. Display all book                |"<<endl;
	cout<<" | 5. Exit Program                    |"<<endl;
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
			b.add(mTitle, mAuthor, mPrice, mYearReleased);
			cout<<"\nSelect your operation from the list : ";
			cin>>choice;
		} else if (choice == 4) {
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
