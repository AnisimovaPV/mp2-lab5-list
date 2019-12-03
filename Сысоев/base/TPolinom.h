#pragma once
#include "TList.h"
#include "TMonom.h"
#include <stdlib.h>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

class TPolinom
{
	TList<TMonom> monom;
	string polinom;
public:
	TPolinom(string _polinom = "")
	{
		polinom = _polinom;
		if (polinom != "")
			WriteMonom();
	}
	void WriteMonom();                             //запись мономов полинома
	bool Operation(char op);                       //проверка на знак
	bool XYZ(char xyz);                            //проверка на символ
	bool operator==(const TPolinom &p);
	bool operator!=(const TPolinom &p);
	TPolinom& operator=(TPolinom& p);
	TPolinom  operator+(TPolinom& p);
	TPolinom  operator-(TPolinom& p);
	int ResultInXYZ(int _x, int _y, int _z);       //результат в точке 
	string XYZ_Diff(char ch);                      //производная
	string Integration(char ch);                   //интеграл
	string GetPolin(TPolinom& p);                  //получение полинома как строки

	friend ostream & operator<<(ostream &os, TPolinom &pl);
	friend istream & operator>>(istream &is, TPolinom &pl);
};