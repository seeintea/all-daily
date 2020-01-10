//  导入 JQUERY
import $ from 'jquery';
// import 处理 CSS 样式表
// webpack 默认打包处理 JS 类型文件，无法处理非 JS 文件
// 处理非 JS 文件 需要手动安装一些适合的三方 loader 加载器
// 打包 CSS 文件 需要 npm i style-loader css-loader -D
import './css/index.css';
import './css/index.scss';

$(function() {
    $('li:odd').css('backgroundColor', 'lightGreen');
    $('li:even').css('backgroundColor', function() {
        return '#' + 'B20000';
    })
})

// webpack 功能
//1. 处理JS文件之间的依赖关系
//2. 处理JS的兼容问题