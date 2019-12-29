<template>
    <div>     
        <div>
            <input type="text" v-model="id" />
            <input type="text" v-model="name" @keyup.113="add"/>    <!-- 或者使用 keyup.enter -->
            <input type="submit" @click="add" />
            <label>检索：</label>
            <input type="text" v-model="asearch" v-focus v-color="'blue'"/>
        </div>

        <table class="table table-bordered table-hover table-striped">
            <thead>
                <tr>
                    <td>ID</td>
                    <td>Name</td>
                    <td>Ctime</td>
                    <td>Oper</td>
                </tr>
            </thead>
            <tr v-for="item in dataSearch(asearch)" :key="item.id">
                <td>{{item.id}}</td>
                <td v-text="item.name"></td>
                <td>{{item.ctime | dataFormat("yyyy-mm-dd")}}</td>
                <td><a href="" @click.prevent="del(item.id)">{{'删除' | delFormat}}</a></td>
            </tr>
        </table>

        <h2 v-fontWeight="'100'" v-fontSize="'18'">{{new Date()}}</h2>

    </div>
</template>

<script>

export default {
    name: 'Code2',
    data: function() {
        return {
            id: '',
            name: '',
            asearch: '',
            list: [
                {id:1, name: 'cs', ctime: new Date()},
                {id:2, name: 'cd', ctime: new Date()},
            ]
        }
    },
    methods: {
        add() {
            if(this.id == '' || this.name == '') return;    //判断为空
            let info = {id: this.id, name: this.name, ctime: new Date()};
            this.list.push(info);
            this.id = '';
            this.name = '';
        },
        del(id){
            /*this.list.some((item,i) => {
                if(item.id == id){
                    this.list.splice(i,1);
                    return true;
                }
            })*/
            let index = this.list.findIndex(item => {
                if(item.id == id){
                    return true;
                }
            });
            this.list.splice(index, 1);
        },
        dataSearch(asearch){
            /*let newList = [];
            this.list.forEach(item =>{
                if(item.name.indexOf(asearch) != -1){
                    newList.push(item);
                }
            })
            return newList;*/
            let newList = this.list.filter(item => {
                if(item.name.includes(asearch)){
                    return item;
                }
            })
            return newList;
        },
    },
    filters: {
        //  局部过滤器 与 全局冲突时 优先使用 局部过滤器
        delFormat: function(data){
            return data+' self test';
        }
    },
    directives: {
        // 自定义私有指令
        'fontWeight' : {
            bind: function(el,binding){
                el.style.fontWeight = binding.value;
            }
        },
        // 指令简写
        // 等同于将函数 写入 bind 和 inserted 中
        'fontSize': function(el,binding) {
            el.style.fontSize = parseInt(binding.value) + 'px';
        }
    },
}
</script>

<style scoped>

</style>