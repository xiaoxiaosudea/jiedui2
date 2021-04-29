#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
#include<cmath>
#include<string>
#include<stdio.h>
using namespace std;
#define random() (rand()%100000)

//��������
char create_symbol(int n)
{
	int n1, j;
	char symbol[1];
	if (n == 0)
	{
		n1 = 2;
	}
	else if (n == 1)
	{
		n1 = 4;
	}
	j = random() % n1;
	if (j == 0) symbol[0] = '+';
	else if (j == 1) symbol[0] = '-';
	else if (j == 2) symbol[0] = '*';
	else symbol[0] = '/';
	return symbol[0];
}
//������ת�����ַ�����
string int_string(int number)
{
	int temp = abs(number);
	char str[200];
	itoa(temp, str, 10);
	string str_ = str;
	return str_;
}
//����ʽת����һ���ַ���
string combination(string str1, string str2, char k)
{
	string equation;
	equation = str1 + k + str2;
	return equation;
}
//������
int main()
{
	srand((int)time(NULL));  //����ʱ������ ��ʹ�ó���ÿ�����еĽ������ͬ
	int num1, num2, count, n, change, amount = 0, shuchu, range, j, repeat = 0, bracket;
	string str_num1, str_num2, temp;
	cout << "���޳˳�����1 Y��0 N��" << endl;
	cin >> n;
	cout << "�Ƿ������ţ�1 Y��0 N��" << endl;
	cin >> bracket;
	cout << "��Ŀ�Ƿ����ļ��������1 Y��0 N��" << endl;
	cin >> shuchu;
	cout << "�������ַ�Χ��" << endl;
	cin >> range;
	cout << "�������������" << endl;
	cin >> amount;
	string Equation[1000];
	char symbol;
	ofstream fout;
	if (shuchu == 1)
	{
		fout.open("TEXT.txt");
		fout << amount << "���������������£�" << endl;
	}
	else
	{
		cout << amount << "���������������£�" << endl;
	}
	for (int i = 0; i < amount; i++)
	{
		num1 = random() % range + 1;
		num2 = random() % range + 1;
		count = random() % 9 + 2;
		symbol = create_symbol(n);
		str_num1 = int_string(num1);
		str_num2 = int_string(num2);
		Equation[i] = combination(str_num1, str_num2, symbol);
		if (count > 2)
		{
			for (count; count > 2; count--)
			{
				symbol = create_symbol(n);
				str_num1 = Equation[i];
				if (bracket == 1)
				{
					change = random() % 2;
					if (change == 0)
					{
						str_num1 = '(' + str_num1 + ')';
					}
				}
				symbol = create_symbol(n);
				num2 = random() % range + 1;
				str_num2 = int_string(num2);
				change = random() % 2;
				if (change == 0)
				{
					temp = str_num1;
					str_num1 = str_num2;
					str_num2 = temp;
				}
				Equation[i] = combination(str_num1, str_num2, symbol);
			}
		}
		//�ж��Ƿ��ظ�
		for (j = 0; j < i; j++)
		{
			if (Equation[j] == Equation[i])
			{
				i = i - 1;
				repeat = 1;
				break;
			}
		}
		if (repeat != 1)//�����ظ��������
		{
			if (shuchu == 1)
			{
				fout << Equation[i] << "=" << endl;
			}
			else
			{
				cout << Equation[i] << "=" << endl;
			}
		}

	}
	if (shuchu == 1)
	{
		fout.close();
	}
}