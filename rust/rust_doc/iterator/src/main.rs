fn test_iter() {
    let vec = vec![1, 2, 3];
    let iter = vec.iter();
    for val in iter {
        println!("Got: {val}");
    }
}

fn test_iter_sum() {
    // consuming adaptors
    let vec = vec![1, 2, 3];
    let iter = vec.iter();
    let total: i32 = iter.sum();
    assert_eq!(total, 6);
}

fn test_iterator_adaptors() {
    let vec = vec![1, 2, 3];
    let v: Vec<_> = vec.iter().map(|x| x + 1).collect();
    for elem in v.iter() {
        println!("{elem}");
    }
}

#[derive(PartialEq, Debug)]
struct Shoe {
    size: u32,
    style: String,
}

fn shoes_in_size(shoes: Vec<Shoe>, shoe_size: u32) -> Vec<Shoe> {
    shoes.into_iter().filter(|s| s.size == shoe_size).collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn filters_by_size() {
        let shoes = vec![
            Shoe {
                size: 10,
                style: String::from("sneaker"),
            },
            Shoe {
                size: 13,
                style: String::from("sandal"),
            },
            Shoe {
                size: 10,
                style: String::from("boot"),
            },
        ];

        let in_my_size = shoes_in_size(shoes, 10);

        assert_eq!(
            in_my_size,
            vec![
                Shoe {
                    size: 10,
                    style: String::from("sneaker")
                },
                Shoe {
                    size: 10,
                    style: String::from("boot")
                },
            ]
        );
    }
}

fn main() {
    test_iter();
    test_iter_sum();
    test_iterator_adaptors();
}
