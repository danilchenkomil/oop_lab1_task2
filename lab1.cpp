#include <iostream>
#define N 10

void inp_m(double*, int);
int search(double*, int);
double &otr(double a[] , int);
using namespace std;

int main(void)
{
	double a[N];
	int ind;
	cout << "Array" << endl;
	inp_m(a, N);
	otr(a, N);
	cout << endl << "Result:" << endl;
	for (int i = 0; i < N; i++)
		cout << " " << a[i];
	ind = search(a, N);
	cout <<endl<< "Element #" << ind <<endl;
	return 0;
	
}

double &otr(double a[], int n)
{
		int i = 0;
		for (int i = 0; i < 10; i++)
		if (a[i] < 0) {
			a[i] = a[i] * a[i];
		}
		return a[i];
}

void inp_m(double* a, int n)
{
		for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int search(double* m, int n)
{
	double razn, minrazn=100, dsum = 0, psum = 0;
	int i, j, ans = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i - 1; j++) dsum += m[j];
		for (j = i + 1; j < n; j++) psum += m[j];
		razn = fabs(dsum - psum);
		if (razn < minrazn && i>0)
		{
			minrazn = razn;
			ans = i;
		}
		dsum = 0; psum = 0;
	}
	return ans;
}