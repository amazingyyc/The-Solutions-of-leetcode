#include <iostream>

using namespace std;

/************************************************************************/
/* Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.                                                                     */
/************************************************************************/

//dividend除数 
//divisor被除数
int divide(int dividend, int divisor) 
{
	//dividend divisor为有符号的 int 可能导致越界
	if (0 == divisor)	return INT_MAX;

	//判断 符号
	bool sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);

	//使用无符号存储 防止越界
	unsigned int a = dividend > 0 ? dividend : -dividend;
	unsigned int b = divisor > 0 ? divisor : -divisor;

	unsigned int result = 0;

	while (a >= b)
	{
		unsigned int re = 1;
		unsigned int tb = b;

		while (a >= tb)
		{
			a -= tb;

			result += re;

			if (tb < INT_MAX >> 1)
			{
				tb += tb;
				re += re;
			}
		}
	}

	if (sign)
	{
		//有符号
		//if (result > INT_MAX + 1)
			//return INT_MAX;
		//else
			return -1 * result;
	}

	if (result > INT_MAX)
		return INT_MAX;

	return result;
}

int main()
{
	int a = -2147483647 - 1;
	int b = - 1;

	int result = divide(a, -1);

	cout << result << endl;

	return 1;
}