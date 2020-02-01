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
            import ('@components/concert/concert.vue'),
        children: [
            // 子路由
            {
                path: 'singer',
                name: '歌手',
                redirect: '/find'
            },
            {
                path: 'rank',
                name: '排行',
                component: () =>
                    import ('@components/find/find.vue')
            },
            {
                path: 'songList',
                name: '全部歌单',
                component: () =>
                    import ('@components/find/find.vue')
            },
            {
                path: 'broading',
                name: '电台',
                component: () =>
                    import ('@components/find/find.vue')
            },
            {
                path: 'listing',
                name: '一起听',
                component: () =>
                    import ('@components/find/find.vue')
            },
        ]
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