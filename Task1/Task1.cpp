// Task1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <sstream>

void init (std::vector<int>& v) {
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i] = i + 1;
	}
}

void search_way (const std::vector<int>& v, std::vector<int>& index, int c, const int& step) {
	int i = 0;
	while (c--)
	{
		index.push_back(v[i]);
		if (step >= v.size() - i) {		// Если i + шаг больше размера v
			i = step - v.size() + i;		// начинаем новый круг с индексом элемента равным 0 + (шаг - (размер v - i))
		}
		else {
			i += step;						// Иначе увеличиваем i на m 
		}
	}
}

void print (const std::vector<int> index) {
	for (const int& a : index)
	{
		std::cout << a;
	}
}

int main(int argc, char *argv[])
{
	std::stringstream convert_n(argv[1]);
	std::stringstream convert_m(argv[2]);
	int n, m;
	convert_n >> n;			// конвертируем и получаем размер массива
	convert_m >> m;			// конвертируем и получаем размер шага
	m--;
	int c = 0;
	// c - const. (c * m) / n = 1 or (c * m) % n = 0 : m за c шагов делает полный круг в кольцевом массиве.
	for (;;)
	{
		c++;
		if (!((c * m) % n))
		{
			break;
		}
	}
	std::vector<int> v(n);	// вектор в котором хранится наш кольцевой массив
	init(v);				// инициализация массива
	std::vector<int> index; // вектор для хранения пути
	search_way(v, index, c, m);
	print(index);
	return 0;
}