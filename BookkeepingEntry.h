//
// Created by tasneem on 29/04/2020.
//

#ifndef HW2_BOOKKEEPINGENTRY_H
#define HW2_BOOKKEEPINGENTRY_H

#include "Customer.h"
#include "BeverageItem.h"

namespace OOP_Hw2{
    class BookkeepingEntry{
    public:
      //  int id;
        const std::string name_of_customer;
        const std::string name_of_bev;
        int is_alcohol;
        double price;
        bool succeess;
        BookkeepingEntry(const std::string &bev_name,const std::string &customer_name,int is_alcohol, double price);
        BookkeepingEntry(const BookkeepingEntry& other);
       // friend bool operator==(const BookkeepingEntry &item1, const BookkeepingEntry &item2);
    };
}

#endif //HW2_BOOKKEEPINGENTRY_H
