'use srtict';
/**
 * @param {string[]} strs
 * @return {string}
 */
const longestCommonPrefix = function(strs) {
    // 判断空数组
    if (strs.length == 0) {
        return ""
    }
    let pstr = strs[0];
    for (let i = 1; i < strs.length; i++) {
        let j = 0;
        for (; j < strs[i].length; j++) {
            if (pstr[j] != strs[i][j]) {
                break;
            }
        }
        pstr = pstr.substr(0, j);
        if (pstr === undefined) {
            return "";
        }
    }
    return pstr
};

const test_exp = ["f1lower", "flow", "flight"];

console.log(longestCommonPrefix(test_exp));