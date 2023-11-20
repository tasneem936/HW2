//
// Created by tasneem on 29/04/2020.
//

#ifndef HW2_BEVERAGEITEM_H
#define HW2_BEVERAGEITEM_H
#include <iostream>


namespace OOP_Hw2{
    class  BeverageItem{
            private:
            std::string name;
            double price;
            int is_alcohol; // boolean flag
            BeverageItem(std::string& name, double price);
            public:
            static BeverageItem CreateAlcoholic(const std::string& name, double price);
            static BeverageItem CreateNonAlcoholic(const std::string& name, double price);
            const std::string& GetName() const;
            double GetPrice() const;
            bool IsAlcoholic() const;
            void SetPrice(double newPrice);
            /*-------------------- HELPER FUNCTIONS ---------------------- */
            BeverageItem();
            BeverageItem(const BeverageItem &other); //copy c'tor
            BeverageItem& operator=(const BeverageItem &item); //assignment


    };
}


#endif //HW2_BEVERAGEITEM_H
