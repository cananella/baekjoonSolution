use std::io::{stdin,stdout, Write, BufWriter};
use std::collections::VecDeque;

fn main(){
    let mut input=String::new();
    stdin().read_line(&mut input).unwrap();
    let n:usize=input.trim().parse().expect("parse fail");

    let stdout = stdout();
    let mut out = BufWriter::new(stdout.lock());

    let mut graph: Vec<Vec<usize>>= vec![Vec::new(); 100_001];
    let mut parent=vec! [0;100_001];
    let mut visited=vec! [false;100_001];

    for _ in 0..n-1{
        let mut input=String::new();
        stdin().read_line(&mut input).unwrap();
        let mut inp =input.split_ascii_whitespace()
                            .map(str::parse).flatten();
        let a: usize =inp.next().unwrap();
        let b: usize =inp.next().unwrap();
        graph[a].push(b);
        graph[b].push(a);
    }
    visited[1]=true;

    let mut q =VecDeque::new();
    q.push_back(1);

    while !q.is_empty(){
        let node:usize;
        if let Some(data) = q.front(){
            node = *data;
        }else{continue;}
        for i in &graph[node]{
            if visited[*i] {continue;}
            parent[*i]=node;
            visited[*i]=true;
            q.push_back(*i);
        }
        q.pop_front();
        // println!("{:?}",q);
    }

    for i in 2..=n{
        writeln!(out,"{}",parent[i]).unwrap();
    }
}