// Lesson4CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Figure {
private:
    Point* points;
    int size;
public:
    Figure() : Figure(5) {}
    Figure(int size) : points{ new Point[size] }, size{ size } 
    {

    }
    Figure(const Figure& figure) : points{ new Point[figure.size]}, size{figure.size}
    {
        for (int i = 0; i < size; i++)
        {
            points[i] = figure.points[i];
        }
    }
    Figure(Figure&& figure) : points{ figure.points }, size{ figure.size }
    {
        figure.points = nullptr;
        figure.size = 0;
    }
    Figure& operator=(const Figure& figure)
    {
        if (!(this == &figure))
        {
            if (size != figure.size)
            {
                size = figure.size;
                points = new Point[size];
                
            }
            for (int i = 0; i < size; i++)
            {
                points[i] = figure.points[i];
            }
        }
    }
    ~Figure() 
    {
        delete[] points;
    }
};
class Point {
private:
    int x;
    int y;
public:
    Point() : Point(0, 0) {}
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    friend bool operator==(const Point& point, const Point& point2)
    {
        return point.x == point2.x && point.y == point2.y;
    }
    Point& operator=(const Point& point)
    {
        if(!(this == &point))
        { 
            this->x = point.x;
            this->y = point.y;
        }
    }

};

int main()
{
    
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
