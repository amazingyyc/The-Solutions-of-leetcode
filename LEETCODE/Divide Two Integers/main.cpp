#include <iostream>

using namespace std;

/************************************************************************/
/* Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.                                                                     */
/************************************************************************/

//dividend���� 
//divisor������
int divide(int dividend, int divisor) 
{
	//dividend divisorΪ�з��ŵ� int ���ܵ���Խ��
	if (0 == divisor)	return INT_MAX;

	//�ж� ����
	bool sign = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);

	//ʹ���޷��Ŵ洢 ��ֹԽ��
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
		//�з���
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