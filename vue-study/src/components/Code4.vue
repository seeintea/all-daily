<template>
    <div>
        <p>axios-study !</p>
        <!-- <input type="button" value="get请求" @click="getInfo" /> -->
        <table class="table table-bordered table-hover table-striped">
            <thead>
                <tr>
                    <td>ID</td>
                    <td>Name</td>
                    <td>Ctime</td>
                    <td>Oper</td>
                </tr>
            </thead>
            <tr v-for="item in list" :key="item.id">
                <td>{{ item.id }}</td>
                <td>{{ item.name }}</td>
                <td>{{ item.ctime | dataFormat('yyyy-MM-DD') }}</td>
                <td><a href="" @click.prevent='del(item.id)'>delete</a></td>
            </tr>
        </table>
    </div>
</template>

<script>
import axios from 'axios'

// 配置 baseURL  
axios.defaults.baseURL = 'http://www.znp.ink:3000';

export default {
    name: 'Code4',
    data: function() {
        return {
            list: [],

        }
    },
    methods: {
        del(id) {
            let index = this.list.findIndex(item => {
                if(item.id == id){
                    return true;
                }
            });
            this.list.splice(index, 1);
        },
        getInfo() {
            axios.get('/toplist/artist')
            .then(result => {
                let obj = result.data.list.artists;
                let l;
                for (let item in obj) {
                    l = {id: obj[item].id, name: obj[item].name, ctime: new Date()};
                    this.list.push(l);
                }
            })
            .catch(() => {
                console.log("data failed !")
            })
        },
    },
    created(){
        this.getInfo();
    }
}
</script>