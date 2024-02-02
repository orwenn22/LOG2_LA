raylib = raylib/src

src_files = ./*.cpp

# require EMSDK to be in the PATH
# TODO: make the changes requiered to remove ASYNCIFY
q2a.html: ${src_files}
	emcc ${src_files} ./raylib/src/libraylib.a \
		-o q2a.html \
		-I${raylib} -s USE_GLFW=3 -s ASYNCIFY \
		--shell-file shell.html \
		-sGL_ENABLE_GET_PROC_ADDRESS
