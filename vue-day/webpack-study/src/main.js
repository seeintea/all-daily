//  导入 JQUERY
import $ from 'jquery';
// import 处理 CSS 样式表
// webpack 默认打包处理 JS 类型文件，无法处理非 JS 文件
// 处理非 JS 文件 需要手动安装一些适合的三方 loader 加载器
// 打包 CSS 文件 需要 npm i style-loader css-loader -D
import './css/index.css';
// import './css/index.scss';

import 'bootstrap/dist/css/bootstrap.css'

$(function() {
    $('li:odd').css('backgroundColor', 'lightGreen');
    $('li:even').css('backgroundColor', function() {
        return '#' + 'B20000';
    })
})

// webpack 功能
//1. 处理JS文件之间的依赖关系
//2. 处理JS的兼容问题

class Person {
    static info = { name: 'gu', age: 22 }
}

// var p1 = new Person()

// function Animal(name) {
//     this.name = name;
// }

// let al = new Animal('gu');

// console.log(a1.name);

console.log(Person.info);
// webpack 中 通过 babel 将高级语法转换为低级语法
// npm i babel-core babel-loader babel-plugin-transform-runtime -D
// npm i babel-preset-env babel-preset-stage-0 -D
// babel-loader 8.0 全新配置
// npm i babel-loader @babel/core @babel/runtime @babel/preset-env @babel/plugin-proposal-class-properties @babel/plugin-transform-runtime -D
// 配置文件 见  .babelrc