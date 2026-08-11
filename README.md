# rust-benchmark

C benchmark program showcasing (fully optimized) C performance compared to idiomatic Rust.

This was actually an exercise for me in compiling a Rust library (_librustsum.a_) and linking it into the `rust-benchmark` C program with GCC.

This exercise had mixed results.

- 100 million elements into an array, C beat Rust.
```bash
Allocating array of 100000000 elements...
Running benchmarks...  

[C Version]    Result: 100000000 | Time: 0.028705 seconds
[Rust Version] Result: 100000000 | Time: 0.029139 seconds

Difference: Rust was 1.51% slower than C.
```

- 1 billion elements, Rust beat C.
```bash
Allocating array of 100000000 elements...
Running benchmarks...  

[C Version]    Result: 100000000 | Time: 0.030418 seconds
[Rust Version] Result: 100000000 | Time: 0.029858 seconds

Difference: Rust was 1.87% faster than C.
```

![WUT!?](https://media0.giphy.com/media/v1.Y2lkPTc5MGI3NjExaDdid2pnZndrMGdxZHNydXk3amdscmEyYjRxZGRvN2tmbmNsYXJqZyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/YVPwi7L2izTJS/giphy.gif)

These results were also quite inconsistant.
