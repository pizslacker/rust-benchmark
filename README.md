# rust-benchmark

C benchmark program showcasing (fully optimized) C performance compared to idiomatic Rust.

This was actually an exersize for me in compiling a Rust library (_librustsum.a_) and linking it into the `rust-benchmark` C program with GCC.

This exersize had mixed results. If I allocated 100 million elements into an array, C beat Rust, but if I added 1 billion elements, Rust beat C.
