package controller

import (
	"net/http"
	"shopping/dao"
	"text/template"
)

// GetAllBooks 查询所有图书
func GetAllBooks(w http.ResponseWriter, r *http.Request) {
	books := dao.GetAllBooks()
	t := template.Must(template.ParseFiles("views/pages/manager/book_manager.html"))
	t.Execute(w, books)
}

// BookChange  图书修改
func BookChange(w http.ResponseWriter, r *http.Request) {

}
