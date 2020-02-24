package controller

import (
	"html/template"
	"net/http"
)

// HTTPHandle HTTP处理器合集
func HTTPHandle() {
	// 静态资源处理
	httpStaticMap()
	// 首页处理器
	http.HandleFunc("/", initIndex)
	// User 处理器
	userHandle()
	// Manager 处理器

	// Order 处理器

	// Cart 处理器
}

// HTTPServe 开启HTTP服务
func HTTPServe() {
	http.ListenAndServe(":8080", nil)
}

// 首页处理器
func initIndex(w http.ResponseWriter, r *http.Request) {
	// 解析模版
	t := template.Must(template.ParseFiles("views/index.html"))
	// 执行模版
	t.Execute(w, "")
}

// 静态资源处理
func httpStaticMap() {
	http.Handle("/static/", http.StripPrefix("/static/", http.FileServer(http.Dir("views/static"))))
	http.Handle("/pages/", http.StripPrefix("/pages/", http.FileServer(http.Dir("views/pages"))))
}

// User处理器
func userHandle() {
	http.HandleFunc("/login", ShoppingLogin)
}
