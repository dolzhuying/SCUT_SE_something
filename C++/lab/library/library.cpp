#include"library.h"

int Borrower:: num_books()
{
	return books_have;
}

void Borrower::message1()
{
	cout << "id:" << id << " name: " << first_name << ' ' << last_name<<' ';
	cout << "book_have: "<<books_have<<'\n';
	for (auto& i : book_loaned)cout << i << ' ';
	cout << '\n';
}

Borrower::Borrower()
{
	string last_name1, first_name1, id1;
	int books_have1 = 0;
	cout << "输入name——id:";
	cin >> id1;
	if (id1.length() != 5)
	{
		cout << "borrower_id错误";
		exit(1);
	}
	this->id = id1;
	cout << "输入fistname：";
	cin >> first_name1;
	this->first_name = first_name1;
	cout << "输入lastname:";
	cin >> last_name1;
	this->last_name = last_name1;
	cout << "输入借书数量：";
	int n;
	cin >> n;
	this->books_have = n;
	book_loaned.resize(n);
	cout << "输入书籍id：";
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		book_loaned[i] = a;
	}
}

void Bookrecord::message2()
{
	cout << "id: " << id << " 书名：" << name << " 作者姓名：" << writer_first_name << " " << writer_last_name<<' ';
	cout << "年份：" << year << " 剩余数量：" << num_stillhave << '\n';
}

Bookrecord::Bookrecord()
{
	string id1, name1, writer_first_name1, writer_last_name1, year1;
	int num_stillhave1;
	cout << "输入id：";
	cin >> id1;
	if (id1[0] < 'A' || id1[0]>'Z')
	{
		cout << "book_id错误。";
		exit(1);
	}
	id = id1;
	cout << "输入书名：";
	cin >> name1;
	this->name = name1;
	cout << "输入作者firstname：";
	cin >> writer_first_name1;
	this->writer_first_name = writer_first_name1;
	cout << "输入作者lastname:";
	cin >> writer_last_name1;
	this->writer_last_name = writer_last_name1;
	cout << "输入年份：";
	cin >> year1;
	if (year1.length() != 4 || (year1[0] != '1' && year1[0] != '2'))
	{
		cout << "年份错误。";
		exit(1);
	}
	this->year = year1;
	cout << "输入数量：";
	cin >> num_stillhave1;
	this->num_stillhave = num_stillhave1;
}

void Catalogue::message3()
{
	for (auto& i : book)i.message2();
}

Catalogue::Catalogue()
{
	cout << "输入book数量：\n"; int n; cin >> n;
	num_bookrecord = n;
	book.resize(n);
	cout << "ok\n";

}

void Library::message4()
{
	cout << "共借出" << book_out << "本书\n";
	catalogue.message3();
	for (auto& i : borrower)i.message1();
}

Library::Library()
{
	
	cout << "输入borrower数量：\n";
	int n;
	cin >> n;
	borrower.resize(n);
	cout << "ok\n";
	num_borrower = n;
	for (int i = 0; i < n; i++)
	{
		
		for (auto& j : borrower[i].book_loaned)
		{
			for (auto& k : catalogue.book)
			{
				if (j == k.id)
				{
					book_out++;
					k.num_stillhave--;
				}
			}

		}
	}
}