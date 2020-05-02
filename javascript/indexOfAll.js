var __spreadArrays = (this && this.__spreadArrays) || function () {
    for (var s = 0, i = 0, il = arguments.length; i < il; i++) s += arguments[i].length;
    for (var r = Array(s), k = 0, i = 0; i < il; i++)
        for (var a = arguments[i], j = 0, jl = a.length; j < jl; j++, k++)
            r[k] = a[j];
    return r;
};
var indexOfAll = function (array, find) {
    return array.reduce(function (init, next, idx) {
        next === find ? /*init.push(idx)*/ __spreadArrays(init, [idx]) : init;
        return init;
    }, []);
};
var arr = [1, 2, 5, 8, 3, 1, 1, 5, 1, 1];
var find = 1;
console.log(indexOfAll(arr, find));
