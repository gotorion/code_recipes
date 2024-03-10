fn my_func() {
    let (a, mut b) : (bool, bool) = (true, false);
    println!("a = {:?} and b = {:?}", a, b);
    println!("a = {} and b = {}", a, b);
    b = true;
    assert_eq!(a, b);
}

fn main() {
    my_func();

    let num = 6;
    println!("{}", num);
    // num = 7; // error! You can not change value of immutable varible
    println!("{}", num);

    let mut name = "John"; // use mut keyword
    println!("{}", name);
    name = "Bob";
    println!("{}", name);

    // use _ to say a varible may not be used
    let my_var = 10; // this will be warn
    let _your_var = 20; // this will not be warn

    let x = 5;
    let x = x + 1;
    println!("outside x = {}", x);
    {
        let x = x * 2;
        println!("inside x = {}", x);
    }
    println!("outside x = {}", x);
    
    let space = "   ";
    let space = space.len();
    println!("length of space = {}", space);
}
