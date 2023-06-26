# Basic HTTP Server made using C++

This documentation provides instructions on installing, using, testing, and deploying the project.

## Table of Contents

- [Table of Contents](#table-of-contents)
- [1. Installation](#1-installation)
- [2. Usage](#2-usage)
- [3. Testing](#3-testing)
- [4. Deployment](#4-deployment)

## 1. Installation

To install the C++ HTTP Server, follow these steps:

1. Ensure that you have the following prerequisites installed:
   - C++ compiler (GCC or Clang)
   - Boost library (version 1.70 or higher)
   - CMake (version 3.10 or higher)

2. Clone the project repository from GitHub:

```shell
git clone https://github.com/Thavarshan/chttp.git
```

3. Navigate to the project directory:

```shell
cd chttp
```

4. Create a build directory:

```shell
mkdir build
cd build
```

5. Generate the build files using CMake:

```shell
cmake ..
```

6. Compile the project:

```shell
make
```

Upon successful completion of these steps, the compiled `server` binary will be generated in the `build` directory.

## 2. Usage

To use the HTTPServer, follow these steps:

1. Ensure that the server is compiled by following the installation instructions.
2. Open a terminal or command prompt.
3. Navigate to the `build` directory:

```shell
cd chttp/build
```

4. Start the server by running the `server` binary:

```shell
./server
```

5. The server will start listening on port 8080 by default. You can modify the port number by passing it as a command-line argument:

```shell
./server <port>
```

6. Once the server is running, it will start accepting incoming HTTP requests.

## 3. Testing

To run the test cases for the HTTP Server, follow these steps:

1. Ensure that the server is compiled by following the installation instructions.
2. Open a terminal or command prompt.
3. Navigate to the `build` directory:

```shell
cd chttp/build
```

4. Run the `server_test` binary to execute the test cases:

```shell
./server_test
```

5. The test cases will be executed, and the test results will be displayed in the terminal.
6. Verify that all the test cases pass without any failures or errors.

## 4. Deployment

To deploy the HTTPServer project, follow these steps:

1. Compile the server by following the installation instructions.
2. Transfer the compiled `server` binary to the target deployment environment.
3. On the target deployment environment, open a terminal or command prompt.
4. Navigate to the directory where the `server` binary is located.
5. Start the server by running the `server` binary:

```shell
./server
```

6. The server will start listening on the default port 8080. If needed, you can modify the port by passing it as a command-line argument:

```shell
./server <port>
```

7. Ensure that the necessary network configurations, such as firewalls and port forwarding, are in place to allow incoming connections to the server.
8. Once deployed, the server will be ready to accept incoming
