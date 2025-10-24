#include "../include/figure.h"
#include <cmath>

Figure::Figure(size_t n) : points(n) {}

Figure::Figure(const Figure& other) : points(other.points) {}

Figure::Figure(Figure&& other) noexcept : points(std::move(other.points)) {}

Figure& Figure::operator=(const Figure& other){
    if (this != &other){
        points = other.points;
    }
    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept{
    if (this != &other){
        points = std::move(other.points);
    }
    return *this;
}

bool Figure::operator==(const Figure& other) const{
    const double EPS = 1e-6;
    if (points.size() != other.points.size()){
        return false;
    }

    for (size_t i = 0; i < points.size(); ++i){
        if (std::abs(points[i].get_x() - other.points[i].get_x()) > EPS ||
            std::abs(points[i].get_y() - other.points[i].get_y()) > EPS){
                return false;
            }
    }
    return true;
}

std::ostream& operator<<(std::ostream& os, const Figure& f){
    for (const auto& p : f.points){
        os << p << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Figure& f){
    for (auto& p : f.points){
        is >> p;
    }
    return is;
}

