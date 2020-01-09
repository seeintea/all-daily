//  导入 JQUERY
import $ from 'jquery';

$(function() {
    $('li:odd').css('backgroundColor', 'lightgreen');
    $('li:even').css('backgroundColor', function() {
        return '#' + 'B20000';
    })
})

// webpack 功能
//1. 处理JS文件之间的依赖关系
//2. 处理JS的兼容问题