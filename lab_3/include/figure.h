#pragma once

#include <iostream>
#include <vector>
#include "point.h"

class Figure{
protected:
    std::vector<Point> points;

public:
    Figure() = default;
    Figure(size_t n);
    virtual ~Figure() = default;

    Figure(const Figure& other);
    Figure(Figure&& other) noexcept;

    Figure& operator=(const Figure& other);
    Figure& operator=(Figure&& other) noexcept;

    bool operator==(const Figure& other) const;

    virtual Point getCenter() const = 0;
    virtual bool isCorrect() const = 0;
    virtual operator double() const = 0; // площадь

    friend std::ostream& operator<<(std::ostream& os, const Figure& f);
    friend std::istream& operator>>(std::istream& is, Figure& f);

};