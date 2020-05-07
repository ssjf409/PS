function solution(clothes) {
    var answer = 0;
    const m = new Map();
    
    clothes.forEach(function(el) {
        let kinds = el[1];
        if(m.has(kinds)) {
            m.set(kinds, m.get(kinds) + 1);
        } else {
            m.set(kinds, 1);
        }
    });
    
    let sum = 1;
    
    for(let val of m.values()) {
        sum *= (val + 1);
    }
    answer = sum - 1;
    
    
    return answer;
}