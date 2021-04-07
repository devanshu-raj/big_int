#include "big_int.hpp"
using namespace std;


/** 1. Constructor Test **/

void constructor_test() {

	cout << "\n\nConstructor Test :\n\n";

	//a. Default constructor
	big_int def;

	//b. 'int' parameterized constructor
	big_int int_pos(1234);
	big_int int_neg(-1234);

	//c. 'long long' parameterized constructor
	big_int long_long_pos(999999999999);
	big_int long_long_neg(-999999999999);

	//d. 'string' parameterized constructor
	big_int str_pos1("12345");
	big_int str_neg1("-12345");
	big_int str_pos2("+000012345");
	big_int str_neg2("-0000012345");

	//Printing test results
	cout << "big_int() = " << big_int() << endl;
	cout << "default_constructor = " << def << endl;

	cout << "int_pos = " << int_pos << endl;
	cout << "int_neg = " << int_neg << endl;

	cout << "long_long_pos = " << long_long_pos << endl;
	cout << "long_long_neg = " << long_long_neg << endl;

	cout << "str_pos1 = " << str_pos1 << endl;
	cout << "str_neg1 = " << str_neg1 << endl;
	cout << "str_pos2 = " << str_pos2 << endl;
	cout << "str_neg2 = " << str_neg2 << endl;
}

/** 2. Addition Test **/
void addition_test() {

	cout << "\n\nAddition Test :\n\n";

	big_int x, y;

	//a. Postive + Positive
	x = 6, y = 4;
	cout << "6 + 4 = " << x + y << endl;

	//b. Negative + Positive
	x = -6, y = 4;
	cout << "-6 + 4 = " << x + y << endl;
	x = -4, y = 6;
	cout << "-4 + 6 = " << x + y << endl;

	//c. Postive + Negative
	x = 6, y = -4;
	cout << "6 + (-4) = " << x + y << endl;
	x = 4, y = -6;
	cout << "4 + (-6) = " << x + y << endl;

	//d. Negative + Negative
	x = -6, y = -4;
	cout << "(-6) + (-4) = " << x + y << endl;

	//e. Postive + Zero
	x = 19, y = 0;
	cout << "19 + 0 = " << x + y << endl;
	x = 0, y = 19;
	cout << "0 + 19 = " << x + y << endl;

	//f. Negative + Zero
	x = -19, y = 0;
	cout << "(-19) + 0 = " << x + y << endl;
	x = 0, y = -19;
	cout << "0 + (-19) = " << x + y << endl;

	//g. Large integers addition
	x = string("888888888888888888888888888888888888888888888888888888888");
	y = string("111111111111111111111111111111111111111111111111112222222");
	cout << endl << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x + y = " << x + y << endl;

	x = string("-888888888888888888888888888888888888888888888888888888888");
	y = string("111111111111111111111111111111111111111111111111112222222");
	cout << endl << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x + y = " << x + y << endl;

	x = string("888888888888888888888888888888888888888888888888888888888");
	y = string("-111111111111111111111111111111111111111111111111122222222");
	cout << endl << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x + y = " << x + y << endl;

	x = string("-888888888888888888888888888888888888888888888888888888888");
	y = string("-111111111111111111111111111111111111111111111111122222222");
	cout << endl << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x + y = " << x + y << endl;
}

/** 3. Subtraction Test **/
void subtraction_test() {

	cout << "\n\nSubtraction Test :\n\n";

	big_int x, y;

	//a. Postive - Positive
	x = 6, y = 4;
	cout << "6 - 4 = " << x - y << endl;
	x = 4, y = 6;
	cout << "4 - 6 = " << x - y << endl;

	//b. Negative - Positive
	x = -6, y = 4;
	cout << "-6 - 4 = " << x - y << endl;
	x = -4, y = 6;
	cout << "-4 - 6 = " << x - y << endl;

	//c. Postive - Negative
	x = 6, y = -4;
	cout << "6 - (-4) = " << x - y << endl;
	x = 4, y = -6;
	cout << "4 - (-6) = " << x - y << endl;

	//d. Negative - Negative
	x = -6, y = -4;
	cout << "(-6) - (-4) = " << x - y << endl;
	x = -4, y = -6;
	cout << "(-4) - (-6) = " << x - y << endl;

	//e. Postive - Zero
	x = 19, y = 0;
	cout << "19 - 0 = " << x - y << endl;

	//f. Negative - Zero
	x = -19, y = 0;
	cout << "(-19) - 0 = " << x - y << endl;

	//g. Zero - Positive
	x = 0, y = 19;
	cout << "0 - 19 = " << x - y << endl;

	//h. Zero - Negative
	x = 0, y = -19;
	cout << "0 - (-19) = " << x - y << endl;

	//i. Large integers subtraction
	x = string("888888888888888888888888888888888888888888888888888880000");
	y = string("111111111111111111111111111111111111111111111111112222222");
	cout << endl << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x - y = " << x - y << endl;

	x = string("-888888888888888888888888888888888888888888888888888880000");
	y = string("111111111111111111111111111111111111111111111111112222222");
	cout << endl << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x - y = " << x - y << endl;

	x = string("888888888888888888888888888888888888888888888888888880000");
	y = string("-111111111111111111111111111111111111111111111111122222222");
	cout << endl << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x - y = " << x - y << endl;

	x = string("-888888888888888888888888888888888888888888888888888880000");
	y = string("-111111111111111111111111111111111111111111111111122222222");
	cout << endl << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x - y = " << x - y << endl;
}

