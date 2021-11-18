gxx=g++ 
src=$(shell find ./ -name "*.cpp")
gflags=-std=c++17
obj=$(src:%.cpp=%.o)
bin=main

$(bin):$(obj)
	$(gxx) -v $(gflags) -o $(bin) $(obj)

%.o:%.cpp
	$(gxx) -v $(gflags) -c $< -o $@

clean:
	rm -rf $(obj) $(bin)
