use num::complex::Complex;

fn test_complex_num() {
    let a = Complex {re: 2.1, im: -1.2};
    let b = Complex::new(11.1, 22.2);
    let result = a + b;
    println!("{} + {}i", result.re, result.im);
}

fn main() {

    let a : u8 = 255;
    let b = a.wrapping_add(20);
    // let c = a.overflowing_add(20);
    let (c, d) = a.overflowing_add(20);
    let e = a.checked_add(20);
    
    println!("b = {}", b);
    println!("c = {} and d = {}", c, d);
    // println!("e = {}", e); // error

    let x = (-40_f64).sqrt();

    if x.is_nan() {
        println!("Undefined behavior.");
    }
    // test_operator();
    // test_vector();
    // test_range();
    test_complex_num();
}

fn test_operator() {
    let num1 = 30;
    let num2 : i32 = 40;
    let num3 = 40_i32;
    let sum = num1 + num2 + num3;
    println!("{} + {} + {} = {}", num1, num2, num3, sum);
}

fn test_vector() {
    let vec = [
        40.0,
        40.33333f32,
        50.32_f32,
    ];
    println!("{:.2}", vec[1]);
}

fn test_range() {
    for i in 1..=5 {
        println!("{}", i);
    }

    for ch in 'a'..='z' {
        println!("{}", ch);
    }
}