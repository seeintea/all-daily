<template>
    <div>
        <div>
            <input type="text" v-model="id" />
            <input type="text" v-model="name" />
            <input type="button" value="add" @click="add">
        </div>
        <!-- <ul> -->
            <!-- 列表过度 v-for 循环 不能使用 transition 包裹 -->
            <!-- appear 实现入场效果 -->
            <!-- tag 设置transition为指定元素 默认为span标签 -->
            <transition-group mode="out-in" appear tag='ul'>
                <li v-for="(item,i) in list" :key='item.id' @click="del(i)">
                    {{item.id}} --- {{ item.name }}
                </li>
            </transition-group>
        <!-- </ul> -->
    </div>
</template>

<script>
export default {
    name: 'Code6',
    //data 定义成方法目的 调用相同组件的不共享一个data对象
    data: () => {
        return {
            id: '',
            name: '',
            list: [
                {id: 1, name: 'x1'},
                {id: 2, name: 'x2'},
                {id: 3, name: 'x3'},
                {id: 4, name: 'x4'},
                {id: 5, name: 'x5'}
            ]
        }
    },
    methods: {
        add() {
            if(this.id === '' || this.name === '') return;
            let obj = {id: this.id, name: this.name};
            this.list.push(obj);
            this.id = this.name = '';
        },
        del(i) {
            this.list.splice(i,1);
        }
    }
}
</script>

<style scoped>
li {
    margin: 10px;
    border: 1px dotted #333;
    width: 100%;
}

li:hover {
    background: #b20000;
}

.v-enter,
.v-leave-to {
    opacity: 0;
    transform: translateX(-80px);
}

.v-enter-active,
.v-leave-active {
    transition: all 0.5s ease;
}

/* 配合使用 */
.v-move {
     transition: all 0.5s ease;
}

.v-leave-active {
    position: absolute;
}
</style>