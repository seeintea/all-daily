// global Observer Model
var Event = (function() {

    var clientList = {},
        listen,
        tigger,
        remove;

    listen = function(key, fn) {
        if (!clientList[key]) {
            // as Array
            clientList[key] = [];
        }
        clientList[key].push(fn);
    };

    tigger = function() {
        var key = Array.prototype.shift.call(arguments);
        fns = clientList[key];
        // undefined or remove 
        if (!fns || fns.length === 0) {
            return false;
        }
        for (var i = 0, fn; fn = fns[i++];) {
            fn.apply(this, arguments);
        }
    };

    remove = function(key, fn) {
        var fns = clientList[key];
        if (!fns) {
            return false;
        }
        // undefined => Array isNull
        if (!fn) {
            fns && (fns.length = 0)
        } else {
            for (var l = fns.length - 1; l >= 0; l--) {
                var _fn = fns[l];
                if (_fn === fn) {
                    fns.slice(l, 1);
                }
            }
        }
    };

    return {
        listen: listen,
        tigger: tigger,
        remove: remove
    }
})();