/** 4. Multiplication Test **/
void multiplication_test() {

	cout << "\n\nMultiplication Test :\n\n";

	big_int x, y;

	//a. Postive * Positive
	x = 6, y = 4;
	cout << "(6) * (4) = " << x * y << endl;

	//b. Negative * Positive
	x = -6, y = 4;
	cout << "(-6) * (4) = " << x * y << endl;

	//c. Postive * Negative
	x = 6, y = -4;
	cout << "(6) * (-4) = " << x * y << endl;

	//d. Negative * Negative
	x = -6, y = -4;
	cout << "(-6) * (-4) = " << x * y << endl;

	//e. Postive * Zero
	x = 19, y = 0;
	cout << "19 * 0 = " << x * y << endl;

	//f. Negative * Zero
	x = -19, y = 0;
	cout << "(-19) * 0 = " << x * y << endl;

	//g. Large integers multiplication
	x = string("888888888888888888888888888888888888888888888888888880000");
	y = string("111111111111111111111111111111111111111111111111112222222");
	cout << endl << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x * y = " << x * y << endl;

	x = string("-888888888888888888889999999999999999999999999999999999999");
	y = string("11116666666667777777777788888888888888889999999999999");
	cout << endl << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x * y = " << x * y << endl;
}

/** 5. Division Test **/
void division_test() {

	cout << "\n\nDivision Test :\n\n";

	big_int x, y;

	//a. Postive / Positive
	x = 9, y = 4;
	cout << "9 / 4 = " << x / y << endl;
	x = 4, y = 9;
	cout << "4 / 9 = " << x / y << endl;

	//b. Negative / Positive
	x = -9, y = 4;
	cout << "(-9) / 4 = " << x / y << endl;
	x = -4, y = 9;
	cout << "(-4) / 9 = " << x / y << endl;

	//c. Postive / Negative
	x = 9, y = -4;
	cout << "9 / (-4) = " << x / y << endl;
	x = 4, y = -9;
	cout << "4 / (-9) = " << x / y << endl;

	//d. Negative / Negative
	x = -9, y = -4;
	cout << "(-9) / (-4) = " << x / y << endl;
	x = -4, y = -9;
	cout << "(-4) / (-9) = " << x / y << endl;

	//e. Zero / Integer
	x = 0, y = 19;
	cout << "0 / 19 = " << x / y << endl;
	x = 0, y = -19;
	cout << "0 / (-19) = " << x / y << endl;

	//f. Integer / Zero
	// Will throw a runtime_error and program will be terminated

	//g. Large integers division
	x = string("888888888888888888888888888888888888888888888888888880000");
	y = string("111111111111111111111111111111111111111111111111112222222");
	cout << endl << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x / y = " << x / y << endl;

	x = string("888888888888888888888888888888888888888888888888887877867567578880000");
	y = string("-11111111111111111111111111111111111111111111111112222222254543444");
	cout << endl << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x / y = " << x / y << endl;
}

/** 6. Modulo Test **/
void modulo_test() {

	cout << "\n\nModulo Test :\n\n";
	cout << "WARNING : This method does not work for large negative integers\n\n";

	big_int x, y;

	//a. Integers in the 'Long Long' range
	x = 9, y = 4;
	cout << "9 % 4 = " << x % y << endl;
	x = -4, y = 9;
	cout << "(-4) % 9 = " << x % y << endl;
	x = 9, y = -4;
	cout << "9 % (-4) = " << x % y << endl;
	x = -4, y = -9;
	cout << "(-4) % (-9) = " << x % y << endl;
	x = string("-7866876");
	y = string("8698");
	cout << "(-7866876) % 8698 = " << x % y << endl;

	//b. Zero % Integer
	x = 0, y = 19;
	cout << "0 % 19 = " << x % y << endl;
	x = 0, y = -19;
	cout << "0 % (-19) = " << x % y << endl;

	//c. Integer % Zero
	// Will throw a runtime_error and program will be terminated

	//d. Large 'POSITIVE' integers modulo
	x = string("888888888888888888888888888888888888888888888888888880000");
	y = string("111111111111111111111111111111111111111111111111112222222");
	cout << endl << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "x % y = " << x % y << endl;
}

