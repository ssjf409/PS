

/*

행렬의 거듭제곱을 구하는 분할 정복 알고리즘

*/

#include <iostream>

#include <cmath>

using namespace std;

 

//정방행렬을 표현하는 SquareMatrix 클래스가 있다고 가정

class SquareMatrix

{

private:

        int **arr;

        int m_size;

public:

        SquareMatrix(int n = 2) :m_size(n)

        {

               arr = new int*[m_size];

               for (int i = 0; i < m_size; i++)

                       arr[i] = new int[m_size]; //동적할당

        }

        ~SquareMatrix()

        {

               for (int i = 0; i < m_size; i++) //해제

                       delete[] arr[i];

               delete[] arr;

        }

        SquareMatrix(SquareMatrix &sm):m_size(sm.m_size)

        {

               arr = new int*[m_size];

               for (int i = 0; i < m_size; i++)

                       arr[i] = new int[m_size];

               for (int i = 0; i < m_size; i++)

                       for (int j = 0; j < m_size; j++)

                              arr[i][j] = sm.arr[i][j];

        }

        SquareMatrix &operator*(SquareMatrix &b)

        {

               SquareMatrix result(m_size);

               for (int i = 0; i < m_size; i++) //초기화

                       for (int j = 0; j < m_size; j++)

                              result.arr[i][j] = 0;

 

               for (int i = 0; i < m_size; i++)

                       for (int j = 0; j < m_size; j++)

                              for (int k = 0; k < m_size; k++)

                                      result.arr[i][j] += (arr[i][k] * b.arr[k][j]);

 

               for (int i = 0; i < m_size; i++)

                       for (int j = 0; j < m_size; j++)

                              arr[i][j] = result[i][j];

               return *this;

        }

        SquareMatrix &operator=(SquareMatrix &b)

        {

               if (arr)

               {

                       for (int i = 0; i < m_size; i++) //해제

                              delete[] arr[i];

                       delete[] arr;

               }

               arr = new int*[b.m_size];

               for (int i = 0; i < b.m_size; i++)

                       arr[i] = new int[b.m_size];

 

               for (int i = 0; i < b.m_size; i++)

                       for (int j = 0; j < b.m_size; j++)

                              arr[i][j] = b.arr[i][j];

               return *this;

        }

        int size(void) const

        {

               return m_size;

        }

        int *operator[](int i)

        {

               return arr[i];

        }

        friend istream &operator>>(istream &is, SquareMatrix &sm);

        friend ostream &operator<<(ostream &os, SquareMatrix &sm);

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

 

//n*n 크기의 항등 행렬을 반환하는 함수

SquareMatrix Identity(int n)

{

        SquareMatrix base(n);

        for (int i = 0; i < n; i++)

               for (int j = 0; j < n; j++)

                       if (i == j)

                              base[i][j] = 1;

                       else

                              base[i][j] = 0;

        return base;

}

 

//A^m을 반환

SquareMatrix pow(SquareMatrix &A, int m)

{

        //기저 사례:A^0=1

        if (m == 0)

               return Identity(A.size());

        if (m % 2 > 0)

               return pow(A, m - 1) * A;

        SquareMatrix half = pow(A, m / 2);

        //A^m=(A^(m/2))*(A^(m/2))

        return half*half;

}

 

 

int main(void)

{

        int size, num;

        cout << "행렬의 크기: ";

        cin >> size;

        SquareMatrix matrix(size);

        cin >> matrix;

 

        cout << "행렬의 거듭제곱을 구하는 분할 정복 알고리즘" << endl;

        cout << "제곱수 입력: ";

        cin >> num;

        cout << endl << num << "번만큼 제곱한 결과" << endl;

        cout << pow(matrix, num) << endl;

        return 0;

}