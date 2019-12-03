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
	void WriteMonom();                             //������ ������� ��������
	bool Operation(char op);                       //�������� �� ����
	bool XYZ(char xyz);                            //�������� �� ������
	bool operator==(const TPolinom &p);
	bool operator!=(const TPolinom &p);
	TPolinom& operator=(TPolinom& p);
	TPolinom  operator+(TPolinom& p);
	TPolinom  operator-(TPolinom& p);
	int ResultInXYZ(int _x, int _y, int _z);       //��������� � ����� 
	string XYZ_Diff(char ch);                      //�����������
	string Integration(char ch);                   //��������
	string GetPolin(TPolinom& p);                  //��������� �������� ��� ������

	friend ostream & operator<<(ostream &os, TPolinom &pl);
	friend istream & operator>>(istream &is, TPolinom &pl);
};