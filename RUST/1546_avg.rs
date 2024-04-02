use std::io;

fn main(){
    let mut num =String::new();
    io::stdin().read_line(&mut num).expect("Failed to read input");
    let num:i32 = num.trim().parse().expect("Invalid input");

    
    let mut input =String::new();
    io::stdin().read_line(&mut input).expect("Failed to read input");
    let input:Vec<i32> = input.split_whitespace()
                        .map(|s| s.trim().parse().expect(" parsing error"))
                        .collect::<Vec<_>>();
    
    let mut ans=0.0;
    let max_value = *input.iter().max().unwrap();

    for i in input.iter(){
        ans += *i as f64/max_value as f64 *100.0;
    }
    let ans:f64 = ans/num as f64;

    println!("{}",ans);
   
}
