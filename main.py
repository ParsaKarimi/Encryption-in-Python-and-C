import os, sys, random

if len(sys.argv) != 4 or sys.argv[1] not in ("--e", "--d"):
    print("correct format is <--e/--d> <input path> <output path>")
    os._exit(1)
if not os.path.exists(sys.argv[2]):
    print("input file couldn't be found")
    os._exit(1)

def encrypt(input_path, output_path):
    key = list(range(256))
    random.shuffle(key)

    with open(output_path, 'wb') as output_file:
        output_file.write(bytes(key))
        with open(input_path, 'rb') as input_file:
            while True:
                value = input_file.read(1)
                if value == b'':
                    break
                value = value[0]
                encrypted_value = key[value]
                output_file.write(bytes([encrypted_value]))

def decrypt(input_path, output_path):
    with open(input_path, 'rb') as input_file:
        key = [None] * 256
        for i, byte in enumerate(input_file.read(256)):
            key[byte] = i

        if None in key:
            print("input file isn't encrypted with this program")
            return

        with open(output_path, 'wb') as output_file:
            while True:
                encrypted_value = input_file.read(1)
                if encrypted_value == b'':
                    break
                encrypted_value = encrypted_value[0]
                decrypted_value = key[encrypted_value]
                output_file.write(bytes([decrypted_value]))

if sys.argv[1] == "--e":
    encrypt(sys.argv[2], sys.argv[3])
elif sys.argv[1] == "--d":
    decrypt(sys.argv[2], sys.argv[3])