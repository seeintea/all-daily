// 售楼案例

// 定义售楼处
var salesOffices = {};

// 订阅者队列
salesOffices.clientList = [];

// 增加订阅者
salesOffices.listen = function(fn) {
    this.clientList.push(fn);
}

// 发布消息
salesOffices.trigger = function() {
    for (var i = 0, fn; fn = this.clientList[i++];) {
        fn.apply(this, arguments);
    }
}

// 测试
salesOffices.listen(function(price, squareMeter) {
    console.log('价格 = ' + price);
    console.log('面积0 = ' + squareMeter);
});

salesOffices.listen(function(price, squareMeter) {
    console.log('价格 = ' + price);
    console.log('面积1 = ' + squareMeter);
});

salesOffices.trigger(200000, 88);
salesOffices.trigger(300000, 100);

// 针对订阅

var salesOfficesKey = {};

// 存放回调函数
salesOfficesKey.clientList = {};

salesOfficesKey.listen = function(key, fn) {
    if (!this.clientList[key]) {
        this.clientList[key] = [];
    }
    // 将订阅者的函数存放到对应的数组中
    this.clientList[key].push(fn);
}

salesOfficesKey.trigger = function() {
    var key = Array.prototype.shift.call(arguments),
        fns = this.clientList[key];
    if (!fns || fns.length === 0) {
        return false
    }
    for (var i = 0, fn; fn = fns[i++];) {
        fn.apply(this, arguments);
    }
}

// 测试
salesOfficesKey.listen('squareMeter88', function(price) {
    console.log('价格 = ' + price);
});

salesOfficesKey.listen('squareMeter100', function(price) {
    console.log('价格 = ' + price);
});

salesOfficesKey.trigger('squareMeter88', 200000);
salesOfficesKey.trigger('squareMeter88', 300000);