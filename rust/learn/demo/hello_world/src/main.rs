fn greet_world() {
    let southern_germany = "Grüß Gott!";
    let chinese = "世界，你好";
    let english = "World, hello";
    let regions = [southern_germany, chinese, english];
    for region in regions.iter() {
        println!("{}", &region);
    }
}

fn len_and_count() -> () {
    let slice = "hello";
    println!("byte of slice = {} and length of slice = {}", slice.len(), slice.chars().count());
    let slice_1 = "你好";
    println!("byte of slice_1 = {} and length of slice_1 = {}", slice_1.len(), slice_1.chars().count());
}

fn main() {
    // greet_world();
    len_and_count();
}
