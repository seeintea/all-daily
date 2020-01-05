import Vue from 'vue';
import VueRouter from 'vue-router';
import Home from '../App.vue';

Vue.use(VueRouter);

const routes = [{
        path: '/',
        name: 'home',
        component: Home,
    },
    {
        path: '/1',
        name: 'Code2',
        component: () =>
            import ('../components/Code2.vue')
    },
    {
        path: '/2',
        name: 'Code3',
        component: () =>
            import ('../components/Code3.vue')
    },
    {
        path: '/3',
        name: 'Code4',
        component: () =>
            import ('../components/Code4.vue')
    },
    {
        path: '/4',
        name: 'Code5',
        component: () =>
            import ('../components/Code5.vue')
    },
    {
        path: '/5',
        name: 'Code6',
        component: () =>
            import ('../components/Code6.vue')
    },
    {
        path: '/7',
        name: 'Code7',
        component: () =>
            import ('../components/Code7.vue')
    },
    {
        path: '/8',
        name: 'Code8',
        component: () =>
            import ('../components/Code8.vue')
    },
    {
        path: '/9',
        name: 'Code9',
        component: () =>
            import ('../components/Code9.vue')
    },
    {
        path: '/10',
        name: 'Code10',
        component: () =>
            import ('../components/Code10.vue')
    },
    {
        path: '/11',
        name: 'Code11',
        component: () =>
            import ('../components/Code11.vue')
    },
    {
        path: '/test',
        name: 'VueTest',
        component: () =>
            import ('@/components/Test.vue')
    }
]

const router = new VueRouter({
    routes,
});

export default router;