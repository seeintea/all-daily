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

//ToUpdateBookPage 去更新图书页面
func ToUpdateBookPage(w http.ResponseWriter, r *http.Request) {
	bookID := r.FormValue("bookID")
	book, _ := dao.GetBookByID(bookID)
	t := template.Must(template.ParseFiles("views/pages/manager/book_modify.html"))
	t.Execute(w, book)
}

//UpdateBookByID 根据ID更新图书
func UpdateBookByID(w http.ResponseWriter, r *http.Request) {
	book := &model.Book{}
	id, _ := (strconv.ParseInt(r.PostFormValue("bookID"), 10, 0))
	book.Title = r.PostFormValue("title")
	book.Author = r.PostFormValue("author")
	book.Price, _ = strconv.ParseFloat(r.PostFormValue("price"), 64)
	sales, _ := (strconv.ParseInt(r.PostFormValue("sales"), 10, 0))
	stock, _ := strconv.ParseInt(r.PostFormValue("stock"), 10, 0)
	book.ID = int(id)
	book.Sales = int(sales)
	book.Stock = int(stock)
	err := dao.UpdateBook(book)
	if err != nil {
		panic(err.Error())
	}
	GetBooks(w, r)
}

//GetPageBooks 获取带分页的图书
func GetPageBooks(w http.ResponseWriter, r *http.Request) {
	// 获取页码
	pageNo := r.FormValue("pageNo")
	page, _ := dao.GetPageBooks(pageNo)
	t := template.Must(template.ParseFiles("views/pages/manager/book_manager.html"))
	t.Execute(w, page)
}
