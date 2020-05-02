// 手写 call apply bind
const obj = {
	name : 'objName',
	getName(...args) {
		console.log(args)
		return this.name;
	}
}

global.name = 'globalName'

const newObj = obj.getName;
const newObjCom = obj.getName();

console.log(newObj());
console.log(newObjCom);

Function.prototype._call = function(content = global) {
	content.fn = this;
	let args = [...arguments].slice(1);
	let res = content.fn(...args);
	delete content.fn;
	return res;
}

const _callOb = {
	name: '_callOb'
}

const _callObj = obj.getName;
_callObj._call(_callOb, 1, 2, 3, 4, 5);

Function.prototype._apply = function(content = global) {
	content.fn = this;
	let res;
	if(arguments[1]) {
		res = content.fn(...arguments[1]);
	} else {
		res = content.fn();
	}
	delete content.fn;
	return res;
}

const _applyObj = obj.getName;
_applyObj._apply(_callOb,[1,2,3,4,5]);

Function.prototype._bind = function(content) {
	if(typeof this !=  'function') {
		throw Error('not a function');
	}
	let _this = this;
	let args = [...arguments].slice(1);
	return function F() {
		if(_this instanceof F){
			return _this.apply(_this, args.concat([...arguments]));
		}
		return _this.apply(content, args.concat([...arguments]));
	}
}

const _bindObj = obj.getName;
_bindObj._bind(_callOb,1,3,5,7,9)();