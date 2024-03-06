package main

import (
	"fmt"
	"unsafe"
)

func main() {
	var ch byte = ')'
	fmt.Println(ch)
	fmt.Println(unsafe.Sizeof(ch))

	char := '%'
	fmt.Println(char)
	fmt.Println(unsafe.Sizeof(char))

}
