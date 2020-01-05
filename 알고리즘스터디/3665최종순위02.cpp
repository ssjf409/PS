#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> arr_v;
vector<int> inDegree;



bool swap_flow(int num1, int num2) {
    //num1 -> num2 일 때,
    for(int i = 1; i < arr_v[num1].size(); i++) {
        if(arr_v[num1][i] == num2) {
            arr_v[num1].erase(arr_v[num1].begin() + i);
            arr_v[num2].push_back(num1);
            inDegree[num1]++;
            inDegree[num2]--;
            return true;
        }
    }

    //num2 -> num1 일 때,
    for(int i = 1; i < arr_v[num2].size(); i++) {
        if(arr_v[num2][i] == num1) {
            arr_v[num2].erase(arr_v[num2].begin() + i);
            arr_v[num1].push_back(num2);
            inDegree[num2]++;
            inDegree[num1]--;
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
        for(int i = 1; i < arr_v[x].size(); i++) { // 0->1으로 바꿈
            int y = arr_v[x][i];
            // 새롭게 차수가 0이 된 정점을 큐에 삽입합니다.
            if(--inDegree[y] == 0) {
                q.push(y);
            }
        }
    }
    // 연결 잘 되는지?
    for(int i = 0; i < n; i++) {
        cout << result_v[i] << " ";
    }
    cout << '\n';
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

        // input
        vector<int> input_v;
        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            input_v.push_back(temp);
        }

        // 0 으로 만들기 , inDegree 전부 0 으로 만들기
        // 0
        // 0
        // ...
        // 0
        vector<int> padding_v;
        padding_v.push_back(0);
        for(int j = 0; j <= n; j++) {
            arr_v.push_back(padding_v);
            inDegree.push_back(0);
        }

        
        // k는 input_v의 인덱스
        // input_v의 값 자체는 arr_v의 인덱스가 된다.(arr_ 그렇게 만들어놓음)
        for(int j = 0; j < n; j++) {
            int cnt = 0;
            for(int k = 0; k < j; k++) {
                // cout << "arr_v[input_v[k]].push_back(input_v[j])\n";
                // cout << "k : " << k << '\n';
                // cout << "input_v[k] : " << input_v[k] << '\n';
                // cout << "input_v[j] : " << input_v[j] << '\n';
                
                arr_v[input_v[k]].push_back(input_v[j]);
                inDegree[input_v[j]]++;
            }
        }


        // // arr_v 찍어보기
        // cout << "before swap() ========\n";
        // for(int j = 1; j < arr_v.size(); j++) {
        //     for(int k = 1; k < arr_v[j].size(); k++) {
        //         cout << arr_v[j][k] << ' ';
        //     }
        //     cout << '\t' << "inDegree : " << inDegree[j];
        //     cout << '\n';
        // }


        cin >> num_change;
        for(int j = 0; j < num_change; j++) {
            int num1, num2;
            cin >> num1 >> num2;
            swap_flow(num1, num2);
        }

        
        // // arr_v 찍어보기
        // cout << "after swap() ========\n";
        // for(int j = 1; j < arr_v.size(); j++) {
        //     for(int k = 1; k < arr_v[j].size(); k++) {
        //         cout << arr_v[j][k] << ' ';
        //     }
        //     cout << '\t' << "inDegree : " << inDegree[j];
        //     cout << '\n';
        // }


        

        topologySort(n);



        


    }
    return 0;
}