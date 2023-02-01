MAKE := make
all:
	$(MAKE) -C ./3dPlayground-Core
	$(MAKE) -C ./Player

clean:
	$(MAKE) clean -C ./3dPlayground-Core
	$(MAKE) clean -C ./Player