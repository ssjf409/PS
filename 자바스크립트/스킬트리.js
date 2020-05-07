function solution(skill, skill_trees) {
    var answer = 0;
    
    const m = new Map();
    for(let i = 0; i < skill.length; i++) {
        m.set(skill[i], i);
    }
    
    
    skill_trees.forEach(function(el) {
        let index = 0;
        let flag = false;
        for(let i = 0; i < el.length; i++) {
            if(m.has(el[i])) {
                if(m.get(el[i]) !== index++) {
                    flag = true;
                    break;
                }
                
            }
        }
        if(!flag) answer++;
    });
    
    
    return answer;
}