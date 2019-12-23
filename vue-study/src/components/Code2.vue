<template>
    <div>

        <div>
            <input type="text" v-model="id" />
            <input type="text" v-model="name" />
            <input type="submit" @click="add" />
            <label>检索：</label>
            <input type="text" v-model="asearch" />
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
                <td>{{item.ctime}}</td>
                <td><a href="" @click.prevent="del(item.id)">删除</a></td>
            </tr>
        </table>
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
}
</script>

<style scoped>

</style>