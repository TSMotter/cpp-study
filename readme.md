# CPP study repository

- Each folder containing a `CMakeLists.txt` file is seen as a stand alone small project that can be compiled and run by itself

- To build:
```bash
./bbuild.sh <target>
```

- To build and run:
```bash
./bbuild.sh <target> run
```

- Where "`<target>`" is the path to a folder that contains a `CMakeLists.txt`, like "helloworld" or "cpp-crash-course/2_2"

- To create a new folder (target):
```bash
./create.sh <name>
```