// 手写 new
function create() {
	const obj = {};
	const fn = [].shift.call(arguments);
	obj.__proto__ = fn.protptype;
	const res = fn.apply(obj, arguments);
	return typeof res == 'object' ? res : obj;
}