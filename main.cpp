#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

//content struct for all the data
struct content {
	string title, author;
	float price;
	int yearReleased, qty, id;
	bool rent = 0;
};

//node have a struct content as data, and can reach rest of data inside content struct, node to point to next node
struct node {
	content data;
	node *next;
};

//class linklistf will have all the function to run the operation
class linklistf {
private:
	node *head, *tail, *prev, *temp;
	bool found = false;

public:
	//initialize node 
	linklistf() {
		head = tail = NULL;
	}

	//add node to linked list
	void add(string mTitle, string mAuthor, float mPrice, int mYearReleased, int mQty) {
		node *temp = new node;
		temp->data.title = mTitle;
		temp->data.author = mAuthor;
		temp->data.price = mPrice;
		temp->data.yearReleased = mYearReleased;
		temp->data.qty = mQty;
		temp->next = NULL;

		//add hashing to generate id
		temp->data.id = hash(mYearReleased);

		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next;
		}
	}
	
	//function buy to buy book, will confirm and ask for quantity wanted to buy
	void buy() {
			char choice;
			int qty;
			cout << "Would you like to buy this book? [Y/N] : ";
			cin >> choice;
			switch (choice) {
			case 'Y':
			case 'y':
				cout<<"How many to buy for this book? : ";
				cin>>qty;
				temp->data.qty-=qty;
				cout<<"Book "<<temp->data.title<<" has been bought"<<endl;
				cout<<"Quantity left is "<<temp->data.qty<<endl;
				if(temp->data.qty == 0) {
					temp=prev=head;
					int set = 0;
					if(head->data.qty == 0) {
						temp = head;
						head=head->next;
						temp->next = NULL;
						delete temp;
						set=1;
					}
					//other node
					if(set != 1) {
						prev=head;
						temp=prev->next;
						while(set!=1) {
							if(temp->data.qty == 0) {
								prev->next=temp->next;
								temp->next = NULL;
								delete temp;
								set = 1;
							}  else if (temp->next == NULL){
								break;
							} else {
								prev = temp;
								temp = temp->next;
							}
						}
						
					}
				}
				break;
			default:
				cout<<"Exit to menu"<<endl; break;
			}
	}

	//function hashing to create a unique id for book and sorting
	int hash(const int year) {
		int hash = 0;
		//random number generated with front truncated add with year
		hash = (rand()%100*1000) + 100 + year;
		return hash;
	}

	//display all data in the linked list
	void display() {
		if(temp->next == NULL) {
			cout<<"No book found"<<endl;
		}
		temp = head;
		while (temp != NULL) {
			cout << "Book ID : " << temp->data.id << endl;
			cout << "Book title : " << temp->data.title << endl;
			cout << "Book author : " << temp->data.author << endl;
			cout << "Book price : " << temp->data.price << endl;
			cout << "Book year released : " << temp->data.yearReleased << endl;
			cout << "Quantity available : " << temp->data.qty << endl
				 << endl;
			temp = temp->next;
		}
	}
	
	//search inside linked list based on title given
	void search(string title) {
		temp = head;
		while(temp->next != NULL) {
			if ((title.compare(temp->data.title)) == 0) {
				found = true; 	//if found, print the detail of the specific book
				if (found) {
					cout << "Book title : " << temp->data.title << endl;
					cout << "Book author : " << temp->data.author << endl;
					cout << "Book price : " << temp->data.price << endl;
					cout << "Book year released : " << temp->data.yearReleased << endl;
					cout << "Quantity available : " << temp->data.qty << endl
						 << endl;
				}
				found = false;
			} else {
				temp = temp->next;	
			}
		}
	}
	
	//function borrow to make book as rented and decrease quantity by one
	void borrow() {
		// After search ask whether want to borrow or return
			char choice;
			cout << "Would you like to borrow this book? [Y/N]";
			cin >> choice;
			switch (choice) {
			case 'Y':
			case 'y':
				temp->data.rent = true;
				temp->data.qty--;
				cout<<"Book has been borrow"<<endl;
				cout<<"Quantity left is "<<temp->data.qty<<endl;
				break;
			default: 
				cout<<"Exit to menu"<<endl;
			}
	}

	//function returnbook to display rented book and add back quantity
	void returnBook() {
		string title;
		char choice;
		temp = head;
		// Display Rented Books
		cout<<"---Book Borrowed---"<<endl;
		while (temp!= NULL) {
			if (temp->data.rent) {
				cout << "Book ID : " << temp->data.id << endl;
				cout << "Book title : " << temp->data.title << endl;
				cout << "Book author : " << temp->data.author << endl;
				cout << "Book price : " << temp->data.price << endl;
				cout << "Book year released : " << temp->data.yearReleased << endl;
				temp = temp->next;
			} else {
				temp = temp->next;
			}
		}
		// Choice to return book
		cout << "\nWould you like to return a book? [Y/N]: ";
		cin >> choice;
		while (choice == 'Y' || choice == 'y') {
			if (choice == 'Y' || choice == 'y') {
				// Title of book to return
				fflush(stdin);
				cout << "Enter the title of the book you would like to return : ";
				getline(cin, title);
				temp = head;
				// Update book qty
				while (temp != NULL) {
					if (temp->data.title == title) {
						temp->data.qty++;
						temp->data.rent = false;
					}
					temp = temp->next;
				}
			}
			cout<<"Book returned successfully"<<endl;
			break;
		}
	}

	//sort by id
	void sort() {
		node *a, *b, *c, *d, *r;

		a = b = head;

		// While b is not the last node
		while (b->next) {

			c = d = b->next;

			// While d is pointing to a valid node
			while (d) {

				if (b->data.id > d->data.id) {

					// If d appears immediately after b
					if (b->next == d) {

						// Case 1: b is the head of the linked list
						if (b == head) {

							// Move d before b
							b->next = d->next;
							d->next = b;

							// Swap b and d pointers
							r = b;
							b = d;
							d = r;

							c = d;

							// Update the head
							head = b;

							// Skip to the next element
							// as it is already in order
							d = d->next;
						}

						// Case 2: b is not the head of the linked list
						else {

							// Move d before b
							b->next = d->next;
							d->next = b;
							a->next = d;

							// Swap b and d pointers
							r = b;
							b = d;
							d = r;

							c = d;

							// Skip to the next element
							// as it is already in order
							d = d->next;
						}
					}

					// If b and d have some non-zero
					// number of nodes in between them
					else {

						// Case 3: b is the head of the linked list
						if (b == head) {

							// Swap b->next and d->next
							r = b->next;
							b->next = d->next;
							d->next = r;
							c->next = b;

							// Swap b and d pointers
							r = b;
							b = d;
							d = r;

							c = d;

							// Skip to the next element
							// as it is already in order
							d = d->next;

							// Update the head
							head = b;
						}

						// Case 4: b is not the head of the linked list
						else {

							// Swap b->next and d->next
							r = b->next;
							b->next = d->next;
							d->next = r;
							c->next = b;
							a->next = d;

							// Swap b and d pointers
							r = b;
							b = d;
							d = r;

							c = d;

							// Skip to the next element
							// as it is already in order
							d = d->next;
						}
					}
				}
				else {

					// Update c and skip to the next element
					// as it is already in order
					c = d;
					d = d->next;
				}
			}

			a = b;
			b = b->next;
		}
	}

	// Function to print the list for sorting function after sorted (different than display())
	void printList() {
		temp = head;
		while (temp != NULL) {
			cout <<"ID: "<< temp->data.id << " Title: " << temp->data.title<<endl;
			temp = temp->next;
		}
	}
};

