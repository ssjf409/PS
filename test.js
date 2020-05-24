
const calculator = {
  function plus(a, b){ return a+b; };
  minus: function(a, b){ return a-b; },
  times: function(a, b){ return a*b; },
  division: function(a, b){ return a*b; }
}
const plus = calculator.plus(2, 3)
console.log(plus);