package controller

import (
	"fmt"
	"net/http"
)

//SetCookieDome 设置Cookie测试
func SetCookieDome(w http.ResponseWriter, r *http.Request) {
	cookie := http.Cookie{
		Name:     "user",
		Value:    "admin",
		HttpOnly: true,
		MaxAge:   60,
	}
	cookie2 := http.Cookie{
		Name:     "age",
		Value:    "18",
		HttpOnly: true,
	}
	//发送给客户端
	http.SetCookie(w, &cookie)
	//w.Header().Set("Set-Cookie", cookie.String())
	w.Header().Add("Set-Cookie", cookie2.String())
}

//GetCookieDome 设置Cookie测试
func GetCookieDome(w http.ResponseWriter, r *http.Request) {
	cookies := r.Header["Cookie"]
	fmt.Println(cookies)
	cookie, _ := r.Cookie("user")
	fmt.Println(cookie)
}
