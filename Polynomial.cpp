#include <iostream>

class Term {
public:
    int coeff;
    int exp;
};

class Poly {

private:
    int n;
    Term *terms;
public:
    Poly();
    Poly(int n);
    ~Poly();
    Poly operator+(Poly &p);
    friend std::ostream &operator << (std::ostream& os, Poly & p);
};
Poly::Poly(){
    this->n = 0;
    this->terms = NULL;
}

Poly::Poly(int n){
    this->n = n;
    terms = new Term[n];
    std::cout << "Enter terms" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> terms[i].coeff >> terms[i].exp;
    }
}

Poly Poly::operator+(Poly &p) {
    Poly *sum = new Poly;
    sum->terms = new Term[n + p.n];
    int i{}, j{}, k{};
    while (i < n && j < p.n) {
        if (terms[i].exp > p.terms[j].exp)
            sum->terms[k++] = terms[i++];
        else if (terms[i].exp < p.terms[j].exp)
            sum->terms[k++] = p.terms[j++];
        else {
            sum->terms[k].exp = terms[i].exp;
            sum->terms[k++].coeff = terms[i++].coeff + p.terms[j++].coeff;
        }
    }
    while (i < n)
        sum->terms[k++] = terms[i++];
    while (j < p.n)
        sum->terms[k++] = p.terms[j++];
    sum->n = k;
    return *sum;
}

std::ostream &operator <<(std::ostream& os, Poly& p) {
    for (int i = 0; i < p.n; ++i) {
        os << p.terms[i].coeff << "x^" << p.terms[i].exp;
        if (i != p.n - 1)
            os << " + ";
    }
    os << std::endl;
    return os;
}

Poly::~Poly(){
    if (n > 0 && !terms)
        delete [] terms;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Poly p1(3),p2(3), p3;
    p3 = p1 + p2;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << p3 << std::endl;
    return 0;
}
