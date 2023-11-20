//
// Created by tasneem on 29/04/2020.
//

#include "BeverageItem.h"
#define ONE 1
#define ZERO 0

using namespace OOP_Hw2;

BeverageItem::BeverageItem(std::string &name, double price):name(name),price(price){}
/* ------------------------------------ */
bool BeverageItem::IsAlcoholic() const {
    return this->is_alcohol;
}
//--------------------------------------//
const std::string &BeverageItem::GetName() const {
    return this->name;
}
//-------------------------------------------//
double BeverageItem::GetPrice() const {
    return this->price;
}
//-----------------------------------------//
void BeverageItem::SetPrice(double newPrice) {
    this->price=newPrice;
}
//-----------------------------------------//
BeverageItem BeverageItem::CreateAlcoholic(const std::string &name, double price) {
    BeverageItem temp=BeverageItem();
    temp.name=name;
    temp.price=price;
    temp.is_alcohol=ONE;
    BeverageItem *item=new BeverageItem(temp);
    return *item;
}
//---------------------------------------//
BeverageItem BeverageItem::CreateNonAlcoholic(const std::string &name, double price) {
    BeverageItem temp=BeverageItem();
    temp.name=name;
    temp.price=price;
    temp.is_alcohol=ZERO;
    BeverageItem *item=new BeverageItem(temp);
    return *item;
}
//-----------------------------------------------------------//
BeverageItem& BeverageItem::operator=(const BeverageItem &item) {
    if(this==&item) /* if they are the same object */
        return *this;

    this->name=item.name;
    this->price=item.price;
    this->is_alcohol=item.is_alcohol;

    return *this;
}
/* -------------------------------------------------------- */
BeverageItem::BeverageItem(const BeverageItem &other) {
    this->name=other.name;
    this->price=other.price;
    this->is_alcohol=other.is_alcohol;

}
/* -------------------------------------------------------- */

BeverageItem::BeverageItem() {} // default constructor

