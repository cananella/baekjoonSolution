use std::io::{stdin};

const N_MAXIMUM: usize = 1001;
const MODULAR: usize = 10007;

fn main(){
    let mut input =String::new();
    stdin().read_line(&mut input).unwrap();
    let num:usize= input.trim().parse().expect("Invalid input");
    let mut dp: [usize ; N_MAXIMUM] = [0;N_MAXIMUM];
    dp[1]=1;
    dp[2]=2;
    if num>2{
        for i in 3..=num{
            dp[i]=(dp[i-1]+dp[i-2]) % MODULAR;
        }
    }
    let ans =dp[num];
    println!("{}",ans);
}