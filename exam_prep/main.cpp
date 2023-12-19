#include <iostream>
#include <string>
#include <vector>

#include "vector2d.h"
#include "vector3d.h"

using namespace std;

void reverse_cstring(char *c_string, int max_length);
void print_canvas(char **canvas, int width, int height);

class Date
{
public:
    Date() = default;
    Date(int _year, int _month, int _day);

protected:
    int year;
    int month;
    int day;
};

Date::Date(int _year, int _month, int _day)
{
    year = _year;
    month = _month;
    day = _day;
}

class DateTime : public Date
{
public:
    DateTime(int _year, int _month, int _day, int _hour, int _minute, int _second);

private:
    int hour;
    int minute;
    int second;
};

DateTime::DateTime(int _year, int _month, int _day, int _hour, int _minute, int _second) : Date(_year, _month, _day)
{
    hour = _hour;
    minute = _minute;
    second = _second;
}

class Pet
{
public:
    Pet(string _name, Date _dateOfBirth);

    const string getName() const;

    virtual string makeSound() = 0;

protected:
    string name;
    Date dateOfBirth;
};

Pet::Pet(string _name, Date _dateOfBirth)
{
    name = _name;
    dateOfBirth = _dateOfBirth;
}

const string Pet::getName() const
{
    return name;
}

class Dog : public Pet
{
public:
    Dog(string _name, Date _dateOfBirth, string _breed);

    virtual string makeSound();
    // virtual friend ostream &operator<<(ostream &outputStream, const Dog &rhs);

protected:
    string breed;
};

Dog::Dog(string _name, Date _dateOfBirth, string _breed) : Pet(_name, _dateOfBirth)
{
    breed = _breed;
}

string Dog::makeSound()
{
    return "woof";
}

class Cat : public Pet
{
public:
    Cat(string _name, Date _dateOfBirth, string _breed);

    virtual string makeSound();

protected:
    string breed;
};

Cat::Cat(string _name, Date _dateOfBirth, string _breed) : Pet(_name, _dateOfBirth)
{
    breed = _breed;
}

string Cat::makeSound()
{
    return "meow";
}

string danya(Pet *danya2)
{
    return danya2->makeSound();
}

template <typename T>
void swapValues(T &val1, T &val2)
{
    T temp = val1;
    val1 = val2;
    val2 = temp;
}

template <typename T>
class Pair
{
public:
    Pair() = default;
    Pair(T _element1, T _element2);

    T get1() const;
    T get2() const;

    void set1(T _element);
    void set2(T _element);

    const T addElements() const;

protected:
    T element1;
    T element2;
};

template <typename T>
Pair<T>::Pair(T _element1, T _element2)
{
    element1 = _element1;
    element2 = _element2;
}

template <typename T>
T Pair<T>::get1() const
{
    return element1;
}

template <typename T>
T Pair<T>::get2() const
{
    return element2;
}

template <typename T>
void Pair<T>::set1(T _element)
{
    element1 = _element;
}

template <typename T>
void Pair<T>::set2(T _element)
{
    element2 = _element;
}

template <typename T>
const T Pair<T>::addElements() const
{
    return element1 + element2;
}

int main(int argc, char *argv[])
{
    // Vector2D a;
    // Vector2D b;

    // a.setX(5);
    // a.setY(6);

    // Vector2D c(a);

    // cout << c << endl;
    // cout << ++a << endl;

    // int int_a = 0;
    // int int_b = 0;

    // int &ref_int_a = int_a;

    // int *ptr_int_a = &int_a;
    // int *ptr_int_b = &int_b;

    // char char_a = 'A';
    // char char_b = 'b';

    // cout << ptr_int_a + 1 << endl;

    // Vector3D a3d(-1, 3, 4);

    // cout << a3d << endl;
    // cout << Vector3D::forward << endl;

    // // cout << static_cast<int>(char_a) << endl;

    // char c_string[1024];

    // // cin >> c_string;

    // // reverse_cstring(c_string, 1024);

    // // cout << c_string << endl;

    // int h = 12;
    // int w = 30;

    // char **canvas = new char *[h];

    // for (int i = 0; i < h; i++)
    // {
    //     *(canvas + i) = new char[w];
    // }

    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         *(*(canvas + i) + j) = 'a';
    //     }
    // }

    // print_canvas(canvas, h, w);

    // Dog dog("max", Date(2023, 11, 15), "german shepard");
    // Cat cat("mishka", Date(2005, 1, 2), "english longhair");

    // Dog *dog_ptr = &dog;
    // Cat *cat_ptr = &cat;

    // Pet *ppet;
    // ppet = dog_ptr;

    // cout << dog_ptr->makeSound() << endl;
    // cout << danya(dog_ptr) << endl;
    // cout << danya(cat_ptr) << endl;

    int *p1, *p2;

    p1 = new int;
    p2 = new int;

    *p1 = 10;
    *p2 = 20;

    cout << *p1 << " " << *p2 << endl;

    *p1 = *p2;

    cout << *p1 << " " << *p2 << endl;

    *p1 = 30;

    cout << *p1 << " " << *p2 << endl;

    int v1 = 10;
    int v2 = 69;

    cout << v1 << " " << v2 << endl;
    swapValues(v1, v2);
    cout << v1 << " " << v2 << endl;

    typedef int *intptr;

    intptr pp1, pp2;

    pp1 = &v1;

    cout << *pp1 << endl;

    Pair<int> pair1 = Pair(1, 2);

    cout << pair1.addElements() << endl;

    Pair<int> pair2 = Pair(1, 3);

    Pair<Pair<int>> pairpair = Pair(pair1, pair2);

    cout << pairpair << endl;

    return 0;
}

void print_canvas(char **canvas, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << *(*(canvas + i) + j);
        }
        cout << endl;
    }
}

void reverse_cstring(char *c_string, int max_length)
{
    int null_index = -1;
    for (int i = 0; i < max_length; i++)
    {
        if (*(c_string + i) == '\0')
        {
            null_index = i;
            break;
        }
    }

    if (null_index == -1)
    {
        throw std::runtime_error("cstring has no null character");
    }

    for (int i = 0; i < (null_index / 2); i++)
    {
        char temp = *(c_string + (null_index - i - 1));
        *(c_string + (null_index - i - 1)) = *(c_string + i);
        *(c_string + i) = temp;
    }
}