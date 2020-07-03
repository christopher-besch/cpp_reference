# include <iostream>

void Log(const char* message);

int Multiply(int a, int b)
{
	Log("Multiply");
	int result = a * b;
	return result;
}
