// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string>
#include <utility>
#include <cmath>

enum class Result
{
    kOnCircle,
    kInCircle,
    kOutCircle,
};

typedef std::pair<float, float> Point;

std::ifstream& operator>>(std::ifstream& in, Point& point) {
  in >> point.first;
  in >> point.second;
  return in;
}

std::vector<float> ReadOfFile_Circle(const std::string& kFileName) {
  std::ifstream source;
  source.open(kFileName);
  std::vector<float> date;
  float digit;
  while (source >> digit)
  {
    date.push_back(digit);
  }
  return date;
}

std::vector<Point> ReadOfFile_Points(const std::string& kFileName) {
  std::ifstream source;
  source.open(kFileName);
  std::vector<Point> date;
  Point point;
  while (source >> point)
  {
    date.push_back(point);
  }
  return date;
}

float Distance( const float& kX0, const float& kY0, const float& kX1, const float& kY1 ) {
  float distance;
  float x = abs(kX1 - kX0);
  float y = abs(kY1 - kY0);
  distance = sqrt( (x * x) + (y * y) );
  return distance;
}

void PointChecker( Result& res, const float& kR, const float& kDistance ) {
  if ( kDistance > kR)
  {
   res = static_cast<Result>(2);
  }
  else
  {
    res = kDistance < kR ? static_cast<Result>(1) : static_cast<Result>(0);
  }
}

void Print( Result& res) {
  switch (res)
  {
  case Result::kInCircle:
    std::cout << 1 << "\n";
    break;
  case Result::kOutCircle:
    std::cout << 2 << "\n";
    break;
  case Result::kOnCircle:
    std::cout << 0 << "\n";
    break;
  default:
    std::cout << "Bad story...";
    break;
  }
}

int main( int argc, char *argv[] )
{
  setlocale(LC_ALL, "rus");
  std::string circle_filename(argv[1]);
  std::string point_filename(argv[2]);
  circle_filename += ".txt";
  point_filename += ".txt";
  std::vector<float> circle = ReadOfFile_Circle(circle_filename);
  std::vector<Point> points = ReadOfFile_Points(point_filename);
  float x0, y0, R;
  x0 = circle[0];
  y0 = circle[1];
  R = circle[2];
  Result res;
  int points_count = points.size();
  for (size_t counter = 0; counter < points_count; counter++)
  {
    float distance = Distance(x0, y0, points[counter].first, points[counter].second);
    PointChecker(res, R, distance);
    Print(res);
  }
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
