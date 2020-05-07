function solution(participant, completion) {
    var answer = '';
    participant.sort();
    completion.sort();
    
    
    let flag = false;
    let i;
    for(i = 0; i < completion.length; i++) {
        if(participant[i] !== completion[i]) {
            flag = true;
            break;
        }
    }
    
    answer = participant[i];

    
    return answer;
}