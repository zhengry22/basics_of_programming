#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<cassert>
#include<sstream>
using namespace std;

map<char, int> priority_signs = { {'+',1},{'-',1},{'*',2},{'/',2},{'^',3},{'(',4}};

enum states {
	START,
	NUM,
	OP,
	LEFT,
	RIGHT,
	ERROR
};

bool operand_judge(char a)
{
	auto search = priority_signs.find(a);
	if (search != priority_signs.end())
	{
		return 1;
	}
	else
		return 0;
}

int pop_calc(int a, int b, char c)//a=tmp1,b=tmp2
{
	switch (c)
	{
	case '+':
		return a + b;
	case '-':
		return b - a;
	case '*':
		return a * b;
	case '/':
		return b / a;
	case '^':
	{
		int sum = 1;
		for (int i = 1; i <= a; i++)
		{
			sum *= b;
		}
		return sum;
	}
	}
}

void two_numbers_calc(stack<int>& number, stack<char>& operands)
{

	int tmp1, tmp2, sgn;
	tmp1 = number.top();
	number.pop();
	tmp2 = number.top();
	number.pop();
	sgn = operands.top();
	operands.pop();
	number.push(pop_calc(tmp1, tmp2, sgn));

}



int calc(string formula)
{
	//all the variables
	stack<int> number;
	stack<char> operands;
	string formula2; int length = formula2.size(), flag = 0;
	string num_tmp;
	stringstream str_io; int calc_nums;


	/*cout << "formula in form: ";
	for (auto e : formula2)
	{
		cout << e;
	}
	cout << endl;*/
	
	for (auto e : formula)
	{
		if (e >= '0' && e <= '9') {//e is number
			flag = 1;
			num_tmp = num_tmp + e;
		}
		else {
			if (flag == 1) {
				str_io << num_tmp;
				str_io >> calc_nums;
				number.push(calc_nums);
				flag = 0;
				cout << "the number pushed: " << number.top() << endl;
				num_tmp = ""; str_io.clear(); str_io.str("");
			}
			if (priority_signs.contains(e)) {//end of number
				if (!(e == '(' || (!operands.empty() && operands.top() == '('))&&number.size() >= 2 && priority_signs[operands.top()] >= priority_signs[e])
				{//在识别逻辑运算符的时候，编译器是从语句左侧向右侧进行识别的，注意把需要先判断的放在前面
					if (number.size() > 1 && !operands.empty() && (priority_signs[operands.top()] >= priority_signs[e]))
					{
						two_numbers_calc(number, operands);
					}
					cout << "come up with result: " << number.top() << endl;


				}
				//is sign but is not parentheses
				operands.push(e);
				cout << "the operand pushed: " << operands.top() << endl;
			}

			else if (e == ')')
			{
				if (flag == 1) {
					str_io << num_tmp;
					str_io >> calc_nums;
					number.push(calc_nums);
					flag = 0;
					cout << "the number pushed: " << number.top() << endl;
					num_tmp = ""; str_io.clear(); str_io.str("");
				}
				while (operands.top() != '(')//number.size() > 1 && !operands.empty() && (priority_signs[operands.top()] >= priority_signs[e]))
				{
					two_numbers_calc(number, operands);
				}
				operands.pop();
				cout << "come up with result: " << number.top() << endl;
			}
		}
			
		
	}
	return number.top();
	
}

int main()
{
	string formula;
	getline(cin, formula);//input in formula
	formula = '(' + formula + ')';
	int result = calc(formula);
	cout << result << endl;
}