function getCnt(student, index, cnt) {
    if(index == student.length) {
        return cnt;
    }
    
    if(student[index] === 0) {
        let leftCnt = 0;
        let rightCnt = 0;
        if(index !== 0 && student[index - 1] === 2) {
            student[index - 1]--;
            student[index]++;
            leftCnt = getCnt(student, index + 1, cnt + 1);
            student[index - 1]++;
            student[index]--;
        }
        if(index + 1 !== student.length && student[index + 1] === 2) {
            student[index + 1]--;
            student[index]++;
            rightCnt = getCnt(student, index + 1, cnt + 1);
            student[index + 1]++;
            student[index]--;
        }
        return Math.max(leftCnt, rightCnt, getCnt(student, index + 1, cnt));
        
    } else {
        return getCnt(student, index + 1, cnt);
    }
    
}



function solution(n, lost, reserve) {
    var answer = 0;
    
    let student = new Array(n).fill(1);
    lost.forEach(function(el) {
        student[el - 1]--; 
    });
    
    reserve.forEach(function(el) {
       student[el - 1]++; 
    });
    
    let cnt = 0;
    for(let i = 0; i < student.length; i++) {
        if(student[i] >= 1) cnt++;
    }
    
    answer = getCnt(student, 0, cnt);
    
    return answer;
}