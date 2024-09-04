#include<iostream>
using namespace std;
#include"zoo.h"
#include<random>
#include<ctime>

bool animal::reset_food()
{
	if (food_got == food_capacity)
	{
		food_got = 0;
		return 1;
	}
	return 0;
}

void animal::add_food(int i)
{
	food_got += enclosure::food[i] / (i + 1);
}

Money Money::operator+(int i)
{
	Money res(dollars + (i + cents) / 100, (cents + i) % 100);
	return res;
}

Money Money::operator-(int i)
{
	Money res(dollars - (i + cents) / 100, (i+ cents) % 100);
	if (res.cents < 0) {
		res.dollars--;
		res.cents += 100;
	}
	return res;
}

Money Money::operator+(double i)
{
	Money res(dollars + i,cents);
	return res;
}

Money Money::operator-(double i)
{
	Money res(dollars - i, cents);
	return res;
}
int enclosure::check_dirt()
{
	if (dirt_level >= 2000)
	{
		cur = 0;
		
		return 1;
	}
	return 0;
}

bool enclosure::check_cur()const
{
	if (cur)return 1;
	return 0;
}

void enclosure::add_dirt_level(int a)
{
	dirt_level += a;
}

void enclosure::reset_cur()
{
	cur = 1;
	close_day += 1;
	dirt_level = 0;
}

int enclosure::close__day()const
{
	return close_day;
}
bool zookeeper::check_clean_day()const
{
	if (clean_day == 10)return false;
	return true;
}

void zookeeper::clean()
{
	clean_day++;
}

int zookeeper::clean__day()const
{
	return clean_day;
}



foodseller seller; zookeeper keeper;
int foodseller::check_food_left()const
{

	if (!food_list[0][0] || !food_list[1][0] || !food_list[2][0])return 0;
	return 1;
}

void foodseller::add_money_today(int i)
{
	today = today + i;
	money = money + i;
}

void foodseller::get_money_summary()const
{
	cout << "�����̽������룺" << today.dollars << "��Ԫ" << today.cents << "����" << "\n";

}

void foodseller::reset_income()
{
	today.dollars = 0; today.cents = 0;
}

void foodseller::get_total()const
{
	cout << "������:" << money.dollars << "��Ԫ��" << money.cents << "����\n";
}

void child::feed0()
{

	enclosure::food[0] += animal_food_0;
	animal_food_0 = 0;

}

void child::feed1()
{

	enclosure::food[1] += animal_food_1;
	animal_food_1 = 0;

}

void child::feed2()
{

	enclosure::food[2] += animal_food_2;
	animal_food_2 = 0;

}

void adult::buy_id(int n)
{
	money = money - n * 40 - 100;
}

void adult::buy_distribute_food01(int n)
{
	food0 = (money.dollars * 100 + money.cents) / 3 / 20;
	if (food0 > foodseller::food_list[0][0])food0 = foodseller::food_list[0][0];
	foodseller::food_list[0][0] -= food0;
	seller.today = seller.today + food0 * 20;
	seller.money = seller.money + food0 * 20;

	food1 = (money.dollars * 100 + money.cents) / 3 / 30;
	if (food1 > foodseller::food_list[1][0])food1 = foodseller::food_list[1][0];
	foodseller::food_list[1][0] -= food1;
	seller.today = seller.today + food1 * 30;
	seller.money = seller.money + food1 * 30;

	for (int i = 0; i < n; i++)
	{
		kids[i].animal_food_0 = food0 / n;
		food0 -= food0 / n;
		kids[i].animal_food_1 = food1 / n;
		food1 -= food1 / n;
	}
}

