use std::thread;
use std::time::Duration;

#[derive(Debug, PartialEq, Copy, Clone)]
enum ShirtColor {
    Red,
    Blue,
}

struct Inventory {
    shirts: Vec<ShirtColor>,
}

impl Inventory {
    fn giveaway(&self, user_preference: Option<ShirtColor>) -> ShirtColor {
        user_preference.unwrap_or_else(|| self.most_stocked())
    }

    fn most_stocked(&self) -> ShirtColor {
        let mut num_red = 0;
        let mut num_blue = 0;
        for color in &self.shirts {
            match color {
                ShirtColor::Red => num_red += 1,
                ShirtColor::Blue => num_blue += 1,
            }
        }
        if num_red > num_blue {
            ShirtColor::Red
        } else {
            ShirtColor::Blue
        }
    }
}

fn test_shirt() {
    let store = Inventory {
        shirts: vec![ShirtColor::Blue, ShirtColor::Red, ShirtColor::Red],
    };
    let user_pref = Some(ShirtColor::Red);
    let give = store.giveaway(user_pref);
    println!("The user with pref {:?} gets {:?}", user_pref, give);
}

fn test_auto_deduct() {
    let expensive_closure = |num| {
        println!("calculating slowly...");
        thread::sleep(Duration::from_secs(2));
        num
    };
    println!("{}", expensive_closure(2));
}

fn test_capture() {
    // only borrow
    let list = vec![1, 2, 3];
    println!("Before defining closure: {list:?}");

    let only_borrows = || println!("From closure: {list:?}");
    println!("Before calling closure: {list:?}");
    only_borrows();
    println!("After calling closure: {list:?}");
    // borrow mut
    let mut list = vec![1, 2, 3];
    println!("Before defining closure: {list:?}");

    let mut borrow_mutably = || list.push(7);
    //     println!("After calling closure: {list:?}"); // error, has mut ref
    borrow_mutably();
    println!("After calling closure: {list:?}");
    // move
    thread::spawn(move || println!("From thread: {list:?}"))
        .join()
        .unwrap();
    //    list; // error
}

fn main() {
    test_shirt();
    test_auto_deduct();
    test_capture();
}
