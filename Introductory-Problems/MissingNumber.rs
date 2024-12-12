fn main() {
    use std::io::stdin;
 
    let mut s = String::new();
    let mut s2 = String::new();
    
    stdin().read_line(&mut s).expect("Hey, wrong input");
    let n: i32 = s.trim().parse().expect("nah");
    stdin().read_line(&mut s2).expect("Hey, wrong input again");
 
    let vector: Vec<i32> = s2.split_whitespace().map(|x| x.parse::<i32>().expect("nah")).collect();
 
    let mut used: Vec<i32> = Vec::new();
    used.resize(n as usize, -1);
 
 
    for num in vector {
        used[(num as usize) - 1] = 1;
    }
 
    for i in 0..used.len() {
        if used[i] == -1 {
            println!("{}", i+1);
            return;
        }
    }
}