int main() {
	node *head, *temp, *prev;
	string mTitle, mAuthor;
	float mPrice;
	int mYearReleased, choice, mQty;
	linklistf b;
	cout << " --------------------------------------" << endl;   //menu of available operation
	cout << " | MMU LIBRARY BOOK MANAGEMENT SYSTEM |" << endl;
	cout << " --------------------------------------" << endl;
	cout << " | 1. Add new book                    |" << endl;   //add
	cout << " | 2. Buy a book                      |" << endl;   //delete
	cout << " | 3. Borrow a book                   |" << endl;   //search
	cout << " | 4. Return a book                   |" << endl;   //return
	cout << " | 5. Display all book                |" << endl;   //display
	cout << " | 6. Sort books                      |" << endl;   //sort & display
	cout << " | 7. Exit Program                    |" << endl;
	cout << " --------------------------------------" << endl;
	cout << "Select your operation from the list : ";
	cin >> choice;

	while(choice  == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7){
			if (choice == 1) {
				fflush(stdin);
				cout << "Add title of book : ";
				getline(cin, mTitle);
				cout << "Author of the book : ";
				getline(cin, mAuthor);
				cout << "Price of the book : ";
				cin >> mPrice;
				cout << "Year of book released : ";
				cin >> mYearReleased;
				cout << "Enter quantity of book : ";
				cin >> mQty;
				b.add(mTitle, mAuthor, mPrice, mYearReleased, mQty);
				cout<<"Book added successfully"<<endl;
			}
			else if (choice == 2) {
				b.display();
				fflush(stdin);
				cout<<"Enter book title to buy: ";
				getline(cin, mTitle);
				b.search(mTitle);
				b.buy();
			}
			else if (choice == 3) {
				b.display();
				fflush(stdin);
				cout << "Enter book title to borrow: ";
				getline(cin, mTitle);
				b.search(mTitle);
				b.borrow();
			}
			else if (choice == 4) {
				b.returnBook();
			}
			else if (choice == 5) {
				b.display();
			}
			else if (choice == 6) {
				b.sort();
				b.printList();
			}
			else if (choice == 7) {
				cout << "Thanks for using our program!";
				return 0;
			}
			cout << " \n---------------------------------------" << endl;
			cout << " | MMU LIBRARY BOOK MANAGEMENT SYSTEM |" << endl;
			cout << " --------------------------------------" << endl;
			cout << " | 1. Add new book                    |" << endl;   //add
			cout << " | 2. Buy a book                      |" << endl;   //delete
			cout << " | 3. Borrow a book                   |" << endl;   //search
			cout << " | 4. Return a book                   |" << endl;   //return
			cout << " | 5. Display all book                |" << endl;   //display
			cout << " | 6. Sort books                      |" << endl; 	 //sort & display
			cout << " | 7. Exit Program                    |" << endl;
			cout << " --------------------------------------" << endl;
			cout << "Select your operation from the list : ";
			cin >> choice;
	}
	
	
}



