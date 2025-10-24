#include "../include/array.h"
#include <iostream>
#include <stdexcept>

Array::Array() : arr(nullptr), size(0), capacity(0) {}

Array::~Array(){
    for (size_t i =0; i < size; ++i){
        delete arr[i];
    }
    delete[] arr;
}

void Array::resize(size_t newCapacity){
    Figure** newArr = new Figure*[newCapacity];
    for (size_t i = 0; i < size; ++i){
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

void Array::push_back(Figure* f){
    if (size == capacity){
        size_t newCap = capacity == 0 ? 2 : capacity * 2;
        resize(newCap);
    }
    arr[size++] = f;
}

void Array::remove(size_t idx){
    if (idx >= size) {
        throw std::out_of_range("Index out of range");
    }
    delete arr[idx];

    for (size_t i = idx; i < size - 1; ++i){
        arr[i] = arr[i + 1];
    }
    --size;
}

void Array::clear(){
    for (size_t i = 0; i < size; ++i){
        delete arr[i];
    }
    delete[] arr;
    arr = nullptr;
    size = 0;
    capacity = 0;
}

Figure* Array::operator[](size_t idx) const{
    if (idx >= size){
        throw std::out_of_range("Index out of range");
    }
    return arr[idx];
}

size_t Array::getSize() const {
    return size;
}

double Array::totalArea() const {
    double sum = 0.0;
    for(size_t i = 0; i < size; ++i){
        sum += static_cast<double>(*arr[i]);
    }
    return sum;
}

void Array::printAll() const {
    for (size_t i = 0; i < size; ++i){
        std::cout << "Figure " << i << ": " << *arr[i];
        Point center = arr[i]->getCenter();
        std::cout << " Center: " << center;
        std::cout << " Area: " << static_cast<double>(*arr[i]) << "\n";
    }
}
