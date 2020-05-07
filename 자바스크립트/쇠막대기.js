function solution(arrangement) {
    var answer = 0;
    
    let s = new Array();
    
    let cnt = 0;
    
    for(let i = 0; i < arrangement.length; i++) {
        if(arrangement[i] === '(') s.push('(');
        else {
            if(arrangement[i - 1] === '(') {
                cnt += (s.length - 1);    
            } else {
                cnt++;
            }
            s.pop();
        }
    }
    
    answer = cnt;

    
    return answer;
}