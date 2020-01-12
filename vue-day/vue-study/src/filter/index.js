import Vue from 'vue';

// 全局
Vue.filter('dataFormat', function(data, pattern) {
    // data.replace(/x/g, 'y') 全局匹配 将 x 替换成 y
    let dt = new Date(data);
    let y = dt.getFullYear();
    let m = (dt.getMonth() + 1).toString().padStart(2, '0'); //补充 0  Ex. 1 -> 01
    let d = (dt.getDate()).toString().padStart(2, '0');

    if (pattern && pattern.toLowerCase() === 'yyyy-mm-dd') {
        return `${y}-${m}-${d}`;
    } else {
        let h = dt.getHours();
        let f = dt.getMinutes();
        let s = dt.getSeconds();
        return `${y}-${m}-${d} ${h}:${f}:${s}`;
    }

});