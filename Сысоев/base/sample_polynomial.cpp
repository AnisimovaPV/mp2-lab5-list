#include <iostream>
#include <string>
#include "TPolinom.h"
#include "TList.h"


using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");

	string str1, str2;
	cout << "Введите первый полином ";
	cin >> str1;
	TPolinom p(str1);
	cout << "Введите второй полином ";
	cin >> str2;
	TPolinom p1(str2);
	TPolinom p3("");
	TPolinom p4("");
	int flag = 1;
	while (flag)
	{
		cout << " Меню:                                 " << endl
			<< "1.Сложение                              " << endl
			<< "2.Вычитание                             " << endl
			<< "3.Сравнение                             " << endl
			<< "4.Первый полином в заданной точке       " << endl
			<< "5.Второй полином в заданной точке       " << endl
			<< "6.Производная                           " << endl
			<< "7.Интеграл                              " << endl
			<< "0.Выход                                 " << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << p + p1 << endl << endl;  
			break;
		case 2:
			cout << p - p1 << endl << endl;
			break;
		case 3:
			if (p == p1)
				cout << "Равны   " << endl << endl;
			else
				cout << "Не равны   " << endl << endl;
			break;
		case 4:
			int x, y, z;
			cin >> x >> y >> z;
			cout << "Итог=  " << p.ResultInXYZ(x, y, z) << endl << endl;
			break;
		case 5:
			int x1, y1, z1;
			cin >> x1 >> y1 >> z1;
			cout << "Итог=  " << p1.ResultInXYZ(x1, y1, z1) << endl << endl;
			break;
		case 6:
			cout << "Производную 1 или 2 полинома ? " << endl;
			int k;
			cin >> k;
			if (k == 1)
				p3 = p;
			if (k == 2)
				p3 = p1;
			cout << "1. По Х " << endl
				 << "2. По Y " << endl
			     << "3. По Z " << endl;
			int xyz;
			cin >> xyz;
			switch (xyz)
			{
			case 1:
				cout << "Производная по х= " << p3.XYZ_Diff('x') << endl << endl;
				break;
			case 2:
				cout << "Производная по у= " << p3.XYZ_Diff('y') << endl << endl;
				break;
			case 3:
				cout << "Производная по z= " << p3.XYZ_Diff('z') << endl << endl;
				break;
			default:
				cout << "Такого номера нет " << endl << endl;
				break;
			}
			break;
		case 7:
			cout << "Интеграл 1 или 2 полинома ? " << endl; 
			int k1;
			cin >> k1;
			if (k1 == 1)
				p3 = p;
			if (k1 == 2)
				p3 = p1;
			cout << "1. По Х " << endl
				 << "2. По Y " << endl
			   	 << "3. По Z " << endl;
			int integ;
			cin >> integ;
			switch (integ)
			{
			case 1:
				cout << "Интеграл по x= " << p3.Integration('x') << endl << endl;
				break;
			case 2:
				cout << "Интеграл по y= " << p3.Integration('y') << endl << endl;
				break;
			case 3:
				cout << "Интеграл по z= " << p3.Integration('z') << endl << endl;
				break;
			default:
				cout << "Такого номера нет " << endl << endl;
				break;
			}
			break;
		case 0:
			flag = 0;;
			break;
		default:
			cout << "Такого номера нет " << endl << endl;
			break;
		}
	}
	system("pause");
}