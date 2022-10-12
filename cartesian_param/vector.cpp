#include "vector.hh"

//Operator []
const int& Vector::operator[](size_t pos) const{
    return vect_coords[pos];
}

int& Vector::operator[](size_t pos){
    return vect_coords[pos];
}

/*Operator *=
Vector& Vector::operator*=(const Vector& rhs) {
    for (int i = 0; i < NDIM; i++) 
        vect_coords[i] *= rhs[i];
    
    return *this;
}*/

Vector operator*=(Vector &rhs, const value n)
{
    for (size_t i = 0; i <  NDIM; i++)
    {
        rhs[i] = rhs[i] * n;
    }
    return rhs;
}
//Operator *
Vector operator*(Vector& rhs,const value val)
{
    auto v = Vector();
    for (int i = 0; i < NDIM; i++)
        v[i] = rhs[i] * val;
    return v;
}

int operator*(const Vector& lhs, const Vector& rhs) {
    int sum = 0;
    for (int i = 0; i < NDIM; i++) {
        sum += lhs[i] * rhs[i];
    }
    return sum;
}

//Operator <<
std::ostream& operator<<(std::ostream &os, const Vector& rhs)
{
    os << "{";
    int i = 0;
    for (; i < NDIM - 1; i++)
        os << rhs[i] <<  ",";
    return os << "}";
}

//Operator +=

Vector& Vector::operator+=(int value)  {
    for (int i = 0; i < NDIM; i++)
        vect_coords[i] += value;
    return *this;
}
Vector& Vector::operator+=(const Vector& rhs) {
    for (int i = 0; i < NDIM; i++)
        vect_coords[i] += rhs[i];
    return *this;
    //for (int i = 0; i < rhs.getSize();i++)
    //  vect_coords[i] += rhs[i];
    //  return *this;
}

//Operator +
Vector operator+(const Vector& lhs, const Vector& rhs) {
    Vector new_v = Vector();
    for (int i = 0; i < NDIM; i++) {
        new_v[i] = lhs[i] + rhs[i];
    }
    return new_v;
}

//Operator -
Vector operator-(const Vector& lhs, const Vector& rhs)  {
    Vector new_v = Vector();
    for (int i = 0; i < NDIM; i++) {
        new_v[i] = lhs[i] - rhs[i];
    }
    return new_v;
}
//Operator -=
Vector& Vector::operator-=(const Vector& rhs){
    for (int i = 0; i < NDIM; i++)
        vect_coords[i] -= rhs[i];

    return *this;
}

