package main

import (
	"crypto/md5"
	"fmt"
	"html/template"
	"io"
	"log"
	"net/http"
	"os"
	"regexp"
	"strconv"
	"strings"
	"time"
)

func sayHelloName(w http.ResponseWriter, r *http.Request) {
	r.ParseForm() //解析url传递的参数，对于post 解析 request body
	//if no `r.ParseForm()` no beneath content
	fmt.Println(r.Form)
	fmt.Println("path", r.URL.Path)
	fmt.Println("scheme", r.URL.Scheme)
	fmt.Println(r.Form["url_long"])
	for k, v := range r.Form {
		fmt.Println("key:", k)
		fmt.Println("val:", strings.Join(v, ""))
	}
	fmt.Fprintln(w, "Hello BBN!")
}

func login(w http.ResponseWriter, r *http.Request) {
	fmt.Println("method:", r.Method) //获取请求方法
	if r.Method == "GET" {
		t, _ := template.ParseFiles("04.form.gtpl")
		log.Println(t.Execute(w, nil))
	} else {
		// 请求登陆数据 执行登陆逻辑判
		r.ParseForm()
		// 表单服务器端验证
		// 禁止为空
		if len(r.Form["username"][0]) == 0 {
			// do something ...
		}
		// 数值判断 way 1
		getInt, err := strconv.Atoi(r.Form.Get("age"))
		if err != nil {
			// error
			// do something ...
		}
		if getInt > 100 {
			// do something ...
		}
		// way 2 regexp
		/*
			if m, _ := regexp.MatchString("^[0-9]+$", r.Form.Get("age")); !m {
				return false
			}
		*/
		// 中文
		if m, _ := regexp.MatchString("^\\p{Han}+$", r.Form.Get("username")); !m {
			// chinese
		}
		// English
		if m, _ := regexp.MatchString("^[a-zA-Z]+$", r.Form.Get("username")); !m {
			// english
		}
		// select mode
		slice := []string{"apple", "pear", "banana"}
		v := r.Form.Get("fruit")
		for _, item := range slice {
			if item == v {
				//find one
			}
		}
		// 更多配制
		// https://github.com/astaxie/build-web-application-with-golang/blob/master/zh/04.2.md

		fmt.Println("username:", r.Form["username"])
		fmt.Println("password:", r.Form["password"])
		// go 对输入的字符进行转意
		template.HTMLEscape(w, []byte(r.Form.Get("username"))) //输出到客户端
	}
}

func upload(w http.ResponseWriter, r *http.Request) {
	fmt.Println("method:", r.Method)
	if r.Method == "GET" {
		crutime := time.Now().Unix()
		h := md5.New()
		io.WriteString(h, strconv.FormatInt(crutime, 10))
		token := fmt.Sprintf("%x", h.Sum(nil))
		t, _ := template.ParseFiles("04.upload.gtpl")
		t.Execute(w, token)
	} else {
		r.ParseMultipartForm(32 << 20)
		file, handler, err := r.FormFile("uploadfile")
		if err != nil {
			fmt.Println(err)
			return
		}
		defer file.Close()
		fmt.Fprintf(w, "%v", handler.Header)
		f, err := os.OpenFile("./test/"+handler.Filename, os.O_WRONLY|os.O_CREATE, 0666)
		if err != nil {
			fmt.Println(err)
			return
		}
		defer f.Close()
		io.Copy(f, file)
	}
}

func main() {
	fmt.Println("from test")
	http.HandleFunc("/", sayHelloName)
	http.HandleFunc("/login", login)
	http.HandleFunc("/upload", upload)
	err := http.ListenAndServe(":6060", nil)
	if err != nil {
		log.Fatal("ListenAndServe:", err)
	}

}
