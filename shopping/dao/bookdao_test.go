package dao

import (
	"fmt"
	"testing"
)

func TestMain(m *testing.M) {
	fmt.Println("开始测试BookDao中的函数:")
	m.Run()
}

func TestBook(t *testing.T) {
	t.Run("获取所有图书:", testGetBooks)
}

func testGetBooks(t *testing.T) {
	books, _ := GetBooks()
	for k, v := range books {
		fmt.Printf("第%v本图书信息是：%v\n", k+1, v)
	}
}
