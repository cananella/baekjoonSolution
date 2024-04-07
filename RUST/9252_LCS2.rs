use std::io::stdin;
use std::cmp;

fn main(){
    let mut input1=String::new();
    let mut input2=String::new();
    stdin().read_line(&mut input1).unwrap();
    stdin().read_line(&mut input2).unwrap();
    let letters_a: Vec<char> = input1.trim().chars().collect();
    let letters_b: Vec<char> = input2.trim().chars().collect();

    let mut dp=vec![[0;1001];1001];
    
    for i in 1..=letters_b.len(){
        for j in 1..=letters_a.len(){
            if letters_a[j-1]==letters_b[i-1]{
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else {
                dp[i][j]=cmp::max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    // for i in 1..=letters_b.len(){
    //     for j in 1..=letters_a.len(){
    //         print!("{} ",dp[i][j]);
    //     }
    //     println!("");
    // }
    let mut v =Vec::new();
    let ans=cmp::min(dp[letters_b.len()][letters_a.len()],cmp::min( letters_a.len() , letters_b.len() ));
    if ans==0{
        println!("0");
    }
    else{
        println!("{}",ans);
        let mut dy= letters_b.len();
        let mut dx= letters_a.len();
        while dx>=1&&dy>=1 {
            if dp[dy][dx]>dp[dy][dx-1] && dp[dy][dx]>dp[dy-1][dx] && dp[dy][dx]>dp[dy-1][dx-1]{
                v.push(letters_a[dx-1]);
                // print!("{}",letters_a[dx-1]);
                dy-=1;
                dx-=1;
            }
            else if dp[dy][dx]==dp[dy][dx-1] && dp[dy][dx]>dp[dy-1][dx]{
                dx -=1;
            }
            else if dp[dy][dx]>dp[dy][dx-1] && dp[dy][dx]==dp[dy-1][dx]{
                dy -=1;
            }
            else {dy -=1;}
        }
        v.reverse();
        for i in v{
            print!("{}",i);
        }
    }
}