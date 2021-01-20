let concat = (array1, array2) => Array.concat([array1, array2]);

let updateElementInArray = (array, index, newValue) => {
  let lengthOfArray = Array.length(array);

  Js.Array.slice(~start=0, ~end_=index, array)
  ->concat([|newValue|])
  ->concat(Js.Array.slice(~start=index + 1, ~end_=lengthOfArray - 1, array));
};
