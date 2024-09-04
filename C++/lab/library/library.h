#include<iostream>
using namespace std;
#include<vector>

class Borrower
{
private:
	string id; string last_name, first_name; int books_have;
public:
	vector<string>book_loaned;
	Borrower();
	
	int num_books();
	
	void message1();
	
	~Borrower() {}
};

class Bookrecord
{
private:
	string  name, writer_first_name, writer_last_name, year;
	
public:
	int num_stillhave; string id;
	Bookrecord();

	void message2();
	
	~Bookrecord() {}
};

class Catalogue
{
private:
	int num_bookrecord;
	
public:
	vector<Bookrecord>book;
	Catalogue();
	
	void message3();
	
	~Catalogue(){}
};

class Library
{
private:
	Catalogue catalogue; 
	vector<Borrower>borrower;
	int book_out=0, num_borrower;
	friend Catalogue; friend Borrower;
public:
	Library();
	
	void message4();
	
	~Library() {}
};
