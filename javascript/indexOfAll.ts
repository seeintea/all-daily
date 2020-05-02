const indexOfAll = (array: Array<number>, find: number) => {
	return array.reduce((init: Array<number>, next: number, idx: number) => {
		next === find ? init.push(idx) : init;
		return init;
	}, []);
}

const arr: Array<number> = [1, 2, 5, 8, 3, 1, 1, 5, 1, 1];
const find: number = 1;
console.log(indexOfAll(arr, find));
