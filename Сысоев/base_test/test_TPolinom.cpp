#include "TPolinom.cpp"
#include "TMonom.h"
#include <gtest.h>


//POLINOM
TEST(TPolinom, can_create_first_polinom)
{
	ASSERT_NO_THROW(TPolinom p("10x^5y^3z^2+4x^4y^5z^2-3x^3y^5+5x^2y^5z^6+3xy^5z^6-8xyz+10"));
}
TEST(TPolinom, can_create_second_polinom)
{
	ASSERT_NO_THROW(TPolinom p("2x^4y^5z^2-3x^3y^2z^8+7xyz^6+2z"));
}
TEST(TPolinom, can_create_third_polinom)
{
	ASSERT_NO_THROW(TPolinom p("4x^7y^3+7x^4y^5z^2-3x^3y^5+8x-14"));
}
TEST(TPolinom, can_compare_equal_polinoms_experement_1)
{
	TPolinom p1("4x^7y^3+7x^4y^5z^2-3x^3y^5+8x-14");
	TPolinom p2("4x^7y^3+7x^4y^5z^2-3x^3y^5+8x-14");
	EXPECT_TRUE(p1 == p2);
}
TEST(TPolinom, can_compare_equal_polinoms_experement_2)
{
	TPolinom p1("5x^2y^5z^6+3xy^5z^6-8xyz+10");
	TPolinom p2("5x^2y^5z^6+3xy^5z^6-8xyz+10");
	EXPECT_TRUE(p1 == p2);
}
TEST(TPolinom, can_compare_different_polinoms_experement_1)
{
	TPolinom p1("4x^7y^3+7x^4y^5z^2-3x^3y^5+8x-14");
	TPolinom p2("10x^5y^3z^2+4x^4y^5z^2-3x^3y^5");
	EXPECT_TRUE(p1 != p2);
}
TEST(TPolinom, can_compare_different_polinoms_experement_2)
{
	TPolinom p1("3x^3y^5+8x-14");
	TPolinom p2("8x^5y^3z^2-14x^4y^5z^2");
	EXPECT_TRUE(p1 != p2);
}
TEST(TPolinom, can_assign_polinoms_experement_1)
{
	TPolinom p1("4x^7y^3+7x^4y^5z^2");
	TPolinom p2("-3x^3y^5+8x-14");
	ASSERT_NO_THROW(p2 = p1);
}
TEST(TPolinom, can_assign_polinoms_experement_2)
{
	TPolinom p1("3xy^5z^6-8xyz+10");
	TPolinom p2("10x^5y^3z^2+4x^4y^5z^2");
	ASSERT_NO_THROW(p2 = p1);
}
TEST(TPolinom, result_polinom_in_point_experement_1)
{
	TPolinom p1("2x^4y^2z+7xyz+2z");
	int res = p1.ResultInXYZ(1, 1, 2);
	EXPECT_TRUE(22 == res);
}
TEST(TPolinom, result_polinom_in_point_experement_2)
{
	TPolinom p1("4x^7y^3+7x^4y^5z^2");
	int res = p1.ResultInXYZ(1, 1, 2);
	EXPECT_TRUE(32 == res);
}
TEST(TPolinom, can_get_derivative_polinom_to_x_experement_1)
{
	TPolinom p1("5x^2y^5z^6+3xy^5z^6");
	string res = p1.XYZ_Diff('x');
	EXPECT_TRUE("10.000000xy^5z^6+3.000000y^5z^6" == res);
}
TEST(TPolinom, can_get_derivative_polinom_to_x_experement_2)
{
	TPolinom p1("7x^4y^5z^2-3x^3y^5z^3+8x-14z");
	string res = p1.XYZ_Diff('x');
	EXPECT_TRUE("28.000000x^3y^5z^2-9.000000x^2y^5z^3+8.000000" == res);
}
TEST(TPolinom, can_get_derivative_polinom_to_y_experement_1)
{
	TPolinom p1("5x^2y^5z^6+3xy^5z^6");
	string res = p1.XYZ_Diff('y');
	EXPECT_TRUE("25.000000x^2y^4z^6+15.000000xy^4z^6" == res);
}
TEST(TPolinom, can_get_derivative_polinom_to_y_experement_2)
{
	TPolinom p1("7x^4y^5z^2-3x^3y^5z^3+8x-14z");
	string res = p1.XYZ_Diff('y');
	EXPECT_TRUE("35.000000x^4y^4z^2-15.000000x^3y^4z^3" == res);
}
TEST(TPolinom, can_get_derivative_polinom_to_z_experement_1)
{
	TPolinom p1("5x^2y^5z^6+3xy^5z^6");
	string res = p1.XYZ_Diff('z');
	EXPECT_TRUE("30.000000x^2y^5z^5+18.000000xy^5z^5" == res);
}
TEST(TPolinom, can_get_derivative_polinom_to_z_experement_2)
{
	TPolinom p1("7x^4y^5z^2-3x^3y^5z^3+8x-14z");
	string res = p1.XYZ_Diff('z');
	EXPECT_TRUE("14.000000x^4y^5z-9.000000x^3y^5z^2-14.000000" == res);
}
TEST(TPolinom, can_get_integral_polinom_to_x_experement_1)
{
	TPolinom p1("2x^4y^5z^2+7xyz^6+3xy+10");
	string res = p1.Integration('x');
	EXPECT_TRUE("0.400000x^5y^5z^2+3.500000x^2yz^6+1.500000x^2y+10.000000x" == res);
}
TEST(TPolinom, can_get_integral_polinom_to_x_experement_2)
{
	TPolinom p1("7x^4y^5z^2-3x^3y^5+8z-14");
	string res = p1.Integration('x');
	EXPECT_TRUE("1.400000x^5y^5z^2-0.750000x^4y^5+8.000000xz-14.000000x" == res);
}
TEST(TPolinom, can_get_integral_polinom_to_y_experement_1)
{
	TPolinom p1("2x^4y^5z^2+7xyz^6+3xy+10");
	string res = p1.Integration('y');
	EXPECT_TRUE("0.333333x^4y^6z^2+3.500000xy^2z^6+1.500000xy^2+10.000000y" == res);
}
TEST(TPolinom, can_get_integral_polinom_to_y_experement_2)
{
	TPolinom p1("7x^4y^5z^2-3x^3y^5+8z-14");
	string res = p1.Integration('y');
	EXPECT_TRUE("1.166667x^4y^6z^2-0.500000x^3y^6+8.000000yz-14.000000y" == res);
}
TEST(TPolinom, can_get_integral_polinom_to_z_experement_1)
{
	TPolinom p1("2x^4y^5z^2+7xyz^6+3xy+10");
	string res = p1.Integration('z');
	EXPECT_TRUE("0.666667x^4y^5z^3+1.000000xyz^7+3xyz+10.000000z" == res);
}
TEST(TPolinom, can_get_integral_polinom_to_z_experement_2)
{
	TPolinom p1("7x^4y^5z^2-3x^3y^5+8z-14");
	string res = p1.Integration('z');
	EXPECT_TRUE("2.333333x^4y^5z^-3x^3y^5z+4.000000z^2-14.000000z" == res);
}
TEST(TPolinom, can_check_operation_in_polinom)
{
	TPolinom p1("7x^4y^5z^2-3x^3y^5+8x-14");
	TPolinom p2;
	string p = p2.GetPolin(p1);
	EXPECT_EQ(1, p1.Operation(p[17]));
}
TEST(TPolinom, can_check_symbol_in_polinom)
{
	TPolinom p1("7x^4y^5z^2-3x^3y^5+8x-14");
	TPolinom p2;
	string p = p2.GetPolin(p1);
	EXPECT_EQ(1, p1.XYZ(p[8]));
}
TEST(TPolinom, addition_different_polinoms_experement_1)
{
	TPolinom p1("10x^5y^3z^2+4x^4y^5z^2-3x^3y^5+5x^2y^5z^6+3xy^5z^6-8xyz+10");
	TPolinom p2("2x^4y^5z^2-3x^3y^2z^8+7xyz^6+2z");
	TPolinom p3;
	EXPECT_EQ("10.000000x^5y^3z^2+6.000000x^4y^5z^2-3.000000x^3y^5-3.000000x^3y^2z^8+5.000000x^2y^5z^6+3.000000xy^5z^6+7.000000xyz^6-8.000000xyz+2.000000z+10.000000", p3.GetPolin(p1 + p2));
}
TEST(TPolinom, addition_different_polinoms_experement_2)
{
	TPolinom p1("10x^5y^3z^2+4x^4y^5z^2-3x^3y^5+5x^2y^5z^6+3xy^5z^6-8xyz+10");
	TPolinom p2("-4x^4y^5z^2+3x^3y^5+5x^2y^5z+8xyz-10");
	TPolinom p3;
	EXPECT_EQ("10.000000x^5y^3z^2+5.000000x^2y^5z^6+5.000000x^2y^5z+3.000000xy^5z^6", p3.GetPolin(p1 + p2));
}
TEST(TPolinom, subtraction_different_polinoms_experement_1)
{
	TPolinom p1("10x^5y^3z^2+4x^4y^5z^2-3x^3y^5+5x^2y^5z^6+3xy^5z^6-8xyz+10");
	TPolinom p2("2x^4y^5z^2-3x^3y^2z^8+7xyz^6+2z");
	TPolinom p3;
	EXPECT_EQ("10.000000x^5y^3z^2+2.000000x^4y^5z^2-3.000000x^3y^5+3.000000x^3y^2z^8+5.000000x^2y^5z^6+3.000000xy^5z^6-7.000000xyz^6-8.000000xyz-2.000000z+10.000000", p3.GetPolin(p1 - p2));
}
TEST(TPolinom, subtraction_different_polinoms_experement_2)
{
	TPolinom p1("10x^5y^3z^2+4x^4y^5z^2-3x^3y^5+5x^2y^5z^6+3xy^5z^6-8xyz+10");
	TPolinom p2("-4x^4y^5z^2+3x^3y^5+5x^2y^5z+8xyz-10");
	TPolinom p3;
	EXPECT_EQ("10.000000x^5y^3z^2+8.000000x^4y^5z^2-6.000000x^3y^5+5.000000x^2y^5z^6-5.000000x^2y^5z+3.000000xy^5z^6-16.000000xyz+20.000000", p3.GetPolin(p1 - p2));
}

