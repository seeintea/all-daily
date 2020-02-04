const path = require('path');

function resolve(dir) {
    return path.join(__dirname, dir);
}

module.exports = {
    chainWebpack: config => {
        config.resolve.alias
            .set("@", resolve('src'))
            .set("@api", resolve('src/api'))
            .set("@common", resolve('src/common'))
            .set("@components", resolve('src/components'))
            .set("@router", resolve('src/router'))
            .set("@store", resolve('src/store'))
            .set("@utils", resolve('src/utils'))
            .set("@base", resolve('src/base'))
    }
}