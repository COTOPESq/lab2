#include "vector.h"

using namespace std;

Vector::Vector() : array(nullptr), size(0) {}

Vector::Vector(int* arr, int n) : size(n) {
    array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = arr[i];
    }
}

Vector::Vector(const Vector& other) : size(other.size) {
    array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = other.array[i];
    }
}

Vector::Vector(Vector&& other) noexcept : array(other.array), size(other.size) {
    other.array = nullptr;
    other.size = 0;
}

Vector::~Vector() {
    delete[] array;
}

int& Vector::operator[](int index) {
    return array[index];
}

Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] array;
        size = other.size;
        array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] array;
        array = other.array;
        size = other.size;
        other.array = nullptr;
        other.size = 0;
    }
    return *this;
}

ostream& operator<<(ostream& os, const Vector& vec) {
    os << "[";
    for (int i = 0; i < vec.size; ++i) {
        os << vec.array[i];
        if (i < vec.size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

istream& operator>>(istream& is, Vector& vec) {
    // Ввод размерности вектора
    is >> vec.size;

    // Выделение памяти под массив
    delete[] vec.array;
    vec.array = new int[vec.size];

    // Ввод элементов массива
    for (int i = 0; i < vec.size; ++i) {
        is >> vec.array[i];
    }

    return is;
}
