#include <iostream>
#include <string>
using namespace std;

int SearchForMiddle(int from, int to)
{
	return (to + from) / 2;
}

int main()
{
	setlocale(0, "ru");
	int from; int to; int middle; int choice;
	while (true)
	{
		cout << "Введите промежуток" << endl;
		cout << "От "; cin >> from; 
		cout << "До "; cin >> to; 
		if (to > from)
		{
			break;
		}
		else
		{
			cout << "Промежуток нужно указывать от маленького к большому!" << endl;
		}
	}

	cout << "Загадайте число из этого промежутка." << endl;
	middle = SearchForMiddle(from, to);
	cout << "\tЭто число " << middle << "?" << endl;
	int a;
	for (int i = 0; true; i++)
	{
		cout << "\t1-yes\t2-more\t3-less\t4-start over\n>>> ";
		cin >> choice;
		switch (choice)
		{
			case 1:
			cout << "Вы загадали число " << middle << endl;
			break;

			case 2:
			from = middle; // закидываем в from знач middle
			middle = SearchForMiddle(from, to); //в middle сохраняется новое среднее значение 
			cout << "\tЭто число " << middle << "?" << endl;
			break;

			case 3:
			to = middle;
			middle = SearchForMiddle(from, to);
			cout << "\tЭто число " << middle << "?" << endl;
			break;

			case 4:
			cout << "Заново." << endl;
			break;

			default:
			cout << "Нет такого варианта. Попробуйте ещё раз." << endl;
			i = 0;
			break;
		}
		if (choice == 1)
		{
			a = i+1;
			break;
		}
		else if (choice == 4)
		{
			i = 0;
		}
	}

	cout << "Чтобы найти загаданное число понадобилось попыток: " << a << endl;
}

