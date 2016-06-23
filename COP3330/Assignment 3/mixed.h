/*
Programmers Name: John Stubbs
      Assignment: #3
            Date: 2/15/13

This file defines the Mixed class
*/
#ifndef MIXED_H
#define MIXED_H
#include <iostream>

using namespace std;

class Mixed
{
    friend istream& operator>>(istream& s, Mixed& m);
    friend ostream& operator<<(ostream& s, const Mixed& m);
    friend const Mixed operator+(const Mixed m1, const Mixed m2);
    
    private:
        int interger;
        int num;
        int den;

    public:
        Mixed(int i = 0);
        Mixed(int i, int n, int d);
        double Evaluate();
        void ToFraction();
        void Simplify();
        int Lcd();
        Mixed operator++();
        Mixed operator++(int);
        Mixed operator--();
        Mixed operator--(int);
        bool operator==(const Mixed m1);
        bool operator!=(const Mixed m1);
        bool operator>=(const Mixed m1);
        bool operator<=(const Mixed m1);
        bool operator>(const Mixed m1);
        bool operator<(const Mixed m1);
        const Mixed operator-(const Mixed m1);
        const Mixed operator*(const Mixed m1);
        const Mixed operator/(const Mixed m1);
};
#endif
