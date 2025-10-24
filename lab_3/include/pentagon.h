#pragma once
#include "figure.h"

class Pentagon : public Figure{
public:
    Pentagon();
    explicit Pentagon(double radius);
    virtual ~Pentagon() = default;

    virtual Point getCenter() const override;
    virtual bool isCorrect() const override;
    explicit operator double() const override;
};

