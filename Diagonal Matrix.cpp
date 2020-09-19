#include <iostream>
class Diagonal {
private:
    int *A;
    int n;
public:
    Diagonal(int size);
    ~Diagonal();
    int get(int i, int j);
    void set(int i, int j, int x);
    void display();
    friend std::ostream & operator <<(std::ostream& os, Diagonal &d);
};

Diagonal::Diagonal(int size) {
    this->n = size;
    A = new int[size];
}

Diagonal::~Diagonal() {
    delete[]A;
}

int Diagonal::get(int i, int j) {
    if (i == j)
        return A[i];
    return 0;
}

void Diagonal::set(int i, int j, int x) {
    if (i == j)
        A[i] = x;
}

void Diagonal::display() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                std::cout << A[i] << " ";
            else
                std::cout << 0 << " ";
        }
        std::cout << std::endl;
    }
}

std::ostream & operator<<(std::ostream &os, Diagonal &d) {
    for (int i = 0; i < d.n; ++i) {
        for (int j = 0; j < d.n; ++j) {
            if (i == j)
                os << d.A[i] << " ";
            else
                os << 0 << " ";
        }
        os << std::endl;
    }
    return os;
}

int main(int argc, const char * argv[]) {
    Diagonal m(4);
    m.set(0,0,5);
    m.set(1,1,1);
    m.set(2,2,3);
    m.set(3,3,7);
    //m.display();
    std::cout << m << std::endl;
    return 0;
}
