open System

let rec fact (x: float): float =
    match x with
    | 0.0 | 1.0 -> 1.0
    | _ -> x * fact (x-1.0)

let e_x (x: float) =
    Array.map (fun i -> Math.Pow(x, i) / (fact i)) [|0.0 .. 9.0|]
    |> Array.sum


[<EntryPoint>]
let main args =
    let n = Console.ReadLine() |> int

    for _ in 1 .. n do
        let x = Console.ReadLine() |> float |> e_x
        Console.WriteLine(x)
    
    0