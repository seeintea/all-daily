// Array Iterayor
var Iterator = function(array) {
    var current = 0;

    var next = function() {
        current += 1;
    }

    var isDown = function() {
        return current >= array.length;
    }

    var getCurrentItem = function() {
        return array[current];
    }

    return {
        next: next,
        isDown: isDown,
        getCurrentItem: getCurrentItem
    }
}

var isSameIter = function(iter, ntIter) {
    while (!iter.isDown() || !ntIter.isDown()) {
        if (iter.getCurrentItem() !== ntIter.getCurrentItem()) {
            throw new Error('iter and ntIter not same Itertor!');
        }
        iter.next();
        ntIter.next();
    }
    console.log('iter and ntIter is same Itertor!')
}

var iter = Iterator([1, 2, 3, 4, 6, 6]);
var ntIter = Iterator([1, 2, 3, 4, 5, 6]);

isSameIter(iter, ntIter);