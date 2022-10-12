#pragma once

#include <ostream>
#include <iostream>
#include <initializer_list>

#include "config.h"
using namespace std;

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector(){
        for(int i = 0; i < NDIM; i++)
        {
            vect_coords[i] = 0;
        }
    };
    Vector(initializer_list<int> li)
    {
        int count = 0;
        for (int element : li) {
            vect_coords[count] = element;
            ++count;
        }
    };
    // possibly more
// Public Member functions here
    const int& operator[](size_t pos) const;
    int& operator[](size_t pos);
    Vector& operator+=(const Vector& rhs);
    Vector& operator+=(int scalar);
    Vector& operator-=(const Vector& rhs);
    
    // More to go

private:
// Private Member functions here
    int vect_coords[NDIM];
// Member variables are ALWAYS private, and they go here
};

// Nonmember function operators go here
ostream& operator<<(ostream& os, const Vector& rhs);
Vector operator+(const Vector& lhs, const Vector& rhs);
Vector operator-(const Vector& lhs, const Vector& rhs);
Vector operator*(Vector& rhs, const value a);
//Vector operator*(const Vector& lhs, int scalar);
//Vector operator*(int scalar, const Vector& rhs);
int operator*(const Vector& lhs, const Vector& rhs);
Vector operator*=(Vector& rhs, const value a);
