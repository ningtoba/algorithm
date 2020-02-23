#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct content
{
	string title, author;
	float price;
	int yearReleased, qty, id;
	bool rent;
};

struct node
{
	content data;
	node *next;
};

class linklistf
{
private:
	node *head, *tail, *prev, *temp;
	bool found = false;

public:
	linklistf()
	{
		head = tail = NULL;
	}

	void add(string mTitle, string mAuthor, float mPrice, int mYearReleased, int mQty)
	{
		node *temp = new node;
		temp->data.title = mTitle;
		temp->data.author = mAuthor;
		temp->data.price = mPrice;
		temp->data.yearReleased = mYearReleased;
		temp->data.qty = mQty;
		temp->next = NULL;

		//add hashing to generate id
		temp->data.id = hash(mTitle);

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
	}

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
	void search(string title)
	{
		temp = head;
		if (temp->data.title == title)
		{
			found = true;
			if (found)
			{
				cout << "Book title : " << temp->data.title << endl;
				cout << "Book author : " << temp->data.author << endl;
				cout << "Book price : " << temp->data.price << endl;
				cout << "Book year released : " << temp->data.yearReleased << endl;
				cout << "Quantity available : " << temp->data.qty << endl
					 << endl;
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

	void sort()
	{
		node *a, *b, *c, *d, *r;

		a = b = head;

		// While b is not the last node
		while (b->next)
		{

			c = d = b->next;

			// While d is pointing to a valid node
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
						else
						{

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
					else
					{

						// Case 3: b is the head of the linked list
						if (b == head)
						{

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
						else
						{

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
				else
				{

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

	// Function to print the list
	void printList()
	{
		while (head)
		{
			cout << head->data.id << " " << endl;
			head = head->next;
		}
	}
};

int main()
{
	node *head, *temp, *prev;
	string mTitle, mAuthor;
	float mPrice;
	int mYearReleased, choice, mQty;
	linklistf b;
	cout << " --------------------------------------" << endl;
	cout << " | MMU LIBRARY BOOK MANAGEMENT SYSTEM |" << endl;
	cout << " --------------------------------------" << endl;
	cout << " | 1. Add new book                    |" << endl;   //add
	cout << " | 2. Buy a book                      |" << endl;   //delete
	cout << " | 3. Search a book                   |" << endl;   //search
	cout << " | 4. Return a book                   |" << endl;   //return
	cout << " | 5. Display all book                |" << endl;   //file & sort & display
	cout << " | 6. Sort books                	     |" << endl; //file & sort & display
	cout << " | 7. Exit Program                    |" << endl;
	cout << " --------------------------------------" << endl;
	cout << "Select your operation from the list : ";
	cin >> choice;

	while (choice != 5)
	{
		if (choice == 1)
		{
			cout << "Add title of book : ";
			cin >> mTitle;
			cout << "Author of the book : ";
			cin >> mAuthor;
			cout << "Price of the book : ";
			cin >> mPrice;
			cout << "Year of book released : ";
			cin >> mYearReleased;
			cout << "Enter quantity of book : ";
			cin >> mQty;
			b.add(mTitle, mAuthor, mPrice, mYearReleased, mQty);
		}
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
