
#include <iostream>
#include <locale>
#include <string>
#include <Windows.h>
#include <ctime>
#include < stdio.h >
#include <time.h>

using namespace std;

struct DateTime
{
	int day{};
	int mounth{};
	int year{};
	int hours{};
	int minutes{};
};
struct affairs
{
	string title{};
	int priority{};
	string description{};
	DateTime when{};
};

affairs Put()
{
	affairs addDelo{};
	cout << "Ввидите название дела " << endl;
	cin.ignore();
	getline(cin, addDelo.title);
	cout << "Ввидите приоретет вашего дела " << endl;
	cout << "1 - Высший приоритет, важнее ничего нет" << endl;
	cout << "2 - Важные дела, нужно сделать как можно раньше " << endl;
	cout << "3 - Желательные дела, сделаем хорошо не сделаем не страшно" << endl;
	cout << "4 - Не важные дела,качество нашей жизни не измениться если не будем их делать" << endl;
	cout << "5 - Развлечения" << endl;
	cin >> addDelo.priority;
	cout << "Ввидите описание дела " << endl;
	cin.ignore();
	getline(cin, addDelo.description);
	cout << "Ввидите дату в формате день/месяц/год" << endl;
	cin >> addDelo.when.day >> addDelo.when.mounth >> addDelo.when.year;
	cout << "Ввидите время в формате часы/минуты" << endl;
	cin >> addDelo.when.hours >> addDelo.when.minutes;
	return addDelo;
}




affairs* insertDela(affairs* massDela,int& numberDelmax,int& countDela)
{
	system("cls");
	countDela++;
	affairs* mussor = new affairs[numberDelmax + 1];
	for (int i = 0; i < numberDelmax; i++)
	{
		mussor->title[i] = massDela->title[i];
		mussor->priority[i] = massDela->priority[i];
		mussor->description[i] = massDela->description[i];
		mussor->when.day[i] = massDela->when.day[i];
		mussor->when.mounth[i] = massDela->when.mounth[i];
		mussor->when.year[i] = massDela->when.year[i];
		mussor->when.hours[i] = massDela->when.hours[i];
		mussor->when.minutes[i] = massDela->when.minutes[i];
		
	}
	massDela[countDela] = Put();
	return massDela;
}

affairs* deleteDela(affairs* massDela, int& countDela)
{
	system("cls");
	int NumberDela{};
	cout << "Ввидите номер дела которое хотите удалить" << endl;
	cin >> NumberDela;
	for (int i = NumberDela; i < countDela; ++i)
	{
		massDela[i] = massDela[i + 1];
	}
	--countDela;
	return massDela;
}