/** 7. Assignment Operator Test **/

void assignment_operator_test() {

	cout << "\n\nAssignment Operator Test :\n\n";

	//a. Initialising value using assignment operator
	big_int a = 2, b = 3;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	// big_int c = string("123456789");
	big_int c = 123456789;
	cout << "c = " << c << endl;

	//b. Arithmetic assignment operators
	a += b;
	cout << "after a += b, a = " << a << endl;
	a -= b;
	cout << "after a -= b, a = " << a << endl;
	c *= a;
	cout << "after c *= a, c = " << c << endl;
	c /= b;
	cout << "after c /= b, c = " << c << endl;
	c %= b;
	cout << "after c %= b, c = " << c << endl;

}

/** 8. Unary Operator Test **/

void unary_operator_test() {

	cout << "\n\nUnary Operator Test :\n\n";

	big_int a;
	cout << "initial value, a = " << a << endl;
	cout << "a++ = " << a++ << endl;
	cout << "a = " << a << endl;
	cout << "++a = " << ++a << endl;
	cout << "++(++a) = " << ++(++a) << endl;

	cout << "a-- = " << a-- << endl;
	cout << "a = " << a << endl;
	cout << "--a = " << --a << endl;
	cout << "--(--(--a)) = " << --(--(--a)) << endl;
}

/** 9. Relational Operator Test **/

void relational_operator_test() {

	cout << "\n\nRelational Operator Test :\n\n";

	big_int a = string("9999999999999999999999999999998888");
	big_int b = string("9999999999999999999999999999998888");
	big_int c = string("-9999999999999999999999999999988888");

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;

	cout << "(a == b) => " << boolalpha << (a == b) << endl;
	cout << "(b == c) => " << boolalpha << (b == c) << endl;
	cout << "(a == c) => " << boolalpha << (a == c) << endl;

	cout << "(a > b) => " << boolalpha << (a > b) << endl;
	cout << "(b > c) => " << boolalpha << (b > c) << endl;
	cout << "(a > c) => " << boolalpha << (a > c) << endl;

	cout << "(a < b) => " << boolalpha << (a < b) << endl;
	cout << "(b < c) => " << boolalpha << (b < c) << endl;
	cout << "(a < c) => " << boolalpha << (a < c) << endl;

	cout << "(a >= b) => " << boolalpha << (a >= b) << endl;
	cout << "(b >= c) => " << boolalpha << (b >= c) << endl;
	cout << "(a >= c) => " << boolalpha << (a >= c) << endl;

	cout << "(a <= b) => " << boolalpha << (a <= b) << endl;
	cout << "(b <= c) => " << boolalpha << (b <= c) << endl;
	cout << "(a <= c) => " << boolalpha << (a <= c) << endl;

	cout << "(a != b) => " << boolalpha << (a != b) << endl;
	cout << "(b != c) => " << boolalpha << (b != c) << endl;
	cout << "(a != c) => " << boolalpha << (a != c) << endl;
}

/** 10. Utility Methods Test **/

void utility_test() {

	cout << "\n\nUtility Test :\n\n";

	big_int n(0);
	cout << "n = " << n << endl;
	cout << "n.is_zero() = " << boolalpha << n.is_zero() << endl;
	n = "-9999999999999999999999999999999999999999999";
	cout << "n = " << n << endl;
	cout << "n.absolute() = " << n.absolute() << endl;
	cout << "n.digit_count() = " << n.digit_count() << endl;
	cout << "n.fits_in_ll() = " << boolalpha << n.fits_in_ll() << endl;
	cout << "n.multipy_10(5) = " << n.multiply_10(5) << endl;
	cout << "n.divide_10(30) = " << n.divide_10(30) << endl;
	n = n.divide_10(30);
	cout << "n.fits_in_ll() = " << boolalpha << n.fits_in_ll() << endl;
}

/** Running Tests **/

int main() {

	freopen("tests_output.txt", "w", stdout);

	constructor_test();

	addition_test();

	subtraction_test();

	multiplication_test();

	division_test();

	modulo_test();

	assignment_operator_test();

	unary_operator_test();

	relational_operator_test();

	utility_test();

	return 0;
}
