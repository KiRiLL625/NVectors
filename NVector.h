#ifndef VECTOR_N_NVECTOR_H
#define VECTOR_N_NVECTOR_H


#include <vector>

class NVector {
private:
    int n;
    std::vector<double> v;
public:
    NVector(int n);
    NVector(int n, double value);
    NVector(const NVector &nv);
    NVector& operator=(const NVector &nv);
    ~NVector();

    double abs() const;
    double scalar_mult(const NVector &nv) const;
    NVector sum(const NVector &nv) const;
    NVector sub(const NVector &nv) const;
    NVector mul(double k) const;

    int get_n() const;

    NVector operator+(const NVector &nv) const;
    NVector operator-(const NVector &nv) const;
    NVector operator*(double k) const;
    double operator*(const NVector &nv) const;
    NVector operator++();
    NVector operator++(int);
    NVector operator--();
    NVector operator--(int);
    double& operator[](int i);
    const double& operator[](int i) const;

};


#endif //VECTOR_N_NVECTOR_H
