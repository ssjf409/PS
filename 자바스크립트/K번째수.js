function solution(array, commands) {
    var answer = [];
    if(commands.length === 0) return answer;
    
    for(let i = 0; i < commands.length; i++) {
        let temp = array.slice(commands[i][0] - 1, commands[i][1]);
        temp.sort(function(a, b) {
            return a - b;
        });
        answer.push(temp[commands[i][2] - 1]);
    }
    
    
    return answer;
}