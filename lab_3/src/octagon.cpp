#include "../include/octagon.h"
#include <cmath>

// Создаём фигуру из 8 точек
Octagon::Octagon() : Figure(8){}

// Вычисление площади с помощью формулы Гаусса
// универсальной для любых многоугольников
Octagon::operator double() const {
    double area = 0.0;
    for(size_t i = 0; i < 8; ++i){
        size_t j = (i + 1) % 8;
        area += points[i].get_x() * points[j].get_y() - points[j].get_x() * points[i].get_y();
    }
    return 0.5 * std::fabs(area);
}

const char* Octagon::getName() const {
    return "Octagon";
}

// Геометрический центр фигуры 
Point Octagon::getCenter() const {
    const double EPS = 1e-6;
    double area = static_cast<double>(*this);
    if (area < EPS){
        return Point(0.0, 0.0);
    }

    double cx = 0.0;
    double cy = 0.0;
    for (size_t i = 0; i < 8; ++i){
        size_t j = (i + 1) % 8;
        double cross = points[i].get_x() * points[j].get_y() - points[j].get_x() * points[i].get_y();
        cx += (points[i].get_x() + points[j].get_x()) * cross;
        cy += (points[i].get_y() + points[j].get_y()) * cross;
    }

    cx /= (6.0 * area);
    cy /= (6.0 * area);

    return Point(cx, cy);
}

bool Octagon::isCorrect() const {
    const double EPS = 1e-6;
    
    if (size != 8)
        return false;

    for (int i = 0; i < 8; ++i){
        for (int j = i + 1; j < 8; ++j){
            double dx = points[i].get_x() - points[j].get_x();
            double dy = points[i].get_y() - points[j].get_y();
            if (std::sqrt(dx * dx + dy * dy) < EPS){
                return false;
            }
        }
    }

    double dx0 = points[1].get_x() - points[0].get_x();
    double dy0 = points[1].get_y() - points[0].get_y();
    double base_side = std::sqrt(dx0 * dx0 + dy0 * dy0);

    for (int i = 1; i < 8; ++i) {
        int j = (i + 1) % 8;
        double dx = points[j].get_x() - points[i].get_x();
        double dy = points[j].get_y() - points[i].get_y();
        double curr_side = std::sqrt(dx * dx + dy * dy);

        if (std::fabs(curr_side - base_side) > EPS) {
            return false;
        }
    }

    return static_cast<double>(*this) > EPS;
}
