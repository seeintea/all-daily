const Singleton = function(name) {
	this.name = name;
	this.instanc = null;
}

Singleton.prototype.getName = function() {
	console.log(this.name);
}

Singleton.getInstance = function(name = null) {
	if(!this.instanc) {
		this.instanc = new Singleton(name);
	}
	return this.instanc;
}

const a = Singleton.getInstance();
const b = Singleton.getInstance();
const c = new Singleton('c');

// console.log(a === b);
// console.log(c)
// console.log(a === c);
// 上述单例模式 依然可以用 new 构造新的实例

const SingletonTp = (function(){
	let instanc;
	const _create = function(name) {
		this.name = name;
		if(instanc) {
			return instanc;
		}
		this.getName();
		return instanc = this;
	}
	_create.prototype.getName = function(){
		console.log(this.name);
	}
	return _create;
})()

// const d = new SingletonTp('d');
// const e = new SingletonTp('e');
// console.log(d === e);
// 代码都存放在一起 不便于管理


const CreateSingleton = function(name) {
	this.name = name;
	this.getName();
}

CreateSingleton.prototype.getName = function() {
	console.log(this.name);
}

const SingletonTpp = (function() {
	let instanc;
	return function(name) {
		if(!instanc){
			instanc = new CreateSingleton(name);
		}
		return instanc;
	}
})()

const f = new SingletonTpp('f');
const g = new SingletonTpp('g');
console.log(f === g);