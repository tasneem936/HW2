//
// Created by tasneem on 29/04/2020.
//

#ifndef HW2_CUSTOMER_H
#define HW2_CUSTOMER_H

#include <iostream>

namespace OOP_Hw2{
    class Customer{
    private:
        const std::string name;
        const int id;
        const int age;
    public:
        Customer(std::string name, int age,int id);
         std::string GetName() const ;
         int GetAge() const ;
         int GetId() const ;


    };
}
#endif //HW2_CUSTOMER_H
