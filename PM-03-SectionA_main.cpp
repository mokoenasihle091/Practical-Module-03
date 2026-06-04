#include <iostream>
using namespace std;

//Create a Parent class which calculates the area of a rectangle
//create a constructor function to create and initialise a new object which intakes in 2 parameters which is length and width
//create a child class which calculates the volume of rectangle
//create a second child class which checks whether is it really a rectangle or a square



class Rectangle{

public:
    double length;
    double width;
    int speed;

    // Constructor
     Rectangle(double l, double w){

        length = l;
        width = w;
        speed = 0;
    }

    // Calculate Area
    virtual double Area() {

        return length * width;
    }
};

// Child Class 1 - Calculate Volume
class VolumeRectangle : public Rectangle
{
public:
    double height;

    VolumeRectangle(double l, double w, double h)
        : Rectangle(l, w)
    {
        height = h;
    }

    // Overriding
    double Area() override
    {
        return length * width * height;
    }
};

// Child Class 2 - Check Shape
class ShapeChecker : public Rectangle
{
public:
    ShapeChecker(double l, double w)
        : Rectangle(l, w)
    {
    }

    void checkShape() {

        if (length == width)
            cout << "Square" << "\n";
        else
            cout << "Rectangle" << "\n";
    }
};

// Book Class
class Book
{
public:
    string title;

    Book(string t) {

        title = t;
    }
};

int main()
{
    // PA0109 - Multiple Objects
    VolumeRectangle obj1(10, 5, 2);
   // VolumeRectangle obj2(4, 3, 2);

    // Dot Operator
    cout << "Length of obj1: " << obj1.length << "\n";
    cout << "Length of obj2: " << obj1.length << "\n";

    // Object State
    obj1.speed = 60;
    cout << "Speed: " << obj1.speed << "\n";

    //Area Calculation
    Rectangle rect(10, 5);
    cout << "Area = " << rect.Area() << "\n";

    // Method Overriding
    cout << "Volume = " << obj1.Area() << "\n";

    // Shape Check
    ShapeChecker shape(8, 8);
    shape.checkShape();

    // PA0110 - Book Class with Three Instances
    Book b1("C++ Basics");
    Book b2("48 Laws of Power");
    Book b3("Harry Potter");

    cout << "Books:" << "\n";
    cout << b1.title << "\n";
    cout << b2.title << "\n";
    cout << b3.title << "\n";

    return 0;
}
