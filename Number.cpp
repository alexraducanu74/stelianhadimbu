#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"
#include <iostream>
int atoi1(char* sir)
{
	int num = 0;
	for (int i = 0; i < strlen(sir); i++)
		num = num * 10 + (sir[i] - '0');
	return num;
}
Number::Number(const char* value, int base)
{
	if (base >= 2 && base <= 16)
	{
		nr = new char[strlen(value) + 1];
		strcpy(nr, value);
		nr[strlen(nr)] = '\0';
		this->base = base;
		digits = strlen(nr);
	}
	else return;
}
Number::Number(const Number& obj)
{
	nr = new char[obj.digits + 1];
	strcpy(nr, obj.nr);
	base = obj.base;
	digits = obj.digits;
}
Number::Number(const int value)
{
	base = 10;
	int num = value;
	int tmp = value, n = 0;
	while (tmp)
	{
		n++;
		tmp /= 10;
	}
	digits = n;
	nr = new char[n + 1];
	for (int i = n - 1; i >= 0; i--)
	{
		nr[i] = num % 10 + '0';
		num /= 10;
	}
	nr[n] = '\0';
}
Number::Number(Number&& obj)
{
	nr = obj.nr;
	base = obj.base;
	digits = obj.digits;

	obj.nr = nullptr;
	obj.base = 0;
	obj.digits = 0;
}
Number::~Number()
{
	delete[] nr;
}
Number& Number::operator = (int value)
{
	int num = value;
	int n = 0;
	while (num)
	{
		num /= base;
		n++;
	}
	char* aux = new char[n + 1];
	int i = n - 1;
	while (value > 0)
	{
		int digit = value % base;
		if (digit > 9 && digit < 16)
			aux[i--] = 'A' + digit - 10;
		else aux[i--] = digit + '0';
		value /= base;
	}
	digits = n;
	delete[] nr;
	nr = aux;
	nr[n] = '\0';
	return (*this);
}
Number& Number::operator = (const char* sir)
{
	int i = 0, n = 0;
	while (sir[i])
	{
		n++;
		i++;
	}
	char* aux = new char[n + 1];
	strcpy(aux, sir);
	aux[n] = '\0';
	Number number(aux, 10);
	number.SwitchBase(base);
	delete[] nr;
	nr = new char[n + 1];
	digits = number.digits;
	strcpy(nr, number.nr);
	nr[n] = '\0';
	return (*this);
}
Number& Number::operator = (Number&& obj)
{
	if (this != &obj)
	{
		delete[] this->nr;

		nr = obj.nr;
		digits = obj.digits;
		base = obj.base;

		obj.nr = nullptr;
		obj.digits = 0;
		obj.base = 0;
	}
	return (*this);
}
Number& Number::operator += (const Number& obj)
{
	Number tmp1 = *this, tmp2=obj;
	int b = 0;
	if (tmp1.base > tmp2.base) b = tmp1.base;
	else b = tmp2.base;
	if (tmp1.base != 10) tmp1.SwitchBase(10);
	if (tmp2.base != 10) tmp2.SwitchBase(10);
	int num1 = atoi1(tmp1.nr), num2 = atoi1(tmp2.nr);
	num1 = num1 + num2;
	Number number = num1;

	delete[] nr;

	if (number.base != b) number.SwitchBase(b);
	nr = new char[number.digits + 1];
	strcpy(nr, number.nr);
	nr[number.digits] = '\0';
	digits = number.digits;
	base = number.base;

	return (*this);
}
Number& Number::operator -- (int value)
{
	this->nr[this->digits - 1] = '\0';
	this->digits--;
	return (*this);
}
Number& Number::operator -- ()
{
	do
	{
		for (int i = 0; i < digits - 1; i++)
			nr[i] = nr[i + 1];
		digits--;
		nr[digits] = '\0';
	} while (nr[0] == '0');
	return (*this);
}
Number operator + (Number n1, Number n2)
{
	int b;
	if (n1.GetBase() > n2.GetBase())
		b = n1.GetBase();
	else b = n2.GetBase();
	if (n1.GetBase() != 10) n1.SwitchBase(10);
	if (n2.GetBase() != 10) n2.SwitchBase(10);
	int num1 = atoi1(n1.GetNumber()), num2 = atoi1(n2.GetNumber());
	num1 = num1 + num2;
	Number number = num1;
	if (number.GetBase() != b) number.SwitchBase(b);
	return number;
}
Number operator - (Number n1, Number n2)
{
	int b;
	if (n1.GetBase() > n2.GetBase())
		b = n1.GetBase();
	else b = n2.GetBase();
	if (n1.GetBase() != 10) n1.SwitchBase(10);
	if (n2.GetBase() != 10) n2.SwitchBase(10);
	int num1 = atoi1(n1.GetNumber()), num2 = atoi1(n2.GetNumber());
	num1 = num1 - num2;
	Number number = num1;
	if (number.GetBase() != b) number.SwitchBase(b);
	return number;
}
int Number::operator [] (int value)
{
	return nr[value];
}
bool Number::operator > (Number obj)
{
	Number tmp = *this;
	if (tmp.base != 10) tmp.SwitchBase(10);
	if (obj.base != 10) obj.SwitchBase(10);
	int num1 = atoi1(tmp.nr), num2 = atoi1(obj.nr);
	if (num1 > num2) return true;
	return false;
}
bool Number::operator < (Number obj)
{
	Number tmp = *this;
	if (tmp.base != 10) tmp.SwitchBase(10);
	if (obj.base != 10) obj.SwitchBase(10);
	int num1 = atoi1(tmp.nr), num2 = atoi1(obj.nr);
	if (num1 < num2) return true;
	return false;
}
bool Number::operator <= (Number obj)
{
	Number tmp = *this;
	if (tmp.base != 10) tmp.SwitchBase(10);
	if (obj.base != 10) obj.SwitchBase(10);
	int num1 = atoi1(tmp.nr), num2 = atoi1(obj.nr);
	if (num1 <= num2) return true;
	return false;
}
bool Number::operator >= (Number obj)
{
	Number tmp = *this;
	if (tmp.base != 10) tmp.SwitchBase(10);
	if (obj.base != 10) obj.SwitchBase(10);
	int num1 = atoi1(tmp.nr), num2 = atoi1(obj.nr);
	if (num1 >= num2) return true;
	return false;
}
bool Number::operator == (Number obj)
{
	Number tmp = *this;
	if (tmp.base != 10) tmp.SwitchBase(10);
	if (obj.base != 10) obj.SwitchBase(10);
	int num1 = atoi1(tmp.nr), num2 = atoi1(obj.nr);
	if (num1 == num2) return true;
	return false;
}
bool Number::operator != (Number obj)
{
	Number tmp = *this;
	if (tmp.base != 10) tmp.SwitchBase(10);
	if (obj.base != 10) obj.SwitchBase(10);
	int num1 = atoi1(tmp.nr), num2 = atoi1(obj.nr);
	if (num1 != num2) return true;
	return false;
}
void Number::SwitchBase(int newBase)
{
	if (base == newBase) return;
	else 
	{
		if (base != 10)
		{
			int num = 0, p = 1;
			for (int i = digits - 1; i >= 0; i--)
			{
				if (nr[i] >= 'A' && nr[i] <= 'F')
					num = num + (nr[i] - 'A' + 10) * p;
				else num = num + (nr[i] - '0') * p;
				p *= this->base;
			}
			int tmp = num, len = 0;
			while (tmp)
			{
				len++;
				tmp /= 10;
			}
			digits = len;
			char* aux = new char[len + 1];
			for (int i = len - 1; i >= 0; i--)
			{
				aux[i] = num % 10 + '0';
				num /= 10;
			}
			delete[] nr;
			nr = aux;
			nr[len] = '\0';
			base = 10;
		}
		if (newBase != 10)
		{
			int num = atoi1(nr);
			int tmp = num;
			int n = 0;
			while (tmp)
			{
				tmp /= newBase;
				n++;
			}
			char* aux = new char[n + 1];
			int i = n - 1;
			while (num > 0)
			{
				int digit = num % newBase;
				if (digit > 9 && digit < 16)
					aux[i--] = 'A' + digit - 10;
				else aux[i--] = digit + '0';
				num /= newBase;
			}
			digits = n;
			delete[] this->nr;
			nr = aux;
			nr[n] = '\0';
		}
	}
	this->base = newBase;
}
void Number::Print()
{
	printf("Number: %s Base: %d Digits: %d\n", this->nr, this->base, this->digits);
}
int Number::GetDigitsCount()
{
	return this->digits;
}
int Number::GetBase()
{
	return this->base;
}
char* Number::GetNumber()
{
	return this->nr;
}
