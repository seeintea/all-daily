interface LabelledValue {
    label: string;
    color?: string; // 可选属性
    readonly count: number; //只读 只能在初始化时赋值
    // ReadonlyArray<>
} 

function printLabel(labelledObj: LabelledValue) {
    console.log(labelledObj.label);
}

interface StringArray {
    [index: number]: string;
    length?: number;
    // name: string
}

let myArray: StringArray = ['Bob', 'Fred'];

interface ClockInterface1 {
    currentTime: Date;
    setTime(d: Date);
}

class Clock implements ClockInterface1 {
    currentTime: Date;
    setTime(d: Date) {
        this.currentTime = d;
    }
}

interface Shape {
    color: string;
}

interface PenStroke {
    penWhide: number;
}

interface Square extends Shape, PenStroke {
    sideLength: number;
}

let square = <Square>{};
square.color = 'blue';
square.penWhide = 10;
square.sideLength = 5;