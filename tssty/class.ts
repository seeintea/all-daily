class Greeter {
    greeting: string;
    constructor(message: string) {
        this.greeting = message;
    }
    greet() {
        return `Helle ${this.greeting}`;
    }
}

class Animal {
    public name: string;
    private age: number;
    protected food: string;

    // readonly name: string;

    constructor(name: string) {
        this.name = name;
    }
    public setAge(age: number) {
        this.age = age;
    }
    public getAge() {
        return this.age;
    }
    move(step: number) {
        console.log(`Animal is moved ${step} way`);
    }
}

class Dog extends Animal {

    constructor(name: string) {
        super(name);
    }

    setFood(food: string) {
        this.food = food;
    }

    bark() {
        console.log('Woof Woof');
    }
}

let d = new Dog("woof");
// d.food => worry
// d.name 

class Employee {

    static rold: number = 1;

    private _fullName: string;

    get fullName() {
        Employee.rold = 2;
        return this._fullName;
    }

    set fullName(name: string) {
        this._fullName = name;
    }

}

let Employeee: typeof Employee = Employee;

let empeee = new Employeee();

// 抽象类
abstract class Animall {
    abstract makeSound(): void;
}

// 类当做接口使用
class Point {
    x: number;
    y: number;
}

interface Point3D extends Point {
    z: number;
}

let prin3D:Point3D = {
    x: 1,
    y: 2,
    z: 3
}