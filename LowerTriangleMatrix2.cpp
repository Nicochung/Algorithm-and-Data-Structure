#include <iostream>
class LowerTriangleMatrix {
private:
    int *A;
    int n;
public:
    LowerTriangleMatrix(int dimension);
    ~LowerTriangleMatrix();
    int get(int i, int j);
    void set(int i, int j, int x);
    void display();
    friend std::ostream & operator <<(std::ostream& os, LowerTriangleMatrix &d);
};

LowerTriangleMatrix::LowerTriangleMatrix(int dimension) {
    this->n = dimension;
    int size = n * (n + 1) / 2;
    A = new int[size];
}

LowerTriangleMatrix::~LowerTriangleMatrix() {
    delete[]A;
}

int LowerTriangleMatrix::get(int i, int j) {
    if (i >= j)
        //return A[i*(i+1) / 2 + j];
        return A[n*j- (j-1)*j/2 + i - j];
    return 0;
}

void LowerTriangleMatrix::set(int i, int j, int x) {
    if (i >= j)
        //A[i*(i+1)/2 + j] = x;
        A[n*j- (j-1)*j/2 + i - j] = x;
}

void LowerTriangleMatrix::display() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i >= j)
                //std::cout << A[i*(i+1)/2 + j] << " ";
                std::cout << A[n*j- (j-1)*j/2 + i - j] << " ";
            else
                std::cout << 0 << " ";
        }
        std::cout << std::endl;
    }
}

std::ostream & operator<<(std::ostream &os, LowerTriangleMatrix &d) {
    for (int i = 0; i < d.n; ++i) {
        for (int j = 0; j < d.n; ++j) {
            if (i >= j)
                //os << d.A[i*(i+1)/2 + j] << " ";
                os << d.A[d.n*j- (j-1)*j/2 + i - j] << " ";
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
    LowerTriangleMatrix m(d);
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
