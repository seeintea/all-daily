<template>
    <div>
        {{ msg }}
    </div>
</template>

<script>

var login = {
    template: '<h1>这是登陆组件</h1>'
}

export default {
    name: 'Code13',
    data: () => {
        return {
            msg: 'Test ....',
        }
    },
    render: function(createElement) {
        let html = createElement(login);
        return html;
        // 返回结果会替换指定的容器
    },
    methonds: {

    },
}
</script>