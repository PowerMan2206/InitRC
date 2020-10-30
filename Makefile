BIN=/usr/bin

initrc:
	cc initrc.c -o ./init --verbose

install:
	echo "Moving the current init into init.old..."
	mv $(BIN)/init $(BIN)/init.old
	echo "Moving InitRC into init..."
	mv ./init $(BIN)/init

uninstall:
	echo "Deleting /bin/init (InitRC)..."
	rm -f $(BIN)/init
	echo "Moving init.old into init..."
	mv $(BIN)/init.old $(BIN)/init