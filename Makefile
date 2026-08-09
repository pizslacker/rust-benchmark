rust-benchmark: rust-benchmark.c
	rustc -O --crate-type staticlib sum_rust.rs -o librustsum.a
	gcc -O3 rust-benchmark.c librustsum.a -o rust-benchmark -lpthread -ldl
	strip rust-benchmark

clean:
	rm -f rust-benchmark librustsum.a