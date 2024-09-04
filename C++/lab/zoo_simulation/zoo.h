#include<iostream>
using namespace std;
#include<vector>
#include<random>
#include<ctime>

class animal
{
protected:
	int weight, food_capacity, food_got = 0;
public:
	animal() :weight(rand() % 1000), food_capacity(0) {}
	bool reset_food();
	void add_food(int i);
	virtual ~animal() {};
};

class elephant :public animal
{
private:
	int trunk; int food_capacity = 750;
public:
	elephant() :animal(), trunk(rand() % 2 + 1) {}
	~elephant()override {}
};

class giraffe :public animal
{
private:
	int neck; int food_capacity = 500;
public:
	giraffe() :animal(), neck(rand() % 3 + 2) {}
	~giraffe() override{}
};

class monkey :public animal
{
private:
	int arm; int food_capacity = 300;
public:
	monkey() :animal(), arm(rand() % 2) {}
	~monkey() override{}
};


class Money
{

public:
	double dollars; int cents;
	Money(double a, int b) :dollars(a), cents(b) {}
	Money operator+(int a);
	Money operator-(int a);
	Money operator+(double a);
	Money operator-(double a);
	
	~Money() {  }
};


class enclosure
{
private:
	bool cur; int dirt_level , close_day ;
public:

	static int food[3];
	enclosure() :cur(1), dirt_level(0),close_day(0){}
	bool check_cur()const;
	void add_dirt_level(int a);
	int check_dirt();
	void reset_cur();
	int close__day()const;

	~enclosure() {}
};
int enclosure::food[3] = { 0,0,0 };



class person
{
protected:
	string name; int age;
public:
	person() :name("kk"), age(rand() % 100) {}

	virtual ~person() {};
};

class zookeeper :public person
{
private:
	int clean_day;
public:
	zookeeper() :person(), clean_day(0) {}
	bool check_clean_day()const;
	void clean();
	int clean__day()const;
	~zookeeper()override {}
};

class visitor :public person
{
protected:
	int id;
public:
	visitor() :person(), id(rand() % 999) {}

	virtual ~visitor()override {}
};

class child:public visitor
{
public:
	int animal_food_0 = 0, animal_food_1 = 0, animal_food_2 = 0;
	child() :visitor() {}
	void feed0();
	void feed1();
	void feed2();
	~child()override { }
};

class adult :public visitor
{
protected:
	int food0 = 0, food1 = 0, food2 = 0;
	
	Money money;
public:
	vector<child>kids;
	adult() :visitor(), money(rand() % 11 + 10, 0), kids(rand() % 3 + 1) {}
	void buy_id(int n);
	void buy_distribute_food012(int n);
	void buy_distribute_food01(int n);
	void buy_distribute_food02(int n);
	void buy_distribute_food12(int n);
	~adult()override {  }
};

class foodseller :public person
{
protected:
	Money money; Money today;
public:
	friend adult;
	foodseller() :person(), money(0, 0),today(0,0) {}
	static int food_list[3][2];
	static double today_income;
	int check_food_left()const;
	void get_money_summary()const;
	void get_total()const;
	void add_money_today(int i);
	void reset_income();
	~foodseller()override {}
};
int foodseller::food_list[3][2] = { {10000,20},{7000,30},{4000,50}};
