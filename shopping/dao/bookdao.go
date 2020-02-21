package dao

import (
	"shopping/model"
	"shopping/utils"
	"strconv"
)

//GetBooks 获取数据库中所有图书
func GetBooks() ([]*model.Book, error) {
	sqlStr := "select id,title,author,price,sales,stock,img_path from books"
	rows, err := utils.Db.Query(sqlStr)
	if err != nil {
		return nil, err
	}
	var books []*model.Book
	for rows.Next() {
		book := &model.Book{}
		rows.Scan(&book.ID, &book.Title, &book.Author, &book.Price, &book.Sales, &book.Stock, &book.ImgPath)
		books = append(books, book)
	}
	return books, nil
}

//AddNewBook 添加新的图书
func AddNewBook(b *model.Book) error {
	sqlStr := "insert into books(title,author,price,sales,stock,img_path) values(?,?,?,?,?,?)"
	_, err := utils.Db.Exec(sqlStr, b.Title, b.Author, b.Price, b.Sales, b.Stock, b.ImgPath)
	if err != nil {
		return err
	}
	return nil
}

//DeleteBook 删除图书
func DeleteBook(bookID string) error {
	sqlStr := "delete from books where id = ?"
	_, err := utils.Db.Exec(sqlStr, bookID)
	if err != nil {
		return err
	}
	return nil
}

//GetBookByID 根据ID获取图书信息
func GetBookByID(bookID string) (*model.Book, error) {
	sqlStr := "select id,title,author,price,sales,stock,img_path from books where id = ?"
	row := utils.Db.QueryRow(sqlStr, bookID)
	book := &model.Book{}
	row.Scan(&book.ID, &book.Title, &book.Author, &book.Price, &book.Sales, &book.Stock, &book.ImgPath)
	return book, nil
}

//UpdateBook 更新图书
func UpdateBook(book *model.Book) error {
	sqlStr := "update books set title=?,author=?,price=?,sales=?,stock=? where id =?"
	_, err := utils.Db.Exec(sqlStr, book.Title, book.Author, book.Price, book.Sales, book.Stock, book.ID)
	if err != nil {
		return err
	}
	return nil
}

//GetPageBooks 带分页的图书信息
func GetPageBooks(pageNo string) (*model.Page, error) {
	iPageNo, _ := strconv.ParseInt(pageNo, 10, 64)
	// 获取数据库中的总数
	sqlStr := "select count(*) from books"
	var totalRecord int64
	row := utils.Db.QueryRow(sqlStr)
	row.Scan(&totalRecord)
	var pageSize int64 = 4
	var totalPageNo int64
	if totalRecord%pageSize == 0 {
		totalPageNo = totalRecord / pageSize
	} else {
		totalPageNo = totalRecord/pageSize + 1
	}
	//获取当前页图书
	sqlStr2 := "select id,title,author,price,sales,stock,img_path from books limit ?,?"
	rows, err := utils.Db.Query(sqlStr2, (iPageNo-1)*pageSize, pageSize)
	if err != nil {
		return nil, err
	}
	var books []*model.Book
	for rows.Next() {
		book := &model.Book{}
		rows.Scan(&book.ID, &book.Title, &book.Author, &book.Price, &book.Sales, &book.Stock, &book.ImgPath)
		books = append(books, book)
	}
	page := &model.Page{
		Books:       books,
		PageNo:      iPageNo,
		PageSize:    pageSize,
		TotalPageNo: totalPageNo,
		TotalRecord: totalRecord,
	}
	return page, nil
}
