package main

import (
	"fmt"
)

func main() {
	nums := []int{1,2,3,4,5};
	for x, v :=range nums {
		fmt.Println(x,":",v);
	}
	for _, v :=range nums {
		fmt.Println(v);
	}
}