package main

import (
	"fmt"
)

func main() {
	fmt.Println("slice & map learn")

	// slice 可以理解为无大小的数组
	// 其是 对底层数组的一个连续片段的引用
	// 其不占用内存 且 效率比数组高
	arr := [6]int{1, 2, 3, 4, 5, 6}
	//define array
	//	vsr arr = new([5]int)
	//	var arr = [5]int{18, 20, 15, 22, 16}
	//	var arr [5]int
	var sliceArr = arr[2:6]
	//define slice
	//	var sliceArr = [6]int{1,2,3,4,5,6}
	//	var sliceArr = make([]int,10,50)
	fmt.Println(arr, sliceArr)
	fmt.Println(len(sliceArr), cap(sliceArr))
	//切片重组
	sliceArr = make([]int, 3, 10)
	fmt.Println(sliceArr, len(sliceArr), cap(sliceArr))
	sliceArr = arr[2:5]
	fmt.Println(sliceArr, len(sliceArr), cap(sliceArr))
	//切片复制
	sliceCopy := make([]int, 5)
	copy(sliceCopy, sliceArr[:2])
	fmt.Println(sliceCopy, len(sliceCopy), cap(sliceCopy))
	// append() 函数
	sliceArr = append(sliceCopy, 10)
	fmt.Println(sliceArr, len(sliceArr), cap(sliceArr))

}
