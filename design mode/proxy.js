// 代理模式

// 明星买鞋
var Shose = function(name) {
    this.name = name;
}

Shose.prototype.getName = function() {
    return this.name;
}

var star = {
    byShoses: function(name) {
        console.log('买了一双' + name);
    }
}

// star.byShoses(new Shose('皮鞋'));

// 明星助理帮忙买鞋
var assistant = {
    byShoses: function(shose) {
        star.byShoses(shose.getName());
    }
}

assistant.byShoses(new Shose('高跟鞋'));