void adult::buy_distribute_food02(int n)
{
	food0 = (money.dollars * 100 + money.cents) / 3 / 20;
	if (food0 > foodseller::food_list[0][0])food0 = foodseller::food_list[0][0];
	foodseller::food_list[0][0] -= food0;
	seller.today = seller.today + food0 * 20;
	seller.money = seller.money + food0 * 20;

	food2 = (money.dollars * 100 + money.cents) / 3 / 50;
	if (food2 > foodseller::food_list[2][0])food2 = foodseller::food_list[2][0];
	foodseller::food_list[2][0] -= food2;
	seller.today = seller.today + food2 * 50;
	seller.money = seller.money + food2 * 50;

	for (int i = 0; i < n; i++)
	{
		kids[i].animal_food_0 = food0 / n;
		food0 -= food0 / n;
		kids[i].animal_food_2 = food2 / n;
		food2 -= food2 / n;
	}

}

void adult::buy_distribute_food12(int n)
{
	food1 = (money.dollars * 100 + money.cents) / 3 / 30;
	if (food1 > foodseller::food_list[1][0])food1 = foodseller::food_list[1][0];
	foodseller::food_list[1][0] -= food1;
	seller.today = seller.today + food1 * 30;
	seller.money = seller.money + food1 * 30;

	food2 = (money.dollars * 100 + money.cents) / 3 / 50;
	if (food2 > foodseller::food_list[2][0])food2 = foodseller::food_list[2][0];
	foodseller::food_list[2][0] -= food2;
	seller.today = seller.today + food2 * 50;
	seller.money = seller.money + food2 * 50;

	for (int i = 0; i < n; i++)
	{
		kids[i].animal_food_1 = food1 / n;
		food1 -= food1 / n;
		kids[i].animal_food_2 = food2 / n;
		food2 -= food2 / n;
	}
}

void adult::buy_distribute_food012(int n)
{
	food0 = (money.dollars * 100 + money.cents) / 3 / 20;
	if (food0 > foodseller::food_list[0][0])food0 = foodseller::food_list[0][0];
	foodseller::food_list[0][0] -= food0;
	seller.today = seller.today + food0 * 20;
	seller.money = seller.money + food0 * 20;

	food1 = (money.dollars * 100 + money.cents) / 3 / 30;
	if (food1 > foodseller::food_list[1][0])food1 = foodseller::food_list[1][0];
	foodseller::food_list[1][0] -= food1;
	seller.today = seller.today + food1 * 30;
	seller.money = seller.money + food1 * 30;

	food2 = (money.dollars * 100 + money.cents) / 3 / 50;
	if (food2 > foodseller::food_list[2][0])food2 = foodseller::food_list[2][0];
	foodseller::food_list[2][0] -= food2;
	seller.today = seller.today + food2 * 50;
	seller.money = seller.money + food2 * 50;

	for (int i = 0; i < n; i++)
	{
		kids[i].animal_food_0 = food0 / n;
		food0 -= food0 / n;
		kids[i].animal_food_1 = food1 / n;
		food1 -= food1 / n;
		kids[i].animal_food_2 = food2 / n;
		food2 -= food2 / n;
	}
}

