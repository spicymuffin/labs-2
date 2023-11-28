#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    float bmi = 0;
    float weight = 0;
    float height = 0;

    cout << "input yo weight in kilograms: ";
    cin >> weight;
    cout << "input yo height in meters: ";
    cin >> height;

    bmi = weight / (height * height);

    cout << "yo BMI: " << bmi << endl;
    cout << "you are: ";

    if (bmi < 18.5)
    {
        cout << "Underweight" << endl;
    }
    else if (18.5 <= bmi && bmi <= 24.9)
    {
        cout << "Normal" << endl;
    }
    else if (25.0 <= bmi && bmi <= 29.9)
    {
        cout << "Overweight (Obesity Grade IV)" << endl;
    }
    else if (30.0 <= bmi && bmi <= 34.9)
    {
        cout << "Obesity Grade II" << endl;
    }
    else if (35.0 <= bmi && bmi <= 39.9)
    {
        cout << "Obesity grade III" << endl;
    }
    else if (bmi > 40.0)
    {
        cout << "Obesity Grade IV" << endl;
    }
}