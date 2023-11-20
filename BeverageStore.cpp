//
// Created by tasneem on 29/04/2020.
//

#include "BeverageStore.h"
#include "BookkeepingEntry.h"
#include "DynamicArray.h"
#include <string>

using namespace OOP_Hw2;

#define LEGAL_AGE 18
#define DEFULT 1
#define FULL_PERCENT 100

/* ######################## HELPER FUNCTIONS ########################### */

int BeverageStore::getBeverageArraySize() const {
    return this->amount_of_beverages;
}
//--------------------------------------------------//
int BeverageStore::getMembersArraySize() const {
    return this->amount_of_members;
}
//-------------------------------------------------//
int BeverageStore::getManageArraySize() const {
    return this->amount_of_manager;
}
//-------------------------------------------------//
// check if the given id belongs to one of the Club-member customers
bool BeverageStore::existMember(int id) const {
    for (int i = 0; i <this->amount_of_members ; ++i) {
        if(id==ClubMembersArr[i])
            return true;
    }
    return false;
}
//------------------------------------------------//
BeverageItem*  BeverageStore::existBeverage(const std::string &bev_name) {
    for (int i = 0; i < this->amount_of_beverages ; ++i) {
        if(bev_name==this->BeverageArr[i].GetName()){
            return &(BeverageArr[i]);

        }
    }
    return NULL  ;
}

//----------------------------------------------------------//

/* ############################ END OF HELPER FUNCTIONS ########################### */

//---------------------------------------------------------//
// c'tor
BeverageStore::BeverageStore(double clubMembersDiscountPercent) {
    this->amount_of_beverages=0;
    this->amount_of_members=0;
    this->amount_of_manager=0;
    this->total_income=0;
    this->discount=clubMembersDiscountPercent;
}
//--------------------------------------------------//
BeverageStore &BeverageStore::AddClubMember(int id) {
    this->ClubMembersArr+=(id);
    this->amount_of_members++;
    return *this;
}
//-------------------------------------------------//
BeverageStore &BeverageStore::AddBeverage(const BeverageItem &beverage) {
    this->BeverageArr+=beverage;
    this->amount_of_beverages++;
    return *this;
}
//-------------------------------------------------//
void BeverageStore::AddToBook(BookkeepingEntry &purchase_try, bool had_success) {
    purchase_try.succeess=had_success;
    if(had_success){
        total_income+=purchase_try.price;
    }
    this->ManageArr+=purchase_try;
    this->amount_of_manager++;
}
//-----------------------------------------------//
bool BeverageStore::BuyBeverage(const std::string &beverageName, const Customer &person) {
    //__________ PARAMETERS ______//
    int id = person.GetId();
    int age = person.GetAge();
    int is_alcohol;
    double bev_price;
    std::string customer_name=person.GetName();
    double store_discount=this->discount;
    int bev_exist;
    bool member_exist;
    BeverageItem* temp_bev=NULL;
    //____ END OF PARAMETERS____//

    temp_bev=existBeverage(beverageName);     //////////////////////////////////////////////////////////////////
    member_exist=existMember(id);            ///// LOOK FORWARD THE BEVERAGE AND THE BUYER IN THE STOR ////////
                                           ///////////////////////////////////////////////////////////////////

    if( temp_bev!=NULL){
        is_alcohol=temp_bev->IsAlcoholic();
        if((is_alcohol && age >= LEGAL_AGE )|| !is_alcohol ){
            if(member_exist){ // this is a successful purchase with discount
        bev_price=((FULL_PERCENT-store_discount)/FULL_PERCENT)*(temp_bev->GetPrice());
        is_alcohol=temp_bev->IsAlcoholic();
        BookkeepingEntry purchase_try(beverageName,customer_name,is_alcohol,bev_price);
        this->AddToBook(purchase_try, true);
        return true;
        } else
            {
                // this is a successful purchase without discount
                bev_price=temp_bev->GetPrice();
                is_alcohol=temp_bev->IsAlcoholic();
                BookkeepingEntry purchase_try(beverageName,customer_name,is_alcohol,bev_price);
                this->AddToBook(purchase_try, true);
                return true;

            }
        }
    }
        BookkeepingEntry purchase_try(beverageName,customer_name,DEFULT,DEFULT);
        this->AddToBook(purchase_try, false);
        return false;
    }

//-------------------------------------------------//
double BeverageStore::TotalIncome() const {
    return total_income;
}
//-------------------------------------------------//
//std::ostream& OOP_Hw2::operator<<(std::ostream &outputStream, const BeverageStore &beverageStore) {
//    double price;
//    std::string name_of_bev,name_of_person;
//
//    for (int i = 0; i < beverageStore.amount_of_manager ; ++i) {
//        price=beverageStore.ManageArr[i].price;
//        name_of_bev=beverageStore.ManageArr[i].name_of_bev;
//        name_of_person=beverageStore.ManageArr[i].name_of_customer;
//        if(beverageStore.ManageArr[i].succeess){
//            outputStream<<i+1<<") "<<name_of_person<<" bought '"<< name_of_bev <<"'"<<" with "<< price <<" shekels"<<std::endl;
//        } else{
//            outputStream<<i+1<<") "<<name_of_person<<" request for buying '"<<name_of_bev<<"'"<<" was rejected"<<std::endl;
//        }
//    }
//    return outputStream;
//}
//------------------------------------------------//


