gxx=g++ 
src=$(shell find ./ -name "*.cpp")
obj=$(src:%.cpp=%.o)
bin=main

$(bin):$(obj)
	$(gxx) -o $(bin) $(obj)

%.o:%.cpp
	$(gxx) -c $< -o $@

clean:
	rm -rf $(obj) $(bin)
