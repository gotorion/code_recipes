fn test_char() {
    let first_name = '李';
    println!("first name = {}", first_name);
    println!("memmory size of first name = {}", std::mem::size_of_val(&first_name));
}

fn test_bool() {
    let a = true;
    let b : bool = false;
    println!("a = {} and b = {}", a , b);
}

fn test_return(a: i32, b: i32) -> i32 {
    a + b
    // equals return a + b;
}

fn test_diverge_func() -> ! {
    loop {
        println!("this is in loop");
    }
}

fn main() {
    // test_char();
    // test_bool();
    let sum = test_return(10, 20);
    println!("sum = {}", sum);
    test_diverge_func();
}
