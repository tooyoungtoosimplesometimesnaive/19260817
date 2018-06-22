
fn dfs(a: &[u8]) -> u8 {
    println!("hey {}", &a[0]);
    if a.len() <= 1 {
        a[0]
    } else {
        dfs(&a[0..1]) + dfs(&a[1..])
    }
}

fn main() {

    let number = "1234".as_bytes();
    println!("the length is {}", number.len());
    println!("the number is {}", dfs(number));

}
