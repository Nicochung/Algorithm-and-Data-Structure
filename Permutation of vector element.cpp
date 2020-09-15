#include <iostream>
#include <vector>

using namespace std;
// Prefer method, No extra space
template <class T>
void perm(vector<T>& m, int l, int h) {
    if (l == h) {
        for (auto a: m)
            cout << a << " ";
        cout << endl;
    } else {
        for (int i = l; i <= h; ++i) {
            swap(m[l], m[i]);
            perm(m, l+1,h);
            swap(m[l], m[i]);
        }
    }
}

// since this uses static vector, the size is limited, Method 1 is prefered
void perm2(vector<int> m,int k) {
    static vector<int> A(m.size(),0);
    static vector<int> res(m.size(),0);
    if (k == m.size()) {
        for (auto a: res)
            cout << a << " ";
        cout << endl;
    } else {
        for (int i = 0; i < m.size(); ++i) {
            if (A[i] == 0) {
                res[k] = m[i];
                A[i] = 1;
                perm2(m,k +1);
                A[i] = 0;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<int> cache{1,2,3};
    vector<char> cache2{'A','B','C','D'};
    //perm(cache,0,2);
    //perm2(cache,0);
    perm(cache2,0,3);
    return 0;
}
