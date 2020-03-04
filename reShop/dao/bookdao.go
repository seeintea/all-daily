package dao

import (
	"shopping/model"
	"shopping/utils"
	"strconv"
)

// GetAllBooks 获取所有图书
func GetAllBooks() []*model.Book {
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
	return books
}

// GetBookByID 通过 ID 获取书本信息
func GetBookByID(i int64) *model.Book {
	sqlStr := "select id,title,author,price,sales,stock,img_path from books where id = ?"
	row := utils.Db.QueryRow(sqlStr, i)
	book := &model.Book{}
	err := row.Scan(&book.ID, &book.Title, &book.Author, &book.Price, &book.Sales, &book.Stock, &book.ImgPath)
	utils.ErrorHandle(err)
	return book
}

// GetBookByVague 模糊搜索 int 表示查询到的个数
func GetBookByVague(str string) ([]*model.Book, int) {
	sqlStr := "select id,title,author,price,sales,stock,img_path from books where title like ?"
	// 模糊查找拼接
	str = "%" + str + "%"
	rows, err := utils.Db.Query(sqlStr, str)
	utils.ErrorHandle(err)
	var books []*model.Book
	// 设置标志位
	for rows.Next() {
		book := &model.Book{}
		rows.Scan(&book.ID, &book.Title, &book.Author, &book.Price, &book.Sales, &book.Stock, &book.ImgPath)
		books = append(books, book)
	}
	return books, len(books)
}

// InsertBook 插入图书 true-插入/修改成功
func InsertBook(b *model.Book) bool {
	// 检测是否已存在
	str, result := getBookByName(b.Title)
	id, _ := strconv.ParseInt(str, 10, 0)
	if result {
		// 执行修改操作
		// 正式以 INS 为表示，默认价格修改为最新，库存、销量叠加
		book := GetBookByID(id)
		b.Sales += book.Sales
		b.Stock += book.Stock
		sqlStr := "update books set price = ?, sales = ?, stock = ? where id = ?"
		r, err := utils.Db.Exec(sqlStr, &b.Price, &b.Sales, &b.Stock, &id)
		state := utils.SQLAffected(r, err)
		if state > 0 {
			return true
		}
		return false
	}
	sqlStr := "insert into books(title, author, price, sales, stock, img_path) values (?,?,?,?,?,?)"
	// 插入图书
	r, err := utils.Db.Exec(sqlStr, &b.Title, &b.Author, &b.Price, &b.Sales, &b.Stock, &b.ImgPath)
	// 查找确定是否插入成功
	state := utils.SQLAffected(r, err)
	if state > 0 {
		return true
	}
	return false
}

// UpdateBook 更新图书 true-更新成功
func UpdateBook(b *model.Book) bool {
	// 暂时不考虑对 img_path 的更新
	sqlStr := "update books set title = ?, author = ?, price = ?, sales = ?, stock = ? where id = ?"
	result, err := utils.Db.Exec(sqlStr, &b.Title, &b.Author, &b.Price, &b.Sales, &b.Stock, &b.ID)
	state := utils.SQLAffected(result, err)
	if state > 0 {
		return true
	}
	return false
}

// DeleteBookByID 删除图书 true-删除成功
func DeleteBookByID(str string) bool {
	sqlStr := "delete from books where id = ?"
	result, err := utils.Db.Exec(sqlStr, str)
	state := utils.SQLAffected(result, err)
	if state > 0 {
		return true
	}
	return false
}

// getBookByName 根据书名查找图书 true-找到
func getBookByName(str string) (string, bool) {
	sqlStr := "select id from books where title = ?"
	row := utils.Db.QueryRow(sqlStr, str)
	id := -1
	err := row.Scan(&id)
	utils.ErrorHandle(err)
	if id > 0 {
		return strconv.Itoa(id), true
	}
	return strconv.Itoa(-1), false
}
