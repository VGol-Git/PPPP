#include <iostream>
#include <cmath>
#include <string>
using namespace std;

std::string func(double a, double b, double c, double d, double e, double f) {
	//double a, b, c, d, e, f;
	//cin >> a >> b >> c >> d >> e >> f;
	std::string answer;
	if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0))
	{
		cout << '5';
		answer.push_back('5');	
	}
	else if ((a*d - c * b != 0) && ((e*d - b * f != 0) || (a*f - c * e != 0)))
	{
		double y = (a * f - c * e) / (a * d - c * b);
		double x = (d * e - b * f) / (d * a - b * c);
		cout << "2 " << x << ' ' << y;
		answer = "2 "+ to_string(x)+" "+to_string(y);
	}
	else if (((a*d - c * b == 0) && ((e*d - b * f != 0) || (a*f - c * e != 0))) ||
		(a == 0 && c == 0 && e / b != f / d) ||
		(b == 0 && d == 0 && e / a != f / c) ||
		(a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0)))
	{
		if (((a == 0 && b == 0 && e == 0 && d != 0 && c == 0) ||
			(c == 0 && d == 0 && f == 0 && b != 0 && a == 0)))
		{
			double y;
			if (b == 0)
				y = f / d;
			else if (d == 0)
				y = e / b;
			else if (e == 0 || f == 0)
				y = 0;
			cout << '4' << ' ' << y;
			answer = "4 " + to_string(y);
		}
		else if (((a == 0 && b == 0 && e == 0 && c != 0 && d == 0) ||
			(c == 0 && d == 0 && f == 0 && a != 0 && b == 0)))
		{
			double x;
			if (a == 0)
				x = f / c;
			else if (c == 0)
				x = e / a;
			else if (e == 0 || f == 0)
				x = 0;
			cout << '3' << ' ' << x;
			answer = "3 " + to_string(x);
		}
		else {
			cout << '0';
			answer = '0';
			//return "0";
		}

	}
	else if (a == 0 && c == 0)
	{
		double y;
		if (e == 0)
			y = f / d;
		else if (f == 0)
			y = e / b;
		else
			y = e / b;
		cout << '4' << ' ' << y;
		answer = "4 " + to_string(y);

		//return "4";

	}
	else if (b == 0 && d == 0)
	{
		double x;
		if (e == 0)
			x = f / c;
		else if (f == 0)
			x = e / a;
		else
			x = e / a;
		cout << '3' << ' ' << x;
		answer = "3 " + to_string(x);

		//return "3";

	}
	else if (b == 0 && e == 0)
	{
		double k, n;
		k = -c / d;
		n = f / d;
		cout << '1' << ' ' << k << ' ' << n;
		answer = "1 " + to_string(k) + " " + to_string(n);

		//return "1";

	}
	else if (d == 0 && f == 0)
	{
		double k, n;
		k = -a / b;
		n = e / b;
		cout << '1' << ' ' << k << ' ' << n;
		answer = "1 " + to_string(k) + " " + to_string(n);

		//return "1";

	}
	else if (a == 0 && e == 0)
	{
		double k, n;
		k = -d / c;
		n = f / c;
		cout << '1' << ' ' << k << ' ' << n;
		answer += "1 " + to_string(k) + " " + to_string(n);

		//return "1";

	}
	else if (c == 0 && f == 0)
	{
		double k, n;
		k = -b / a;
		n = e / a;
		cout << '1' << ' ' << k << ' ' << n;
		answer += "1 " + to_string(k) + " " + to_string(n);

	//	return "1";

	}
	else if ((a / b == c / d))
	{
		double k, n;
		k = -c / d;
		n = f / d;
		cout << '1' << ' ' << k << ' ' << n;
		answer += "1 " + to_string(k) + " " + to_string(n);

	//	return "1";
	}
	else
	{
		cout << "Are you kidding me?";
		answer = "Are you kidding me?";
	}
	return answer;
}


int main()
{




	return 0;
}

