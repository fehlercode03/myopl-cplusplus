{ pkgs }: {
	deps = [
		pkgs.python39
		pkgs.tree
		pkgs.hexdump
		pkgs.coreutils
		pkgs.file
		pkgs.pwndbg
		pkgs.gdb
		# only these two strictly necessary
		pkgs.fmt
		pkgs.clang_12
	];
}
