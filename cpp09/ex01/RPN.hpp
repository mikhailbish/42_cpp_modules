#pragma once

#include <stack>
#include <cmath>
#include <iostream>

struct RPN {
	private:
		std::stack<double> _holder;
		void _processNumber(double);
		void _processSign(char);
		void _checkOverflow(double num);
		bool _lastIsSpace = true;
	public:
		void processChar(char c);
		double getResult();
};
