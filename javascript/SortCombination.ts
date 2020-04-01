// 排列组合算法

// utils
// swap 数组交换
const swap = (array: Array<any>, be: number, af: number) => {
	[array[be], array[af]] = [array[af], array[be]];
}

// 排序暴力解法
// 字符串的长度没增加 1 择要增加一层循环 
// 存在问题 若字符串中有相同字符 程序出错
const force = (str: Array<string>) => {
	for (const i in str) {
		for (const j in str) {
			for (const k in str) {
				if (str[i] != str[j] && str[j] != str[k] && str[k] != str[i]) {
					console.log("[" + str[i] + "," + str[j] + "," + str[k] + "]");
				}
			}
		}
	}
}

// testing
console.log("暴力法测试字符“abc”:");
force(['a', 'b', 'c']);
console.log("暴力法测试字符“aac”:");
force(['a', 'a', 'c']);

// 递归解法
const rank = (array: Array<string>, step) => {
	if (array.length == step) {
		console.log(array);
		return;
	} else {
		for (let i = step; i < array.length; i++) {
			// 需要一个数组保持原来的状态
			// 以保证一下递归仍是初始数组
			const [...temp] = array;
			swap(array, step, i);
			rank(array, step + 1);
			array = temp.slice();
		}
	}
}

// testinf
console.log("递归法测试字符“abc”:");
rank(['a', 'b', 'c'], 0);
console.log("递归法测试字符“aac”:");
rank(['a', 'a', 'c'], 0);

// 上述算法仍然存在问题
// 例如 无法正确处理 “aac”
// 进一步优化

const isExist = (array: Array<any>, step: number, hash: object) => {
	for (let i = step; i < array.length; i++) {
		Object.keys(hash).forEach((_, index) => {
			if (index != array[i]) {
				hash[array[i]] = true;
			}
		})
	}
}

const difRank = (array: Array<string>, step, hash: object) => {
	if (array.length == step) {
		console.log(array);
		return;
	} else {
		isExist(array, step, hash);
		for (let i = step; i < array.length; i++) {
			if (hash[array[i]]) {
				hash[array[i]] = false;
				const [...temp] = array;
				swap(array, step, i);
				rank(array, step + 1);
				array = temp.slice();
			}
		}
	}
}

// testing
console.log("递归法优化测试字符“abc”:");
difRank(['a', 'b', 'c'], 0, { "": "" });
console.log("递归法优化测试字符“aac”:");
difRank(['a', 'a', 'c'], 0, { "": "" });

// 组合问题
const combination = (array: Array<any>, step: number, comb: number) => {
	if (array.length == step) {
		// 用一个 hash 存入 返回哈希 
		// lazy 不做了
		console.log(array.slice(0, comb));
		return;
	} else {
		for (let i = step; i < array.length; i++) {
			const [...temp] = array;
			swap(array, step, i);
			combination(array, step + 1, comb);
			array = temp.slice();
		}
	}
}

// testing
console.log("组合测试字符“abcdef”:");
combination(["a", "b", "c", "d", "e", "f"], 0, 3);