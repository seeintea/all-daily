module.exports = {
    configureWebpack: {
        resolve: {
            alias: {
                'assets': '@/assets',
                'common': '@/cpmmom',
                'components': '@/components',
                'network': '@/network',
                'views': '@/views'
            }
        }
    }
}