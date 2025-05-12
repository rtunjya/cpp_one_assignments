
# C++ One Assignments
![build](https://github.com/kstatz12/cpp_one_assignments/actions/workflows/cmake_build.yml/badge.svg)

## Visual Studio
if you want to use a full-featured IDE like visual studio or CLion make sure you have the CMake tools installed
[link](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170) and loading this project _should_ just work

## Environment Setup

### Vagrant
#### Install
- install Vagrant from [link](https://developer.hashicorp.com/vagrant/docs/installation)

- make sure you have a CPU that allows virtualization
  - Enable Virtualization [link](https://support.microsoft.com/en-us/windows/enable-virtualization-on-windows-c5578302-6e43-4b4b-a449-8ced115f58e1)

### Virtualbox
#### Install 
- install Virtualbox for your system
  - [link](https://www.virtualbox.org/wiki/Downloads)
  
  - note if you are on windows you can use [hyper-v](https://learn.microsoft.com/en-us/windows-server/virtualization/hyper-v/hyper-v-overview?pivots=windows-server) instead of the virtualbox hypervisor, but it is integrated into windows to the extent that if the VM crashes, it will also crash the host (your computer)

  - note for Mac Silicone users: you have to jump through some hoops. You can either switch out the base box (ubuntu 22.04) with an ARM version or use the `qemu` provider to run under virtualization AND emulation
  
  - if you are running linux I assume you can set up `libvrt` on your own

### Visual Studio Code
#### Install
- download [link](https://code.visualstudio.com/download)

#### Plugins
- remote development plugin [link](https://code.visualstudio.com/docs/remote/remote-overview)

- c++ tools [link](https://code.visualstudio.com/docs/languages/cpp)

### Git
#### Install

- install git bash for your platform [link](https://git-scm.com/downloads)

## Spinning Up

open a [Windows terminal](https://github.com/microsoft/terminal)/powershell/cmd/git bash window and navigate to your project

``` shell
cd ~/{path to your project}
```

spin up vagrant

``` shell
vagrant up
```

if you are using virtualbox for a provider you have to pass that in

``` shell
vagrant up --provider virtualbox
```

## Connecting your editor

- in your shell, in the root directory of the project enter `vagrant ssh-config` and copy the output. It should look something like 

``` shell
Host default
  HostName 192.168.122.144
  User vagrant
  Port 22
  UserKnownHostsFile /dev/null
  StrictHostKeyChecking no
  PasswordAuthentication no
  IdentityFile /home/karl/src/cpp_two_assignments/.vagrant/machines/default/libvirt/private_key
  IdentitiesOnly yes
  LogLevel FATAL
```

- Launch Visual Studio Code and hit Ctrl+Shift+P to open the command palette

- Choose `Open SSH Configuration File`

- Paste the config

- Change the `Host default` to something like `Host cpp_assignments`

- Open the command palette again (Ctrl+Shift+P) and search for `Remote SSH: Connect To Host` and choose your host name from the previous step

- This will open a new VSCode window and start installing tools on the remote server

- Once you are fully connected choose `Open Folder` and then choose on `/home/vagrant/code`

- Now you should be able to edit files as if they were local

## Compiling

### SSH
- in your shell type `vagrant ssh`

- cd into `/home/vagrant/code`

- Enter the following commands to build and compile your project

``` shell
cmake -S . build

cmake --build build
```

then to run all the tests

``` shell
./build/ctest
```

if this results in 
```
*********************************
No test configuration file found!
*********************************
Usage

  ctest [options]
```

then run 

```
cd algorithms
mkdir build
cd build
cmake ../
make
ctest
```

in that order, and it will run the specific tests for the algorithms project. to build the battleship tests just 
```
cd battleship
```

from the root directory and it will specify those tests
### In Editor

to build the project you can use the built-in hotkey: Ctrl+Shift+B


to compile choose `Run Tasks` and choose `cmake compile`

to test run `cmake test`

=======
# Battleship
The goal of the battleship assignment is to find all the ships on a grid in as few guesses as possible. 

## Compiling/Running
### Vagrant

### Windows
- [CMake For Visual Studio Documentation](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=msvc-170) Install Visual Studio 2022, Cmake Tools and C++ Tools on your home computer

## Rules
The board is 1000x1000 with 5 ships

you must implement `src/user_solver.cpp`
``` c++
void UserSolver::solve(Board &board)
{
  //Your Implementation goes here
  ReturnType t = guess(1, 1, board);
}
```

An example implementation is in `src/example_solver.cpp`

``` c++
void ExampleSolver::solve(Board &board) {
  for (int i = 0; i < board.getX(); i++) {
    for (int j = 0; j < board.getY(); j++) {
        guess(i, j, board);
    }
  }
}
```

The `Solver` class exposes a function called `guess` that takes in 3 arguments. an `X` coordinate, a `Y` coordinate and the board to look up the coordinates. It returns a `ResultType`. There are 4 possible values for the `ResultType` enum: `Hit`, `Miss`, `Near Miss`, and `Bad Guess`. They signify
- Miss is returned when the cell at x,y is empty and no adjacent cell has a value
- Near Miss is returned when the cell at x,y is empty but an adjacent cell has a value
- Hit is returned when the cell at x,y has a value
- Bad Guess is returned when the x,y coordinates are out of range

using these return values you must devise an algorithm to find the 5 ships in fewer moves than the computer (see example)


### Running Tests
in the root of the battleship project run:
``` shell
my_project$ cd build && ctest
```

the output looks something like 
``` shell
Test project /home/karl/src/cpp_one_assignments/battleship/build
    Start 1: SOLVER_TEST.BasicAssertions
1/1 Test #1: SOLVER_TEST.BasicAssertions ......   Passed    0.04 sec

100% tests passed, 0 tests failed out of 1
```

## Rubric
| Criteria                          | Points |
|-----------------------------------|--------|
| Code Completes without Errors     | 50     |
| Code Uses Correct C++ Conventions | 30     |
| Code is legible and followable    | 10     |
| Code Compiles                     | 10     |
6d0bd6a (completed assignment)

