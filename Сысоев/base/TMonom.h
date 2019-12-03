#pragma once
#include "TList.h"
#include "TPolinom.h"
#include <stdlib.h>
#include <string>
#include <vector>

class TMonom
{
	double coefficient;
	int pow;

public:
	TMonom(double _coeff = 0, int _pow = 0, string _monom = "")
	{
		coefficient = _coeff;
		pow = _pow;
	}
	TMonom operator+(const TMonom &monom);
	TMonom operator-(const TMonom &monom);
	TMonom operator*(const TMonom &monom);
	bool   operator==(const TMonom &monom);
	bool   operator!=(const TMonom &monom);
	bool   IsEqualPow(TMonom monom);
	double GetCoeff() { return coefficient; }   		  //получить коэффициент
	int    GetPow()   { return pow; }		      	      //получить степени   
};

inline TMonom TMonom::operator+(const TMonom & monom)
{
	if (pow == monom.pow)
	{
		TMonom res;
		res.coefficient = coefficient + monom.coefficient;
		res.pow = pow;
		return res;
	}
	else
		throw "Powers not equal";
}

inline TMonom TMonom::operator-(const TMonom & monom)
{
	if (pow == monom.pow)
	{
		TMonom res;
		res.coefficient = coefficient - monom.coefficient;
		res.pow = monom.pow;
		return res;
	}
	else
		throw "Powers not equal";
}

inline TMonom TMonom::operator*(const TMonom & monom)
{
	TMonom res;
	res.coefficient = coefficient * monom.coefficient;
	res.pow = pow+monom.pow;
	return res;
}

inline bool TMonom::operator==(const TMonom & monom)
{
	if ((coefficient == monom.coefficient) && (pow == monom.pow))
		return 1;
	else
		return 0;
}

inline bool TMonom::operator!=(const TMonom & monom)
{
	if ((coefficient != monom.coefficient) && (pow != monom.pow))
		return 1;
	else
		return 0;
	//return !(*this == monom);
}

inline bool TMonom::IsEqualPow(TMonom monom)
{
	if (GetPow() == monom.GetPow())
		return 1;
	else
		return 0;
}
