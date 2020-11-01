let isOpen: boolean = false;

let decLiteral: number = 6;
let hexLiteral: number = 0xf00d;

let username: string = 'Levie Gu';
let userinfo: string = `hello, my name is ${username}`;

let list: number[] = [1,2,3];
let arr: Array<number> = [1,2,3];

let arr1: Array<number | string> = [1,2,3, 'false'];

enum Color {
    Red,
    Green,
    Blue
}

let c: Color = Color.Blue;

let notSure: any = 4;
notSure = 'NotSure';

let unuse: void = undefined;
unuse = null;

function error(message: string): never {
    throw new Error(message);
}

let someValues: any = 'this is a string';
let strLength: number = (<string>someValues).length;
// or
strLength = (someValues as string).length;

let [first, second]: [number, number] = [1, 2]