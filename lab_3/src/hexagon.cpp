#include "../include/hexagon.h"
#include <cmath>


// Создаём фигуру из 6 точек
Hexagon::Hexagon() : Figure(6){}

// Вычисление площади методом Гаусса
Hexagon::operator double() const {
    double s = 0.0;
    for(size_t i = 0; i < 6; ++i){
        size_t j = (i + 1) % 6;
        s += points[i].get_x() * points[j].get_y() - points[j].get_x() * points[i].get_y();
    }
    return 0.5 * std::fabs(s);
}

// Геометрический центр фигуры 
Point Hexagon::getCenter() const {
    const double EPS = 1e-6;
    double area = static_cast<double>(*this);
    if (area < EPS){
        return Point(0.0, 0.0);
    }

    double cx = 0.0;
    double cy = 0.0;
    for (size_t i = 0; i < 6; ++i){
        size_t j = (i + 1) % 6;
        double cross = points[i].get_x() * points[j].get_y() - points[j].get_x() * points[i].get_y();
        cx += (points[i].get_x() + points[j].get_x()) * cross;
        cy += (points[i].get_y() + points[j].get_y()) * cross;
    }

    cx /= (6.0 * area);
    cy /= (6.0 * area);

    return Point(cx, cy);
}

bool Hexagon::isCorrect() const {
    return points.size() == 6 && double(*this) > 1e-6;
}

