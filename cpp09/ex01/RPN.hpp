#pragma once

#include <stack>
//TODO: OCF
class RPN {
	std::stack<float> _holder;
	void processNumber(float);
	void processSign(char);
	bool _lastIsSpace = true;
	public:
		void processChar(char c);
		float getResult();
};
