function solution(arr)
{
    var answer = [];

    if(arr.length === 0) return answer;
    
    let value = arr[0];
    answer.push(value);
    arr.forEach(function(el) {
        if(el !== value) {
            value = el;
            answer.push(value);
        }
    });
    
    return answer;
}