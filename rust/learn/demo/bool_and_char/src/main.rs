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

fn main() {
    // test_char();
    test_bool();
}
