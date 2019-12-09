package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	fmt.Println("flow control")
	fmt.Print("please input:")
	input := bufio.NewScanner(os.Stdin)
	input.Scan()
	fmt.Println("output:", input.Text())
	output := 2
	switch output {
	case 1:
		fmt.Println("output 1")
		break
	case 2:
		fmt.Println("output 2")
		break
	default:
		fmt.Println("output nil")
		break
	}
	switch result := calculate(1); {
	case result > 0:
		fmt.Println("output > 0")
		// enforce next
		fallthrough
	case result < 0:
		fmt.Println("output < 0")
		break
	default:
		break
	}

}

func calculate(x int) int {
	if x > 0 {
		return 1
	}
	return -1
}
