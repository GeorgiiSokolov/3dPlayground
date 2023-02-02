MAKE := make
all:
	$(MAKE) -C ./Extern/glad
	$(MAKE) -C ./3dPlayground-Core
	$(MAKE) -C ./Player

clean:
	$(MAKE) clean -C ./Extern/glad
	$(MAKE) clean -C ./3dPlayground-Core
	$(MAKE) clean -C ./Player
	