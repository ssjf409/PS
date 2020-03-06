#include <iostream>
#include <vector>

using namespace std;
/*
class TrafficLight {
    public:
    int loc;
    int led;
    int green;
    TrafficLight(int a, int b, int c) {
        loc = a;
        led = b;
        green = c;
    }
};

int main() {
    int N, L;
    cin >> N >> L;

    vector<TrafficLight> light;
    int a, b, c;
    for(int i = 0; i < N; i++) {
        cin >> a >> b >>  c;
        TrafficLight tf(a, b, c);
        light.push_back(tf);
    }
    
    int time = 0;
    int location = 0;
    int lightIndex = 0;
    while(true) {
        time++;
        location++;
        if(light[lightIndex].loc == location) {
            int term = time % (light[lightIndex].led + light[lightIndex].green);

            if(term <= light[lightIndex].led) {
                time += (light[lightIndex].led - term);
            }

            lightIndex++;
        }
        if(location == L) break;
    }

    // cout << time;

    return 0;
}
*/