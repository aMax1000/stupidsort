#include <iostream>
using namespace std;


class Sorting
{
private:
	int* _arr = nullptr;
	size_t _size = 0;

public:
	Sorting(int* arr, size_t size)
	{
		_size = size;
		if (size != 0 && arr != nullptr)
		{
			_arr = new int[_size];
			for (size_t i = 0;i < _size;++i)
			{
				_arr[i] = arr[i];
			}
		}
	}
	int* get_arr()
	{
		return _arr;
	}
	signed int gnome_sort_asc()
	{
		if (_size > 1 && _arr != nullptr)
		{
			signed int itt = 0;
			size_t i = 0;
			while (i < _size - 1) // 2 6 7 8 9
			{
				itt++;
				if (_arr[i] > _arr[i + 1])
				{
					swap(_arr[i], _arr[i + 1]);
					if (i == 0)
					{
						++i;
					}
					else
					{
						--i;
					}
				}
				else
				{
					++i;
				}


			}
			return itt;
		}
	}
	signed int stupid_sort_asc()
	{
		if (_size > 1 && _arr != nullptr)
		{
			signed int itt = 0;
			size_t i = 0;
			while (true)
			{
				itt++;
				if(_arr[i] > _arr[i + 1])
				{
					swap(_arr[i], _arr[i + 1]);
					i = 0;
				}
				else {
					i++;
					if (i >= _size - 1) 
					{
						return itt;
					}
				}
			}
		}
	}
	~Sorting()
	{
		if (_arr != nullptr)
		{
			delete[] _arr;
		}
	}
};



int main()
{
	size_t n;
	cout << "Enter n: ";
	cin >> n;
	if (n > 0)
	{
		int* arr = new int[n];
		cout << "Is manual input? (1 for yes, 0 for no): ";
		int manual;
		cin >> manual;
		if (manual)
		{
			for (size_t i = 0; i < n; i++)
			{
				cout << "Enter arr[" << i << "]: ";
				cin >> arr[i];
			}
		}
		else {
			for (size_t i = 0; i < n; i++)
			{
				arr[i] = rand() % 100;
			}
		}
		Sorting sort(arr, n);
		Sorting sort2(arr, n);
		signed int itt = sort.stupid_sort_asc();
		signed int itt2 = sort2.gnome_sort_asc();
		cout << "Number of iterations stupid sort: " << itt << endl;
		cout << "Number of iterations gnome sort: " << itt2 << endl;
		cout << "How more efficient gnome sort is: " << (double)itt/itt2 << endl;
		int* sortedArr = sort.get_arr();
		for (size_t i = 0;i < n;i++)
		{
			cout << sortedArr[i] << ' ';
		}
		cout << endl;
		delete[] arr;
	}
	return 0;
}