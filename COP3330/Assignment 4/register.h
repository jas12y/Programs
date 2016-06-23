/*
Programmers Name: John Stubbs
      Assignment: #4
            Date: 3/1/13

This file defines the Register class
*/
#ifndef REGISTER_H
#define REGISTER_H
#include <iostream>
#include "sale.h"

const int BLOCK_SIZE = 5;

using namespace std;

class Register : public Sale
{
    private:
    
        int id;
        double tillAmt;
        int current_empty;
        int current_size;
        Sale* Sales;
    
    public:
    
        Register(const int num, const double amt);
        ~Register();
        int GetID();
        double GetAmount();
        void RingUpSale(const ItemType item, const double price);
        void ShowLast();
        void ShowAll();
        void Cancel();
        double SalesTax(int num);
        void Grow();
        void Shrink();

};

#endif
