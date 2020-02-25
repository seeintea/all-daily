package controller

import (
	"net/http"
	"shopping/dao"
	"shopping/model"
	"text/template"
)

// ShoppingLogin 登陆处理器
func ShoppingLogin(w http.ResponseWriter, r *http.Request) {
	// 获取账号密码
	u := r.PostFormValue("username")
	p := r.PostFormValue("password")
	result, user := dao.CheckUserInfo(u, p)
	if result {
		// 返回登陆成功页面
		t := template.Must(template.ParseFiles("views/pages/user/login_success.html"))
		t.Execute(w, user)
	} else {
		// 登陆错误逻辑
		t := template.Must(template.ParseFiles("views/pages/user/login.html"))
		t.Execute(w, "worry")
	}
}

// ShoppingRegist 注册处理器
func ShoppingRegist(w http.ResponseWriter, r *http.Request) {
	// 获取网页上的注册信息
	u := r.PostFormValue("username")
	// 先处理重名问题
	result := dao.CheckUserName(u)
	if !result {
		// 重名发生错误 处理结束
		t := template.Must(template.ParseFiles("views/pages/user/regist.html"))
		t.Execute(w, "worry")
		return
	}
	p := r.PostFormValue("password")
	e := r.PostFormValue("email")
	user := &model.User{
		UserName: u,
		PassWord: p,
		Email:    e,
	}
	// 添加用户
	result = dao.AddNewUser(user)
	if result {
		// 注册成功界面
		// 注册成功后 抛出用户名
		t := template.Must(template.ParseFiles("views/pages/user/regist_success.html"))
		t.Execute(w, u)
	} else {
		// SQL 错误逻辑
		t := template.Must(template.ParseFiles("views/pages/user/regist.html"))
		t.Execute(w, "worry2")
	}
}

// ShoppingReName 账户已存在处理器
func ShoppingReName(w http.ResponseWriter, r *http.Request) {
	// 获取网页上的注册信息
	u := r.PostFormValue("username")
	// 先处理重名问题
	result := dao.CheckUserName(u)
	if !result {
		// 重名发生错误 处理结束
		w.Write([]byte("worry"))
	}
}
