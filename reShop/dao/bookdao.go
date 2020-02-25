package dao

import (
	"shopping/model"
	"shopping/utils"
)

// GetAllBooks 获取所有图书
func GetAllBooks() ([]*model.Book, error) {
	sqlStr := "select id,title,author,price,sales,stock,img_path from books"
	rows, err := utils.Db.Query(sqlStr)
	utils.ErrorHandle(err)
	var books []*model.Book
	// 循环查询到的数据
	for rows.Next() {
		book := &model.Book{}
		rows.Scan(&book.ID, &book.Title, &book.Author, &book.Price, &book.Sales, &book.Stock, &book.ImgPath)
		books = append(books, book)
	}
	return books, nil
}

// GetBookByID 通过 ID 获取书本信息
func GetBookByID(i int64) (*model.Book, error) {
	sqlStr := "select id,title,author,price,sales,stock,img_path from books where id = ?"
	row := utils.Db.QueryRow(sqlStr, i)
	book := &model.Book{}
	err := row.Scan(&book.ID, &book.Title, &book.Author, &book.Price, &book.Sales, &book.Stock, &book.ImgPath)
	utils.ErrorHandle(err)
	return book, nil
}
