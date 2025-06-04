#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;

        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) {
        if (denom == 0) {
            std::cout << "Error: Denominator cannot be zero!" << std::endl;
            denom = 1;
        }
        numerator = num;
        denominator = denom;
        reduce();
    }

    void input() {
        std::cout << "Enter numerator: ";
        std::cin >> numerator;
        std::cout << "Enter denominator: ";
        std::cin >> denominator;
        if (denominator == 0) {
            std::cerr << "Error: Denominator cannot be zero. Reset to 1.\n";
            denominator = 1;
        }
        reduce();
    }

    void print() const {
        std::cout << numerator << "/" << denominator << std::endl;
    }

    Fraction add(const Fraction& other) {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction subtract(const Fraction& other) {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction multiply(const Fraction& other) {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction divide(const Fraction& other) {
        if (other.numerator == 0) {
            std::cerr << "Error: Division by zero fraction!" << std::endl;
            return Fraction(0, 1);
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }
};


int main() {
    Fraction f1, f2;

    std::cout << "Enter first fraction:\n";
    f1.input();

    std::cout << "Enter second fraction:\n";
    f2.input();

    std::cout << "Sum: ";
    f1.add(f2).print();

    std::cout << "Difference: ";
    f1.subtract(f2).print();

    std::cout << "Product: ";
    f1.multiply(f2).print();

    std::cout << "Quotient: ";
    f1.divide(f2).print();

    return 0;
}