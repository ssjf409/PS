#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> arr_v;
vector<int> inDegree;



bool swap_flow(int num1, int num2) {
    //num1 -> num2 일 때,
    for(int i = 0; i < arr_v[num1].size(); i++) {
        if(arr_v[num1][i] == num2) {
            arr_v[num1].erase(arr_v[num1].begin() + i);
            arr_v[num2].push_back(num1);
            return true;
        }
    }

    //num2 -> num1 일 때,
    for(int i = 0; i < arr_v[num2].size(); i++) {
        if(arr_v[num2][i] == num1) {
            arr_v[num2].erase(arr_v[num2].begin() + i);
            arr_v[num1].push_back(num2);
            return true;
        }
    }

    return false;
}

void topologySort(int n) {
    vector<int> result_v;
    queue<int> q;

    // 진입 차수가 0인 노드를 큐에 삽입한다.
    for(int i = 1; i <= n; i++) {
        // cout << inDegree[i] << '\n';
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    // 정렬이 완전히 수행되려면 정확히 n개의 노드를 방문합니다.
    for(int i = 1; i <= n; i++) {
        // n개를 방문하기 전에 큐가 비어버리면 사이클일 발생하는 것입니다.
        if(q.empty()) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        int x = q.front();
        q.pop();
        result_v.push_back(x);
        for(int i = 0; i < arr_v[x].size(); i++) {
            int y = arr_v[x][i];
            if(--inDegree[y] == 0) {
                q.push(y);
            }
        }
    }
    // 연결 잘 되는지?
    // for(int i = 0; i < n; i++) {
    //     cout << result_v[i] << " ";
    // }
    // cout << '\n';
}

int main() {
    int test_case;
    cin >> test_case;
    for(int i = 0; i < test_case; i++) {
        //초기화
        arr_v.clear();
        inDegree.clear();


        int n, num_change;
        cin >> n;

        // 0 by n+1
        // for(int j = 0; j <= n; j++) {
        //     vector<int> v_element;
        //     v_element.push_back(0);
        //     arr_v.push_back(v_element);
        //     inDegree.push_back(0);
        // }
        

        vector<int> input_v;
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            input_v.push_back(temp);
        }

        for(int j = 0; j < n; j++) {
            vector<int> temp_v;
            temp_v.assign(input_v.begin() + j + 1, input_v.end());
            arr_v.push_back(temp_v);
            
        }

        
        // cout << "input data\n";
        // for(int j = 1; j <= n; j++) {
        //     for(int k = 1; k < arr_v[j].size(); k++) {
        //         cout << arr_v[j][k] << ' ';
        //     }
        //     cout << '\n';
        // }

        


        cin >> num_change;
        for(int j = 0; j < num_change; j++) {
            int num1, num2;
            cin >> num1 >> num2;
            swap_flow(num1, num2);
        }

        cout << "========" << i << "번째꺼========\n";
        
        // 0번째는 버리는 거 1번째부터 센다.
        for(int j = 1; j < inDegree.size(); j++) {
            cout << inDegree[j] << ' ';
        }
        cout << '\n';

        topologySort(n);



        


    }
    return 0;
}