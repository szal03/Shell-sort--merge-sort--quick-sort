#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include<fstream>
#include <ctime>

using namespace std;
int _count1 = 0, _count2 = 0, _count3 = 0, _count4 = 0;
int v=0;
int yo=0;
int vo = 0;
int qa = 0;


void shellSort2(int *a, int n) {
	int h, i, j, t;
	for (h = n; h /= 2;) {
		for (i = h; i < n; i++) {
			t = a[i];
			for (j = i; j >= h && t < a[j - h]; j -= h)
				a[j] = a[j - h];
			v++;
			a[j] = t;
			_count1++;
		}
	}
}
void shellSort3(int *a, int n) {
	int h, i, j, t;
	for (h = n; h /= 3;)
	{
		for (i = h; i < n; i++) 
		{
			t = a[i];
			for (j = i; j >= h && t < a[j - h]; j -= h)
			{
				a[j] = a[j - h];	
			}
			a[j] = t;
			_count2++;
			yo++;
		}	
	}
}

void mergeSort(int i_p, int i_k, int *d, int *p) {
	int i_s, i1, i2, i;

	i_s = (i_p + i_k + 1) / 2;
	if (i_s - i_p > 1)
		mergeSort(i_p, i_s - 1, d, p);
	if (i_k - i_s > 0)
		mergeSort(i_s, i_k, d, p);
	i1 = i_p; i2 = i_s;
	for (i = i_p; i <= i_k; i++)
		p[i] = ((i1 == i_s) || ((i2 <= i_k) && (d[i1] > d[i2]))) ? d[i2++] : d[i1++]; qa++;
	for (i = i_p; i <= i_k; i++)
		d[i] = p[i];
}

void quickSort(int *A, int len) {
	if (len < 2)
		return;

	int pt = A[len / 2];

	int i, j;
	for (i = 0, j = len - 1; ; i++, j--) {
		while (A[i] < pt) i++;
		while (A[j] > pt) j--;

		if (i >= j) break;

		swap(A[i], A[j]);
		vo++;
	}

	quickSort(A, i);
	quickSort(A + i, len - i);
}



int main() {
	srand(time(NULL));
	const int N = 100000; // tutaj zminiaj rozmiar
	int i;
	//cin >> N;

	int *a = new int[N];
	int *b = new int[N];
	int *d = new int[N];


	int p[N];
	for (i = 0; i < N; i++) {
		a[i] = rand() % 100;
		b[i] = rand() % 100;
		d[i] = rand() % 100;
	}
	clock_t start1 = clock();
	for (i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << endl << _count1 << endl;
	cout << "ShellSort1" << endl;
	shellSort2(a, N);
	/*for (i = 0; i < N; i++)
		cout << a[i] << " ";*/
	//cout << endl << _count1 << endl; //
	clock_t _end = clock();
	cout << "Czas: " << _end - start1 << endl;
	cout << " Ilosc:   " << v << endl;
	cout << "###########################################" << endl;
	cout << "Shellsort2" << endl;
	clock_t start2 = clock();
	//for (i = 0; i < N; i++)
		//cout << a[i] << " ";
	//cout << endl << _count2 << endl;
	shellSort3(a, N);
	/*for (i = 0; i < N; i++)
		cout << a[i] << " ";*/
	//cout << endl << _count2 << endl;
	clock_t _end2 = clock();
	cout << "Czas: " << _end2 - start2 << endl;
	cout << " Ilosc:   " << yo << endl;
	cout << "##########################################" << endl;
	cout << "MergeSort" << endl;
	clock_t start3 = clock();
	//for (i = 0; i < N; i++)
		//cout << d[i] << " ";
	//cout << endl << _count3 << endl;
	mergeSort(0, N - 1, d, p); //#################dopisz ioœæ kroków czy cus
	/*for (i = 0; i < N; i++)
		cout << d[i] << " ";*/
	//cout << endl << _count3 << endl;
	clock_t _end3 = clock();
	cout << "Czas: " << _end3 - start3 << endl;
	cout << " Ilosc:   " << qa<< endl;
	cout << "###########################################" << endl;

	cout << "QuickSort" << endl;
	clock_t start4 = clock();

	//for (i = 0; i < N; i++)
		//cout << b[i] << " ";
	//cout << endl << _count4 << endl;
	quickSort(b, N);
	/*for (i = 0; i < N; i++)
		cout << b[i] << " ";*/
	//cout << endl << _count4 << endl;;

	clock_t _end4 = clock();
	cout << "Czas: " << _end4 - start4 << endl;
	cout << " Ilosc  " << vo << endl;
	cout << "###########################################" << endl;

	//ifstream l;
	//l.open("zapis.txt");
	//ofstream()


	
	//l.close();
	delete[] a;
	delete[] b;
	delete[] d;
	system("pause");
	return 0;
}
