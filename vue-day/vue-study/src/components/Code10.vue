<template>
    <div>
        <cmt @func="loadCmments"></cmt>
        <li v-for="item in list" :key="item.id" tag="ul">
            <span class="badge">评论人：{{ item.name }}</span>
            {{ item.content }}
        </li>
    </div>
</template>

<script>
import Cmt from './Comp1.vue'

export default {
    name: 'Code10',
    data: () => {
        return {
            list: [
                {id: Date.now(), name: 'Gu', content:'test 1'},
                {id: Date.now()-1, name: 'Qu', content:'test 2'},
                {id: Date.now()-2, name: 'Wu', content:'test 3'},
                {id: Date.now()-3, name: 'Ru', content:'test 4'}
            ]
        }
    },
    created() {
        this.loadCmments();
        console.log(this.$route);
        
        
    },
    methods: {
        loadCmments() {
            let list = JSON.parse(localStorage.getItem('cmts') || '[]');
            this.list = list;
        }
    },
    components:{
        Cmt
    }
}
</script>

<style scoped>

</style>