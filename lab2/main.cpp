#include "vector.h"
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    Vector vec1, vec2, vec3;

    inputFile >> vec1 >> vec2;

    // Вывод в файл
    outputFile << "Vector 1: " << vec1 << endl;
    outputFile << "Vector 2: " << vec2 << endl;

    // Присваивание с копированием
    vec3 = vec1;
    outputFile << "Vector 3 (copy): " << vec3 << endl;

    // Присваивание с перемещением
    vec3 = Vector(vec2);
    outputFile << "Vector 3 (move): " << vec3 << endl;

    // Обращение к элементам
    outputFile << "Element at index 1 of Vector 3: " << vec3[1] << endl;

    ++vec1;
    ++vec2;
    outputFile << "Elements in vector 1 + 1: " << vec1 << endl;
    outputFile << "Elements in vector 2 + 1: " << vec2 << endl;


    inputFile.close();
    outputFile.close();

    return 0;
}
