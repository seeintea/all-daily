import Vue from 'vue'
import VueRouter from 'vue-router'

Vue.use(VueRouter);

const routes = [
    // 路由设置
    {
        path: '/',
        redirect: '/concert'
    },
    {
        path: '/concert',
        name: '音乐馆栏目',
        component: () =>
            import ('@components/concert/concert.vue')
    },
    {
        path: '/find',
        name: '发现栏目',
        component: () =>
            import ('@components/find/find.vue')
    },
    {
        path: '/comment',
        name: '热评栏目',
        component: () =>
            import ('@components/comment/comment.vue')
    },
    {
        path: '/mine',
        name: '我的栏目',
        component: () =>
            import ('@components/mine/mine.vue')
    }
];

const router = new VueRouter({
    routes,
});

export default router;