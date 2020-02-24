#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

<<<<<<< HEAD
//content struct for all the data
struct content {
=======
struct content
{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
	string title, author;
	float price;
	int yearReleased, qty, id;
	bool rent;
};

<<<<<<< HEAD
//node have a struct content as data, and can reach rest of data inside content struct, node to point to next node
struct node {
=======
struct node
{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
	content data;
	node *next;
};

<<<<<<< HEAD
//class linklistf will have all the function to run the operation
class linklistf {
=======
class linklistf
{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
private:
	node *head, *tail, *prev, *temp;
	bool found = false;

public:
<<<<<<< HEAD
	//initialize node 
	linklistf() {
		head = tail = NULL;
	}

	//add node to linked list
	void add(string mTitle, string mAuthor, float mPrice, int mYearReleased, int mQty) {
=======
	linklistf()
	{
		head = tail = NULL;
	}

	void add(string mTitle, string mAuthor, float mPrice, int mYearReleased, int mQty)
	{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
		node *temp = new node;
		temp->data.title = mTitle;
		temp->data.author = mAuthor;
		temp->data.price = mPrice;
		temp->data.yearReleased = mYearReleased;
		temp->data.qty = mQty;
		temp->next = NULL;

		//add hashing to generate id
<<<<<<< HEAD
		temp->data.id = hash(mYearReleased);

		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
=======
		temp->data.id = hash(mTitle);

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
			tail->next = temp;
			tail = tail->next;
		}
	}
<<<<<<< HEAD
	
	//function buy to buy book, will confirm and ask for quantity wanted to buy
	void buy() {
		if(temp->data.qty != NULL) {
			char choice;
			int qty;
			cout << "Would you like to buy this book? [Y/N] : ";
			cin >> choice;
			cout<<"How many to buy for this book? : ";
			cin>>qty;
			switch (choice) {
			case 'Y':
			case 'y':
				temp->data.qty-=qty;
				cout<<"Book "<<temp->data.title<<" has been bought"<<endl;
				cout<<"Quantity left is "<<temp->data.qty<<endl;
				break;
			default:
				cout<<"Exit to menu"<<endl; break;
			}
		} else {
			temp=head;
			head=temp->next;
			temp->next=NULL;
			delete temp;
		}
	}

	//function hashing to create a unique id for book and sorting
	int hash(const int year) {
		int hash = 0;
		int c = 0;
		//random number generated with front truncated add with year
		hash = (rand()*100) + 1000000 + year;
		return hash;
	}