void seeDela(affairs* massDela, int countDela, tm timeNow)
{
	system("cls");
	bool flag = true;
	int count{};
	char yourchoose{};
	while (flag != false)
	{
		cout << "1)Дела на день" << endl;
		cout << "2)Дела на месяц" << endl;
		cout << "3)Назад в меню" << endl;
		cin >> yourchoose;
		switch (yourchoose)
		{
		case '1':
			for (int i = 0; i < countDela+1; i++)
			{
				if (massDela[i].when.day == timeNow.tm_mday && massDela[i].when.mounth-1 == timeNow.tm_mon)
				{
					count++;
					cout << endl;
					cout << "Дело под номером:" << i << endl;
					cout <<"Дело: " << massDela[i].title << endl;
					cout <<"Приоритет: " << massDela[i].priority << endl;
					cout <<"Описание: " << massDela[i].description << endl;
					if (massDela[i].when.day < 10)
						cout<<"Дата: " << '0' << massDela[i].when.day << '.';
					else
						cout << "Дата: " << massDela[i].when.day << '.';
					if (massDela[i].when.mounth < 10)
						cout << '0' << massDela[i].when.mounth << '.';
					else
						cout << massDela[i].when.mounth << '.';
					cout << massDela[i].when.year << endl;
					if (massDela[i].when.hours >= 10)
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << "Время:" << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << "Время:" << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
					else
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << '0' << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << '0' << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
				}
			}
			if (count == 0)
			{
				cout << "Дел на сегодня нет " << endl;
			}
			cout << endl << endl;
			break;
		case '2':
			for (int i = 0; i < countDela+1; i++)
			{
				if (massDela[i].when.mounth-1 == timeNow.tm_mon)
				{
					count++;
					cout << endl;
					cout << "Дело под номером:" << i << endl;
					cout <<"Дело: " << massDela[i].title << endl;
					cout <<"Приоритет: " << massDela[i].priority << endl;
					cout <<"Описание: " << massDela[i].description << endl;
					if (massDela[i].when.day < 10)
						cout<<"Дата: " << '0' << massDela[i].when.day << '.';
					else
						cout << "Дата: " << massDela[i].when.day << '.';
					if (massDela[i].when.mounth < 10)
						cout << '0' << massDela[i].when.mounth << '.';
					else
						cout << massDela[i].when.mounth << '.';
					cout << massDela[i].when.year << endl;
					if (massDela[i].when.hours >= 10)
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << "Время:" << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << "Время:" << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
					else
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << '0' << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << '0' << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
				}
			}
			if (count == 0)
			{
				cout << "Дел на этот месяц нет" << endl;
			}
			cout << endl << endl;
			break;
		case '3':
			flag = false;
			system("cls");
			break;
		}
	}
}
void findDela(affairs* massDela, int countDela)
{
	system("cls");
	char chooseFind{};
	affairs musor{};
	int count{};
	bool flag = true;
	char yourchoose{};
	while (flag != false)
	{
		count = 0;
		cout << "1)По названию " << endl;
		cout << "2)По приоритету" << endl;
		cout << "3)По описанию" << endl;
		cout << "4)По дате" << endl;
		cout << "5)По времени" << endl;
		cout << "6)Назад в меню" << endl;
		cin >> chooseFind;
		system("cls");
		switch (chooseFind)
		{
		case '1':
			cout << "Ввидите название дела которое ищете" << endl;
			cin.ignore();
			getline(cin, musor.title);
			cout << endl << endl;
			for (int i = 0; i < countDela + 1; i++)
			{
				if (massDela[i].title == musor.title)
				{
					count++;
					cout << "Дело под номером:" << i << endl;
					cout << "Дело: " << massDela[i].title << endl;
					cout << "Приоритет: " << massDela[i].priority << endl;
					cout << "Описание: " << massDela[i].description << endl;
					if (massDela[i].when.day < 10)
						cout << "Дата: " << '0' << massDela[i].when.day << '.';
					else
						cout << "Дата: " << massDela[i].when.day << '.';
					if (massDela[i].when.mounth < 10)
						cout << '0' << massDela[i].when.mounth << '.';
					else
						cout << massDela[i].when.mounth << '.';
					cout << massDela[i].when.year << endl;
					if (massDela[i].when.hours >= 10)
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << "Время:" << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << "Время:" << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
					else
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << '0' << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << '0' << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
				}
			}
				if (count == 0)
				{
					cout << "Дел с таким названием найденно не было" << endl;
				}
			break;
		case '2':
			cout << "Ввидите приоритет дела которое ищете" << endl;
			cin >> musor.priority;
			for (int i = 0; i < countDela + 1; i++)
			{
				if (massDela[i].priority == musor.priority)
				{
					count++;
					cout << "Дело под номером:" << i << endl;
					cout << "Дело: " << massDela[i].title << endl;
					cout << "Приоритет: " << massDela[i].priority << endl;
					cout << "Описание: " << massDela[i].description << endl;
					if (massDela[i].when.day < 10)
						cout << "Дата: " << '0' << massDela[i].when.day << '.';
					else
						cout << "Дата: " << massDela[i].when.day << '.';
					if (massDela[i].when.mounth < 10)
						cout << '0' << massDela[i].when.mounth << '.';
					else
						cout << massDela[i].when.mounth << '.';
					cout << massDela[i].when.year << endl;
					if (massDela[i].when.hours >= 10)
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << "Время:" << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << "Время:" << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
					else
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << '0' << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << '0' << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
				}
			}
				if (count == 0)
				{
					cout << "Дел с таким названием найденно не было" << endl;
				}

			break;
		case '3':
			cout << "Ввидите описание дела которое ищете" << endl;
			cin.ignore();
			getline(cin, musor.description);
			cout << endl << endl;
			for (int i = 0; i < countDela + 1; i++)
			{
				if (massDela[i].description == musor.description)
				{
					count++;
					cout << "Дело под номером:" << i << endl;
					cout << "Дело: " << massDela[i].title << endl;
					cout << "Приоритет: " << massDela[i].priority << endl;
					cout << "Описание: " << massDela[i].description << endl;
					if (massDela[i].when.day < 10)
						cout << "Дата: " << '0' << massDela[i].when.day << '.';
					else
						cout << "Дата: " << massDela[i].when.day << '.';
					if (massDela[i].when.mounth < 10)
						cout << '0' << massDela[i].when.mounth << '.';
					else
						cout << massDela[i].when.mounth << '.';
					cout << massDela[i].when.year << endl;
					if (massDela[i].when.hours >= 10)
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << "Время:" << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << "Время:" << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
					else
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << '0' << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << '0' << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
				}
			}
				if (count == 0)
				{
					cout << "Дел с таким названием найденно не было" << endl;
				}
			break;
		case '4':
			cout << "Ввидите дату(день,месяц,год) дела которое ищете" << endl;
			cin >> musor.when.day >> musor.when.mounth >> musor.when.year;
			for (int i = 0; i < countDela + 1; i++)
			{
				if (massDela[i].when.day == musor.when.day && massDela[i].when.mounth == musor.when.mounth && massDela[i].when.year == musor.when.year)
				{
					count++;
					cout << "Дело под номером:" << i << endl;
					cout << "Дело: " << massDela[i].title << endl;
					cout << "Приоритет: " << massDela[i].priority << endl;
					cout << "Описание: " << massDela[i].description << endl;
					if (massDela[i].when.day < 10)
						cout << "Дата: " << '0' << massDela[i].when.day << '.';
					else
						cout << "Дата: " << massDela[i].when.day << '.';
					if (massDela[i].when.mounth < 10)
						cout << '0' << massDela[i].when.mounth << '.';
					else
						cout << massDela[i].when.mounth << '.';
					cout << massDela[i].when.year << endl;
					if (massDela[i].when.hours >= 10)
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << "Время:" << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << "Время:" << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
					else
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << '0' << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << '0' << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
				}
			}
				if (count == 0)
				{
					cout << "Дел с таким названием найденно не было" << endl;
				}
			break;
		case '5':
			cout << "Ввидите время (часы/минуты) дела которое ищете" << endl;
			cin >> musor.when.hours;
			cin >> musor.when.minutes;
			for (int i = 0; i < countDela + 1; i++)
			{
				if (massDela[i].when.hours == musor.when.hours && massDela[i].when.minutes == musor.when.minutes)
				{
					count++;
					cout << "Дело под номером:" << i << endl;
					cout << "Дело: " << massDela[i].title << endl;
					cout << "Приоритет: " << massDela[i].priority << endl;
					cout << "Описание: " << massDela[i].description << endl;
					if (massDela[i].when.day < 10)
						cout << "Дата: " << '0' << massDela[i].when.day << '.';
					else
						cout << "Дата: " << massDela[i].when.day << '.';
					if (massDela[i].when.mounth < 10)
						cout << '0' << massDela[i].when.mounth << '.';
					else
						cout << massDela[i].when.mounth << '.';
					cout << massDela[i].when.year << endl;
					if (massDela[i].when.hours >= 10)
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << "Время:" << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << "Время:" << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
					else
					{
						if (massDela[i].when.minutes > 10)
						{
							cout << '0' << massDela[i].when.hours << ":" << massDela[i].when.minutes << endl;
						}
						else
						{
							cout << '0' << massDela[i].when.hours << ":" << '0' << massDela[i].when.minutes << endl;
						}
					}
				}
			}
				if (count == 0)
				{
					cout << "Дел с таким названием найденно не было" << endl;
				}

			break;
		case'6':
			flag = false;
			break;
		}
	}
}
 void editDela(affairs*& massDela)
{
	 system("cls");
	int NumberDela{};
	char choose{};
	bool flag = true;
	char yourchoose{};
	while (flag != false)
	{
		cout << "Выберите что именно вы хотите отредактировать" << endl;
		cout << "1) Название" << endl;
		cout << "2) Приоритет" << endl;
		cout << "3) Описание" << endl;
		cout << "4) День/месяц/год" << endl;
		cout << "5) Часы/минуты" << endl;
		cout << "6) Выйти " << endl;
		cin >> choose;
		if (choose == '6')
		{
			break;
		}
		cout << "Ввидите номер дела которое хотите отредактировать" << endl;
		cin >> NumberDela;
		switch (choose)
		{
		case '1':
			cout << "Ввидите новое название дела" << endl;
			cin.ignore();
			getline(cin, massDela[NumberDela].title);
			break;
		case '2':
			cout << "Выберите новый приоретет вашего дела " << endl;
			cout << "1 - Высший приоритет, важнее ничего нет" << endl;
			cout << "2 - Важные дела, нужно сделать как можно раньше " << endl;
			cout << "3 - Желательные дела, сделаем хорошо не сделаем не страшно" << endl;
			cout << "4 - Не важные дела,качество нашей жизни не измениться если не будем их делать" << endl;
			cout << "5 - Развлечения" << endl;
			cin >> massDela[NumberDela].priority;
			cout << massDela[NumberDela].priority;
			break;
		case '3':
			cout << "Ввидите новое описание дела " << endl;
			cin.ignore();
			getline(cin, massDela[NumberDela].description);
			break;
		case '4':
			cout << "4)Ввидите новый День/месяц/год" << endl;
			cin >> massDela[NumberDela].when.day >> massDela[NumberDela].when.mounth >> massDela[NumberDela].when.year;
			break;
		case '5':
			cout << "5)Ввидите новое время часы/минуты" << endl;
			cin >> massDela[NumberDela].when.hours >> massDela[NumberDela].when.minutes;
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL,"Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	tm timeNow;
	time_t lt = time(nullptr);
	localtime_s(&timeNow, &lt);
	affairs* massDela;
	int numberDelmax{100};
	int countDela{};
	massDela = new affairs[numberDelmax];
	bool exit{true};
	char choose{};
	while (exit != false)
	{
		cout << "1)Добавить дело" << endl;
		cout << "2)Удалить дело" << endl;
		cout << "3)Редактировать дело" << endl;
		cout << "4)Поиск дел" << endl;
		cout << "5)Отобразить дела" << endl;
		cout << "6)Выход" << endl;
		cin >> choose;
		switch (choose)
		{
		case '1':
			insertDela(massDela, numberDelmax,countDela);
			break;
		case '2':
			deleteDela(massDela, countDela);
			break;
		case '3':
			editDela(massDela);
			break;
		case '4':
			findDela(massDela,countDela);
			break;
		case '5':
			seeDela(massDela,countDela,timeNow);
			break;
		case '6':
			exit = false;
			break;
		}
	}
	delete[]massDela;
}
