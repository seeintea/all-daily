package main

import (
	"net/http"
	"text/template"
)

func templateHandler(w http.ResponseWriter, r *http.Request) {
	// 解析模版
	// t, _ := template.ParseFiles("07.go-web.html")
	// 执行模版
	// t.Execute(w, "hello world !")
	// 通过 Must 函数自动处理异常
	t := template.Must(template.ParseFiles("07.go-web.html", "03.go-web.html"))
	t.ExecuteTemplate(w, "07.go-web.html", "测试信息")

}

func main() {
	http.HandleFunc("/template", templateHandler)
	http.ListenAndServe(":8084", nil)
}
