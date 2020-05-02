// 策略模式 奖金

const calculateBonus = (performanceLevel, salary) => {
	if(performanceLevel === 'S') {
		return salary * 4;
	}
	if(performanceLevel === 'A') {
		return salary * 3;
	}
	if(performanceLevel === 'B') {
		return salary * 2;
	}
}

// console.log(calculateBonus('S', 2000));
// console.log(calculateBonus('B', 1000));
// 过多的 if 代码臃肿

const performanceS = function() {};
const performanceA = function() {};
const performanceB = function() {};

performanceS.prototype.calculate = function(salary) {
	return salary * 4;
}

performanceA.prototype.calculate = function(salary) {
	return salary * 3;
}

performanceB.prototype.calculate = function(salary) {
	return salary * 2;
}

const Bonus = function() {
	this.salary = null;
	this.strategy = null;
}

Bonus.prototype.setSalary = function(salary) {
	this.salary = salary;
}

Bonus.prototype.setStrategy = function(strategy) {
	this.strategy = strategy;
}

Bonus.prototype.getBonus = function() {
	return this.strategy.calculate(this.salary);
}

const a = new Bonus();
a.setSalary(1000);
a.setStrategy(new performanceS);
console.log(a.getBonus());