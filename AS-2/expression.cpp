#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

template <class t>
class Node
{
	t data;
	Node<t> *next;
	template <class T>
	friend class Stack;
};

struct Nvalues
{
	char ch;
	int value;
};

template <class t>
class Stack
{
	Node<t> *top;
	int count = 0;

public:
	Stack()
	{
		top = NULL;
	}

	void push(t info)
	{
		Node<t> *new1 = new Node<t>();
		new1->data = info;
		if (top == NULL)
		{
			top = new1;
		}
		else
		{
			new1->next = top;
			top = new1;
		}
	}

	void pop()
	{
		Node<t> *temp = top;
		if (!isEmpty())
		{
			top = temp->next;
			delete temp;
			temp->next = NULL;
			temp = NULL;
		}
	}
	void display()
	{
		if (top == NULL)
		{
			cout << "Stack Empty " << endl;
		}
		else
		{
			Node<t> *temp = top;
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	bool isEmpty()
	{
		return top == NULL;
	}
	t isTop()
	{
		return top->data;
	}
};

class Expression
{
	string infix;
	int countpo = 0;
	int countpre = 0;
	Stack<char> a;

public:
	Expression()
	{
		infix = "";
	}

	string input()
	{
		cout << "Enter the exp.: ";
		cin >> infix;
		return infix;
	}

	void setInfix(string infix)
	{
		this->infix = infix;
	}

	string getInfix()
	{
		return infix;
	}

	bool isOperator(char c)
	{
		if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isleftBracket(char c)
	{
		if (c == '(' || c == '[' || c == '{')
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	bool isrightBracket(char c)
	{
		if (c == ')' || c == ']' || c == '}')
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	string infixTOpostfix()
	{
		string postfix = "";
		int i = 0;
		while (i < infix.size())
		{
			if (isalpha(infix[i]) || isdigit(infix[i]))
			{
				postfix += infix[i];
				countpo++;
			}
			else if (isleftBracket(infix[i]))
			{
				a.push(infix[i]);
			}
			else if (isrightBracket(infix[i]))
			{
				while (!isleftBracket(a.isTop()) && !a.isEmpty())
				{
					postfix += a.isTop();
					a.pop();
				}
				if (isleftBracket(a.isTop()))
				{
					a.pop();
				}
			}
			else if (isOperator(infix[i]))
			{
				if (a.isEmpty())
				{
					a.push(infix[i]);
				}
				else
				{
					if (prec(infix[i]) > prec(a.isTop()))
					{
						a.push(infix[i]);
					}
					else if (prec(infix[i]) == prec(a.isTop()) && infix[i] == '^')
					{
						a.push(infix[i]);
					}
					else
					{
						while (!(a.isEmpty()) && (prec(infix[i]) <= prec(a.isTop())))
						{
							postfix += a.isTop();
							a.pop();
						}
						a.push(infix[i]);
					}
				}
			}
			i++;
		}

		while (!a.isEmpty())
		{

			postfix += a.isTop();
			a.pop();
		}
		return postfix;
	}

	string infixToPrefix()
	{
		string postfix = "";
		int i = 0;
		while (i < infix.size())
		{
			if (isalpha(infix[i]) || isdigit(infix[i]))
			{
				postfix += infix[i];
				countpre++;
			}
			else if (isleftBracket(infix[i]))
			{
				a.push(infix[i]);
			}
			else if (isrightBracket(infix[i]))
			{
				while (!isleftBracket(a.isTop()) && !a.isEmpty())
				{
					postfix += a.isTop();
					a.pop();
				}
				if (isleftBracket(a.isTop()))
				{
					a.pop();
				}
			}
			else if (isOperator(infix[i]))
			{
				if (a.isEmpty())
				{
					a.push(infix[i]);
				}
				else
				{
					if (prec(infix[i]) > prec(a.isTop()))
					{
						a.push(infix[i]);
					}
					else if (prec(infix[i]) == prec(a.isTop()) && infix[i] == '^')
					{
						a.push(infix[i]);
					}
					else
					{
						while (!(a.isEmpty()) && (prec(infix[i]) < prec(a.isTop())))
						{
							postfix += a.isTop();
							a.pop();
						}
						a.push(infix[i]);
					}
				}
			}
			i++;
		}

		while (!a.isEmpty())
		{

			postfix += a.isTop();
			a.pop();
		}
		return postfix;
	}

	int prec(char c)
	{
		if (c == '^')
			return 3;
		else if (c == '*' || c == '/')
			return 2;
		else if (c == '+' || c == '-')
			return 1;
		else
			return -1;
	}

	bool duplicateChar(Nvalues a[], char d)
	{

		int c = 0;
		for (int i = 0; i < countpo; i++)
		{

			if (a[i].ch == d)
			{
				c++;
			}
		}
		if (c == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	int Evaluatepostfix(string postfix)
	{
		int a = 0;
		Stack<int> b;
		int j = 0;
		int f = 0;
		int g;
		char c;
		Nvalues arr[countpo];
		while (j < postfix.size())
		{
			c = postfix[j];
			if (isalpha(c) || isdigit(c))
			{

				if (!duplicateChar(arr, c))
				{
					cout << "Enter the value of " << c << " :" << endl;
					cin >> g;
					Nvalues myp = {c, g};
					arr[f] = myp;
					b.push(g);

					f++;
				}
				else if (duplicateChar(arr, c))
				{
					int mn = 0;
					for (int w = 0; w < countpo; w++)
					{
						if (arr[w].ch == c)
						{
							mn = w;
						}
					}
					Nvalues myp = {c, arr[mn].value};
					arr[f] = myp;
					b.push(arr[mn].value);
					f++;
				}
			}
			else
			{
				if (isOperator(c))
				{
					int op1 = b.isTop();
					b.pop();
					int op2 = b.isTop();
					b.pop();
					a = eval(op1, op2, c);
					b.push(a);
				}
			}
			j++;
		}
		cout << "The postfix evaluation is: ";
		return a;
	}

	int eval(int op1, int op2, char operate)
	{
		switch (operate)
		{
		case '*':
			return op2 * op1;
		case '/':
			return op1 / op2;
		case '+':
			return op2 + op1;
		case '-':
			return op1 - op2;
		case '^':
			return pow(op1, op2);
		default:
			return 0;
		}
	}

	string toPrefix()
	{
		string e = getInfix();
		int c = e.size();
		string d = "";
		for (int i = c - 1; i >= 0; i--)
		{
			d += e[i];
		}
		for (int i = 0; i < d.size(); i++)
		{
			if (d[i] == '(')
			{
				d[i] = ')';
				i++;
			}
			else if (d[i] == ')')
			{
				d[i] = '(';
				i++;
			}
		}
		setInfix(d);
		d = "";
		string f = infixToPrefix();
		for (int i = f.size() - 1; i >= 0; i--)
		{
			d += f[i];
		}
		return d;
	}

	int Evaluateprefix(string prefix)
	{
		int a = 0;
		int d = 1;
		Stack<int> b;
		int j = prefix.size() - 1;
		int e = 0;
		char c;
		Nvalues arr[countpo];
		int h = 0;
		int g;
		int f = 0;
		while (j >= 0)
		{
			c = prefix[j];
			if (isalpha(c) || isdigit(c))
			{
				if (!duplicateChar(arr, c))
				{
					cout << "Enter the value of " << c << " :" << endl;
					cin >> g;
					Nvalues myp = {c, g};
					arr[f] = myp;
					b.push(g);

					f++;
				}
				else if (duplicateChar(arr, c))
				{
					int mn = 0;
					for (int w = 0; w < countpo; w++)
					{
						if (arr[w].ch == c)
						{
							mn = w;
						}
					}
					Nvalues myp = {c, arr[mn].value};
					arr[f] = myp;
					b.push(arr[mn].value);
					f++;
				}
			}
			else
			{
				if (isOperator(c))
				{
					int op1 = b.isTop();
					b.pop();
					int op2 = b.isTop();
					b.pop();
					a = eval(op1, op2, c);
					b.push(a);
				}
			}
			j--;
		}
		cout << "Prefix evaluation: ";
		return a;
	}
};

int main()
{
	int check = 1, c;
	Expression a;

	while (check == 1)
	{
		cout << "1)Press 1 for converting infix to postfix.\n2)Press 2 to evaluate postfix.\n3)To convert to prefix.\n4)To evaluate prefix.\n5)Exist\n";
		cin >> c;
		switch (c)
		{
		case 1:
			a.input();
			cout << "Postfix equation:- " << a.infixTOpostfix() << endl;
			break;
		case 2:
			cout << a.Evaluatepostfix(a.infixTOpostfix()) << endl;
			break;
		case 3:
			cout << "Prefix equation:- " << a.toPrefix() << endl;
			break;
		case 4:
			cout << a.Evaluateprefix(a.toPrefix()) << endl;
			break;
		case 5:
			check = 0;
			break;
		default:
			cout << "Error" << endl;
		}
	}

	return 0;
}
