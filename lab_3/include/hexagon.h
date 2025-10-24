#pragma once
#include "figure.h"

class Hexagon : public Figure{
public:
    Hexagon();
    explicit Hexagon(double radius);
    virtual ~Hexagon() = default;

    virtual Point getCenter() const override;
    virtual bool isCorrect() const override;
    virtual const char* getName() const override;
    explicit operator double() const override;
};
