// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
#include <iostream>
#include "Array.h"


/**
 * @brief Default Construct a new Array object.
 * 
 */
Array::Array (void)
: data_     (nullptr),
  cur_size_ (0),
  max_size_ (0)
{}

/**
 * @brief Construct a new Array object with 
 *        provided length of array.
 * 
 * @param length 
 */
Array::Array (size_t length)
: data_     (new char [length]),
  cur_size_ (length),
  max_size_ (length)
{}

/**
 * @brief Construct a new Array object with 
 *        provided length and contents of array.
 * 
 * @param length 
 * @param fill 
 */
Array::Array (size_t length, char fill)
: data_     (new char [length]),
  cur_size_ (length),
  max_size_ (length)
{
    for(int i = 0; i<cur_size_; i++){
        data_[i] = fill;
    }
}

/**
 * @brief Copy Construct a new Array object.
 * 
 * @param arr 
 */
Array::Array (const Array & arr)
// COMMENT The copy constructor needs to create a deep copy of the source array. Otherwise,
// the copy will share a pointer with the original. When one goes out of scope, the other
// will eventually crash.
// 
// Solution: Alocated data_ to hold memory for the max size of the array then made a deep
// copy of the array on to data_ by copying every element 
: data_     (new char [arr.max_size_]),
  cur_size_ (arr.cur_size_),
  max_size_ (arr.max_size_)
{   
    for(int i = 0; i<cur_size_; i++){
        data_[i] = arr.data_[i];
    }
}

/**
 * @brief Destroy the Array object.
 * 
 */
Array::~Array (void)
{
    // COMMENT Do not catch the exception here. Instead, let it client decide
    // how to handle it. I know this was shown in the exception handling slides, but
    // it was show to illustrate failure transparency. We do not want that here.
    // 
    // Solution: Removed try-catch code 
    delete [] data_;
}

/**
 * @brief sets whatever is on the left of the equals
 *        sign to what is on the right side.
 * 
 * @param rhs 
 * @return const Array& 
 */
const Array & Array::operator = (const Array & rhs)
{
    // COMMENT Check for self assignment first.
    // 
    // Solution: If the objects are the same then return itself but if they are
    // different then copy rhs

    // COMMENT This method needs to copy the elements from 'rhs' to 'this'.
    // 
    // Solution: Delete old data_ memory to alocate the amount of space that the
    // new object has then copy all of new elements to data_ 

    if(this != &rhs){

        delete [] this->data_;
        this->data_ = new char [rhs.max_size_];

        for(int i = 0; i< rhs.cur_size_; i++){
            this->data_[i] = rhs.data_[i];
        }

        this->cur_size_ = rhs.cur_size_;
        this->max_size_ = rhs.max_size_;
    }

    return *this;
}

/**
 * @brief Returns the element in the array that is
 *        in the specified position
 * 
 * @param index 
 * @return char& 
 */
char & Array::operator [] (size_t index)
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.
    // 
    // Solution: Added a try-catch block that throws and exception of the index
    // is greater than the current size of data_

    try{
        if(index > this->cur_size_){
            throw 999;
        }
        return *(this->data_ + index);
    }
    catch(int oor){
        std::cout << "--INDEX OUT OF RANGE--" << std::endl;
    }
}

/**
 * @brief Returns the element in the array that is
 *        in the specified position.
 * 
 * @param index 
 * @return const char& 
 */
const char & Array::operator [] (size_t index) const
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.
    // 
    // Solution: Added a try-catch block that throws and exception of the index
    // is greater than the current size of data_

    try{
        if(index > cur_size_){
            throw 999;
        }
        return *(this->data_ + index);
    }
    catch(int oor){
        std::cout << "--INDEX OUT OF RANGE--" << std::endl;
    }
}

/**
 * @brief Returns the element in the requested index
 *        of the array.
 * 
 * @param index 
 * @return char 
 */
char Array::get (size_t index) const
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.
    // 
    // Solution: Added a try-catch block that throws and exception of the index
    // is greater than the current size of data_

    try{
        if(index > cur_size_){
            throw 999;
        }
        return data_[index];
    }
    catch(int oor){
        std::cout << "--INDEX OUT OF RANGE--" << std::endl;
    }

}

/**
 * @brief Sets the selected element equal to the 
 *        requested char value.
 * 
 * @param index 
 * @param value 
 */
void Array::set (size_t index, char value)
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.
    // 
    // Solution: Added a try-catch block that throws and exception of the index
    // is greater than the current size of data_

    try{
        if(index > cur_size_){
            throw 999;
        }
        data_[index] = value;
    }
    catch(int oor){
        std::cout << "--INDEX OUT OF RANGE--" << std::endl;
    }

}

/**
 * @brief resizes the array to the new requested size.
 * 
 *        if the new size is less than the current max size 
 *        then the current size of the array is swaped with the new size.
 * 
 *        if the new size is larger than the current max size
 *        then a temp array of the requested size is made and 
 *        filled with the elements of the old array. Then the 
 *        old array is replaced with the new array along with 
 *        the max and current size variable being set to the new value.
 * 
 * @param new_size  (must be > 0)
 */
