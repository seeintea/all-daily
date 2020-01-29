import service from '@utils/http.js'

// achieve banner
export function getBannerAdr() {
    service.get('/banner')
        .then(res => {
            console.log(res.data.banners)
            return res
        }).catch(err => {
            return err;
        })
}

// singer button
export function getSingerList() {
    service.get('')
        .then(res => {
            return res.data
        }).catch(err => {
            return err
        })
}