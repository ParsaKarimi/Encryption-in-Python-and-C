
# File Encryptor and Decryptor

This repository contains implementations of a file encryption and decryption tool written in both Python and C. The project demonstrates custom key-based encryption and decryption using a lightweight approach.

## Why This Project?
This project was created as a learning exercise to explore:
- File I/O operations.
- Cryptographic concepts and random key generation.
- Cross-language implementation of similar functionalities.

## Features
- **Python Implementation**:
  - Simple and easy-to-use script.
  - Dynamic key generation and storage for encryption.

- **C Implementation**:
  - Optimized for performance.
  - CLI-based program with efficient key handling.

---

## Python Implementation

### Usage
To use the Python implementation, run the `main.py` script with the following arguments:

```bash
python main.py <--e/--d> <input_path> <output_path>
```

### Examples
#### Encrypting a File
```bash
python main.py --e input.txt encrypted.dat
```

#### Decrypting a File
```bash
python main.py --d encrypted.dat decrypted.txt
```

### How It Works
- **Encryption**: Generates a random key and maps file bytes to encrypted values.
- **Decryption**: Uses the stored key to restore original file data.

---

## C Implementation

### Compilation
Compile the C program using a C compiler like GCC:
```bash
gcc -o encryptor main.c
```

### Usage
Run the compiled program with the following arguments:
```bash
./encryptor <--e/--d> <input_path> <output_path>
```

### Examples
#### Encrypting a File
```bash
./encryptor --e input.txt encrypted.dat
```

#### Decrypting a File
```bash
./encryptor --d encrypted.dat decrypted.txt
```

### How It Works
- **Key Generation**: Uses `rand()` for creating a 256-byte random key.
- **Encryption**: Maps file bytes to their encrypted counterparts using the key.
- **Decryption**: Maps encrypted bytes back to original values using the stored key.

---

## How to Run the Project

1. Clone this repository:
   ```bash
   git clone https://github.com/ParsaKarimi/Encryption-in-Python-and-C.git
   cd Encryption-in-Python-and-C
   ```
2. Choose your preferred implementation:
   - For Python, ensure Python is installed.
   - For C, compile the program using a C compiler.
3. Run the program using the appropriate commands for each language.
