#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

bool compare(int a, int b) {
    return a < b;
}

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), compare);

    int g = gcd(v[0], v[1]);
    for(int i = g; i < v[0]; i += g) {
        cout << i << '\n';
    }

    return 0;
}