#include <algorithm>
#include <stdexcept>
#include <utility> // std::swap()

#include "vector.h"

Vector &Vector::operator=(const Vector &v){
    if(this == &v)
    {
        return *this;
    }

    size_ = v.size_;
    capacity_ = v.capacity_;

    delete[] data_;

    data_ = new Fraction[capacity_];
    std::copy(v.data_, v.data_ + capacity_, data_);

    return *this;
}

Fraction &Vector::operator[](std::size_t idx) {
    if(idx >= size_)
    {
        throw std::out_of_range("Out of range!\n");
    }
    return data_[idx];
}

const Fraction &Vector::operator[](std::size_t idx) const {
    if(idx >= size_)
    {
        throw std::out_of_range("Out of range!\n");
    }
    return data_[idx];
}

Vector &Vector::operator=(Vector &&v) noexcept {
    if(this == &v)
    {
        return *this;
    }

    size_ = v.size_;
    capacity_ = v.capacity_;

    delete[] data_;

    data_ = v.data_;

    v.data_ = nullptr;
    v.size_ = 0;
    v.capacity_ = 0;

    return *this;
}

void Vector::push_back(const Fraction &f) {
    if(size_ + 1 > capacity_)
    {
        auto* new_data = new Fraction[capacity_ + 1];
        std::copy(data_, data_ + capacity_, new_data);
        new_data[capacity_] = f;

        delete[] data_;

        data_ = new_data;
        size_++;
        capacity_++;
    }
    else
    {
        data_[size_] = f;
        size_++;
    }
}
