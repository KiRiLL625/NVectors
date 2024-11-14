//
// Created by Admin on 14.11.2024.
//

#include <valarray>
#include "NVector.h"

NVector::NVector(int n): n(n), v(n) {}

NVector::NVector(int n, double value): n(n), v(n, value) {}

NVector::NVector(const NVector &nv): n(nv.n), v(nv.v) {}

NVector &NVector::operator=(const NVector &nv) {
    if (this == &nv) {
        return *this;
    }
    n = nv.n;
    v = nv.v;
    return *this;
}

NVector::~NVector() = default;

double NVector::abs() const {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i] * v[i];
    }
    return std::sqrt(sum);
}

double NVector::scalar_mult(const NVector &nv) const {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i] * nv.v[i];
    }
    return sum;
}

NVector NVector::sum(const NVector &nv) const {
    NVector res(n);
    for (int i = 0; i < n; i++) {
        res.v[i] = v[i] + nv.v[i];
    }
    return res;
}

NVector NVector::sub(const NVector &nv) const {
    NVector res(n);
    for (int i = 0; i < n; i++) {
        res.v[i] = v[i] - nv.v[i];
    }
    return res;
}

NVector NVector::mul(double k) const {
    NVector res(n);
    for (int i = 0; i < n; i++) {
        res.v[i] = v[i] * k;
    }
    return res;
}

int NVector::get_n() const {
    return n;
}

NVector NVector::operator+(const NVector &nv) const {
    return sum(nv);
}

NVector NVector::operator-(const NVector &nv) const {
    return sub(nv);
}

NVector NVector::operator*(double k) const {
    return mul(k);
}

double NVector::operator*(const NVector &nv) const {
    return scalar_mult(nv);
}

NVector NVector::operator++() {
    for (int i = 0; i < n; i++) {
        v[i]++;
    }
    return *this;
}

NVector NVector::operator++(int) {
    NVector res(*this);
    for (int i = 0; i < n; i++) {
        v[i]++;
    }
    return res;
}

NVector NVector::operator--() {
    for (int i = 0; i < n; i++) {
        v[i]--;
    }
    return *this;
}

NVector NVector::operator--(int) {
    NVector res(*this);
    for (int i = 0; i < n; i++) {
        v[i]--;
    }
    return res;
}

double& NVector::operator[](int i) {
    return v[i];
}

const double& NVector::operator[](int i) const {
    return v[i];
}