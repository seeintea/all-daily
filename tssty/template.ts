function identity<T>(arg: T) : T {
    return arg;
}


function showArrayLen<T>(args: T[]): number {
    return args.length;
}

// 范行接口
interface GenericIdentityFn<T> {
    (arg: T): T;
}

// 泛型类
class AddClass<T> {
    zeroValue: T;
    add: (x: T, y: T) => T;
}

//  use: 
let addEntity = new AddClass<number>();
addEntity.zeroValue = 0;
addEntity.add = (x:number, y:number) => x+y;