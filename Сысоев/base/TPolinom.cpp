#include <iostream>
#include <string>
#include <cstdlib>
#include "TPolinom.h"
#include "TList.h"


void TPolinom::WriteMonom()
{
	monom.DeleteAllNodes();    //удаление всех мономов
	vector<string> monoms_str; //создание вектора мономов
	int i = 0;
	int len = polinom.length();
	while (i < len)
	{
		string Monom;
		do
		{
			Monom += polinom[i];
			i++;
		} while (!Operation(polinom[i]) && i != polinom.size());  

		monoms_str.push_back(Monom);
	}
	int SizeVectorMonom = monoms_str.size();
	for (int i = 0; i < SizeVectorMonom; i++)
	{
		string coeff;
		int j = 0;

		if (XYZ(monoms_str[i][j]))
		{
			coeff = "1";
		}
		else
		{
			while (!XYZ(monoms_str[i][j]) && j != monoms_str[i].size())
			{
			coeff += monoms_str[i][j];
			j++;
			}
		}
		
		if (j == monoms_str[i].size())
		{
			double db = atof(coeff.c_str());
			TMonom tmp(db, 0);
			monom.AddNodeInEnd(tmp);
		}
		else
		{
			int power = 0; 
			for (j; j < monoms_str[i].size(); j++)
			{
				if (monoms_str[i][j] == 'x')
				{
					if (j + 1 == monoms_str[i].size() || monoms_str[i][j + 1] != '^')
					{
						power += 100;
					}
					else
					{
						j = j + 2;
						power += (int)(monoms_str[i][j] - '0') * 100;
					}
				}
				else
					if (monoms_str[i][j] == 'y')
					{
						if (j + 1 == monoms_str[i].size() || monoms_str[i][j + 1] != '^')
						{
							power += 10;
						}
						else
						{
							j = j + 2;
							power += (int)(monoms_str[i][j] - '0') * 10;
						}
					}
					else
						if (monoms_str[i][j] == 'z')
						{
							if (j + 1 == monoms_str[i].size() || monoms_str[i][j + 1] != '^')
							{
								power += 1;
							}
							else
							{
								j = j + 2;
								power += (int)(monoms_str[i][j] - '0');
							}
						}
			}
			TMonom tmp(atof(coeff.c_str()), power, "");
			monom.AddNodeInEnd(tmp);
		}
	}
}
string TPolinom::GetPolin(TPolinom& p)
{
	string pl;
	for (auto it = p.monom.Begin(); it != p.monom.End(); ++it)
	{
		int deg = it->key.GetPow();
		if (it != p.monom.Begin() && it->key.GetCoeff() > 0)
			pl += "+";
		double coef = round(it->key.GetCoeff()*10.0) / 10.0;
		pl += to_string(coef);
		if ((int)(deg / 100) % 10 != 0)
		{
			if ((int)(deg / 100) % 10 == 1)
				pl += "x";
			else
				pl = pl + "x^" + to_string((int)(deg / 100) % 10);
		}
		if ((int)(deg / 10) % 10 != 0)
		{
			if ((int)(deg / 10) % 10 == 1)
				pl += "y";
			else
				pl = pl + "y^" + to_string((int)(deg / 10) % 10);
		}
		if (deg % 10 != 0)
		{
			if (deg % 10 == 1)
				pl += "z";
			else
				pl += "z^" + to_string(deg % 10);
		}
	}
	return pl;
}
bool TPolinom::Operation(char op)
{
	if (op == '+' || op == '-')
		return 1;
	else
		return 0;
}
bool TPolinom::XYZ(char xyz)
{
	if (xyz == 'x' || xyz == 'y' || xyz == 'z')
		return 1;
	else
		return 0;
}
string TPolinom::XYZ_Diff(char ch)
{
	monom.DeleteAllNodes();    //удаление всех мономов
	vector<string> monoms_str; //создание вектора мономов
	string newpolinom = "";
	string str;
	int i = 0;
	int stlb = 0;
	int len = polinom.length();
	while (i < len)
	{
		string Monom;
		do
		{
			Monom += polinom[i];
			i++;
		} while (!Operation(polinom[i]) && i != polinom.size());

		monoms_str.push_back(Monom);
	}
	int SizeVectorMonom = monoms_str.size();
	for (int i = 0; i < SizeVectorMonom; i++)
	{
		int j = 0;
		int flag = 0;
		for (int l = 0; l < monoms_str[i].size(); l++)
		{
			if (monoms_str[i][l] == ch)
			{
				flag = 1;
				stlb = l;
			}
		}
		if (flag)
		{
			string coeff = "";

			while (!XYZ(monoms_str[i][j]) && j != monoms_str[i].size())
			{
				if (monoms_str[i][j] == '+')
				{
					newpolinom += '+';
				}
				coeff += monoms_str[i][j];
				j++;
			}
			double Coefficient = atof(coeff.c_str());
			if (monoms_str[i][stlb + 1] == '^')
			{
				Coefficient *= (int)(monoms_str[i][stlb + 2] - '0');
				monoms_str[i][stlb + 2] -= 1;

				if (monoms_str[i][stlb + 2] == '1')
					monoms_str[i][stlb + 2] = monoms_str[i][stlb + 1] = ')';
			}
			else
				monoms_str[i][stlb] = ')';
			newpolinom += to_string(Coefficient);

			for (int t = j; t < monoms_str[i].size(); t++)
			{
				if (monoms_str[i][t] != ')')
				{
					newpolinom += monoms_str[i][t];

				}
			}
		}
	}
	return newpolinom;
}
string TPolinom::Integration(char ch)
{
	monom.DeleteAllNodes();    //удаление всех мономов
	vector<string> monoms_str; //создание вектора мономов
	string newpolinom = "";

	int i = 0;
	int len = polinom.length();
	while (i < len)
	{
		string Monom;
		do
		{
			Monom += polinom[i];
			i++;
		} while (!Operation(polinom[i]) && i != polinom.size());  

		monoms_str.push_back(Monom);
	}
	int SizeVectorMonom = monoms_str.size();

	for (int i = 0; i < SizeVectorMonom; i++)
	{
		int j = 0;
		int stlb = 0;
		int flag = 0;
		for (int l = 0; l < monoms_str[i].size(); l++)
		{
			if (monoms_str[i][l] == ch)
			{
				flag = 1;
				stlb = l;
			}
		}
		string coeff = "";
		if (i==0 && XYZ(monoms_str[i][j]))
		{
			coeff = "1";
		}
		else
		{
			if (i > 0 && XYZ(monoms_str[i][j + 1]))
			{
				if (monoms_str[i][j] == '+')
				{
					newpolinom += '+';
				}
				if (monoms_str[i][j] == '-')
				{
					newpolinom += '-';
				}
				coeff = "1";
				j++;
			}
			else
			{
				while (!XYZ(monoms_str[i][j]) && j != monoms_str[i].size())
				{
					if (monoms_str[i][j] == '+')
					{
						newpolinom += '+';
					}
					coeff += monoms_str[i][j];
					j++;
				}
			}
		}
		double Coefficient = atof(coeff.c_str());
		if (flag)
		{
			if ( monoms_str[i][stlb + 1] == '^')
			{
				monoms_str[i][stlb + 2] += 1;
				Coefficient /= (int)(monoms_str[i][stlb + 2] - '0');
				newpolinom += to_string(Coefficient);
				for (int t = j; t < monoms_str[i].size(); t++)
				{
					newpolinom += monoms_str[i][t];
				}
			}
			else
			{
				Coefficient /= 2;
				newpolinom += to_string(Coefficient);
				for (int t = j; t <= stlb; t++)
				{
					newpolinom = newpolinom + monoms_str[i][t];
				}
				newpolinom += "^2";
				stlb++;
				for (int t = stlb; t < monoms_str[i].size(); t++)
				{
					newpolinom += monoms_str[i][t];
				}
			}
		}
		else
		{
			if (j == monoms_str[i].size())
			{
				newpolinom = newpolinom + to_string(Coefficient) + ch;
			}
			else
			{
				if (ch == 'x')
				{
					newpolinom = newpolinom + to_string(Coefficient) + ch;
					for (int o = j; o < monoms_str[i].size(); o++)
					{
						newpolinom += monoms_str[i][o];
					}
				}
				else
				{
					if (ch == 'z')
					{
						newpolinom.pop_back();
						newpolinom = newpolinom + monoms_str[i] + ch;

					}
					else
					{
						flag = 0;
						for (int l = 0; l < monoms_str[i].size(); l++)
						{
							if (monoms_str[i][l] == 'z')
							{
								flag = 1;
							}
						}
						if (flag)
						{
							newpolinom += to_string(Coefficient);
							int p = j;
							while (monoms_str[i][p] != 'z')
							{
								newpolinom += monoms_str[i][p];
								p++;
							}
							newpolinom += ch;
							while (p != monoms_str[i].size())
							{
								newpolinom += monoms_str[i][p];
								p++;
							}
						}
						else
						{
							newpolinom.pop_back();
							newpolinom = newpolinom + monoms_str[i] + ch;
						}
					}
				}

			}
		}
	}
	return newpolinom;
}
double TPolinom::ResultInXYZ(int _x, int _y, int _z)
{
	double sum = 0;
	monom.DeleteAllNodes();    //удаление всех мономов
	vector<string> monoms_str; //создание вектора мономов
	int i = 0;
	while (i < polinom.length())
	{
		string Monom;
		do
		{
			Monom += polinom[i];
			i++;
		} while (!Operation(polinom[i]) && i != polinom.size());  
		monoms_str.push_back(Monom);
	}
	int SizeVectorMonom = monoms_str.size();
	for (int i = 0; i < SizeVectorMonom; i++)
	{
		string coeff;
		int j = 0;
		while (!XYZ(monoms_str[i][j]) && j != monoms_str[i].size())
		{
			coeff += monoms_str[i][j];
			j++;
		}
		if (j == monoms_str[i].size())
		{
			sum += atof(coeff.c_str());
		}
		else
		{
			double mult = 1;
			for (j; j < monoms_str[i].size(); j++)
			{
				if (monoms_str[i][j] == 'x')
				{

					if (j + 1 == monoms_str[i].size() || monoms_str[i][j + 1] != '^')
					{
						mult *= _x;

					}
					else
					{
						int pr = 1;
						for (int t = 0; t < (int)(monoms_str[i][j + 2] - '0'); t++)
						{
							pr *= _x;
						}
						mult *= pr;
						j = j + 2;
					}
				}
				else
					if (monoms_str[i][j] == 'y')
					{
						if (j + 1 == monoms_str[i].size() || monoms_str[i][j + 1] != '^')
						{
							mult *= _y;

						}
						else
						{
							int pr = 1;
							for (int t = 0; t < (int)(monoms_str[i][j + 2] - '0'); t++) 
							{
								pr *= _y;
							}
							mult *= pr;
							j = j + 2;
						}
					}
					else
						if (monoms_str[i][j] == 'z')
						{
							if (j + 1 == monoms_str[i].size() || monoms_str[i][j + 1] != '^')
							{
								mult *= _z;

							}
							else
							{
								int pr = 1;
								for (int t = 0; t < (int)(monoms_str[i][j + 2] - '0'); t++)
								{
									pr *= _z;
								}
								mult *= pr;
								j = j + 2;
							}
						}
			}
			double qw = 1;
			qw = (atof(coeff.c_str()))*mult;
			sum += ((atof(coeff.c_str()))*mult);

		}
	}
	return sum;
}
bool TPolinom::operator==(const TPolinom &p)
{
	if (monom == p.monom)
		return 1;
	else
		return 0;
}
bool TPolinom::operator!=(const TPolinom &p)
{
	return !(*this == p);
}
TPolinom& TPolinom::operator=(TPolinom& p)
{
	if (this != &p)
	{
		monom = p.monom;
		polinom = p.polinom;
		return *this;
	}
}
TPolinom TPolinom::operator+(TPolinom& p)
{
	TPolinom sum, polin1, polin2;
	TList<TMonom>::TIndicator it1,it2;

		polin1 = *this;
		polin2 = p;
		it1 = monom.Begin();
		it2 = p.monom.Begin();
	
	while (it1 != polin1.monom.End())
	{
		if (it2 == polin2.monom.End())
		{
			sum.monom.AddNodeInEnd(&it1);
			++it1;
		}
		else
			if (it1->key.GetPow() == it2->key.GetPow())
			{
				if ((it1->key.GetCoeff() + it2->key.GetCoeff()) != 0)
					sum.monom.AddNodeInEnd(&(it1)+&(it2));
				++it1; ++it2;
			}
			else if (it1->key.GetPow() > it2->key.GetPow())
			{
				sum.monom.AddNodeInEnd(&it1);
				++it1;
			}
			else
			{
				sum.monom.AddNodeInEnd(&it2);
				++it2;
			}
	}
	while (it2 != polin2.monom.End())
	{
		sum.monom.AddNodeInEnd(&it2);
		++it2;
	}
	return sum;
}
TPolinom TPolinom::operator-(TPolinom& p)
{
	TPolinom sub, polin1, polin2;
	TList<TMonom>::TIndicator it1, it2, it3;

	polin1 = *this;
	polin2 = p;
	it1 = monom.Begin();
	it2 = p.monom.Begin();

	for (it1; it1 != polin1.monom.End();)
	{
		if (it2 == polin2.monom.End())
		{
			sub.monom.AddNodeInEnd(&it1);
			++it1;
		}
		else
			if (it1->key.GetPow() == it2->key.GetPow())
			{
				if ((it1->key.GetCoeff() - it2->key.GetCoeff()) != 0)
					sub.monom.AddNodeInEnd(&(it1)-&(it2));
				++it1; ++it2;
			}
			else
				if (it1->key.GetPow() > it2->key.GetPow())
				{
					sub.monom.AddNodeInEnd(&it1);
					++it1;
				}
				else
				{
					TMonom mn(-it2->key.GetCoeff(), it2->key.GetPow());
					it3.Change(mn);
					sub.monom.AddNodeInEnd(&(it3));
					++it2;
				}
	}
	while (it2 != polin2.monom.End())
	{
		TMonom mn(-it2->key.GetCoeff(), it2->key.GetPow());
		it3.Change(mn);
		sub.monom.AddNodeInEnd(&(it3));
		++it2;
	}
	return sub;
}

ostream & operator<<(ostream & os, TPolinom & p)
{
	for (auto it = p.monom.Begin(); it != p.monom.End(); ++it)
	{
		int deg = it->key.GetPow();
		if ( it != p.monom.Begin() && it->key.GetCoeff() > 0.0)
		{
			os << "+";
			os << to_string(it->key.GetCoeff());
		}
		else
		{
			if (it == p.monom.Begin() ||it->key.GetCoeff() < 0.0)
				os << to_string(it->key.GetCoeff());
			else
				os << "+";
		}		
		if ((int)(deg / 100) % 10 != 0)
		{
			if ((int)(deg / 100) % 10 == 1)
				os << "x";
			else
				os << "x^" << (int)(deg / 100) % 10;
		}
		if ((int)(deg / 10) % 10 != 0)
		{
			if ((int)(deg / 10) % 10 == 1)
				os << "y";
			else
				os << "y^" << (int)(deg / 10) % 10;
		}
		if (deg % 10 != 0)
		{
			if (deg % 10 == 1)
				os << "z";
			else
				os << "z^" << deg % 10;
		}
	}
	return os;
}

istream & operator>>(istream & is, TPolinom & p)
{
	is >> p.polinom;
	p.WriteMonom();
	return is;
}
