#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Rule {
    ll A, B, C;
};

int N, K, D;
vector<Rule> rules;


ll getAcornNum(ll mid) {
    ll ret = 0;

    for(const auto& rule : rules) {
        ll temp = min(rule.B, mid) - rule.A;
        if(temp < 0) {
            continue;
        } else {
            ret += temp / rule.C + 1;
        }
    }

    return ret;
}

int main() {
    cin >> N >> K >> D;
    rules.resize(K);

    ll low = N;
    ll high = 0;
    for(int i = 0; i < K; i++) {
        cin >> rules[i].A >> rules[i].B >> rules[i].C;
        if(rules[i].A < low) {
            low = rules[i].A;
        }
        if(rules[i].B > high) {
            high = rules[i].B;
        }
    }

    ll mid, result;

    while(low <= high) {
        mid = (low + high) / 2;

        ll acornNum = getAcornNum(mid);

        if(acornNum >= D) {
            high = mid - 1;
            result = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << result;

    return 0;
}