void Array::resize (size_t new_size)
{
    // COMMENT size_t can never be less than 0
    // 
    // Solution: Changed if statment to only check if its equal to zero then make the 
    // data_ equal to nullptr if it is

    if(new_size == 0){
        delete [] data_;
        data_ = nullptr;
    }
    else if (new_size < max_size_){
        cur_size_ = new_size;
    }
    else if (new_size > max_size_)
    {
        char * temp = new char [new_size];
        for(int i=0; i<cur_size_; i++){
            temp[i] = data_[i];
        }

        delete [] data_;
        data_ = temp;
        
        // COMMENT You code will eventually crash because you are deleting
        // the memory you just stored in data_.
        // 
        // Solution: Removed the deletion of temp's memory

        max_size_ = new_size;
        cur_size_ = new_size;
    }
    
}

/**
 * @brief Finds the requested char and returns its position by 
 *        searching though all elements in the array until it is found.
 *        if its not found -1 will be returned insted.
 * 
 * @param ch 
 * @return int 
 */
int Array::find (char ch) const
{
    for(int i = 0; i<cur_size_; i++){
        if(data_[i] == ch){
            return i;
        }
    }

    return -1;
}

/**
 * @brief Finds the requested char and returns its position by 
 *        searching though all elements in the array at and beyond 
 *        the starting position until it is found. If its not found 
 *        -1 will be returned insted.
 * 
 * @param ch 
 * @param start 
 * @return int 
 */
int Array::find (char ch, size_t start) const
{
    for(int i = start; i<cur_size_; i++){
        if(data_[i] == ch){
            return i;
        }
    }

    return -1;
}

/**
 * @brief Tests to see if what is on the left side of the comparison
 *        opperator == is the same as what is on the right side.
 * 
 * @param rhs 
 * @return true 
 * @return false 
 */
bool Array::operator == (const Array & rhs) const
{
    // COMMENT This is not the correct way to check for comparision.
    // Right now, you are comparing a pointer address to a reference.
    // 
    // Solution: First checking to see if the sizes are the same then 
    // comparing every element to the current size of the arrays

    // COMMENT Two arrays are equal if there content is the same. Just
    // comparing the address of the arrays will not suffice.
    // 
    // Solution: Comparing every element of both arrays with a for loop
    // to see if the elements of both arrays are the same
    
    if (this->cur_size_ != rhs.cur_size_){
        return false;
    }

    for(int i = 0; i<this->cur_size_; i++){
        if(this->data_[i] != rhs.data_[i]){
            return false;
        }
    }

    return true;
    
}

/**
 * @brief Tests to see if what is on the left side of the comparison
 *        opperator != is different to what is on the right side.
 * 
 * @param rhs 
 * @return true 
 * @return false 
 */
bool Array::operator != (const Array & rhs) const
{
    // COMMENT You can define operator != in terms of operator ==.
    // 
    // Solution: Compared array sizes to see if they are different then
    // compared every element in the arrays to see if there are differences

    if (this->cur_size_ != rhs.cur_size_){
        return true;
    }

    for(int i = 0; i<this->cur_size_; i++){
        if(this->data_[i] != rhs.data_[i]){
            return true;
        }
    }

    return false;
}

/**
 * @brief Sets all entities in the array to the requested char.
 * 
 * @param ch 
 */
void Array::fill (char ch)
{
    for(int i = 0; i<cur_size_; i++){
        data_[i] = ch;
    }
}

/**
 * @brief Gets rid of all the excess space in the array by
 *        creating a new array of the current size and setting 
 *        all the elements up to the current size of the old array 
 *        to the new array and sets the max size to the current size.
 * 
 */
void Array::shrink (void)
{
    if(cur_size_ != max_size_){

        char * temp = new char [cur_size_];
        for(int i=0; i<cur_size_; i++){
            temp[i] = data_[i];
        }

        delete [] data_;
        data_ = temp;
        
        // COMMENT You code will eventually crash because you are deleting
        // the memory you just stored in data_.
        // 
       // Solution: Removed the deletion of temp's memory

        max_size_ = cur_size_;
    }
}

/**
 * @brief Reverses the contents of the array.
 * 
 */
void Array::reverse (void)
{
    char temp;
    for(int i = 0; i<(cur_size_/2); i++){
        temp = data_[(cur_size_ - 1 - i)];
        data_[(cur_size_ - 1 - i)] = data_[i];
        data_[i] = temp;
    }
}

/**
 * @brief Makes a copy of the array at the 
 *        requested start position.
 * 
 * @param begin 
 * @return Array 
 */
Array Array::slice (size_t begin) const
{
    Array * new_arr = new Array (cur_size_ - begin);
    new_arr->data_ = (this->data_ + begin);
    new_arr->cur_size_ = cur_size_ - begin;
    new_arr->max_size_ = cur_size_ - begin;
    return *new_arr;
}

/**
 * @brief Makes a copy of the array at the 
 *        requested start and stop positions.
 * 
 * @param begin 
 * @param end 
 * @return Array 
 */
Array Array::slice (size_t begin, size_t end) const
{
    Array * new_arr = new Array ((end + 1) - begin);
    
    int c = 0;
    for(int i = begin; i<(end + 1); i++){
        new_arr->data_[c] = this->data_[i];
        c++;
    }
    new_arr->cur_size_ = (end + 1) - begin;
    new_arr->max_size_ = (end + 1) - begin;

    return *new_arr;
}