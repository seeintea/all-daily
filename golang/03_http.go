package main

import (
	"fmt"
	"log"
	"net/http"
	"strings"
)

func sayHelloName(w http.ResponseWriter, r *http.Request) {
	//解析参数 - 默认不解析
	r.ParseForm()
	//info print console
	fmt.Println(r.Form)
	fmt.Println("path", r.URL.Path)
	fmt.Println("scheme", r.URL.Scheme)
	fmt.Println(r.Form["url_long"])
	for k, v := range r.Form {
		fmt.Println("key:", k)
		fmt.Println("val", strings.Join(v, ""))
	}
	fmt.Fprintf(w, "Hello GLW.BBN")
}

// web service
func main() {
	//set router
	http.HandleFunc("/", sayHelloName)
	//set listing
	err := http.ListenAndServe(":9090", nil)
	if err != nil {
		log.Fatal("ListenAndServe:", err)
	}

}
