function solution(answers) {
    var answer = [];
    
    let secArr = [2, 1, 2, 3, 2, 4, 2, 5];
    let thiArr = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    
    let first = 0;
    let second = 0;
    let third = 0;
    for(let i = 0; i < answers.length; i++) {
        if((i % 5) + 1 === answers[i]) first++;
        if(secArr[i % 8] === answers[i]) second++;
        if(thiArr[i % 10] === answers[i]) third++;
    }
    
    let ret = [first, second, third];
    
    let max = -1;
    for(let i = 0; i < ret.length; i++) {
        if(ret[i] > max) max = ret[i];
    }
    
    for(let i = 0; i < ret.length; i++) {
        if(ret[i] === max) answer.push(i + 1);
    }
    
    return answer;
}