	//display all data in the linked list
	void display() {
		temp = head;
		while (temp != NULL) {
=======

	int hash(const string str)
	{
		int hash = 0;
		int c = 0;

		while (c < str.size())
		{
			hash += (int)str[c] << (int)str[c + 1];
			c++;
		}
		return hash;
	}

	//show first and choose which to delete based on title
	//		void delete() {
	//
	//		}

	void display()
	{
		temp = head;
		while (temp != NULL)
		{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
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
<<<<<<< HEAD
	
	//search inside linked list based on title given
	void search(string title) {
		temp = head;
		if (temp->data.title.compare(title) == 0) {
			found = true; 	//if found, print the detail of the specific book
			if (found) {
=======
	void search(string title)
	{
		temp = head;
		if (temp->data.title == title)
		{
			found = true;
			if (found)
			{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
				cout << "Book title : " << temp->data.title << endl;
				cout << "Book author : " << temp->data.author << endl;
				cout << "Book price : " << temp->data.price << endl;
				cout << "Book year released : " << temp->data.yearReleased << endl;
				cout << "Quantity available : " << temp->data.qty << endl
					 << endl;
<<<<<<< HEAD
			}
		}
		else if (temp == NULL) {
			cout << "Book not available";
			temp = temp->next;
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
		cout<<"Book rented"<<endl;
		while (temp->next != NULL) {
			if (temp->data.rent) {
				cout << "Book ID : " << temp->data.id << endl;
				cout << "Book title : " << temp->data.title << endl;
				cout << "Book author : " << temp->data.author << endl;
				cout << "Book price : " << temp->data.price << endl;
				cout << "Book year released : " << temp->data.yearReleased << endl;
				temp = temp->next;
			}
		}
		// Choice to return book
		cout << "\nWould you like to return a book? [Y/N]";
		cin >> choice;
		while (choice == 'Y' || choice == 'y') {
			if (choice == 'Y' || choice == 'y') {
				// Title of book to return
				cout << "Enter the title of the book you would like to return : ";
				cin >> title;
				temp = head;
				// Update book qty
				while (temp != NULL) {
					if (temp->data.title == title) {
=======
				// After search ask whether want to borrow or return
				char choice;
				cout << "Would you like to borrow this book? [Y/N]";
				cin >> choice;
				switch (choice)
				{
				case 'Y':
				case 'y':
					temp->data.rent = true;
					temp->data.qty--;
					break;
				}
			}
		}
		else if (temp == NULL)
			cout << "Book not available";
		temp = temp->next;
	}

	void returnBook()
	{
		string title;
		char choice;
		temp = head;
		// Display Rented Books
		while (temp != NULL)
		{
			if (temp->data.rent)
			{
				cout << "Book ID : " << temp->data.id << endl;
				cout << "Book title : " << temp->data.title << endl;
				cout << "Book author : " << temp->data.author << endl;
				cout << "Book price : " << temp->data.price << endl;
				cout << "Book year released : " << temp->data.yearReleased << endl;
				temp = temp->next;
			}
		}
		// Choice to return book
		cout << "Would you like to return a book? [Y/N]";
		cin >> choice;
		while (choice == 'Y')
		{
			if (choice == 'Y' || choice == 'y')
			{
				// Title of book to return
				cout << "Enter the title of the book you would like to return";
				cin >> title;
				temp = head;
				// Update book qty
				while (temp != NULL)
				{
					if (temp->data.title == title)
					{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
						temp->data.qty++;
						temp->data.rent = false;
					}
					temp = temp->next;
				}
			}
			cout << "Would you like to return another book? [Y/N]";
			cin >> choice;
		}
	}

<<<<<<< HEAD
	//sort by id
	void sort() {
=======
	void sort()
	{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
		node *a, *b, *c, *d, *r;

		a = b = head;

		// While b is not the last node
<<<<<<< HEAD
		while (b->next) {
=======
		while (b->next)
		{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca

			c = d = b->next;

			// While d is pointing to a valid node
<<<<<<< HEAD
			while (d) {

				if (b->data.id > d->data.id) {

					// If d appears immediately after b
					if (b->next == d) {

						// Case 1: b is the head of the linked list
						if (b == head) {
=======
			while (d)
			{

				if (b->data.id > d->data.id)
				{

					// If d appears immediately after b
					if (b->next == d)
					{

						// Case 1: b is the head of the linked list
						if (b == head)
						{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca

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
<<<<<<< HEAD
						else {
=======
						else
						{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca

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
<<<<<<< HEAD
					else {

						// Case 3: b is the head of the linked list
						if (b == head) {
=======
					else
					{

						// Case 3: b is the head of the linked list
						if (b == head)
						{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca

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
<<<<<<< HEAD
						else {
=======
						else
						{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca

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
<<<<<<< HEAD
				else {
=======
				else
				{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca

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

<<<<<<< HEAD
	// Function to print the list for sorting function after sorted (different than display())
	void printList() {
		temp = head;
		while (temp != NULL) {
			cout <<"ID: "<< head->data.id << " Title: " << head->data.title<<endl;
			temp = temp->next;
=======
	// Function to print the list
	void printList()
	{
		while (head)
		{
			cout << head->data.id << " " << endl;
			head = head->next;
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
		}
	}
};

<<<<<<< HEAD
int main() {
=======
int main()
{
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
	node *head, *temp, *prev;
	string mTitle, mAuthor;
	float mPrice;
	int mYearReleased, choice, mQty;
	linklistf b;
<<<<<<< HEAD
	cout << " --------------------------------------" << endl; //menu of available operation
=======
	cout << " --------------------------------------" << endl;
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
	cout << " | MMU LIBRARY BOOK MANAGEMENT SYSTEM |" << endl;
	cout << " --------------------------------------" << endl;
	cout << " | 1. Add new book                    |" << endl;   //add
	cout << " | 2. Buy a book                      |" << endl;   //delete
<<<<<<< HEAD
	cout << " | 3. Borrow a book                   |" << endl;   //search
	cout << " | 4. Return a book                   |" << endl;   //return
	cout << " | 5. Display all book                |" << endl;   //display
	cout << " | 6. Sort books                      |" << endl;   //sort & display
=======
	cout << " | 3. Search a book                   |" << endl;   //search
	cout << " | 4. Return a book                   |" << endl;   //return
	cout << " | 5. Display all book                |" << endl;   //file & sort & display
	cout << " | 6. Sort books                	     |" << endl; //file & sort & display
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
	cout << " | 7. Exit Program                    |" << endl;
	cout << " --------------------------------------" << endl;
	cout << "Select your operation from the list : ";
	cin >> choice;

<<<<<<< HEAD
	while (choice != 8) {
		if (choice == 1) {
			fflush(stdin);
			cout << "Add title of book : ";
			getline(cin, mTitle);
			cout << "Author of the book : ";
			getline(cin, mAuthor);
=======
	while (choice != 5)
	{
		if (choice == 1)
		{
			cout << "Add title of book : ";
			cin >> mTitle;
			cout << "Author of the book : ";
			cin >> mAuthor;
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
			cout << "Price of the book : ";
			cin >> mPrice;
			cout << "Year of book released : ";
			cin >> mYearReleased;
			cout << "Enter quantity of book : ";
			cin >> mQty;
			b.add(mTitle, mAuthor, mPrice, mYearReleased, mQty);
		}
<<<<<<< HEAD
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
		cout << " | 5. Display all book                |" << endl;   //file & sort & display
		cout << " | 6. Sort books                      |" << endl; //file & sort & display
		cout << " | 7. Exit Program                    |" << endl;
		cout << " --------------------------------------" << endl;
		cout << "Select your operation from the list : ";
=======
		//		else if (choice == 2) {
		//			b.buy();
		//		}
		else if (choice == 3)
		{
			b.display();
			cout << "Enter book title to search";
			cin >> mTitle;
			b.search(mTitle);
		}
		else if (choice == 4)
		{
			b.display();
			b.returnBook();
		}
		else if (choice == 5)
		{
			b.display();
		}
		else if (choice == 6)
		{
			b.sort();
			b.printList();
		}
		else if (choice == 7)
		{
			cout << "Thanks for using our program!";
			return 0;
		}

		cout << "\nSelect your operation from the list : ";
>>>>>>> c5a3d626e1576bab81ff514a20941953c675f9ca
		cin >> choice;
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


