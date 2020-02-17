package controller

import (
	"fmt"
	"html/template"
	"net/http"
	"shopping/dao"
)

// Login 处理用户登陆函数
func Login(w http.ResponseWriter, r *http.Request) {
	// 获取用户名密码
	username := r.PostFormValue("username")
	password := r.PostFormValue("password")
	//调用userdao中验证用户名和密码的方法
	user, _ := dao.CheckUser(username, password)
	if user.ID > 0 {
		//用户名密码正确
		t := template.Must(template.ParseFiles("views/pages/user/login_success.html"))
		t.Execute(w, "")
	} else {
		t := template.Must(template.ParseFiles("views/pages/user/login.html"))
		t.Execute(w, "账户或密码错误")
	}
}

// Regist 处理用户注册函数
func Regist(w http.ResponseWriter, r *http.Request) {
	// 获取用户名密码邮箱
	username := r.PostFormValue("username")
	password := r.PostFormValue("password")
	email := r.PostFormValue("email")
	user, _ := dao.CheckUserName(username)
	if !user {
		dao.SaveUser(username, password, email)
		t := template.Must(template.ParseFiles("views/pages/user/regist_success.html"))
		t.Execute(w, "")
	} else {
		// 用户名存在
		t := template.Must(template.ParseFiles("views/pages/user/regist.html"))
		// t.Execute(w, "用户名已存在")
		t.Execute(w, "")
	}
}

// CheckUserName 检查用户名是否可以使用
func CheckUserName(w http.ResponseWriter, r *http.Request) {
	// 获取 username
	username := r.PostFormValue("username")
	fmt.Println(username)
	user, _ := dao.CheckUserName(username)
	fmt.Println(user)
	if !user {
		w.Write([]byte("用户名可用"))
	} else {
		w.Write([]byte("用户名已经存在"))
	}
}
