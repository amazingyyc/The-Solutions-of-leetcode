#include <iostream>
#include <stack>

using namespace std;

bool isValid(string const& s)
{
	int size = s.size();
	stack<char> sC;

	for (int i = 0; i < size; ++i)
	{
		char c = s[i];

		if (!(c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}'))
			return false;

		if (sC.empty())
		{
			sC.push(c);

			continue;;
		}
			
		char top = sC.top();

		if ((top == '(' && c == ')') || (top == '[' && c == ']') || (top == '{' && c == '}'))
			sC.pop();
		else
			sC.push(c);
	}
	
	return sC.empty();
}

int main()
{
	bool valid = isValid("[]{}[{()[}]");

	return 1;
}