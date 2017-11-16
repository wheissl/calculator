// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
	try
	{
		cout << "Please enter expression (we can handle +, -, *, and /): ";
		int lval = 0;
		int rval;
		char op;
		cin >> lval;               // read leftmost operand
		if (!lval) cerr << "no first operand";
		while (cin >> op) {        // read operator and right-hand operand repeatedly
			cin >> rval;
			if (!cin) cerr << "no second operand";
			switch (op) {
			case '+':
				lval += rval;    // add: lval = lval + rval
				break;
			case '-':
				lval -= rval;    // subtract: lval = lval - rval
				break;
			case '*':
				lval *= rval;    // multiply: lval = lval * rval
				break;
			case '/':
				lval /= rval;    // divide: lval = lval / rval
				break;
			default:             // not another operator: print result
				cout << "Result: " << lval << '\n';
				return 0;
			}
		}
		cerr << "bad expression";
	}
	catch (exception& e) {
		cerr << "error: " << e.what() << '\n';
		return 1;
	}
	catch (...) {
		cerr << "Oops: unknown exception!\n";
		return 2;
	}
}