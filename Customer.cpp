//
// Created by tasneem on 29/04/2020.
//

#include "Customer.h"
#define LEGAL_AGE 18

using namespace OOP_Hw2;

 std::string Customer::GetName() const {
    return name;
}
/* ------------------------------------------------------ */
 int Customer::GetId() const {
    return id;
}
/* ------------------------------------------------------ */
 int Customer::GetAge() const {
    return age;
}
/* ------------------------------------------------------ */
Customer::Customer(std::string name, int age, int id) : name(name),age(age),id(id) {}
/* ------------------------------------------------------ */




