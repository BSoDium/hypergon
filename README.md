# Hypergon 4D rendering engine

<div style="display: flex; flex-direction: row; column-gap: 10px">
  <img src="public/hypergon_icon.png" alt="Logo" height="100" align="left">

  <div>
    A proof of concept for a 4D rendering engine built with OpenGL, in C++.
  </div>
</div>


## Installation

Setup the dependencies mentionned below, *ie* `OpenGL`, `GLFW`, `Glm`, and `Glu`.

### Debian / Ubuntu

```bash
sudo apt-get install libegl1-mesa-dev
sudo apt-get install libglfw3
sudo apt-get install libglfw3-dev
sudo apt install libglm-dev
```

Build the project with `cmake` and `make`:

```bash
cd hypergon
mkdir build
cd build
cmake ..
make
```

## Usage

*To be documented.*