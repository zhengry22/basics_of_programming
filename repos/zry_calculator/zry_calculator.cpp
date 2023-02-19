#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<map>
#include<set>
#include<cassert>
using namespace std;

struct formulas{
	int num;
	char op;
};
vector<formulas> form;
string formula;
map<char, int> priority_signs = {{'+',1},{'-',1},{'*',2},{'/',2},{'^',3},{'(',-1},{')',-1}};

bool operand_judge(char a)
{
	auto search = priority_signs.find(a);
	if (search!= priority_signs.end())
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
		return b-a;
	case '*':
		return a * b;
	case '/':
		return b/a;
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

void two_numbers_calc(stack<int> &number, stack<char> &operands)
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

void input(string &formula, vector<formulas> &form)
{

	int length = formula.size();
	for (int i = 0; i < length; i++)
	{
		int tmp = 0;
		//state 1: formula[i] is a number:
		if (formula[i] - 48 >= 0 && formula[i] - 48 <= 9) {
			//if the number has multiple digits
			if (i >= 1 && formula[i - 1]-48 >= 0 && formula[i - 1]-48 <= 9) {
				tmp = form[form.size() - 1].num;
				form.pop_back();
				form.push_back({ tmp * 10 + formula[i] - 48 ,0});
			}
			//else, it either represents a single number or the higest digit of a number
			else {
				form.push_back({ formula[i] - 48 ,0});
			}
		}
		else if (operand_judge(formula[i]))
		{
			form.push_back({ 0,formula[i] });
		}
	}
}

int calc( vector<formulas> form)
{
	stack<int> number;
	stack<char> operands;
	int parentheses = 0; vector<formulas> form2; int length = form.size(), flag = 0;
	cout << "formula in form: ";
	for (auto e : form)
	{
		if (e.op == 0)
			cout << e.num;
		else
			cout << e.op;
	}
	cout << endl;
	for (int i = 0; i < length; i++) {
	//the op of numbers are 0 while the op of operands are not
		if (form[i].op == 0&&parentheses==0) {//is number
			number.push(form[i].num);
			//assert(!(number.top() == 4));
			cout << "push into number stack: "<<number.top() << endl;
			cout << "size of number is: " << number.size() << endl;
			//and observe whether it is computable, the first situation is that it is computable, than compute
			if (number.size() >= 2 && operands.size() >= 1 && (i==length-1||(priority_signs[operands.top()] >= priority_signs[form[i + 1].op] && operands.top() != '(' && form[i + 1].op != '(' && operands.top() != ')' && form[i + 1].op != ')')))
			{
				while (number.size() > 1 && !operands.empty()&& (i == length - 1||priority_signs[operands.top()]>= priority_signs[form[i + 1].op]))
				{
					two_numbers_calc(number, operands);
				}
				cout << "come up with result: " << number.top()<<endl;
			}
		}
		if(form[i].op!=0) {//考虑括号在后面的情况下，仍需将操作符装入operands2中，注意多种情况的考虑:如果没有括号就放入operands当中，否则放入operands2当中

			if (number.size() >= 2 && operands.size() >= 1 && (i == length - 1 || (priority_signs[operands.top()] >= priority_signs[form[i].op] && operands.top() != '(' && form[i].op != '(' && operands.top() != ')' && form[i].op != ')')))
			{	while(number.size() > 1 && !operands.empty()&& priority_signs[operands.top()] >= priority_signs[form[i].op]&&parentheses==0)
					two_numbers_calc(number, operands);

				cout << "come up with result: " << number.top() << endl;
			}
			if (parentheses == 0 && form[i].op != '(') {
				operands.push(form[i].op);
				cout << "push into operands stack: " << form[i].op << endl;
				cout << "size of operands is: " << operands.size() << endl;
			}
			if (form[i].op == '(')
			{
				parentheses++;
				flag=1;
			}
							
			if (form[i].op == ')')
				parentheses--;
		}
		if (parentheses >= 1&&!(parentheses==1&&form[i].op=='('))
		{
			form2.push_back(form[i]);
		}
		if (parentheses == 0 && flag==1)
		{
			flag = 0;
			number.push(calc(form2));
			cout << "push into number stack: " << number.top() << endl;
			form2.clear();
		}
	}
	//at last, there should be only one number in the number stack
	while (number.size() > 1 && !operands.empty()){
		two_numbers_calc(number, operands);
	}
	

	assert(number.size() == 1);
	if (number.size() == 1) {
		cout << number.top()<<endl;
		return number.top();
	}
	else { 
		cout << "input wrong!!!" << endl; return NULL; }
}

int main()
{
	cin >> formula;//first decimal
	//phase 1: push the formula into form: merge the digits that belong to the same number
	input(formula,form);
	//phase 2: calculation
	int result=calc(form);
	if (result != NULL)
		cout << result << endl;
	return 0;
}

