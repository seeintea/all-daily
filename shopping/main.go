package main

import (
	"html/template"
	"net/http"
	"shopping/controller"
)

// indexHandler 首页处理器
func indexHandler(w http.ResponseWriter, r *http.Request) {
	// 解析模版
	t := template.Must(template.ParseFiles("views/index.html"))
	// 执行
	t.Execute(w, "")
}

func main() {
	// 设置处理静态资源
	http.Handle("/static/", http.StripPrefix("/static/", http.FileServer(http.Dir("views/static"))))
	http.Handle("/pages/", http.StripPrefix("/pages/", http.FileServer(http.Dir("views/pages"))))
	http.HandleFunc("/", indexHandler)
	// 登陆
	http.HandleFunc("/login", controller.Login)
	// 注册
	http.HandleFunc("/regist", controller.Regist)
	// 通过 ajax 请求检测用户名是否可以使用
	http.HandleFunc("/checkUserName", controller.CheckUserName)
	// 获取所有图书
	http.HandleFunc("/getBooks", controller.GetBooks)
	// 新增图书
	http.HandleFunc("/addBook", controller.AddBook)
	// 删除图书
	http.HandleFunc("/deleteBook", controller.DeleteBook)
	// 更新分页
	http.HandleFunc("/toUpdateBookPage", controller.ToUpdateBookPage)
	// 更新图书
	http.HandleFunc("/updateBook", controller.UpdateBookByID)
	// 分页获取
	http.HandleFunc("/getPageBooks", controller.GetPageBooks)
	// 可修改可新增
	http.HandleFunc("/bookModify", controller.BookModidy)
	//测试
	http.HandleFunc("/setTest", controller.SetCookieDome)
	http.HandleFunc("/gettTest", controller.GetCookieDome)

	http.ListenAndServe(":8080", nil)
}
