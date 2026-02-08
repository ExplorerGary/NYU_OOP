#include <iostream>
using namespace std;
class Complex{
  private:
    float real;
    float imaginary;
  public:
    Complex(){
      // To DO (set the default values)
      this->real = 0.0;
      this->imaginary = 0.0;
    }
    Complex(float r, float i){
      // To DO (set the values of real and imaginary)
      this->real = r;
      this->imaginary = i;
    }
    // the following operator will return a new instance of Complex
    Complex operator+(const Complex& rhs) const{
      // To DO
      float newReal = this->real + rhs.real;
      float newImaginary = this->imaginary + rhs.imaginary;
      return Complex(newReal, newImaginary);


    }
    Complex operator-(const Complex& rhs) const{
      // To DO
      float newReal = this->real - rhs.real;
      float newImaginary = this->imaginary - rhs.imaginary;
      return Complex(newReal, newImaginary);
    }
    Complex operator*(const Complex& other) const {
      // To DO
      float a = this->real;
      float b = this->imaginary;
      float c = other.real;
      float d = other.imaginary;
      float newReal = a * c - b * d;
      float newImaginary = a * d + b * c;
      return Complex(newReal, newImaginary);
    }
    Complex operator/(const Complex& other) const {
      // To DO
      float a = this->real;
      float b = this->imaginary;
      float c = other.real;
      float d = other.imaginary;
      float base = c * c + d * d;
      // handling the division by zero case, we return a zero complex number
      if (base == 0) {
        cout << "Division by zero encountered in complex division. Returning 0 + 0i." << endl;
        return Complex(0.0, 0.0);
      }
      float newReal = (a * c + b * d) / base;
      float newImaginary = (b * c - a * d) / base;
      return Complex(newReal, newImaginary);

    }
    Complex conjugate() const {
      // To DO
      return Complex(this->real, -this->imaginary);
    }

    string toString() const {
      if (this->imaginary >= 0)
        return to_string(this->real) + "+i" + to_string(this->imaginary);
      else
        return to_string(this->real) + "-i" + to_string(-this->imaginary);
    }

};