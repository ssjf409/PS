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

    
};


int main() {

    return 0;
}