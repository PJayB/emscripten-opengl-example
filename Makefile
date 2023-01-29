all: build/native/qafoo build/js/qafoo.js

build/native/qafoo: src/qafoo.c src/native.c src/rendering.c
	if uname -a | grep -q "Darwin"; then \
		gcc $^ -lglfw -lsdl -lsdl_image -framework OpenGl -o build/native/qafoo; \
	else \
		gcc $^ -g -O0 -lglfw -lSDL2 -lSDL2_image -lGL -lGLU -o build/native/qafoo; \
	fi

build/js/qafoo.js build/js/qafoo.data: src/qafoo.c src/js.c src/rendering.c
	emcc $^ -I /usr/local/include \
		-o build/js/qafoo.js \
		-s USE_GLFW=3 \
		-s USE_SDL=2 \
		-s USE_SDL_IMAGE=2 \
		-s LEGACY_GL_EMULATION=1 \
		-s SDL2_IMAGE_FORMATS='["png"]' \
		-O2 \
		--preload-file data/qafoo.png

.PHONY: clean
clean:
	@-rm build/native/qafoo 2>/dev/null
	@-rm build/js/qafoo.js build/js/qafoo.data 2>/dev/null
