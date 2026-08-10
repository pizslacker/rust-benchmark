# rust-benchmark

C benchmark program showcasing (fully optimized) C performance compared to idiomatic Rust.

This was actually an exercise for me in compiling a Rust library (_librustsum.a_) and linking it into the `rust-benchmark` C program with GCC.

This exercise had mixed results.

- 100 million elements into an array, C beat Rust.
- 1 billion elements, Rust beat C.

![WUT!?](https://media0.giphy.com/media/v1.Y2lkPTc5MGI3NjExaDdid2pnZndrMGdxZHNydXk3amdscmEyYjRxZGRvN2tmbmNsYXJqZyZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/YVPwi7L2izTJS/giphy.gif)
