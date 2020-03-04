package dao

import (
	"fmt"
	"shopping/model"
	"strconv"
	"testing"
)

func TestBookDao(t *testing.T) {
	fmt.Println("开始测试BookDao")
	// pass
	//t.Run("测试查找全部图书:", testGetAllBooks)
	//t.Run("测试通过ID查找图书:", testGetBookByID)
	//t.Run("测试模糊查找图书:", testGetBookByVague)
	//t.Run("测试插入图书:", testInsertBook)
	//t.Run("测试修改图书:", testUpdateBook)
	//t.Run("测试删除图书:", testDeleteBook)
}

// 测试查找全部图书
func testGetAllBooks(t *testing.T) {
	books := GetAllBooks()
	for _, b := range books {
		fmt.Println(b)
	}
}

// 测试通过 ID 查找图书
func testGetBookByID(t *testing.T) {
	id, _ := strconv.ParseInt("1", 10, 0)
	book := GetBookByID(id)
	fmt.Println(book)
}

// 测试模糊搜索
func testGetBookByVague(t *testing.T) {
	str := "测试"
	// 图书存在
	books, sum := GetBookByVague(str)
	if sum <= 0 {
		fmt.Printf("未查询到")
	}
	for _, b := range books {
		fmt.Println(b)
	}
}

// 插入图书
func testInsertBook(t *testing.T) {
	// 分支测试 1
	fmt.Println("分支测试1: ")
	book := &model.Book{
		Title:  "测试数目",
		Author: "测试作者",
		Price:  65.5,
		Sales:  160,
		Stock:  30,
	}
	result := InsertBook(book)
	if result {
		fmt.Println("插入成功，分支1 pass")
	}
	fmt.Println("分支测试2: ")
	book.Title = "测试数目1"
	result = InsertBook(book)
	if result {
		fmt.Println("插入成功， 分支2 pass")
	}
}

// 更新图书
func testUpdateBook(t *testing.T) {
	book := &model.Book{
		ID:     10,
		Title:  "测试数目up",
		Author: "测试作者up",
		Price:  62.5,
		Sales:  100,
		Stock:  100,
	}
	result := UpdateBook(book)
	if result {
		fmt.Println("修改成功！")
	} else {
		fmt.Println("修改失败！")
	}
}

// 删除图书
func testDeleteBook(t *testing.T) {
	result := DeleteBookByID("11")
	if result {
		fmt.Println("分支1: 测试成功")
	} else {
		fmt.Println("分支1: 测试失败")
	}
	result = DeleteBookByID("1000")
	if !result {
		fmt.Println("分支2: 测试成功")
	} else {
		fmt.Println("分支2: 测试失败")
	}
}
