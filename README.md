# Geometric Shapes

A C++23 console application for exploring basic 2D geometry.  It models circles,
polygons (including triangles and squares) and stores them in a heterogenous
collection.  The program can load figures from a text file, print their
properties and run a small test suite from an interactive menu.

## Features

- **Interactive menu** – view file contents, load figures, print stored shapes
  or search which shapes contain a given point.  Built‑in tests cover the Point,
  Circle and Polygon classes along with the container for figures.
- **Heterogenous container** – `Shapes` manages a dynamic array of `Figure`
  pointers so different shape types can live together.
- **Shape implementations** – concrete classes such as `Circle`, `Polygon`,
  `Square` and `Triangle` provide geometry operations like translation, area,
  circumference and point inclusion checks.
- **File based input** – figures are parsed from a simple comma‑separated text
  file and only those that lie outside the origin‑centred unit circle are
  stored.

## Building

This project uses **CMake**.

```bash
cmake -S . -B build
cmake --build build
```

An executable named `GeometricShapes` will be produced in the `build/`
directory.

## Usage

Run the compiled executable and follow the on‑screen instructions:

```bash
./build/GeometricShapes
```

The default data file is `figures.txt` in the repository root.  Sample menu
options include:

1. Print the content of the text file.
2. Store figures that are **not** inside the unit circle.
3. Display properties of the stored figures.
4. Check which stored figures contain a given point.
5. Execute the built‑in test cases.

## Running the tests

The tests are accessible from the menu.  To run all tests non‑interactively you
can pipe input to the executable:

```bash
printf "5\n5\n9\n" | ./build/GeometricShapes
```

## Repository layout

```
src/
 ├── main/
 │   ├── controls/    # menu logic and file parsing
 │   ├── shapes/      # geometric shape classes
 │   ├── utils/       # Point and String utilities
 │   └── main.cpp     # program entry point
 └── test/            # test cases
```

`figures.txt` provides example shape descriptions.

## License

This project is distributed without a specified license.  Use at your own
 discretion.
