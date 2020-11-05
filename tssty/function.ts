function add(x: number, y: number) :number {
    return x+y;
}

let myadd = function (x: number, y: number) :number {
    return x+y;
}

function buildName(firstname: string, lastname?: string): string {
    if(lastname) {
        return firstname + lastname;
    } else {
        return firstname;
    }
}

function buildName1(firstname: string, lastname = "ts"): string {
    return firstname + lastname
}

// 剩余参数
function buildName2(firstname: string, ...allName: string[]): string {
    return firstname + " " + allName.join("  ");
}

// 重栽函数
function addFunc(x:number, y:number): number;
function addFunc(x:Array<number>): number;
function addFunc(x): any {
    if(x instanceof Array) {
        let res = 0;
        for(let val of x) {
            res += val;
        }
    } else {
        return 0
    }
}