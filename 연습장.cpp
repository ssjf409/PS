#include <iostream>

#include <string>

#include <algorithm>

#include <cstring> //memset

#include <cstdio>

using namespace std;

 

const int MAX = 15;

int K; //부분문자열 개수

string word[MAX+1];

int cache[MAX][(1 << MAX) + 1]; //최대 자릿수 표현하기 위해 (1<<MAX)+1

int overlap[MAX + 1][MAX + 1]; //글자들이 얼마나 겹치는가(overlap)

 

//마지막에 출현한 조각 last와 지금까지 출현한 조각의 집합 used가 주어졌을 때

//나머지 조각을 추가해서 얻을 수 있는 overlaps()의 최대 합

int restore(int last, int used)

{

        //기저 사례

        if (used == (1 << K) - 1) //모든 부분문자열을 다 사용

               return 0;

        //메모이제이션

        int &result = cache[last][used];

        if(result != -1)

               return result;

        result = 0;

        for(int next=0; next<K; next++)

               if ((used & (1 << next)) == 0)

               {

                       int candidate = overlap[last][next] + restore(next, used + (1 << next)); //used+(1<<next)->next 사용했다고 표시

                       result = max(result, candidate);

               }

        return result;

}

 

//처음 호출 시 last는 recover()가 최댓값을 반환한 시작 단어

//used는 1<<last로 둔다

string reconstruct(int last, int used)

{

        //기저 사례

        if (used == (1 << K) - 1)

               return "";

        //다음에 올 문자열 조각을 찾는다

        for (int next = 0; next < K; next++)

        {

               //next가 이미 사용되었으면 제외

               if (used & (1 << next))

                       continue;

               //next를 사용했을 경우의 답이 최적해와 같다면 next를 사용

               int ifUsed = restore(next, used + (1 << next)) + overlap[last][next];

               if (restore(last, used) == ifUsed) {
                   cout << word[next].substr(overlap[last][next]) << '\n';
                       return (word[next].substr(overlap[last][next]) + reconstruct(next, used + (1 << next))); //used+(1<<next)->next 사용했다고 표시
               }
        }

        //에러 발생시

        return "error!";

}

 

//overlap 초기화

int getOverlap(const string &s1, const string &s2)

{

        for (int length=min(s1.size(), s2.size()); length > 0; length--)

               if (s1.substr(s1.size() - length) == s2.substr(0, length))

                       return length;

        return 0;

}

 

int main(void)

{

        int test_case;
        freopen("input.txt", "r", stdin);
        // freopen("output.txt", "w", stdout);

        cin >> test_case;


        if (test_case < 0 || test_case>50)

               exit(-1);

 

        for (int i = 0; i < test_case; i++)

        {

               cin >> K;

               if (K < 1 || K>15)

                       exit(-1);

              

               for (int j = 0; j < K; j++)

                       cin >> word[j]; //부분문자열 입력

 

               memset(cache, -1, sizeof(cache));

 

               while (true)

               {

                       bool removed = false;

                       for(int j=0; j<K && !removed; j++)

                              for(int k=0; k<K; k++)

                                      if (j != k && word[j].find(word[k]) != -1) //부분문자열이 겹친다면 삭제

                                      {

                                              //heapSort 삭제와 비슷한 과정

                                              word[k] = word[K - 1]; //맨 끝에 있는 string과 위치변경

                                              K--;

                                              removed = true;

                                      }

                       if (!removed)

                              break;

               }

               word[K] = "";

 

               //overlap 초기화

               for (int j = 0; j <= K; j++)

                       for (int k = 0; k <= K; k++)

                              overlap[j][k] = getOverlap(word[j], word[k]);

               cout << reconstruct(K, 0) << endl;

        }

        return 0;

}