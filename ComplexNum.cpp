// RK.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

using/*use*/ namespace std;

class ComplexNum
{
private:
	double x;
	double y;
public:
	ComplexNum(double re = 0, double Im = 0) :x(re), y(Im) {};
	ComplexNum(const ComplexNum& cmplx){};
	~ComplexNum(){};//{}
	double fabs()const
	{
		return sqrt(x * x + y * y);
	};

	double arg()const
	{
		return atan2(y, x);
	};
	ComplexNum conj() const { return ComplexNum(x, -y); };
	ComplexNum& operator=(const ComplexNum& cmplx)
	{
		x = cmplx.x;
		y = cmplx.y;
		return *this;
	};

	const ComplexNum& operator+() const //не может изменять члены объекты типа к которому принадлежит
	{
		return *this;
	}
	ComplexNum/*&*/ operator-()const
	{
		return ComplexNum(/*-this.x, -this.y*/   -this->x, -this->y);
	};
	ComplexNum operator+(const ComplexNum& cmplx)const
	{
		return ComplexNum(x + cmplx.x, y + cmplx.y);
	};
	ComplexNum operator-(const ComplexNum& cmplx)const
	{
		return ComplexNum(x - cmplx.x, y - cmplx.y);
	};

	ComplexNum operator*(const ComplexNum& cmplx)const {
		return ComplexNum(x * cmplx.x - y * cmplx.y, x * cmplx.x + y * cmplx.y);
	};
	ComplexNum operator/(const ComplexNum& cmplx)const {
		double dn = cmplx.x * cmplx.x + cmplx.y * cmplx.y;

		return ComplexNum((x * cmplx.x + y * cmplx.y) / dn, (-x * cmplx.y + y * cmplx.x) / dn);
	}

	bool operator==(const ComplexNum& cmplx)const {
		return((x == cmplx.x) && (y == cmplx.y));
	};
	bool operator!=(const ComplexNum& cmplx)const {
		return !(*this == cmplx);
	};
	 friend ostream& operator<<(ostream& str, const ComplexNum& cmplx);

};

 ostream& operator<<(ostream& str, const ComplexNum& cmplx)
{
	if (cmplx.y >= 0)
		str << cmplx.x << " + " << cmplx.y << "I";
	else
		str << cmplx.x << " - " << -cmplx.y << "I";
	return str;
}



int main(int argc,char**argv)
{
   cout << "Hello World!\n";
   ComplexNum a(-1.0, 1.0);
   ComplexNum b(2.0, -3.5);
   ComplexNum c(b);
   cout << "|a| = " << a.fabs() << ", arg(a) = " << a.arg() << endl;
   cout << "|a|^2  " << a * a.conj() << endl;
   cout << "c / b = " << c / b << endl;
   cout << "a + b*c" << a + b * c << endl;
   //cout << "-a+4*b" << -a + 4.0 * b << endl;
   cout << "Good bye!" << endl;
   //cin.get();
   return 0;//возвр знач

}



