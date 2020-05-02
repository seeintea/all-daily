// 手写 instanceof
function proto(left, right) {
	const rp = right.prototype;
	let lp = left.__proto__;
	while(true) {
		if(lp === null){
			return false;
		} else if (lp === rp) {
			return true;
		}
		lp = lp.__proto__;
	}
}