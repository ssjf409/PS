#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 987654321

using namespace std;
typedef long long ll;

struct Stage {
    int t;
    int a;
    int h;
};

int N, ATK;

vector<Stage> stages;


ll getRemainHp(ll mid) {
    ll hp = mid;
    ll atk = ATK;

    for(const auto& stage : stages) {
        if(stage.t == 1) {
            if(stage.h - atk <= 0) continue;
            else {
                ll myTurn = ceil((double)hp / (double)stage.a);
                ll dragTurn = ceil((double)stage.h / atk);
                if(dragTurn > myTurn) return -INF;
                hp -= (dragTurn - 1) * stage.a;
            }
        } else {
            atk += stage.a;
            hp = min(hp + stage.h, mid);
        }
    }
    return hp;
}

int main() {
    cin >> N >> ATK;

    stages.resize(N);

    for(int i = 0; i < N; i++) {
        cin >> stages[i].t >> stages[i].a >> stages[i].h;
    }

    ll low = 0;
    ll high = 123456000000000000;
    ll mid, result;
    
    
    while(low <= high) {
        mid = (low + high) / 2;

        ll remainHp = getRemainHp(mid);

        if(remainHp > 0) {
            high = mid - 1;
            result = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << result;


    return 0;
}