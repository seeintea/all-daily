package controller

import (
	"net/http"
	"shopping/dao"
	"shopping/model"
	"strconv"
	"text/template"
)

// GetBooks 获取所有图书信息
func GetBooks(w http.ResponseWriter, r *http.Request) {
	books, _ := dao.GetBooks()
	t := template.Must(template.ParseFiles("views/pages/manager/book_manager.html"))
	t.Execute(w, books)
}

//AddBook 添加图书
func AddBook(w http.ResponseWriter, r *http.Request) {
	book := &model.Book{}
	book.Title = r.PostFormValue("title")
	book.Author = r.PostFormValue("author")
	book.Price, _ = strconv.ParseFloat(r.PostFormValue("price"), 64)
	sales, _ := (strconv.ParseInt(r.PostFormValue("sales"), 10, 0))
	stock, _ := strconv.ParseInt(r.PostFormValue("stock"), 10, 0)
	book.Sales = int(sales)
	book.Stock = int(stock)
	dao.AddNewBook(book)
	// 调用GetBooks函数
	GetBooks(w, r)
}

//DeleteBook 删除图书
func DeleteBook(w http.ResponseWriter, r *http.Request) {
	id := r.FormValue("bookID")
	dao.DeleteBook(id)
	GetBooks(w, r)
}
