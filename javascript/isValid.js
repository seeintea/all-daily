'use strict';


//  '('，')'，'{'，'}'，'['，']'
/**
 * @param {string} str
 * @return {boolean}
 */
const isValid = function(str) {
    const obj = {
        '(': ')',
        '[': ']',
        '{': '}'
    }

    let temp = [];
    for (let i = 0; i < str.length; i++) {
        let char = str.charAt(i);
        if (char == '(' || char == '[' || char == '{') {
            temp.push(char);
        } else {
            if (obj[temp[temp.length - 1]] == char) {
                temp.pop();
            } else {
                temp.push(char);
                return false;
            }
        }
    }
    if (!temp.length) {
        return true;
    }
    return false;
};

console.log(isValid("([)]"));