
#include <iostream>

int add(int x, int y)
{
	return x + y;
}

int difference(int x, int y)
{
	return x - y;
}

int multiply(int x, int y)
{
	return x * y;
}

void execute_op(int x, int y, int (*operation)(int, int))
{
	std:: cout << operation(x, y) << std::endl;
}

int main()
{
	int (*operation[])(int, int) = {add, multiply, difference};
	std:: string op_strings[] = {"add" , "multiply", "difference"};
	std:: string choices;
	int x = 4;
	int y = 5;
	int flag = 0;
	std:: cout << "choose an operation?" << std:: endl;

	std:: cin >> choices;

	for (int i = 0; i < 3; i++)
	{
		if (op_strings[i] == choices)
		{
			flag = 1;
			std:: cout << operation[i](x, y) << std:: endl;
		}
	}
	if (!flag)
		std:: cout << "What do you mean !!?" << std:: endl;
	return 0;
}
//int main()
//{
//	execute_op(4, 5, multiply);
//}
//int main()
//{
//	int (*operation[])(int , int) = {add , difference, multiply};
//	std:: string operations[] = {"add", "difference", "multiply"};

//	std:: string mult = "multiply";
//	for (int i = 0; i < 3; i++)
//	{
//		if (operations[i] == mult)
//		{
//			std:: cout << operation[i](4, 5) << std::endl;
//		}
//	}
//}