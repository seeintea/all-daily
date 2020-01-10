const path = require('path')

//导入在内存中生成 html 页面的插件
const htmlWebpackPlugin = require('html-webpack-plugin')

module.exports = {
    mode: 'development',
    // 入口文件 表示需要打包的文件
    entry: path.join(__dirname, 'src/main.js'),
    // 出口文件 表示打包后输出文件目录
    output: {
        path: path.join(__dirname, 'dist/'),
        filename: 'bundle.js'
    },
    //自动打包
    //npm i webpack-dev-server -D
    //安装到本地项目依赖
    //打包的文件没有存放在物理磁盘中
    //托管在电脑内存中
    // webpack-dev-server 第二种配置方法
    // devServer: {
    //     open: true,
    //     port: 4000,
    //     contentBase: 'src',
    //     hot: true
    // }
    plugins: [
        new htmlWebpackPlugin({
            template: path.join(__dirname, 'src/index.html'), //指定模版页面
            filename: 'index.html' //指定生成页面名称
        })
    ],
    // 配置三方模块加载器
    module: {
        rules: [{
                test: /\.css$/,
                use: ['style-loader', 'css-loader']
            },
            {
                test: /\.scss$/,
                use: ['style-loader', 'css-loader', 'sass-loader']
            }
        ]
    }
}