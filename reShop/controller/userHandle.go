package controller

import (
	"net/http"
	"shopping/dao"
)

// ShoppingLogin 登陆处理器
func ShoppingLogin(w http.ResponseWriter, r *http.Request) {
	// 获取账号密码
	u := r.PostFormValue("username")
	p := r.PostFormValue("password")
	result := dao.CheckUserInfo(u, p)
	if result {

	}
}
