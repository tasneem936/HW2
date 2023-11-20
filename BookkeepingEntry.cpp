//
// Created by tasneem on 29/04/2020.
//

#include "BookkeepingEntry.h"
#include "Customer.h"
#include "BeverageItem.h"
#include "DynamicArray.h"

int ID_COUNT=0;

using namespace OOP_Hw2;


BookkeepingEntry::BookkeepingEntry(const BookkeepingEntry &other)
:name_of_bev(other.name_of_bev),name_of_customer(other.name_of_customer) {
    this->is_alcohol=other.is_alcohol;
    this->price=other.price;
    this->succeess=other.succeess;
}
//////////////////////////////////////////////////////////////////////
//bool OOP_Hw2::operator==(const BookkeepingEntry &item1, const BookkeepingEntry &item2) {
//    return item1.id==item2.id;
//}
/////////////////////////////////////////////////////////////////////
BookkeepingEntry::BookkeepingEntry(const std::string &bev_name,const std::string &customer_name, int is_alcohol, double price)
:name_of_bev(bev_name),name_of_customer(customer_name) {
    this->is_alcohol=is_alcohol;
    this->price=price;
}




