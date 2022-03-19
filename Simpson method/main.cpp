#include<iostream>
#include<cmath>
#include<cstdlib> //Формула Симпсона
using namespace std;

float f(float x) {
	float f;
	f = 1 / (1 + pow(log(x), 3));
	return f;
}

float fun(float a, float b, int n) {
	float h;
	float x;
	float y;
	h = (b - a) / n;
	y = 0;
	x = a;
	for (int i = 0; i < n; i++) {
		y = y + (f(x) + 4 * f(x + 0.5 * h) + f(x + h));
		x = x + h;
	}
	y = y * h / 6;
	return y;
}

int main() {
	setlocale(LC_ALL, "Russian");
	float a;
	float b;
	int n;
	float eps;
	cout << "Введите отрезок: ";
	cin >> a;
	cin >> b;
	cout << "Введите число частичных отрезков n: ";
	cin >> n;
	cout << "Введите число останова eps: ";
	cin >> eps;

	float y1 = fun(a, b, n);
	n = n * 2;
	float y2 = fun(a, b, n);
	while (abs(y2 - y1) >= eps) {
		y1 = y2;
		n = n * 2;
		y2 = fun(a, b, n);
	}

	cout << "Ответ: " << y2 << endl;
	cin.get();
	cin.get();
}