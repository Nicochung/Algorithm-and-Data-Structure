#include <iostream>

class Element {
public:
    int i{};
    int j{};
    int x{};
};

class Sparse {
private:
    int m;
    int n;
    int num;
    Element *ele;
public:
    Sparse(int m, int n, int num);
    Sparse operator+(Sparse &sp);
    friend std::istream &operator>>(std::istream &is, Sparse &sp);
    friend std::ostream &operator<<(std::ostream &os, Sparse &sp);
    ~Sparse();
};

Sparse::Sparse(int m, int n, int num) {
    this->m = m;
    this->n = n;
    this->num = num;
    ele = new Element[num];
}

std::istream &operator >>(std::istream &is, Sparse &sp) {
    std::cout << "Enter all non-zero elements" << std::endl;
    for (int i = 0; i < sp.num; ++i)
        std::cin >> sp.ele[i].i >> sp.ele[i].j >> sp.ele[i].x;
    return is;
}

std::ostream &operator <<(std::ostream &os, Sparse &sp) {
    for (int i = 0, k = 0; i < sp.m; ++i) {
        for (int j = 0; j < sp.n; ++j) {
            if (i == sp.ele[k].i && j == sp.ele[k].j) {
                os << sp.ele[k++].x << " ";
            } else {
                os << 0 << " ";
            }
        }
        os << std::endl;
    }
    return os;
}

Sparse Sparse::operator+(Sparse &sp) {
    if (m != sp.m || n != sp.n)
        return Sparse(0,0,0);
    Sparse * sum = new Sparse(m,n,num+sp.num);
    
    int i{}, j {}, k{};
    while (i < num && j < sp.num) {
        if (ele[i].i < sp.ele[j].i) {
            sum->ele[k++] = ele[i++];
        } else if (ele[i].i > sp.ele[j].i){
            sum->ele[k++] = sp.ele[j++];
        } else {
            if (ele[i].j < sp.ele[j].j) {
                sum->ele[k++] = ele[i++];
            } else if (ele[i].j > sp.ele[j].j){
                sum->ele[k++] = sp.ele[j++];
            } else {
                sum->ele[k] = ele[i];
                sum->ele[k++].x = ele[i++].x + sp.ele[j++].x;
            }
        }
    }
    for (;i < num; ++i)
        sum->ele[k++] = ele[i];
    for (;j < sp.num; ++j)
        sum->ele[k++] = sp.ele[j];
    sum->num = k;
    return *sum;
}

Sparse::~Sparse() {
    delete []ele;
}
int main(int argc, const char * argv[]) {
    Sparse s1(5,5,5),s2(5,5,5);
    std::cin >> s1;
    std::cin >> s2;
    Sparse sum = s1 + s2;
    std::cout << s1;
    std::cout << s2;
    std::cout << sum;
    return 0;
}
