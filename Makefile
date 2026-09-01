asm-cpu-vendor: asm-cpu-vendor.c
	gcc -O3 -o asm-cpu-vendor asm-cpu-vendor.c
	strip asm-cpu-vendor

clean:
	rm -f asm-cpu-vendor
