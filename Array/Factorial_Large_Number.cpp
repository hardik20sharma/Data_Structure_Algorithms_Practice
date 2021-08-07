#include<iostream>
using namespace std;
#define MAX 500

int multiply(int x, int result[], int result_size)
{
	int carry_over = 0;
	for (int i=0; i<result_size; i++)
	{
		int prod = result[i] * x + carry_over;
		result[i] = prod % 10;
		carry_over = prod/10;
	}

	while (carry_over)
	{
		result[result_size] = carry_over%10;
		carry_over /= 10;
		result_size++;
	}
	return result_size;
}

void factorial(int n) 
{
	int result[MAX];
	result[0] = 1;
	int result_size = 1;

	for (int x=2; x<=n; x++) 
		result_size = multiply(x, result, result_size); 

	for (int i=result_size-1; i>=0; i--)
		cout << result[i];
}

int main()
{
	factorial(100);
	cout << "\n";
}