// 国王和矿工问题
// G = [500,400,300,350,200]
// p = [5,5,3,4,3]

// utils
const Glod: Array<number> = [200, 350, 300, 400, 500];
const People: Array<number> = [3, 4, 3, 5, 5];

const max = (x: number, y: number) => {
	return x > y ? x : y;
}

/**
 * 递归法 国王和矿工问题
 * @param gCount 剩余金矿数
 * @param pCount 可用人数
 * @param Glod 金矿数组
 * @param People 人分配数组
 */
const determin = (gCount: number, pCount: number, Glod: Array<any>, People: Array<any>) => {
	// 人数不够或者可用金矿数为0 
	if (gCount < 0 || pCount < People[gCount]) return 0;
	// 放弃当前金矿
	let left = determin(gCount - 1, pCount, Glod, People);
	// 挖掘此金矿
	let now_People = pCount - People[gCount - 1];
	if (now_People >= 0) {
		let right = Glod[gCount - 1] + determin(gCount - 1, now_People, Glod, People);
		return max(left, right);
	}
	return 0;
}
console.log("递归法解决问题:" + determin(5, 10, Glod, People) + "金");

const determin_bup = (gCount: number, pCount: number, bup: object, Glod: Array<any>, People: Array<any>) => {
	if (gCount < 0 || pCount < People[gCount]) return 0;
	const key: string = `${gCount}${pCount}`;
	let left = determin_bup(gCount - 1, pCount, bup, Glod, People);
	let now_People = pCount - People[gCount - 1];
	if (now_People >= 0 && !bup[key]) {
		let right = Glod[gCount - 1] + determin_bup(gCount - 1, now_People, bup, Glod, People);
		bup[key] = right;
		return max(left, right);
	} else if (now_People >= 0) {
		return max(bup[key], left);
	}
	return 0;
}
console.log("递归备忘法解决问题:" + determin_bup(5, 10, {}, Glod, People) + "金");


