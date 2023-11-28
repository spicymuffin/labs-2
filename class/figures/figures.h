#ifndef FIGURES_H
#define FIGURES_H

#include <iostream>
#include <string>

class Figure
{
    virtual void draw();
};

class Rectangle : Figure
{
    virtual void draw();
};

class Circle : Figure
{
    virtual void draw();
};

class Triangle : Figure
{
    virtual void draw();
};

#endif