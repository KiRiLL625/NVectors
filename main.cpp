#include <iostream>
#include "NVector.h"

bool is_collinear(const NVector &v1, const NVector &v2) {
    if (v1.get_n() != v2.get_n()) {
        return false;
    }
    double ratio = v1[0] / v2[0];
    for (int i = 1; i < v1.get_n(); i++) {
        if (v1[i] / v2[i] != ratio) {
            return false;
        }
    }
    return true;
}

bool is_orthogonal(const NVector &v1, const NVector &v2) {
    return v1 * v2 == 0;
}

bool menu(std::vector<NVector>& vectors){
    int n;
    std::cout << "1. Add vector" << std::endl;
    std::cout << "2. Check collinearity" << std::endl;
    std::cout << "3. Check orthogonality" << std::endl;
    std::cout << "4. Scalar multiplication" << std::endl;
    std::cout << "5. Sum of vectors" << std::endl;
    std::cout << "6. Subtraction of vectors" << std::endl;
    std::cout << "7. Multiplication of vector by scalar" << std::endl;
    std::cout << "8. Print all vectors" << std::endl;
    std::cout << "9. Exit" << std::endl;

    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:{
            std::cout << "Enter the dimension of the vector: ";
            std::cin >> n;
            std::cout << "Enter the vector: ";
            NVector v(n);
            for (int i = 0; i < n; i++) {
                std::cin >> v[i];
            }
            vectors.push_back(v);
            return true;
        }

        case 2:{
            int i, j;
            std::cout << "Enter the numbers of the vectors: ";
            std::cin >> i >> j;
            if (is_collinear(vectors[i], vectors[j])) {
                std::cout << "Vectors are collinear" << std::endl;
            } else {
                std::cout << "Vectors are not collinear" << std::endl;
            }
            return true;
        }

        case 3:{
            int i, j;
            std::cout << "Enter the numbers of the vectors: ";
            std::cin >> i >> j;
            if (is_orthogonal(vectors[i], vectors[j])) {
                std::cout << "Vectors are orthogonal" << std::endl;
            } else {
                std::cout << "Vectors are not orthogonal" << std::endl;
            }
            return true;
        }

        case 4:{
            int i, j;
            std::cout << "Enter the numbers of the vectors: ";
            std::cin >> i >> j;
            std::cout << "Scalar multiplication: " << vectors[i] * vectors[j] << std::endl;
            return true;
        }

        case 5:{
            int i, j;
            std::cout << "Enter the numbers of the vectors: ";
            std::cin >> i >> j;
            std::cout << "Sum of vectors: " << (vectors[i] + vectors[j]).abs() << std::endl;
            return true;
        }

        case 6:{
            int i, j;
            std::cout << "Enter the numbers of the vectors: ";
            std::cin >> i >> j;
            std::cout << "Subtraction of vectors: " << (vectors[i] - vectors[j]).abs() << std::endl;
            return true;
        }

        case 7:{
            int i;
            double k;
            std::cout << "Enter the number of the vector and the scalar: ";
            std::cin >> i >> k;
            std::cout << "Multiplication of vector by scalar: " << (vectors[i] * k).abs() << std::endl;
            return true;
        }

        case 8:{
            for (int i = 0; i < vectors.size(); i++) {
                std::cout << "Vector " << i << ": ";
                std::cout << '{';
                for (int j = 0; j < vectors[i].get_n(); j++) {
                    if(j == vectors[i].get_n() - 1){
                        std::cout << vectors[i][j];
                        break;
                    }
                    std::cout << vectors[i][j] << " ";
                }
                std::cout << '}' << std::endl;
            }
            return true;
        }

        case 9:{
            return false;
        }

        default:{
            return true;
        }
    }
}

int main() {
    std::vector<NVector> vectors;
    while(menu(vectors));
    return 0;
}
