package dao

import (
	"fmt"
	"shopping/model"
	"testing"
)

func TestMain(m *testing.M) {
	fmt.Println("开始测试BookDao中的函数:")
	m.Run()
}

func TestBook(t *testing.T) {
	//t.Run("获取所有图书:", testGetBooks)
	t.Run("测试添加图书", testAddBook)
	t.Run("测试删除图书", testDeleteBook)
}

func testGetBooks(t *testing.T) {
	books, _ := GetBooks()
	for k, v := range books {
		fmt.Printf("第%v本图书信息是：%v\n", k+1, v)
	}
}

func testAddBook(t *testing.T) {
	book := &model.Book{
		Title:   "测试书本",
		Author:  "测试作者",
		Price:   30.2,
		Sales:   32,
		Stock:   100,
		ImgPath: "/static/img/default.jpg",
	}
	err := AddNewBook(book)
	if err != nil {
		panic(err.Error())
	}
}

func testDeleteBook(t *testing.T) {
	err := DeleteBook("6")
	if err != nil {
		panic(err.Error())
	}
}
