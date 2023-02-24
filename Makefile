all: unit-test

unit-test:
	rm -rf testing
	cmake -DTARGET_GROUP=test -B testing
	cd testing && make && ctest -v .




