//
// Created by tasneem on 29/04/2020.
//

#ifndef HW2_BEVERAGESTORE_H
#define HW2_BEVERAGESTORE_H

#include <iostream>
#include "Customer.h"
#include "BookkeepingEntry.h"
#include "BeverageItem.h"
#include "DynamicArray.h"

namespace OOP_Hw2{
    class BeverageStore{
    private:
        DynArray<BeverageItem> BeverageArr;
        int amount_of_beverages;
        DynArray<int> ClubMembersArr;
        int amount_of_members;
        DynArray<BookkeepingEntry> ManageArr;
        int amount_of_manager;
        double total_income;
        double discount;
    public:
        BeverageStore(double  clubMembersDiscountPercent  =  0.0);
        BeverageStore&  AddClubMember(int  id);
        BeverageStore&  AddBeverage(const BeverageItem&  beverage);
        bool  BuyBeverage(const  std::string&  beverageName,  const  Customer&  customer);
        double TotalIncome() const;
        friend std::ostream& operator<<(std::ostream&  outputStream,  const  BeverageStore&  beverageStore){
            double price;
            std::string name_of_bev,name_of_person;

            for (int i = 0; i < beverageStore.amount_of_manager ; ++i) {
                price=beverageStore.ManageArr[i].price;
                name_of_bev=beverageStore.ManageArr[i].name_of_bev;
                name_of_person=beverageStore.ManageArr[i].name_of_customer;
                if(beverageStore.ManageArr[i].succeess){
                    outputStream<<i+1<<") "<<name_of_person<<" bought '"<< name_of_bev <<"'"<<" with "<< price <<" shekels"<<std::endl;
                } else{
                    outputStream<<i+1<<") "<<name_of_person<<" request for buying '"<<name_of_bev<<"'"<<" was rejected"<<std::endl;
                }
            }
            return outputStream;
        }
        /*---------------- HELPER FUNCTIONS -------------------- */
        int getBeverageArraySize()const ;
        int getMembersArraySize()const ;
        int getManageArraySize()const ;
        void AddToBook(BookkeepingEntry &purchase_try, bool had_success);
        bool existMember(int id)const;
        BeverageItem* existBeverage(const std::string& bev_name);


    };

}
#endif //HW2_BEVERAGESTORE_H
