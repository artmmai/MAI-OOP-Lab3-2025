#pragma once
#include "figure.h"

class Octagon : public Figure{
public:
    Octagon();
    explicit Octagon(double radius);
    virtual ~Octagon() = default;

    virtual Point getCenter() const override;
    virtual bool isCorrect() const override;
    explicit operator double() const override;
};
