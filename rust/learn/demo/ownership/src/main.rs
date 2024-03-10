fn test_string() -> () {
    let mut name = String::from("Hello");
    name.push_str(", world!");
    println!("name is {}", name);
}

fn take_ownership(some_string : String) -> () {
    println!("{}", some_string);
}

fn make_copy(num : i32) -> () {
    println!("{}", num);
}

fn main() {
    // test_string();
    let word : String = String::from("Hello world");

    take_ownership(word.clone());
    // how about continue use word
    println!("word = {}", word); // this will be not be an error

    take_ownership(word);
    // how about continue use word
    // println!("word = {}", word); // this will be an error

    let num : i32 = 10;
    make_copy(num);
}
