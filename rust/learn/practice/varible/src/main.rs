fn main() {
    // test_for_loop();
    // test_float();
    test_as();
}

fn test_for_loop() {
    for i in 1..=10 {
        print!("{} ", i);
    }
    println!();
}

fn test_float() {
    let num : f32 = 99.9234234;
    println!("{:1.2}", num);
}

fn test_as() {
    let num : f32 = 99.99;
    let mut yes_or_no : bool = false;
    println!("{}", num as i32 as i8 != 0);
}
