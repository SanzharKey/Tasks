// Task4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::vector<int> ReadFile(const std::string& file_name) {
  std::ifstream source;
  source.open(file_name);
  std::vector<int> digits_;
  int num;
  while (source >> num)
  {
    digits_.push_back(num);
  }
  return digits_;
}

void InsertionSort(std::vector<int>& digits) {
  for (size_t i = 1; i < digits.size(); ++i)
  {
    for (size_t j = i; j > 0 && digits[j - 1] > digits[j]; --j)
    {
      digits[j - 1] ^= digits[j];
      digits[j] ^= digits[j - 1];
      digits[j - 1] ^= digits[j];
    }
  }
}

int Median(const int& size) {
  return size / 2;
}

int StepCount(const std::vector<int>& digits) {
  int counter = 0;
  {
    size_t i = 0;
    size_t j = digits.size() - 1;
    int mediana = Median(digits.size());
    for (; i < mediana; i++)
    {
      counter += abs(digits[i] - digits[mediana]);
    }
    for (; j > mediana; j--)
    {
      counter += abs(digits[j] - digits[mediana]);
    }
  }
  return counter;
}

int main(int argc, char* argv[])
{
  if (!argv[1])
  {
    return 1;
  }
  std::string file_name(argv[1]);
  file_name += ".txt";
  std::vector<int> digits = ReadFile(file_name);
  InsertionSort(digits);
  int counter = StepCount(digits);
  std::cout << counter;
  return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
