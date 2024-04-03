use std::io::stdin;

fn main(){
    let mut max = 0;
    let mut cnt_ans=0;
    for i in 0..9{
        let mut input= String::new();
        stdin().read_line(&mut input).unwrap();
        let num: usize = input.trim().parse().expect("parse fail");
        if max<num{
            max=num;
            cnt_ans=i+1;
        }
    }
    println!("{max}");
    println!("{cnt_ans}");
}