gxx=g++ 
src=$(shell find ./ -name "*.cpp")
gflags=-std=c++17
obj=$(src:%.cpp=%.o)
bin=main

$(bin):$(obj)
	$(gxx) $(gflags) -o $(bin) $(obj)

%.o:%.cpp
	$(gxx) $(gflags) -c $< -o $@

clean:
	rm -rf $(obj) $(bin)
