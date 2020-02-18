package controller

import (
	"net/http"
	"shopping/dao"
	"text/template"
)

// GetBooks 获取所有图书信息
func GetBooks(w http.ResponseWriter, r *http.Request) {
	books, _ := dao.GetBooks()
	t := template.Must(template.ParseFiles("views/pages/manager/book_manager.html"))
	t.Execute(w, books)
}
