#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SquareMatrix{
    private:
    int **arr;
    int m_size;
    public:
    SquareMatrix(int n = 2) : m_size(n) {
        arr = new int*[m_size];
        for(int i = 0; i < m_size; i++) {
            arr[i] = new int [m_size];
        }
    }
    ~SquareMatrix() {
        for(int i = 0; i < m_size; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
    SquareMatrix(SquareMatrix &sm) : m_size(sm.m_size) {
        arr = new int*[m_size];
        for(int i = 0; i < m_size; i++) {
            arr[i] = new int[m_size];
        }
        for(int i = 0; i < m_size; i++) {
            for(int j = 0; j < m_size; j++) {
                arr[i][j] = sm.arr[i][j];
            }
        }
    }
    SquareMatrix& operator*(SquareMatrix &b) {
        SquareMatrix result(m_size);
        for(int i = 0; i < m_size; i++) {
            for(int j = 0; j < m_size; j++) {
                result.arr[i][j] = 0;
            }
        }
        for(int i = 0; i < m_size; i++) {
            for(int j = 0; j < m_size; j++) {
                for(int k = 0; k < m_size; k++) {
                    result.arr[i][j] += (arr[i][k] * b.arr[k][j]);
                }
            }
        }
        for(int i = 0; i < m_size; i++) {
            for(int j = 0; j < m_size; j++) {
                arr[i][j] = result.arr[i][j];
            }
        }
        return *this;
    }
    SquareMatrix& operator=(SquareMatrix &b) {
        if(arr) {
            for(int i = 0; i < m_size; i++) {
                delete[] arr[i];
            }
            delete[] arr;
        }
        arr = new int*[b.m_size];
        for(int i = 0; i < b.m_size; i++) {
            arr[i] = new int[b.m_size];
        }
        for(int i = 0; i < b.m_size; i++) {
            for(int j = 0; j < b.m_size; j++) {
                arr[i][j] = b.arr[i][j];
            }
        }
        return *this;
    }
    int size() const {
        return m_size;
    }
    int* operator[](int i) {
        return arr[i];
    }
    friend istream& operator>>(istream &is, SquareMatrix &sm);
    friend ostream& operator<<(ostream &os, SquareMatrix &sm);
};

istream& operator>>(istream &is, SquareMatrix &sm) {
    for(int i = 0; i < sm.m_size; i++) {
        for(int j = 0; j <sm.m_size; j++) {
            cout << i << "행 " << j << "열 입력 : ";
            is >> sm[i][j];
        }
    }
    return is;
}

ostream &operator << (ostream &os, SquareMatrix &sm) {
    for(int i = 0; i < sm.m_size; i++) {
        for(int j = 0; j < sm.m_size; j++) {
            os << sm[i][j] << ' ';
        }
        os << endl;
    }
    return os;
}

SquareMatrix Identity(int n) {
    SquareMatrix base(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) base[i][j] = 1;
            else base[i][j] = 0;
        }
    }
    return base;
}

SquareMatrix pow(SquareMatrix &A, int m) {
    if(m == 0) return Identity(A.size());
    if(m % 2 > 0) return pow(A, m - 1) * A;
    SquareMatrix half = pow(A, m / 2);

    return half * half;
}


int main() {
    int N;
    int B;
    cin >> N >> B;
    SquareMatrix matrix(N);
    cin >> matrix;

    cout << pow(matrix, B);



    return 0;
}