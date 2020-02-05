export function addClass(el, className) {
    if (hasClass(el, className)) {
        return;
    }
    let newClass = className.split(' ');
    newClass.push(className);
    el.className = newClass.join(' ');

}

// 20200204 problem
export function hasClass(el, className) {
    let reg = new RegExp('(^|\\s)' + className + '(^|\\s)');
    return reg.test(el.className);
}