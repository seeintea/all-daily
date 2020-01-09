const path = require('path')

module.exports = {
    mode: 'development',
    // 入口文件 表示需要打包的文件
    entry: path.join(__dirname, 'src/main.js'),
    // 出口文件 表示打包后输出文件目录
    output: {
        path: path.join(__dirname, 'dist/'),
        filename: 'bundle.js'
    }
    //自动打包
    //npm i webpack-dev-server -D
    //安装到本地项目依赖
    //打包的文件没有存放在物理磁盘中
    //托管在电脑内存中
}