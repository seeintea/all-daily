// ES6 中使用 export default 和 export 向外暴露成员

export default {
    name: 'test',
    age: 20
}

// export default 向外暴露的成员可以使用任意变量来接受

var info = {
    address: '1234',
    name: 'text'
};

// 只允许 export default 向外暴露一次

export var obj = info;

export var obj1 = info;
// 使用 export 向外暴露的成员 只能使用 { } 的形式来接受
// export 可以暴露多个成员