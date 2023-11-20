//
// Created by tasneem on 28/04/2020.
//

#ifndef HW2_DYNAMICARRAY_H
#define HW2_DYNAMICARRAY_H

#define Zero 0
#include <iostream>
#define INIT_SIZE 4

namespace OOP_Hw2
{

template <class T>
class DynArray{
private:
    T** data; // pointer to array of pointers
    int size; // array size include the empty and non empty cells
    int elements; // number of actual elements in the array
public:

    DynArray()
    {
        this->size=INIT_SIZE;
        this->elements=0;
        this->data=new T*[INIT_SIZE];
        initialize();
    }
///////////////////////////////////////
    DynArray(const DynArray& other){
        this->data=new T*[other.size];
        for (int i = 0; i <other.size; i++)
        {
            if(other.data[i]!= NULL)
            {
                data[i] =new T(*other.data[i]);
            }
            else
                data[i]=NULL;
        }
        this->size=other.size;
        this->elements=other.elements;
    }
////////////////////////////////////
    ~DynArray(){
        for (int i = 0; i <this->size ; ++i) {
            delete data[i];
        }
        delete[] data;
    }
//////////////////////////////////
    void expandSize(){
        int new_size=size*2;
        T** tempArray=new T*[new_size];
        for (int i = 0; i < elements ; ++i) { // copy the elements to the new array
            tempArray[i]=new T(*data[i]);
        }
        for (int j = 0; j < size; ++j) { // delete the smaller array
            delete data[j];
        }
        delete[] data;

        this->size=new_size;
        this->data=tempArray;
        this->initialize(elements); /* let all the new cells points to NULL */
    }
    /////////////////////////////////
    void initialize(int from=Zero){
        for (int i = from; i <this->size ; ++i) {
            this->data[i]=NULL;
        }
    }
    //////////////////////////////////////
    int numOfElement(){
        return this->elements;
    }
    //////////////////////////////////////
    T& operator[](int index){
        return *(this->data[index]);
    }

    /////////////////////////////////////

    const T& operator[](int index)const {
        return *(this->data[index]);
    }

///////// FRIENDS //////////////

    T& operator+=(const T& object){
        if(size==elements){
            expandSize();
        }
        data[elements]=new T(object);
        elements++;
        return *(this->data[elements-1]);
    }
};
}


#endif //HW2_DYNAMICARRAY_H
