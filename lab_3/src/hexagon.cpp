#include "../include/hexagon.h"
#include <cmath>

// Создаём фигуру из 6 точек
Hexagon::Hexagon() : Figure(6){}

// Вычисление площади с помощью формулы Гаусса
// универсальной для любых многоугольников
Hexagon::operator double() const {
    double area = 0.0;
    for(size_t i = 0; i < 6; ++i){
        size_t j = (i + 1) % 6;
        area += points[i].get_x() * points[j].get_y() - points[j].get_x() * points[i].get_y();
    }
    return 0.5 * std::fabs(area);
}

const char* Hexagon::getName() const{
    return "Hexagon";
}

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
    const double EPS = 1e-6;

    for (int i = 0; i < 6; ++i){
        for (int j = i + 1; j < 6; ++j){
            double dx = points[i].get_x() - points[j].get_x();
            double dy = points[i].get_y() - points[j].get_y();
            if (std::sqrt(dx * dx + dy * dy) < EPS){
                return false;
            }
        }
    }
    return static_cast<double>(*this) > EPS;
}
