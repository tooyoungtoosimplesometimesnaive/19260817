
fn dfs(a: &[i32]) -> i32 {
    if a.len() <= 1 {
        a[0]
    } else {
        dfs(&a[0..1]) + dfs(&a[1..])
    }
}

fn main() {

    let number = [1,2,3,4];

    println!("the number is {}", dfs(&number[..]));

}
