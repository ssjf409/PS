#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getSum(const vector<int>& a) {
    
    int oneCnt = 0;
    int sum = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] >= 10) {
            sum += 10;
        } else {
            if(a[i] == 1) oneCnt++;
            sum += a[i];
        }
    }
    
    while(oneCnt != 0) {
        if(sum + 10 <= 21) {
            oneCnt--;
            sum += 10;
        } else {
            break;
        }
    }
    
    return sum;
}

int solution(vector<int> cards) {
    int answer = 0;
    
    int index = 0;
    while(true) {
        vector<int> player;
        vector<int> dealer;
        // 0 비김, 1 플레이어, 2 딜러
        int winner = 0;
        
        if(index == cards.size()) break;
        player.push_back(cards[index++]);
        if(index == cards.size()) break;
        dealer.push_back(cards[index++]);
        if(index == cards.size()) break;
        player.push_back(cards[index++]);
        if(index == cards.size()) break;
        dealer.push_back(cards[index++]);
        
        int dealerCard = dealer.back();
        if(dealerCard == 1 || dealerCard == 7) {
            bool flag = false;
            while(getSum(player) < 17) {
                if(index == cards.size()) {
                    flag = true;
                    break;
                }
                player.push_back(cards[index++]);
            }
            if(flag) break;
        } else if(dealerCard >= 4 && dealerCard <= 6) {
            
        } else if(dealerCard == 2 || dealerCard == 3) {
            bool flag = false;
            while(getSum(player) < 12) {
                if(index == cards.size()) {
                    flag = true;
                    break;
                }
                player.push_back(cards[index++]);
            }
            if(flag) break;
        }
        
        int playerSum = getSum(player);
        int dealerSum = getSum(dealer);
        if(playerSum == 21 && dealerSum == 21) {
            continue;
        } else if(playerSum == 21) {
            answer += 3;
            continue;
        } else if(dealerSum == 21) {
            answer -= 2;
            continue;
        } else if(playerSum > 21) {
            answer -= 2;
            continue;
        }
        
        bool flag = false;
        while(getSum(dealer) < 17) {
            if(index == cards.size()) {
                flag = true;
                break;
            }
            dealer.push_back(cards[index++]);
        }
        if(flag) break;
        
        dealerSum = getSum(dealer);
        
        if(dealerSum > 21) {
            answer += 2;
            continue;
        }
        
        if(dealerSum > playerSum) {
            answer -= 2;
        } else if(dealerSum < playerSum) {
            answer += 2;
        }
        
        
        
    }
    

    
    
    return answer;
}