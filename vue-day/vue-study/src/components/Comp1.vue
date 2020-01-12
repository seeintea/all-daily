<template>
    <div>
        <div class="form-group">
            <label> 评论人:</label>
            <input type="text" class="form-control" v-model="user">
        </div>
        <div class="form-group">
            <label> 评论内容:</label>
            <textarea class="form-control" v-model="content"></textarea>
        </div>
        <div class="form-group">
            <input type="button" value="ensure" class="btn-primary" @click="postCon"/>
        </div>

    </div>
</template>

<script>
export default {
    name: 'Comp1',
    data: () => {
        return {
            user: '',
            content: '',
            msg: 'test info'
        }
    },
    methods: {
        postCon() {
            let comment = { id: Date.now(), name: this.user, content:this.content };
            let listJson = JSON.parse(localStorage.getItem('cmts') || '[]' );
            listJson.unshift(comment);
            localStorage.setItem('cmts', JSON.stringify(listJson));
            this.user = this.content = '';
            this.$emit('func');
        },
    },
}
</script>