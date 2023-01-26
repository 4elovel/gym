#include <iostream>
#include <vector>
#include "windows.h"
#include <conio.h>

using namespace std;

class Member
{
public:
	Member(int id, string name, int time = 0) : id(id), name(name), time(time)
	{

	}

	int id, time;
	string name;
};

class Gym
{
public:

	void create() {
		if (counter==10)
		{
			cout << "Gym is full you can`t create new member!!\n";
			return;
		}
		int id;
		string name;
		cout << "Write id ->\n";
		cin >> id;
		for (size_t i = 0; i < vec.size(); i++)
		{
			if (vec[i].id == id)
			{
				cout << "User with this id is alredy exist!\n";
				return;
			}
		}
		cout << "Write name ->\n";
		cin >> name;
		cout << "User is successfully created\n";
		vec.push_back(Member(id, name));
		counter++;
	}

	void del() {
		int id;
		cout << "Write id of user->\n";
		cin >> id;

		for (size_t i = 0; i < vec.size(); i++)
		{
			if (vec[i].id == id)
			{
				vec.erase(vec.begin() + i, vec.begin() + i + 1);
				cout << "User is successfully deleted\n";
				counter--;
				return;
			}
		}
		cout << "Gym has no members with this id\n";
	}

	void pay() {
		int id;
		int time;
		cout << "Write id of user->\n";
		cin >> id;

		for (size_t i = 0; i < vec.size(); i++)
		{
			if (vec[i].id == id)
			{
				cout << "Write amount of month that you want to buy->\n";
				cin >> time;
				vec[i].time += time;
				cout << "Transaction is successfull\n";
				return;
			}
		}
		cout << "Gym has no members with this id\n";
	}

	void info() {
		if (vec.size()==0)
		{
			cout << "Gym is empty!\n";
			return;
		}

		cout << "There are " << counter << " members in this gym\n";
		for (size_t i = 0; i < vec.size(); i++)
		{
			cout << i+1 << " member->\n";
			cout << "id: " << vec[i].id << "\t  payment: " << vec[i].time << " months" << "\tname: " << vec[i].name << endl;
		}
		cout << endl;
		cout << "PRESS ANY BUTTON TO CONTINUE\n";
		_getch();

	}

private:
	static int counter;
	vector <Member> vec;
};

int Gym::counter = 0;

void inline menu() {
	cout << "write \'create\' to create new member\n";
	cout << "write \'delete\' to delete member\n";
	cout << "write \'pay\' to pay for a membership\n";
	cout << "write \'info\' to print information\n";
	cout << "write \'exit\' to exit\n\n";
}

int main()
{
	Gym gym;
	string choice;
	while (true)
	{
		menu();
		cin >> choice;
		if (choice == "create")	gym.create();
		if (choice == "delete")	gym.del();
		if (choice == "pay")	gym.pay();
		if (choice == "info")	gym.info();
		if (choice == "exit")	break;
		cout << endl;
		Sleep(1000);
		system("CLS");
	}
}