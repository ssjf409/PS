#include <iostream>
#include <vector>

using namespace std;

class SquareMatrix {
private:
    int **arr;
    int m_size;
public:
    SquareMatrix(int n = 2) : m_size(n) {
        arr = new int* [m_size];
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
    SquareMatrix(SquareMatrix& sm) : m_size(sm.m_size) {
        arr = new int* [m_size];
        for(int i = 0; i < m_size; i++) {
            arr[i] = new int[m_size];
        }
        for(int i = 0; i < m_size; i++) {
            for(int j = 0; j < m_size; j++) {
                arr[i][j] = sm.arr[i][j];
            }
        }
    }

    SquareMatrix& operator*(SquareMatrix& b) {
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

    int* operator[](int i) {
        return arr[i];
    }

    friend istream& operator>>(istream &is, SquareMatrix &sm);
    friend ostream& operator<<(ostream &is, SquareMatrix &sm);
};


istream &operator>>(istream &is, SquareMatrix &sm)
{
        for (int i = 0; i<sm.m_size; i++)
               for (int j = 0; j < sm.m_size; j++)
               {
                       cout << i << "행 " << j << "열 입력: ";
                       is >> sm[i][j];
               }
        return is;
}

ostream &operator<<(ostream &os, SquareMatrix &sm)
{
        for (int i = 0; i < sm.m_size; i++)
        {
               for (int j = 0; j < sm.m_size; j++)
                       os << sm[i][j] << " ";
               os << endl;
        }
        return os;
}
int main() {

    return 0;
}