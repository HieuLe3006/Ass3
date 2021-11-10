LL = top.ll relu.ll 

# .PHONY clean build

%.o : %.c
	clang -emit-llvm -c -o $@ $<
%.bc : %.o
	opt -O1 -inline -mem2reg -simplifycfg -loops -loop-unroll -o $@ $<
%.ll : %.bc
	llvm-dis -o $@ $<
build: $(LL)
	mkdir -p ../ir/
	mv $^ ../ir/
clean:
	rm -f ../ir/*.ll