#include <iostream>
using namespace std;

template<class T>
class Matrix
{
	T** arr;
	int rows;
	int cols;
public:
	void Delete()
	{

		for (int j = 0; j < rows; j++)
		{
			delete[] arr[j];
		}
		delete[] arr;
	}
	Matrix()
	{
		arr = nullptr;
		rows = 0;
		cols = 0;
	}
	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;
		arr = new T*[rows];
		for (int i = 0; i < rows; i++) 
		{
			arr[i] = new T[cols];
		}

		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < cols; j++) 
			{
				arr[i][j] = rand() % 100 * 1.2;
			}
		}
	}
	void Input()
	{
		cout << "Enter quantity of rows: ";
		cin >> rows;
		cout << "Enter quantity of cols: ";
		cin >> cols;

		if(arr!=nullptr) Delete();

		arr = new T* [rows];
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new T[cols];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cin >> arr[i][j];
			}
		}
	}
	void Output() const
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	~Matrix()
	{
		for (int j = 0; j < rows; j++)
		{
			delete[] arr[j];
		}
		delete[] arr;
	}

	void MaxMin()
	{
		T min = numeric_limits<T>::max();
		T max = numeric_limits<T>::min();
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (arr[i][j] > max) max = arr[i][j];
				if (arr[i][j] < min) min = arr[i][j];
			}
		}
		cout << "Max: " << max << endl << "Min: " << min << endl << endl;
	}
};


int main()
{
	Matrix<int> a(5,5);
	a.Output();

	cout << endl << endl;

	Matrix<double> b(5, 5);
	b.Output();

	cout << endl << endl;

	Matrix<char> c;
	c.Input();
	c.Output();

	c.MaxMin();
	return 0;
}