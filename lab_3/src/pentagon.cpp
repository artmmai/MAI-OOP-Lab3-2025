#include "../include/pentagon.h"
#include <cmath>

// Создаём фигуру из 5 точек
Pentagon::Pentagon() : Figure(5){}

// Вычисление площади методом Гаусса
Pentagon::operator double() const {
    double area = 0.0;
    for(size_t i = 0; i < 5; ++i){
        size_t j = (i + 1) % 5;
        area += points[i].get_x() * points[j].get_y() - points[j].get_x() * points[i].get_y();
    }
    return 0.5 * std::fabs(area);
}

const char* Pentagon::getName() const {
    return "Pentagon";
}

// Геометрический центр фигуры 
Point Pentagon::getCenter() const {
    const double EPS = 1e-6;
    double area = static_cast<double>(*this);
    if (area < EPS){
        return Point(0.0, 0.0);
    }

    double cx = 0.0;
    double cy = 0.0;
    for (size_t i = 0; i < 5; ++i){
        size_t j = (i + 1) % 5;
        double cross = points[i].get_x() * points[j].get_y() - points[j].get_x() * points[i].get_y();
        cx += (points[i].get_x() + points[j].get_x()) * cross;
        cy += (points[i].get_y() + points[j].get_y()) * cross;
    }

    cx /= (6.0 * area);
    cy /= (6.0 * area);

    return Point(cx, cy);
}

bool Pentagon::isCorrect() const {
    const double EPS = 1e-6;
    if (size != 5){
        return false;
    }
    
    for (int i = 0; i < 5; ++i){
        for (int j = i + 1; j < 5; ++j){
            double dx = points[i].get_x() - points[j].get_x();
            double dy = points[i].get_y() - points[j].get_y();
            if (std::sqrt(dx * dx + dy * dy) < EPS){
                return false;
            }
        }
    }
    return static_cast<double>(*this) > EPS;
}

