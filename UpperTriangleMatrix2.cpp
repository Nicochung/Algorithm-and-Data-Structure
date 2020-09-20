#include <iostream>
class UpperTriangleMatrix {
private:
    int *A;
    int n;
public:
    UpperTriangleMatrix(int dimension);
    ~UpperTriangleMatrix();
    int get(int i, int j);
    void set(int i, int j, int x);
    void display();
    friend std::ostream & operator <<(std::ostream& os, UpperTriangleMatrix &d);
};

UpperTriangleMatrix::UpperTriangleMatrix(int dimension) {
    this->n = dimension;
    int size = n * (n + 1) / 2;
    A = new int[size];
}

UpperTriangleMatrix::~UpperTriangleMatrix() {
    delete[]A;
}

int UpperTriangleMatrix::get(int i, int j) {
    if (i >= j)
        return A[j*(j+1) / 2 + i];
        //return A[n*i- (i-1)*i/2 + j - i];
    return 0;
}

void UpperTriangleMatrix::set(int i, int j, int x) {
    if (i >= j)
        A[j*(j+1)/2 + i] = x;
        //A[n*i- (i-1)*i/2 + j - i] = x;
}

void UpperTriangleMatrix::display() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= j)
                std::cout << A[j*(j+1)/2 + i] << " ";
                //std::cout << A[n*i- (i-1)*i/2 + j - i] << " ";
            else
                std::cout << 0 << " ";
        }
        std::cout << std::endl;
    }
}

std::ostream & operator<<(std::ostream &os, UpperTriangleMatrix &d) {
    for (int i = 0; i < d.n; ++i) {
        for (int j = 0; j < d.n; ++j) {
            if (i >= j)
                os << d.A[j*(j+1)/2 + i] << " ";
                //os << d.A[d.n*i- (i-1)*i/2 + j - i] << " ";
            else
                os << 0 << " ";
        }
        os << std::endl;
    }
    return os;
}

int main(int argc, const char * argv[]) {
    int d{}, x{};
    std::cout << "Enter Dimension";
    std::cin >> d;
    UpperTriangleMatrix m(d);
    std::cout << "Enter All elements" << std::endl;
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < d; ++j) {
            std::cin >> x;
            m.set(i,j,x);
        }
    }
    std::cout << "\n\n";
    //m.display();
    std::cout << m << std::endl;
    return 0;
}
