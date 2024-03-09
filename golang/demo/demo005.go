package main
import (
	"fmt"
)

func myfunc() {
	fmt.Println("This is in myfunc.")
}

func main() {
	var test_string string = "Hello world"
	fmt.Println(test_string)
	myfunc()
	// test_string[2] = 'a' // error, string can not be changed
	// var anothre_string = "sfs\ijs" // error, can not use "" when special char exist
	var another_string = `sgs\jgas` // not error, use `` instead
	fmt.Println(another_string)
	another_string += "add more string"
	fmt.Println(another_string)
}