const foo = new Set(['안녕', '하이', '샬롬' ]);
foo.forEach((value, key, s) => {
  console.log(value, key, s);
});