// Lesson4CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Point {
private:
    double x;
    double y;
public:
    Point() : Point(0, 0) {}
    Point(double x, double y)
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
        if (!(this == &point))
        {
            this->x = point.x;
            this->y = point.y;
        }

        return *this;
    }
    void print()
    {
        cout << "Точка:" << x << ":" << y << endl;
    }
};

class Figure {
private:
    Point* points;
    int size;
public:
    Figure() : Figure(5) {}
    Figure(int size) : points{ new Point[size] }, size{ size } 
    {
        for (int i = 0; i < size; i++)
        {
            points[i] = Point(rand() % 10, rand() % 10);
        }
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
        return *this;
    }
    ~Figure() 
    {
        delete[] points;
    }

    void print() 
    {
        cout << "Массив на " << size << "элементов" << endl;
        for (int i = 0; i < size; i++)
        {
            
            points[i].print();
            
        }
        cout << "Конец массива" << endl;
        cout << "" << endl;
    }
};


int main()
{
    setlocale(LC_ALL, "");
    Figure fig(5);
    fig.print();
    Figure fig2(10);
    fig2.print();
    Figure fig3(5);
    fig3.print();

    fig = fig3;
    fig.print();
    fig = fig2;
    fig.print();
    Figure fig4(move(fig));
    fig4.print();
    fig = fig4;
    fig.print();

    return 0;
}