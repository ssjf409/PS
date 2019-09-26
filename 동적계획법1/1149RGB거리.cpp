#include <iostream>
#include <vector>

using namespace std;

class Rgb_acc_price {
    private:
    int r_acc_price = 0;
    int g_acc_price = 0;
    int b_acc_price = 0;

    public:
    Rgb_acc_price();
    ~Rgb_acc_price();
    void Set_price(int r, int g, int b);
    int Return_r_price();
    int Return_g_price();
    int Return_b_price();
    int Return_min_price();
};

Rgb_acc_price::Rgb_acc_price() {
}

Rgb_acc_price::~Rgb_acc_price() {
}

void Rgb_acc_price::Set_price(int r, int g, int b) {
    this->r_acc_price = r;
    this->g_acc_price = g;
    this->b_acc_price = b;
}

int Rgb_acc_price::Return_r_price() {
    return this->r_acc_price;
}
int Rgb_acc_price::Return_g_price() {
    return this->g_acc_price;
}
int Rgb_acc_price::Return_b_price() {
    return this->b_acc_price;
}
int Rgb_acc_price::Return_min_price() {
    int min_price = r_acc_price > b_acc_price ? (b_acc_price > g_acc_price ? g_acc_price : b_acc_price ) : 
                                                (r_acc_price > g_acc_price ? g_acc_price : r_acc_price);
    return min_price;
}


int main() {
    int N;
    int r_price;
    int g_price;
    int b_price;

    int r_total_price;
    int g_total_price;
    int b_total_price;

    cin >> N;
    // vector<pair<int,char>> v(N);
    //0번째 집은 0,0,0으로 채운다.
    vector<Rgb_acc_price> v(N + 1);

    //cin >> r_price >> g_price >> b_price;
    //v[1].Set_price(r_price, g_price, b_price);

    for(int i = 1; i <= N; i++) {
        cin >> r_price >> g_price >> b_price;
        
        //calculate red total price
        if(v[i - 1].Return_b_price() > v[i - 1].Return_g_price()) {
            r_total_price = r_price + v[i - 1].Return_g_price();
        } else {
            r_total_price = r_price + v[i - 1].Return_b_price();
        }
        
        //calculate green total price
        if(v[i - 1].Return_r_price() > v[i - 1].Return_b_price()) {
            g_total_price = g_price + v[i - 1].Return_b_price();
        } else {
            g_total_price = g_price + v[i - 1].Return_r_price();
        }

        
        //calculate blue total price
        if(v[i - 1].Return_r_price() > v[i - 1].Return_g_price()) {
            b_total_price = b_price + v[i - 1].Return_g_price();
        } else {
            b_total_price = b_price + v[i - 1].Return_r_price();
        }

        v[i].Set_price(r_total_price, g_total_price, b_total_price);
        //cout << r_total_price << ' '<< g_total_price << ' ' << b_total_price << '\n';
    }



    cout << v[N].Return_min_price();
    return 0;
}
