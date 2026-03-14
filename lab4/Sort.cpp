#include "Sort.h"

Sort::Sort(int elements_count, int minimum, int maximum)
{
	for (int i = 0; i < elements_count; i++)
	{
		lista.push_back(minimum + (rand() % (maximum - minimum + 1)));
	}

	counter = elements_count;
}

Sort::Sort(std::initializer_list<int> list)
{
	counter = list.size();

	for (int i = 0; i < counter; i++)
	{
		lista.push_back(list.begin()[i]);
	}
}	

Sort::Sort(std::vector<int> v, int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		lista.push_back(v[i]);
	}
	
	counter = cnt;
}

Sort::Sort(int cnt, ...)
{
	va_list list;
	va_start(list, cnt);

	for (int i = 0; i < cnt; i++)
	{
		int p = va_arg(list, int);
		lista.push_back(p);
	}

	va_end(list);
	counter = cnt;

}

Sort::Sort(std::string list)
{
	int cnt = std::count(list.begin(), list.end(), ',');
	counter = cnt + 1;
	int nr;
	int string_cnt = 0;

	for (int i = 0; i<=cnt; i++)
	{
		nr = 0;

		while (isdigit(list[string_cnt])) {
			nr = nr * 10 + (list[string_cnt++] - '0');
		}

		string_cnt++;
		lista.push_back(nr);

	}
}


void Sort::InsertSort(bool ascendent)
{
	if (ascendent)
	{
		for (int i = 1; i < counter; i++)
		{
			int p = i - 1;
			int aux = lista[i];
			while (p >= 0 && lista[p] > aux) {
				lista[p + 1] = lista[p];
				p--;
			}
			lista[p + 1] = aux;
		}
	}
	else {
		for (int i = 1; i < counter; i++)
		{
			int p = i - 1;
			int aux = lista[i];
			while (p >= 0 && lista[p] < aux) {
				lista[p + 1] = lista[p];
				p--;
			}
			lista[p + 1] = aux;
		}
	}
}


void Sort::BubbleSort(bool ascendent)
{
	if (ascendent)
	{
		bool sorted;
		do
		{
			sorted = true;
			for (int i = 0; i < counter-1; i++)
			{
				if (lista[i] > lista[i+1]) {
					std::swap(lista[i], lista[i + 1]);
					sorted = false;
				}
			}

		
		} while (!sorted);
	}
	else {
		bool sorted;
		do
		{
			sorted = true;
			for (int i = 0; i < counter-1; i++)
			{
				if (lista[i] < lista[i + 1]) {
					std::swap(lista[i], lista[i + 1]);
					sorted = false;
				}
			}


		} while (!sorted);
	}
}

int partition(std::vector<int> &ls, int st, int dr, bool ascendent) {

	int pivot = ls[st];
	int i = st+1;
	int j = dr;

	if (ascendent)
	{

		while (i <= j) {
			if (ls[i] <= pivot)
			{
				i++;
			}
			if (ls[j] >= pivot)
			{
				j--;
			}
			if ((i < j) and (ls[i] > pivot) and (ls[j] < pivot))
			{
				std::swap(ls[i], ls[j]);
				i++;
				j--;
			}
		}

		int c = i - 1;
		ls[st] = ls[c];
		ls[c] = pivot;
		return c;
	}
	else
	{
		while (i <= j) {
			if ((ls[i] >= pivot) )
			{
				i++;
			}
			if (ls[j] <= pivot)
			{
				j--;
			}
			if ((i < j) and (ls[i] < pivot) and (ls[j] > pivot))
			{
				std::swap(ls[i], ls[j]);
				i++;
				j--;
			}
		}

		int c = i - 1;
		ls[st] = ls[c];
		ls[c] = pivot;
		return c;
	}
}

void global_quicksort(std::vector<int>& ls, int st, int dr, bool ascendent) {

	if (st<dr)
	{
		int k = partition(ls, st, dr, ascendent);
		global_quicksort(ls, st, k - 1, ascendent);
		global_quicksort(ls, k + 1, dr, ascendent);
	}
}
void Sort::QuickSort(bool ascendent)
{
	global_quicksort(lista, 0, lista.size()-1, ascendent);
}

void Sort::Print()
{
	for ( int i : lista)
	{
		printf("%d ", i);
	}
	printf("\n");
}

int Sort::GetElementsCount()
{
	return counter;
}

int Sort::GetElementFromIndex(int index)
{
	return lista[index];
}