//MONOM
TEST(TMonom, can_get_coefficient_monom_exp_1)
{
	TMonom m(5.0, 123);
	EXPECT_TRUE(5.000000 == m.GetCoeff());
}
TEST(TMonom, can_get_coefficient_monom_exp_2)
{
	TMonom m(5.0, 123);
	TMonom m1;
	m1 = m;
	EXPECT_TRUE(5.0 == m1.GetCoeff());
}
TEST(TMonom, can_get_power_monom_exp_1)
{
	TMonom m(5.0, 123);
	EXPECT_TRUE(123 == m.GetPow());
}
TEST(TMonom, can_get_power_monom_exp_2)
{
	TMonom m(5.0, 123);
	TMonom m1;
	m1 = m;
	EXPECT_TRUE(123 == m1.GetPow());
}
TEST(TMonom, can_assign_monom_check_power)
{
	TMonom m(15.0, 547);
	TMonom m1;
	m1 = m;
	EXPECT_TRUE(547 == m1.GetPow());
}
TEST(TMonom, can_check_different_monom)
{
	TMonom m(15.0, 547);
	TMonom m1(27.3, 987);
	EXPECT_TRUE(m1 != m);
}
TEST(TMonom, can_check_equal_monom)
{
	TMonom m(15.0, 547);
	TMonom m1(15.0, 547);
	EXPECT_TRUE(m1 == m);
}
TEST(TMonom, can_check_equal_power)
{
	TMonom m(15.0, 547);
	TMonom m1(15.0, 123);
	int tmp = m1.IsEqualPow(m);
	EXPECT_NE(1, tmp);
}