#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
private:
    int* array;
    int size;

public:
    Vector();
    Vector(int* arr, int n);
    Vector(const Vector& other); // Конструктор копирования
    Vector(Vector&& other) noexcept; // Конструктор перемещения
    ~Vector();

    // Перегрузка операций
    int& operator[](int index);
    Vector& operator=(const Vector& other); // Операция присваивания с копированием
    Vector& operator=(Vector&& other) noexcept;// Операция присваивания с перемещением
    Vector& operator++();
<<<<<<< HEAD
    Vector operator++(int);
=======
>>>>>>> c512b9c3d77db317ac7e3bd65929cea04fced325

    // Перегрузка операций вставки и извлечения
    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
    friend std::istream& operator>>(std::istream& is, Vector& vec);
};

#endif
