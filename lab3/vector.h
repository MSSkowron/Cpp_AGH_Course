#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include "fraction.h"

class Vector
{
private:
    std::size_t size_;
    std::size_t capacity_;
    Fraction* data_;
public:
    explicit Vector(std::size_t c = 0): size_{0}, capacity_{c}, data_{new Fraction[c]} {}

	Vector(const Vector &vector) : size_{vector.size_},capacity_{vector.capacity_}, data_{new Fraction[capacity_]} 
    {
		std::copy(vector.data_, vector.data_ + capacity_, data_);
	}

    Vector(Vector &&vector) noexcept : size_{vector.size_},capacity_{vector.capacity_}, data_{vector.data_} {
	vector.data_ = nullptr;
	vector.size_ = 0;
    vector.capacity_ = 0;
	}

    ~Vector() { delete[] data_; }

    [[nodiscard]] Fraction* data() const{ return data_; }

    [[nodiscard]] std::size_t size() const{ return size_; }

    [[nodiscard]] std::size_t capacity() const{ return capacity_; }

	Vector& operator=(const Vector& v);

    Fraction& operator[] (std::size_t idx);

    const Fraction& operator[] (std::size_t idx) const;

	Vector& operator=(Vector&& v) noexcept;

    void push_back(const Fraction& f);

};
#endif
