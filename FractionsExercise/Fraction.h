#pragma once

#include <iostream>

// Class for working with fractions. All real job is here.
class Fraction
{

private:
	int numerator;
	int denominator;

	bool isValid = true;

	int greatestCommonDivider(int a, int b)
	{
		if (a == 0)
			return b;
		return greatestCommonDivider(b % a, a);
	}

public:
	Fraction()
	{
	}

	Fraction(int n, int d)
	{

		int divisor = greatestCommonDivider(n, d);
		if (divisor != 0)
		{
			numerator = n / divisor;
			denominator = d / divisor;
		}
		else
		{
			numerator = n;
			denominator = d;
		}
		if (denominator < 0)
		{
			numerator *= -1;
			denominator *= -1;
		}
		if (denominator == 0)
			isValid = false;
	}

	Fraction(std::string s)
	{
		try
		{
			std::size_t found = s.find('/');
			if (found == std::string::npos)
			{
				numerator = std::stoi(s);
				denominator = 1;
				return;
			}
			std::string n_str = s.substr(0, found);
			std::string d_str = s.substr(found + 1, s.length() - found - 1);

			// check & in numerator
			found = n_str.find('&');
			if (found != std::string::npos)
			{
				std::string n1_str = n_str.substr(0, found);
				std::string n2_str = n_str.substr(found + 1, s.length() - found - 1);

				numerator = std::stoi(n2_str);
				denominator = std::stoi(d_str);

				int integer = std::stoi(n1_str);
				numerator += integer * denominator;
			}
			else
			{
				numerator = std::stoi(n_str);
				denominator = std::stoi(d_str);
			}

			if (denominator == 0)
				isValid = false;
		}
		catch(...)
		{
			isValid = false;
		}
	}

	bool IsValid() { return isValid; };

	// Operator overloading
	Fraction operator + (const Fraction& rhs) const
	{
		int n = numerator * rhs.denominator + denominator * rhs.numerator;
		int d = denominator * rhs.denominator;
		Fraction* res = new Fraction(n, d);
		return *res;
	}
	Fraction operator - (const Fraction& rhs) const
	{
		int n = numerator * rhs.denominator - denominator * rhs.numerator;
		int d = denominator * rhs.denominator;
		Fraction* res = new Fraction(n, d);
		return *res;
	}
	Fraction operator * (const Fraction& rhs) const
	{
		int n = numerator * rhs.numerator;
		int d = denominator * rhs.denominator;
		Fraction *res = new Fraction(n, d);
		return *res;
	}
	Fraction operator / (const Fraction& rhs) const
	{
		int n = numerator * rhs.denominator;
		int d = denominator * rhs.numerator;
		Fraction* res = new Fraction(n, d);
		return *res;
	}	

	friend std::ostream& operator<<(std::ostream& output, const Fraction& f)
	{
		if (f.denominator == 1)
		{
			output << f.numerator;
		}
		else if (f.numerator < f.denominator)
		{
			output << f.numerator << "/" << f.denominator;
		}
		else
		{
			output << f.numerator / f.denominator << "&" << f.numerator % f.denominator << "/" << f.denominator;
		}
		return output;
	}

	friend bool operator== (Fraction& lhs, Fraction& rhs)
	{
		if (lhs.numerator == rhs.numerator &&
			lhs.denominator == rhs.denominator)
		{
			return true;
		}
		return false;
	}

	friend Fraction calculate(Fraction fraction1, Fraction fraction2, std::string op)
	{
		if (!fraction1.IsValid())
		{
			throw std::exception("fraction1 is not valid");
		}
		if (!fraction2.IsValid())
		{
			throw std::exception("fraction2 is not valid");
		}
		Fraction f;
		if (op == "+")
		{
			f = fraction1 + fraction2;
		}
		else if (op == "-")
		{
			f = fraction1 - fraction2;
		}
		else if (op == "*")
		{
			f = fraction1 * fraction2;
		}
		else if (op == "/")
		{
			f = fraction1 / fraction2;
		}
		else
		{
			throw std::exception("Unknown operation");
		}
		if (!f.IsValid())
		{
			throw std::exception("Bad result");
		}
		return f;
	}

};