void zoo_simulation()
{
	int day = 0, adu_total = 0, kid_total = 0;
	enclosure animal_enclosure[3];
	animal* a1[6] = { NULL };
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)a1[i] = new elephant;
		else if (i == 1 || i == 2)a1[i] = new giraffe;
		else a1[i] = new monkey;
	}

	while (seller.check_food_left() && keeper.check_clean_day())
	{
		day++;
		if (animal_enclosure[0].check_cur() && animal_enclosure[1].check_cur() && animal_enclosure[2].check_cur())//������
		{
			int today_tourist = 0;
			int num_adu = rand() % 21 + 20, num_kid;
			today_tourist += num_adu;
			adu_total += num_adu;
			person* tourist = new adult[40];
			adult* adu = dynamic_cast<adult*>(tourist);
			if (adu)
			{
				for (int i = 0; i < num_adu; i++)
				{
					num_kid = adu[i].kids.size();
					today_tourist += num_kid;
					kid_total += num_kid;

					adu[i].buy_id(num_kid);
					adu[i].buy_distribute_food012(num_kid);

					for (auto& kid : adu[i].kids)
					{
						kid.feed0();
						kid.feed1();
						kid.feed2();
					}

				}
				for (int i = 0; i < 3; i++)
				{
					animal_enclosure[i].add_dirt_level(animal_enclosure->food[i]);
				}
				for (int i = 0; i < 6; i++)
				{
					if (!i)
					{
						a1[i]->add_food(0);
						animal_enclosure->food[0] = 0;
					}
					else if (i == 1 || i == 2)
					{
						a1[i]->add_food(1);
						animal_enclosure->food[1] = 0;
					}
					else
					{
						a1[i]->add_food(2);
						animal_enclosure->food[2] = 0;
					}
				}

				for (int i = 0; i < 3; i++)
				{
					if (!animal_enclosure[i].check_dirt())continue;
					else if (animal_enclosure[i].check_dirt()) break;
				}

				cout << "�����ǵ�" << day << "�죬Χ�������ţ�����" << today_tourist << "���οͲι�,";
				seller.get_money_summary();
				seller.reset_income();

				if (tourist != NULL)
				{
					delete[]tourist;
					tourist = NULL;
					adu = NULL;
				}

				cout << "\n\n";

			}
			if (!seller.check_food_left() || !keeper.check_clean_day())break;
		}


		else if (!animal_enclosure[0].check_cur())//���󲻿�
		{
			keeper.clean();
			animal_enclosure[0].reset_cur();
			int today_tourist = 0;
			int num_adu = rand() % 21 + 20, num_kid;
			today_tourist += num_adu;
			adu_total += num_adu;
			person* tourist1 = new adult[40];
			adult* adu1 = dynamic_cast<adult*>(tourist1);
			if (adu1)
			{
				for (int i = 0; i < num_adu; i++)
				{
					num_kid = adu1[i].kids.size();
					today_tourist += num_kid + 1;
					kid_total += num_kid + 1;

					adu1[i].buy_id(num_kid);
					adu1[i].buy_distribute_food12(num_kid);

					for (auto& kid : adu1[i].kids)
					{
						kid.feed1();
						kid.feed2();
					}
				}
				for (int i = 1; i < 3; i++)
				{
					animal_enclosure[i].add_dirt_level(animal_enclosure->food[i]);
				}
				for (int i = 1; i < 6; i++)
				{

					if (i == 1 || i == 2)
					{
						a1[i]->add_food(1);
						animal_enclosure->food[1] = 0;
					}
					else
					{
						a1[i]->add_food(2);
						animal_enclosure->food[2] = 0;
					}
				}

				for (int i = 1; i < 3; i++)
				{
					if (!animal_enclosure[i].check_dirt())continue;
					else if (animal_enclosure[i].check_dirt()) break;
				}
				cout << "�����ǵ�" << day << "�죬����Χ�������ţ���Ҫ��������" << today_tourist << "���οͲι�,";
				seller.get_money_summary();
				seller.reset_income();

				if (tourist1 != NULL)
				{
					delete[]tourist1;
					tourist1 = NULL;
					adu1 = NULL;
				}

				
				cout << "\n\n";

			}
			

			if (!seller.check_food_left() || !keeper.check_clean_day())break;

		}

		else if (!animal_enclosure[1].check_cur())//����¹����
		{
			keeper.clean();
			animal_enclosure[1].reset_cur();
			int today_tourist = 0;
			int num_adu = rand() % 21 + 20, num_kid;
			today_tourist += num_adu;
			adu_total += num_adu;
			person* tourist2 = new adult[40];
			adult* adu2 = dynamic_cast<adult*>(tourist2);
			if (adu2)
			{
				for (int i = 0; i < num_adu; i++)
				{
					num_kid = adu2[i].kids.size();
					today_tourist += num_kid;
					kid_total += num_kid + 1;

					adu2[i].buy_id(num_kid);
					adu2[i].buy_distribute_food02(num_kid);

					for (auto& kid : adu2[i].kids)
					{
						kid.feed0();
						kid.feed2();
					}
				}

				for (int i = 0; i < 3; i++)
				{
					animal_enclosure[i].add_dirt_level(animal_enclosure->food[i]);
				}
				for (int i = 0; i < 6; i++)
				{
					if (!i)
					{
						a1[i]->add_food(0);
						animal_enclosure->food[0] = 0;
					}
					else if (i == 1 || i == 2)
					{
						continue;
					}
					else
					{
						a1[i]->add_food(2);
						animal_enclosure->food[2] = 0;
					}
				}
				for (int i = 0; i < 3; i++)
				{
					if (i == 1)continue;
					if (!animal_enclosure[i].check_dirt())continue;
					else if (animal_enclosure[i].check_dirt()) break;
				}

				cout << "�����ǵ�" << day << "�죬����¹Χ�������ţ���Ҫ��������" << today_tourist << "���οͲι�,";
				seller.get_money_summary();
				seller.reset_income();

				if (tourist2 != NULL)
				{
					delete[]tourist2;
					tourist2 = NULL;
					adu2 = NULL;
				}
				
				cout << "\n\n";

			}
			

			if (!seller.check_food_left() || !keeper.check_clean_day())break;

		}

		else if (!animal_enclosure[2].check_cur())//���Ӳ���
		{
			keeper.clean();
			animal_enclosure[2].reset_cur();
			int today_tourist = 0;
			int num_adu = rand() % 21 + 20, num_kid;
			today_tourist += num_adu;
			adu_total += num_adu;
			person* tourist3 = new adult[40];
			adult* adu3 = dynamic_cast<adult*>(tourist3);
			if (adu3)
			{
				for (int i = 0; i < num_adu; i++)
				{
					num_kid = adu3[i].kids.size();
					today_tourist += num_kid;
					kid_total += num_kid + 1;

					adu3[i].buy_id(num_kid);
					adu3[i].buy_distribute_food01(num_kid);
					for (auto& kid : adu3[i].kids)
					{
						kid.feed0();
						kid.feed1();
					}
				}

				for (int i = 0; i < 3; i++)
				{
					animal_enclosure[i].add_dirt_level(animal_enclosure->food[i]);
				}
				for (int i = 0; i < 3; i++)
				{
					if (!i)
					{
						a1[i]->add_food(0);
						animal_enclosure->food[0] = 0;
					}
					else if (i == 1 || i == 2)
					{
						a1[i]->add_food(1);
						animal_enclosure->food[1] = 0;
					}

				}
				for (int i = 0; i < 2; i++)
				{

					if (!animal_enclosure[i].check_dirt())continue;
					else if (animal_enclosure[i].check_dirt()) break;
				}

				cout << "�����ǵ�" << day << "�죬����Χ�������ţ���Ҫ��������" << today_tourist << "���οͲι�,";
				seller.get_money_summary();
				seller.reset_income();

				if (tourist3 != NULL)
				{
					delete[]tourist3;
					tourist3 = NULL;
					adu3 = NULL;
				}

				
				cout << "\n\n";

			}
			

			if (!seller.check_food_left() || !keeper.check_clean_day())break;

		}
	}

	cout << "����԰��������" << day << "�죬�����ο͹�" << adu_total << "�ˣ���ͯ�ο͹�" << kid_total << "��\n";
	seller.get_total();
	cout << "����Ա��������" << keeper.clean__day() << "��\n";
	cout << "����Χ�����ر���" << animal_enclosure[0].close__day() << "�죬����¹Χ�����ر���" << animal_enclosure[1].close__day() << "�죬����Χ�����ر���" << animal_enclosure[2].close__day() << "��\n";
	if (!keeper.check_clean_day())
	{
		cout << "����԰����Ա�ܹ������\n";
	}
	if (!seller.check_food_left())
	{
		if (!seller.food_list[0][0])cout << "���ҵĻ���������\n";
		else if (!seller.food_list[1][0])cout << "���ҵĺ��ܲ�������\n";
		else if (!seller.food_list[2][0])cout << "���ҵ��㽶������\n";
	}
	for (int i = 0; i < 6; i++)
	{
		delete a1[i];
		a1[i] = NULL;
	}
}

int main()
{
	srand(time(0));
	zoo_simulation();
}

