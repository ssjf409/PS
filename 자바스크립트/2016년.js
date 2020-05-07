let month = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
let day = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"];

function solution(a, b) {
    var answer = '';
    
    let sum = 0;
    for(let i = 1; i < a; i++) {
        sum += month[i];
    }
    sum += b;
    sum += 4;
    
    answer = day[sum % 7];
    
    return answer;
}