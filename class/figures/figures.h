#ifndef FIGURES_H
#define FIGURES_H

#include <iostream>
#include <string>

class Figure
{
    virtual void draw() = 0;
    virtual void center() = 0;
    virtual ~Figure() = 0;
};

class Rectangle : Figure
{
    virtual void draw();
    virtual void center();
    virtual ~Rectangle();
};

class Circle : Figure
{
    virtual void draw();
    virtual void center();
};

class Triangle : Figure
{
    virtual void draw();
    virtual void center();
};

#endif