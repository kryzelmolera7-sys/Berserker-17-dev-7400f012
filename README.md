# Stockfish

A free and strong UCI chess engine.

Explore Stockfish docs • Report a bug • Open a discussion • Discord • Blog

## Overview

Stockfish is a free and strong UCI chess engine derived from Glaurung 2.1 that analyzes chess positions and computes the optimal moves.

Stockfish does not include a graphical user interface (GUI). A GUI is required to display a chessboard and to make it easy to input moves. GUIs are developed independently from Stockfish and are available online. Please read the documentation for your GUI of choice for information about how to use Stockfish with it.

See also the Stockfish documentation for further usage help.

## Files

This distribution of Stockfish consists of the following files:

- README.md, the file you are currently reading.
- Copying.txt, a text file containing the GNU General Public License version 3.
- AUTHORS, a text file with the list of authors for the project.
- src, a subdirectory containing the full source code, including a Makefile that can be used to compile Stockfish on Unix-like systems.
- one or more files with the .nnue extension, storing the neural network for the NNUE evaluation. Binary distributions may embed this file.

## Contributing

See the [Contributing Guide](CONTRIBUTING.md).

### Donating hardware

Improving Stockfish requires a massive amount of testing. You can donate your hardware resources by installing the Fishtest Worker and viewing the current tests on Fishtest.

### Improving the code

In the [chessprogramming wiki](https://www.chessprogramming.org/), many techniques used in Stockfish are explained with a lot of background information. The section on Stockfish describes many features and techniques used by Stockfish. However, it is generic rather than focused on Stockfish's precise implementation.

The engine testing is done on [Fishtest](https://tests.stockfishchess.org/).

If you want to help improve Stockfish, please read [this guideline first](https://github.com/official-stockfish/Stockfish/blob/master/CONTRIBUTING.md), where the basics of Stockfish development are explained.

Discussions about Stockfish take place mainly on the [Stockfish Discord server](https://discord.gg/8nV7Kc3). This is also the best place to ask questions about the codebase and how to improve it.

## Compiling Stockfish

Stockfish supports 32-bit and 64-bit CPUs, certain hardware instructions, big-endian machines such as PowerPC, and other platforms.

On Unix-like systems, it should be easy to compile Stockfish directly from the source code with the included Makefile in the `src` folder.

In general, it is recommended to run `make help` to see a list of make targets with corresponding descriptions.

An example suitable for most Intel and AMD chips:

```bash
cd src
make -j profile-build
```

Detailed compilation instructions for all platforms can be found in the Stockfish documentation.

## License

Stockfish is free software, distributed under the GNU General Public License version 3. See [Copying.txt](Copying.txt) for the full license text.

## Project links

- Homepage: https://stockfishchess.org/
- GitHub: https://github.com/official-stockfish/Stockfish
- Fishtest: https://tests.stockfishchess.org/
- Discord: https://discord.gg/8nV7Kc3

This README is intended as a concise project overview; for the latest details and in-depth instructions, please refer to the official documentation and source tree.
