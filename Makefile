all:
	mkdir -p build bin
	
	cd src; javac *.java; jar cfev Esonaldo.jar Main *.class; mv *.class ../build/; mv Esonaldo.jar ../bin/;

clean:
	rm -rf build bin

run:
	java -jar bin/Esonaldo.jar